#ifndef BST_FUCNTIONS_H_
#define BST_FUNCTIONS_H_

#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

template <typename T>
struct tree_node {
    T _item;
    tree_node<T>* _left;
    tree_node<T>* _right;
    int _height;
    int balance_factor() {
        //balance factor = height of the right subtree 
        //                        - the height of the left subtree
        //a NULL child has a height of -1
        //a leaf has a height of 0
        return _right->height - _left->height;
    }

    int height() {
        // Height of a node is 1 + height of the "taller" child
        //A leaf node has a height of zero: 1 + max(-1,-1)
        int leftNum = 0, rightNum = 0;
        if (this == NULL) {
            return -1;
        }
        if (this->_left == NULL) {
            leftNum = -1;
        } else {
            leftNum = _left->height();
        }
        if (this->_right == NULL) {
            rightNum = -1;
        } else {
            rightNum = _right->height();
        }
        return (1 + max(rightNum, leftNum));
    }
    int update_height() {
        //set the _height member variable (call height();)
        _height = height();
        return _height;
    }

    tree_node(T item = T(), tree_node* left = NULL,
        tree_node* right = NULL) :
        _item(item), _left(left), _right(right) {
        _height = -1;
    }
    friend ostream& operator <<(ostream& outs,
        const tree_node<T>& t_node) {
        outs << "|" << t_node._item << "|";
    }
};

template <typename T> //inserts an item into an existing tree ignores repeats
void tree_insert(tree_node<T>*& root, const T& insert_me) {
    if (root == NULL) {
        root = new tree_node<T>(insert_me);
    } else if (insert_me < root->_item) {
        //put item into the left
        tree_insert(root->_left, insert_me);
    } else if (insert_me > root->_item) {
        tree_insert(root->_right, insert_me);
    }
    root->update_height();
}

template <typename T> //searches for a target and returns that node 
tree_node<T>* tree_search(tree_node<T>* root, const T& target) {
    if (!root) {
        return root;
    }
    if (root->_item == target) {
        return root;
    }
    if (target > root->_item) {
        return tree_search(root->_right, target);
    }
    if (target < root->_item) {
        return tree_search(root->_left, target);
    }
}


template <typename T> //searches for a target and returns true if found
bool tree_search(tree_node<T>* root, const T& target,
    tree_node<T>*& found_ptr) {
    if (!root) {
        found_ptr = NULL;
        return false;
    }
    if (root->_item == target) {
        found_ptr = root;
        return true;
    }
    if (target > root->_item) {
        return tree_search(root->_right, target,found_ptr);
    }
    if (target < root->_item) {
        return tree_search(root->_left, target,found_ptr);
    }
}

template<typename T>
void tree_print(tree_node<T>* root, int level = 0,
    ostream& outs = cout) {
    if (root) {
        tree_print(root->_right, level + 1);
        outs << setw(4 * level) << "" << "[" << root->_item << "]" << endl;
        tree_print(root->_left, level + 1);
    }
}

template<typename T>       //prints detailes info about each node
void tree_print_debug(tree_node<T>* root, int level = 0,
    ostream& outs = cout) {
    if (root) {
        tree_print(root->_right, level + 1);
        outs << setw(4 * level) << "" << "[" << root->_item << "] H:" << root->height() << endl;
        tree_print(root->_left, level + 1);
    }
}

template <typename T>       //clear the tree
void tree_clear(tree_node<T>*& root) {
    if (root) {
        tree_clear(root->_left);
        tree_clear(root->_right);
        delete root;
        root = NULL;
    }
}

template <typename T>       //erase target from the tree
bool tree_erase(tree_node<T>*& root, const T& target) {
    // this attempts to erase a number from the tree it checks if the item is a leaf or branch if its a branch
    //then the item needs to be replaced by the greatest item to its left thus making the tree ok again
    if (!root) {
        return false;
    }
    if (root->_item == target) {
        T temp;
        if (root->_right != NULL) {
            tree_remove_max(root->_left, temp);
            root->_item = temp;
        } else {
            tree_node<T>* temp = root->_left;
            delete root;
            root = temp;
        }
        return true;
    }
    if (target > root->_item) {
        return tree_erase(root->_right, target);
    }
    if (target < root->_item) {
        return tree_erase(root->_left, target);
    }
    return false;
}

template <typename T>       //erase rightmost node from the tree
                            // store the item in max_value
void tree_remove_max(tree_node<T>*& root, T& max_value) {
    tree_node<T>* tree_ptr;
    if (!root) {
        
    } else if (root->_right == NULL) {
        tree_ptr = root->_left;
        max_value = root->_item;
        delete root;
        root = tree_ptr;
    } else if (root->_left == NULL && root->_right == NULL) {
        max_value = root->_item;
        delete root;
        root = NULL;
    } else {
        tree_remove_max(root->_right, max_value);
        root->update_height();
    }
    
}

template <typename T>       //return copy of tree pointed to by root
tree_node<T>* tree_copy(tree_node<T>* root) {
    if (root) {
        return new tree_node<T>(root->_item, tree_copy(root->_left), tree_copy(root->_right));
    } else {
        return NULL;
    }
}

template <typename T>       // tree -> sorted array
void tree_to_sorted_list(const tree_node<T>* root, T*& arrPtr,int& index) {
    if (root) {
        tree_to_sorted_list(root->_left, arrPtr, index);
        arrPtr[index++] = root->_item;
        tree_to_sorted_list(root->_right, arrPtr, index);
    }
}

template <typename T>    // sorted array -> tree
tree_node<T>* tree_from_sorted_list(const T* a, int start, int end) {
    if (start > end) {
        return NULL;
    }

    tree_node<T>* temp = new tree_node<T>((a[(start + end) / 2]));
    temp->_left = tree_from_sorted_list(a, start, (start + end) / 2 - 1);
    temp->_right = tree_from_sorted_list(a, ((start + end) / 2 + 1), end);
    return temp;
}

template <typename T>     // sorted array -> tree
tree_node<T>* tree_from_sorted_list(const T* a, int size) {
    return tree_from_sorted_list(a, 0, size-1);
}

template <typename T>       //gets the size of a tree
void tree_size(const tree_node<T>* root, int &size) {
    if (root) {
        tree_size(root->_left, size);
        size++;
        tree_size(root->_right, size);
    }
}

template <typename T>       //Add tree src to dest
void tree_add(tree_node<T>*& dest, const tree_node<T>* src) {
    //this converts a tree to 2 sorted list then combines those list and finally makes
    //destination a new tree based off the sorted array
    int size1 = 0, size2 = 0, size3 = 0, index1 = 0, index2 = 0;
    tree_size(dest,size1);
    tree_size(src,size2);
    int* destArr = new int[size1];
    int* srcArr = new int[size2];
   
    tree_to_sorted_list(dest, destArr, index1);
    tree_to_sorted_list(src, srcArr, index2);
    
    index1 = 0;
    index2 = 0;
    size3 = size1 + size2;

    //checks for repeats and sets a flag to ignore them also reduces our size as we would not need to include 
    // the repeats
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (destArr[i] == srcArr[j]) {
                size3--;
                srcArr[j] = -1;
            }
        }
    }
   
    int* newDestArr = new int[size3];
   
    //adds both of the arrays to a new array then sorts it at the bottom
    for (int i = 0; i < size1; i++) {
        newDestArr[i] = destArr[index1];
        index1++;
    }
    for (int i = size1; i < size3; i++) {
        if (srcArr[index2] != -1) {
            newDestArr[i] = srcArr[index2];

        } else {
            index2++;
            newDestArr[i] = srcArr[index2];
        }
        index2++;
    }

    sort(newDestArr, newDestArr + size3);
    //clear the old tree and set it equal to a new tree we made from the sorted list
    tree_clear(dest);
    dest = tree_from_sorted_list(newDestArr,size3);
}

#endif // !BST_FUCNTIONS_H_

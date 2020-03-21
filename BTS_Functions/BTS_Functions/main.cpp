/*
 * Author: Steven Herrera
 * Project: BST Functions
 * Purpose: This is meant to test the functions which will be doing all the hard work for the BST class
 *          
 *          
 * Notes: I was unable to get the tree from sorted list to work without using a helper function
 *
 */

#include <iostream>
#include "BST_Functions.h"
using namespace std;

void test_tree_copy() {
    cout << "===================== Testing Tree Copy =====================\n";
    tree_node<int>* firstTree = new tree_node<int> (50);
    tree_node<int>* secondTree = NULL;
    tree_insert(firstTree,40);
    tree_insert(firstTree,45);
    tree_insert(firstTree, 35);
    tree_insert(firstTree, 60);
    tree_insert(firstTree, 55);
    tree_insert(firstTree, 75);
    cout << "Tree 1\n";
    tree_print(firstTree);
    cout << "Tree 2\n";
    tree_print(secondTree);
    cout << "\nTree 2 after copy\n";
    secondTree = tree_copy(firstTree);
    tree_print(secondTree);
}

void test_remove_max() {
    cout << "\n\n===================== Testing remove Max =====================\n";
    tree_node<int>* firstTree = new tree_node<int>(50);
    int num = 0;
    
    tree_insert(firstTree, 40);
    tree_insert(firstTree, 45);
    tree_insert(firstTree, 35);
    tree_insert(firstTree, 60);
    tree_insert(firstTree, 55);
    tree_insert(firstTree, 75);

    cout << "Tree 1\n";
    tree_print(firstTree);

    while (firstTree) {
        tree_remove_max(firstTree, num);
        cout << "Tree 1 after removing " << num << endl;
        tree_print_debug(firstTree);
        cout << endl;
    }
}

void test_tree_erase() {
    cout << "\n\n===================== Testing Tree Erase =====================\n";
    tree_node<int>* firstTree = new tree_node<int>(50);
    int num = 60;

    tree_insert(firstTree, 40);
    tree_insert(firstTree, 45);
    tree_insert(firstTree, 35);
    tree_insert(firstTree, 60);
    tree_insert(firstTree, 55);
    tree_insert(firstTree, 75);

    cout << "Tree 1\n";
    tree_print(firstTree);
    
    cout << "Tree 1 after removing " << num << endl;
    tree_erase(firstTree, num);
    tree_print(firstTree);
    num = 40;
    cout << "Tree 1 after removing " << num << endl;
    tree_erase(firstTree, num);
    tree_print(firstTree);
    
}

void test_tree_from_sorted_list() {
    const int size = 9;
    int arr[size];
    tree_node<int>* tree = NULL;
    cout << "\n\n============== Testing Tree From Sorted List ==============\n";
    cout << "array we are using\n";
    for (int i = 0; i < size; i++) {
        arr[i] = i * 10;
        cout << arr[i] << " ";
    }
    tree = tree_from_sorted_list(arr, size);
    cout << "\nTree made from list:\n";
    tree_print(tree);
}

void test_tree_search() {
    tree_node<int>* firstTree = new tree_node<int>(50);
    tree_node<int>* foundPtr = NULL;
    int num = 40;
    
    cout << "\n\n================= Testing Tree Search =================\n";
    
    tree_insert(firstTree, 40);
    tree_insert(firstTree, 45);
    tree_insert(firstTree, 35);
    tree_insert(firstTree, 60);
    tree_insert(firstTree, 55);
    tree_insert(firstTree, 75);
    
    cout << "Tree 1\n";
    tree_print(firstTree);

    while (true) {
        cout << "we will search for " << num << endl;
        if (tree_search(firstTree, num, foundPtr)) {
            cout << "we found " << foundPtr->_item << endl;
        } else {
            cout << "could not find " << num << endl;
            break;
        }
        num += 5;
    }
    
}

void test_tree_to_sorted_list() {
    tree_node<int>* firstTree = new tree_node<int>(50);
    int* arrPtr = new int[7];
    int num = 40;
    int index = 0;
    cout << "\n\n================= Testing Tree To Array =================\n";

    tree_insert(firstTree, 40);
    tree_insert(firstTree, 45);
    tree_insert(firstTree, 35);
    tree_insert(firstTree, 60);
    tree_insert(firstTree, 55);
    tree_insert(firstTree, 75);

    cout << "Tree 1\n";
    tree_print(firstTree);
    cout << "Array made from Tree 1\n";
    tree_to_sorted_list(firstTree, arrPtr,index);
    for (int i = 0; i < 7; i++) {
        cout << arrPtr[i] << " ";
    }
    

}

void test_tree_add() {
    cout << "\n\n===================== Testing Tree Add =====================\n";
    tree_node<int>* firstTree = new tree_node<int>(50);
    tree_node<int>* secondTree = new tree_node<int>(90);
    tree_insert(firstTree, 40);
    tree_insert(firstTree, 45);
    tree_insert(firstTree, 35);
    tree_insert(firstTree, 60);
    tree_insert(firstTree, 55);
    tree_insert(firstTree, 75);

    tree_insert(secondTree, 80);
    tree_insert(secondTree, 85);
    tree_insert(secondTree, 40);
    tree_insert(secondTree, 100);
    tree_insert(secondTree, 95);
    tree_insert(secondTree, 110);

    cout << "Tree1\n";
    tree_print(firstTree);
    cout << "\n\nTree2\n";
    tree_print(secondTree);

    cout << "\n\nTree1 after tree add\n";
    tree_add(firstTree, secondTree);
    tree_print(firstTree);

}

int main()
{
    test_tree_copy();
    test_remove_max();
    test_tree_erase();
    test_tree_from_sorted_list();
    test_tree_search();
    test_tree_to_sorted_list();
    test_tree_add();

    return 0;
}


#ifndef Z_OUTPUT_H_
#define Z_OUTPUT_H_
/*
===================== Testing Tree Copy =====================
Tree 1
        [75]
    [60]
        [55]
[50]
        [45]
    [40]
        [35]
Tree 2

Tree 2 after copy
        [75]
    [60]
        [55]
[50]
        [45]
    [40]
        [35]


===================== Testing remove Max =====================
Tree 1
        [75]
    [60]
        [55]
[50]
        [45]
    [40]
        [35]
Tree 1 after removing 75
    [60]
        [55]
[50] H:2
        [45]
    [40]
        [35]

Tree 1 after removing 60
    [55]
[50] H:2
        [45]
    [40]
        [35]

Tree 1 after removing 55
[50] H:2
        [45]
    [40]
        [35]

Tree 1 after removing 50
    [45]
[40] H:1
    [35]

Tree 1 after removing 45
[40] H:1
    [35]

Tree 1 after removing 40
[35] H:0

Tree 1 after removing 35



===================== Testing Tree Erase =====================
Tree 1
        [75]
    [60]
        [55]
[50]
        [45]
    [40]
        [35]
Tree 1 after removing 60
        [75]
    [55]
[50]
        [45]
    [40]
        [35]
Tree 1 after removing 40
        [75]
    [55]
[50]
        [45]
    [35]


============== Testing Tree From Sorted List ==============
array we are using
0 10 20 30 40 50 60 70 80
Tree made from list:
            [80]
        [70]
    [60]
        [50]
[40]
            [30]
        [20]
    [10]
        [0]


================= Testing Tree Search =================
Tree 1
        [75]
    [60]
        [55]
[50]
        [45]
    [40]
        [35]
we will search for 40
we found 40
we will search for 45
we found 45
we will search for 50
we found 50
we will search for 55
we found 55
we will search for 60
we found 60
we will search for 65
could not find 65


================= Testing Tree To Array =================
Tree 1
        [75]
    [60]
        [55]
[50]
        [45]
    [40]
        [35]
Array made from Tree 1
35 40 45 50 55 60 75

===================== Testing Tree Add =====================
Tree1
        [75]
    [60]
        [55]
[50]
        [45]
    [40]
        [35]


Tree2
        [110]
    [100]
        [95]
[90]
        [85]
    [80]
        [40]


Tree1 after tree add
            [110]
        [100]
            [95]
    [90]
            [85]
        [80]
[75]
            [60]
        [55]
            [50]
    [45]
            [40]
        [35]

*/

#endif // !Z_OUTPUT_H_


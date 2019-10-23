# MinMax-Heap
Implementation of the MinMax Heap data structure.

## Purpose:
For this lab, you will implement a Minmax heap in C++.

## General Requirements:
In this assignment, you will develop an array-based implementation of a Minmax heap. The
initial build of the Minmax heap should use the top-down approach. No duplicates are allowed
to be inserted. Also, each time you insert/remove an element, you should organize the heap
following the minmax heap property.

## In the Minmax heap:
The root of T will be at the minimum level and the next level should be a maximum level.
Minimum and maximum levels will alternate until all the integers in the data.txt file are
inserted into the heap.

Here is where the min and max nodes are located:
  
  min nodes: even levels (0, 2, 4…)
  
  max nodes: odd levels (1, 3, 5…)

The Minmax heap methods should be implemented as follows:

- BuildHeap() - should build the Minmax heap using the top-down approach.
- Insert(x) - should insert x into the Minmax heap. This means you should add a new
element into the heap. After the insertion of new element, the heap should still satisfy
the MinMax heap property.
- Delete(x) - should delete the element x from the Minmax heap. After deleting the
element x, the heap should still satisfy the Minmax heap property.
- MinLevelElements() - should print out the elements of the Minmax heap at even levels
in level order.
- MaxLevelElements() - should print out the elements of the Minmax heap at odd levels in
level order.
- Exit() – should exit from the program.

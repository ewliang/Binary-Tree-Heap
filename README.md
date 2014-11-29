Binary-Tree-Heap
================

C++ implementation of a heap and heap sort through use of a binary tree structure via Max_Heap Implementation.
The algorithm for my version of the program is implemented by traveling through the tree.

If done by hand, inserting involves a zig zag left to right, top to bottom traveling approach, which is how my
insert() function works. 

As for the remove() function, a similar approach is done.


DISCLAIMER: Project is still ongoing, and there are still a few problems.


Problems:

Remove()
  - only removes first 3, then it infinite loops and can't remove beyond 3 nodes and repeats 3 results...

HeapSort()
  - will be fixed once remove() is complete


Challenge:

How to do reassignment of last node if the new last node will be the left major subtree's right most node...

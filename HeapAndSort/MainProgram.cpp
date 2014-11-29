//MAX_HEAP Implementation
//
//File: MainProgram.cpp
//
//Author: Eric Liang
//Website: http://www.eric-liang.com

#include "BTHeap.h"
#include "Node.h"
#include <iostream>
using namespace std;

int main()
{
	//HEAP TREE CREATION
	Node *n1 = new Node(1);
	Node *n2 = new Node(3); //Child swap
	Node *n3 = new Node(5);
	Node *n4 = new Node(7); //Lv1 New Level and Swap
	Node *n5 = new Node(9);
	Node *n6 = new Node(8);
	Node *n7 = new Node(6);
	Node *n8 = new Node(4);
	Node *n9 = new Node(2);
	Node *test = new Node(1000); //Tests for Perculate All the Way Up from Very Bottom
	Node *fin = new Node(10); //Tests for New Root Node Case if Retrieve After Remove() once.

	BTHeap heapTree(n1);

	//HEAP NODE INSERTION
	heapTree.insert(heapTree.root, n2);
	heapTree.insert(heapTree.root, n3);
	heapTree.insert(heapTree.root, n4);
	heapTree.insert(heapTree.root, n5);
	heapTree.insert(heapTree.root, n6);
	heapTree.insert(heapTree.root, n7);
	heapTree.insert(heapTree.root, n8);
	heapTree.insert(heapTree.root, n9);
	heapTree.insert(heapTree.root, test); 
	heapTree.insert(heapTree.root, fin);

	//Display Purposes
	cout << "Data Used: 1  3  5  7  9  8  6  4  2  1000  10" << endl << endl;

	//EMPTY CHECK
	if(heapTree.empty())
		cout << "HEAP STATUS: EMPTY" << endl << endl;
	else
		cout << "HEAP STATUS: NOT EMPTY" << endl << endl;

	//RETRIEVE LARGEST ITEM
	cout << "LARGEST NUMBER: ";
	heapTree.retrieve();

	//REMOVE LARGEST NODE
	cout << "CURRENT ROOT: "; 
	heapTree.retrieve();
	heapTree.remove();
	cout << "NEW ROOT AFTER REMOVAL: ";
	heapTree.retrieve();
	cout << endl;

	//HEAP SORT
	cout << "<<HEAP SORT BEGINS>>" << endl;
	//heapTree.HeapSort();                //The HeapSort() was commented out due to infinite loop after 3 removals.

	heapTree.retrieve();
		heapTree.remove();
	heapTree.retrieve();
		heapTree.remove();
	heapTree.retrieve();
		heapTree.remove();
	heapTree.retrieve();
		heapTree.remove();
	heapTree.retrieve();
		heapTree.remove();
	heapTree.retrieve();
		heapTree.remove();
	heapTree.retrieve();
		heapTree.remove();
	heapTree.retrieve();
		heapTree.remove();
	heapTree.retrieve();
		heapTree.remove();
	heapTree.retrieve();
		heapTree.remove();
	heapTree.retrieve();
		heapTree.remove();

	cin.get();
	return 0;
}


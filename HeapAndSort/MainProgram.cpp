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
	Node *n2 = new Node(3);
	Node *n3 = new Node(5);
	Node *n4 = new Node(7);
	Node *n5 = new Node(9);
	Node *n6 = new Node(8);
	Node *n7 = new Node(6);
	Node *n8 = new Node(4);
	Node *n9 = new Node(2);

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

	//EMPTY CHECK
	if(heapTree.empty())
		cout << "Heap is EMPTY" << endl;
	else
		cout << "Heap is NOT EMPTY" << endl;

	//RETRIEVE LARGEST ITEM
	heapTree.retrieve();

	//REMOVE LARGEST NODE
	//heapTree.remove(n5);

	//HEAP SORT
	//heapTree.HeapSort();

	cin.get();
	return 0;
}


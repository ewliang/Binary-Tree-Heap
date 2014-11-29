//MAX_HEAP Implementation
//
//File: BTHeap.h
//
//Author: Eric Liang
//Website: http://www.eric-liang.com

#pragma once
#include "Node.h"
#include <vector>
class BTHeap
{
public:
	Node * root;
	Node * last;
	BTHeap(Node*);
	bool empty();
	void perculateUp(Node *p, Node *n);
	Node* levelDown(Node *n);
	void perculateDown(Node *p);
	void insert(Node* r, Node* n);
	void retrieve();
	Node* levelDownRight(Node *n);
	void remove();
	void HeapSort();
};
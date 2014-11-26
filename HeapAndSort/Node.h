//MAX_HEAP Implementation
//
//File: Node.h
//
//Author: Eric Liang
//Website: http://www.eric-liang.com

#pragma once
class Node
{
public:
	int data;
	Node * parent;
	Node * right;
	Node * left;
	Node(int data);
};
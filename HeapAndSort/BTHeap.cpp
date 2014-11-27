//MAX_HEAP Implementation
//
//File: BTHeap.cpp
//
//Author: Eric Liang
//Website: http://www.eric-liang.com

#include "BTHeap.h"
#include "Node.h"
#include <iostream>
using namespace std;

BTHeap::BTHeap(Node* r)
{	
	root = r;
}

bool BTHeap::empty()
{
	if (root == '\0')
		return true;
	else
		return false;
}

void BTHeap::perculateUp(Node *p, Node *n)
{
	if(n->data > p->data)
	{
		int temp = p->data;
		p->data = n->data;
		n->data = temp;
	}
	if(p->parent != NULL)
		perculateUp(p->parent, p);
	//else
	//{
	//	root = p;
	//}
}

Node* BTHeap::perculateDown(Node* t)
{
	if(t->left != NULL)
		perculateDown(t->left);
	else
		return t->left;
}

void BTHeap::insert(Node*r, Node *n)
{	
	if(r->parent == NULL) //ROOT
	{
		if(r->left == NULL) //LEFT IS NULL
		{
			n->parent = r;
			r->left = n;
			if(n->data > r->data) //CHILD > PARENT?
			{ //but doesn't this way of things mean the nodes swap location but parent pointer still points to old location??? :X PROBLEM!
				int temp;
				temp = r->data;
				r->data = n->data;
				n->data = temp;
				root = r;
			}
		}
		else if(r->right == NULL) //RIGHT IS NULL
		{
			n->parent = r;
			r->right = n;
			if(n->data > r->data) //CHILD > PARENT?
			{
				int temp;
				temp = r->data;
				r->data = n->data;
				n->data = temp;
				root = r;
			}
		}
		else //LEFT AND RIGHT NOT NULL
		{
			insert(r->left, n);
		}
	}
	else //NOT A ROOT
	{
		if(r->left == NULL) //LEFT IS NULL
		{
			n->parent = r;
			r->left = n;
			perculateUp(r, n);
		}
		else if(r->right == NULL) //RIGHT IS NULL
		{
			n->parent = r;
			r->right = n;
			perculateUp(r, n);
		}
		else //LEFT AND RIGHT NOT NULL
		{
			if(r->parent->right != r)
			{//left sub-branch case
				insert(r->parent->right, n);
			}
			else if(r->parent->right == r)
			{//right sub-branch case -- maybe it's farthest right
				if(r->parent->parent->right == r->parent) //right most case
				{//right most case
					Node *traverser;
					traverser = root;
					Node *leftMostNode = perculateDown(traverser);
					insert(leftMostNode, n);
				}
				else
				{
					insert(r->parent->parent->right->left, n);
				}
			}
		}
	}
}

void BTHeap::retrieve()
{
	if(this->empty()) //Tree is Empty Safeguard
	{
		cout << "Error, Tree is Empty! Please Insert Items into Tree First." << endl;
	}
	else
	{
		if (root == '\0')
			cout << "Root is empty!" << endl;
		else
		{
			cout << root->data << " " << endl;
		}
	}
}

void BTHeap::remove(Node * n) //remove the parameter?
{
	Node * xsucc;
	if ((n->left == NULL) && (n->right == NULL))
	{
		if (n->parent != NULL)//leaf
		{
			if (n->data > n->parent->data)
				n->parent->right = NULL;
			else
				n->parent->left = NULL;
		}
		else //root, no children
		{
			root = NULL;
			cout << "\n The tree is empty now \n";
		}
	}
	//one right child, no left child - impossible case (will never happen)
	//one left child, no right child
	if ((n->right == NULL) && (n->left != NULL))
	{
		if (n->data > n->parent->data)
			n->parent->right = n->left;
		else
			n->parent->left = n->left;
	}
	if ((n->right != NULL) && (n->left != NULL))//two childern, find the successor, replace, and remove
	{
		xsucc = n->right;
		while (xsucc->left != NULL)
		{
			xsucc = xsucc->left;
		}
		n->data = xsucc->data;
		if (xsucc->right != NULL)
			xsucc->parent->left = xsucc->right;
		else
			xsucc->parent->left = '\0';
	}
}

void BTHeap::HeapSort()
{
	while(!empty())
	{
		retrieve();
		//remove();
	}
}

bool BTHeap::search(Node *root, int key)
{	if (root == '\0')
		return false;
	else
	{  if (root->data == key)
			return true;
		else
		{	if (root->data > key)
				search(root->left, key);
			else
				search(root->right, key);
		}

	}
}

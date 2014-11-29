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
void BTHeap::insert(Node*r, Node *n)
{	
	last = n;
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
			if(r->parent->right == r)
			{//right sub-branch case -- maybe it's farthest right
				if(r->parent->parent != NULL)
				{
					if(r->parent->parent->right == r->parent) //right most case
					{//right most case
						Node *traverser;
						traverser = root;
						Node *leftMostNode = levelDown(traverser);
						insert(leftMostNode, n);
					}
					else
					{
						insert(r->parent->parent->right->left, n);
					}
				}
				else if(r->parent->parent == NULL)
				{
					Node *traverser;
					traverser = root;
					Node *leftMostNode = levelDown(traverser);
					insert(leftMostNode, n);
				}
			}
			else if(r->parent->right != r)
			{//left sub-branch case
				insert(r->parent->right, n);
			}
		}
	}
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
}

Node* BTHeap::levelDown(Node *t)
{
	if(t->left != NULL)
		levelDown(t->left);
	else
		return t;
}

void BTHeap::retrieve()
{
	if(this->empty()) //Tree is Empty Safeguard
	{
		cout << "Tree is Empty!" << endl;
	}
	else
	{
		cout << root->data << " " << endl;
	}
}

Node* BTHeap::levelDownRight(Node *t)
{
	if(t->right != NULL)
		levelDown(t->right);
	else
		return t;
}

void BTHeap::remove()
{
	if(root != last)
	{
		Node *tempLast;
		int temp;
		if(root->left == last) //root + left child left
		{
			tempLast = root;
			temp = root->data;
			root->data = last->data;
			last->data = temp;
			last = NULL;
			last = tempLast;
		}
		else if(root->right == last)
		{
			tempLast = root->left;
			temp = last->data;
			last->data = root->data;
			root->data = temp;
			last = NULL;
			last = tempLast;
			if(root->left->data > root->data)
			{
				temp = root->left->data;
				root->left->data = root->data;
				root->data = temp;
			}
		}
		else
		{
			temp = root->data;
			root->data = last->data;
			last->data = temp;
			tempLast = last;
			//REASSIGN LAST
			
			//check which child (L or R)
			//then determine whether you need to go up and outer
			//assume small tree
			//then large tree

			if(last->parent->left == last) //L child
			{//need to travel out
				if(last->parent->parent->left != last->parent)
				{//no need to travel super out, just stay within 
					tempLast = last->parent->parent->left->right;
				}
				else
				{//must travel out as long as not left most half of tree
					if(last->parent->parent != root)
					{
						if(last->parent->parent->parent->left != last->parent->parent)
						{
							tempLast = last->parent->parent->parent->left->right->right;
						}
						else
						{//must go up one level's last item as tempLast
							//travel down right
							Node *rLast = levelDownRight(root);
							tempLast = rLast;
						}
					}
					else
					{
						tempLast = last->parent->parent->left->right;
					}
				}
			}
			else //R child
			{//no need to jump out
				tempLast = last->parent->left;
			}

			//END
			last = NULL;
			last = tempLast;

			perculateDown(root);
		}
	}
	else //Root Remains
	{
		root = NULL;
		last = NULL;
	}
}

void BTHeap::perculateDown(Node *p)
{
	int temp;
	if(p->left == NULL) //LEFT NULL -- p is last node AND no right node
	{
		//nothing happens
	}
	else //LEFT NOT NULL
	{
		if(p->right != NULL) //RIGHT NOT NULL
		{
			//compare left to right to find out which is bigger
			if(p->left->data > p->right->data)
			{//LEFT BIGGER THAN RIGHT
				//LEFT vs PARENT
				if(p->left->data > p->data)
				{//LEFT > PARENT -> SWAP!
					temp = p->data;
					p->data = p->left->data;
					p->left->data = temp;
					perculateDown(p->left);
				}
			}
			else
			{//RIGHT BIGGER THAN LEFT
				//RIGHT vs PARENT
				if(p->right->data > p->data)
				{//RIGHT > PARENT -> SWAP!
					temp = p->data;
					p->data = p->right->data;
					p->right->data = temp;
					perculateDown(p->right);
				}
			}
		}
		else //RIGHT NULL
		{
			//left compare to parent -- because outermost checked for left's existence, in here left is guaranteed to exist
			if(p->left->data > p->data)
			{//SWAP
				temp = p->data;
				p->data = p->left->data;
				p->left->data = temp;
				perculateDown(p->left);
			}
		}
	}
}

void BTHeap::HeapSort()
{
	while(!empty())
	{
		retrieve();
		remove();
	}
}
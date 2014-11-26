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
	if(r->parent == NULL) //ROOT
	{
		if(r->left == NULL) //LEFT IS NULL
		{
			n->parent = r;
			r->left = n;
			if(n->data > r->data) //CHILD > PARENT?
			{
				Node* temp;
				temp = r;
				r = n;
				n = temp;
				root = r;
			}
		}
		else if(r->right == NULL) //RIGHT IS NULL
		{
			n->parent = r;
			r->right = n;
			if(n->data > r->data) //CHILD > PARENT?
			{
				Node* temp;
				temp = r;
				r = n;
				n = temp;
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
			if(n->data > r->data) //CHILD > PARENT?
			{
				Node* temp;
				temp = r;
				r = n;
				n = temp;
				root = r;
			}
		}
		else if(r->right == NULL) //RIGHT IS NULL
		{
			n->parent = r;
			r->right = n;
			if(n->data > r->data) //CHILD > PARENT?
			{
				Node* temp;
				temp = r;
				r = n;
				n = temp;
				root = r;
			}
		}
		else //LEFT AND RIGHT NOT NULL
		{
			
			if(r->parent->right != r) //WHILE NOT RIGHT MOST NODE
			{
				if(r->parent->right != NULL)
				{
					insert(r->parent->right, n);
				}
			}
			else //RIGHT MOST NODE
			{
				//at right most node on the current level, go to next level first node
				Node *traverser;
				traverser = root;
				while(traverser->left != NULL)
				{
					if(traverser->left == NULL)
					{
						insert(traverser, n);
						break;
					}
					else
					{
						traverser = traverser->left; //keep going down while left is not null
					}
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

void BTHeap::inorder(Node *r)
{	if (r != '\0')
	{	inorder(r->left);
		cout << r->data<<" ";
		inorder(r->right);
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

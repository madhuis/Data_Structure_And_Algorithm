/*************************************************************************************************************
PROGRAM: Assignment 5
AUTHOR: Ishan Madhu
LOGON ID: z1763923
DUE DATE: October 18, 2015
FUNCTION: Class implementation of the binTree class
***************************************************************************************************************/

#include "assign5.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

/***************************************************************
FUNCTION: binTree()

USE: Initializes the root to null

ARGUMENTS: None

RETURNS: No Valie
***************************************************************/
binTree::binTree()
{
	root = NULL;
}

/***************************************************************
FUNCTION: void binTree()

USE: Inserts a node in the tree

ARGUMENTS: val - an integer that is inserted

RETURNS: No Value
***************************************************************/
void binTree::insert(int val)
{
  insert(root, val);
}
/***************************************************************
FUNCTION: unsigned height()

USE: Returns the height of the tree

ARGUMENTS: None

RETURNS: The height of the tree in unsigned int value
***************************************************************/
unsigned binTree::height() const
{
	return height(root);
}
/***************************************************************
FUNCTION: unsigned size() const

USE: Returns the size of the tree

ARGUMENTS: None

RETURNS: The size of the tree in unsigned int value
***************************************************************/
unsigned binTree::size() const
{
	return size(root);
}
/***************************************************************
FUNCTION: void inorder()

USE: Inorder traversal of the tree

ARGUMENTS: p - a pointer to a function

RETURNS: No Value
***************************************************************/
void binTree::inorder(void(*p)  (int))
{
	inorder(root, p);
}
/***************************************************************
FUNCTION: void preorder()

USE: Preorder traversal of the tree

ARGUMENTS: 1. p - a pointer to a function

RETURNS: Nothing
***************************************************************/
void binTree::preorder(void(*p) (int))
{
	preorder(root, p);
}
/***************************************************************
FUNCTION: void postorder()

USE: Postorder traversal of the tree

ARGUMENTS: p - a pointer to a function

RETURNS: No Value
***************************************************************/
void binTree::postorder(void(*p) (int))
{
	postorder(root, p);
}

/****************************************************************************
FUNCTION: void insert(Node*&, int)

USE: It inserts a node in the tree based on height of right and left subtrees

ARGUMETS: r - a reference to a pointer of the Node class
	  x - an integer that is inserted into the tree

RETURNS: No Value
******************************************************************************/
void binTree::insert(Node*& r, int x)
{
	if(r == NULL)
	    r = new Node(x);
  
	else
  	{
    		if(height(r->right) < height(r->left))
      		  insert(r->right, x);
		
		else
		  insert(r->left, x);
  }

}
/***************************************************************
FUNCTION: unsigned height()const

USE: It gets the height of the tree

ARGUMENTS:r - a pointer to the Node class

RETURNS: The height of the tree in unsigned int value
***************************************************************/
unsigned binTree::height(Node* r) const
{
	if(r == NULL)
  	{
 	     return 0;
  	}

	int left = height(r->left);
	
	int right = height(r->right);

	return 1 + max(left, right);
}
/***************************************************************
FUNCTION: unsigned size()const

USE: It gets the size of the tree

ARGUMENTS: p - a pointer to the Node class

RETURNS: The size of the tree in unsigned int value
***************************************************************/
unsigned binTree::size(Node* p) const
{
  if(p == NULL)
  {
     return 0;
  }
  else
  {
     return size(p->left) + size(p->right) + 1;
  }
}
/***************************************************************
FUNCTION: void inorder(Node*, void(*) (int))

USE: Inorder traversal of the tree

ARGUMENTS: p - a pointer to a function
	   fun - a pointer to a function

RETURNS: Nothing
***************************************************************/
void binTree::inorder(Node* p, void(*fun) (int))
{
	if(p != NULL)
  	{
	inorder(p->left, fun);
	
	fun(p->data);
	
	inorder(p->right, fun);
  	}

}
/***************************************************************
FUNCTION: void preorder(Node*, void(*) (int))

USE: Preorder traversal of the tree

ARGUMENTS: p - a pointer to a function
           fun - a pointer to a function

RETURNS: No Value
***************************************************************/
void binTree::preorder(Node* p, void(*fun) (int))
{
	if(p != NULL)
  	{
    
	fun(p->data);

	preorder(p->left, fun);

	preorder(p->right, fun);
  	
	}

}
/***************************************************************
FUNCTION: void postorder(Node*, void(*) (int))

USE: Postorder traversal of the tree

ARGUMENTS: p - a pointer to a function
           fun - a pointer to a function

RETURNS: No Value
***************************************************************/
void binTree::postorder(Node* p, void(*fun) (int))
{
	if(p != NULL)
  	{
	postorder(p->left, fun);
	
	postorder(p->right, fun);

	fun(p->data);

 	}

}


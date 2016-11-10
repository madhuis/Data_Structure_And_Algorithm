/**************************************************************************************************************
PROGRAM: Assignment 6

AUTHOR: Ishan Madhu

LOGON ID: z1763923

DUE DATE: October 27, 2015

FUNCTION: Class implementation of the BST class
***************************************************************************************************************/
#include <iostream>

#include <algorithm>

#include "assign5.h"

#include "assignment6.h"

using namespace std;

/***************************************************************
   FUNCTION: void insert(int)

   USE: inserts a node in the tree

   ARGUMENTS: val - an integer

   RETURNS: None
***************************************************************/
void BST::insert(int val)
{
	
	insert(root, val);

}
/****************************************************************************
   FUNCTION: void insert(Node*&, int)

   USE: It inserts a node

   ARGUMENTS: ptr - a reference to a pointer of the Node class
              val - an integer inserted into the tree

   RETURNS: None
******************************************************************************/
void BST::insert(Node* &ptr, int val)
{
	if(ptr == NULL)
  	{
    
		ptr = new Node(val);

  	}
	
	else if(val < ptr->data)
     		insert(ptr->left, val);
  
	else
	     insert(ptr->right, val);

}
/***************************************************************
   FUNCTION: bool search(int)

   USE: It searches for an item 

   ARGUMENTS: val - an integer that is to be searched for

   RETURNS: If it is true, item will be found
***************************************************************/
bool BST::search(int val)
{

	return search(root, val);
}
/****************************************************************************
   FUNCTION: bool search(Node*&, int)

   USE: Searches for an item 

   ARGUMENTS: ptr - a reference to a pointer of the Node class
              val - an integer that is to be searched for

   RETURNS: If it is true, item will be found
******************************************************************************/
bool BST::search(Node* &ptr, int val)
{
	if(ptr == NULL)
  	{
 
	    return false;
 	 }
	else if(ptr->data == val)
  	{
     	
		return true;
  	
	}
  	
	else if(ptr->data > val)
  	{
     
		return search(ptr->left, val);
  
	}
  
	else
  	{
     		
		return search(ptr->right, val);
  	}
}
/***************************************************************
   FUNCTION: bool remove(int)

   USE: It removes an item

   ARGUMENTS: val - an integer that is to be removed

   RETURNS: if it is true, item is removed
***************************************************************/

bool BST::remove(int val)
{
	  return remove(root, val);

}
/****************************************************************************
   FUNCTION: bool remove(Node*&, int)

   USE: It removes an item

   ARGUMENTS: ptr - a reference to a pointer of the Node class
              val - an integer 

   RETURNS: if it is true, item is removed
******************************************************************************/
bool BST::remove(Node* &ptr, int val)
{
	if(ptr == NULL)
  	{
  		return false;
  	
	}
	
	if(ptr->data > val)
  	{
  
		remove(ptr->left, val);
  	}

  	
	else if(ptr->data < val)
  	{
     		
		remove(ptr->right, val);
  	}
  
  	else
  	{
    		if(ptr->left != NULL && ptr->right != NULL) 
    		{
       			Node *tempPtr;

		       tempPtr = ptr->left;

		       while(tempPtr->right != NULL)
		           tempPtr = tempPtr->right;
       
			ptr->data = tempPtr->data;
       
			remove(ptr->left, tempPtr->data);
    		}
    
		else if(ptr->left == NULL && ptr->right == NULL)
    		{
       			delete ptr;
       
			ptr = NULL;
    		}
    
		else  
    		{
		       Node* tempPtr = ptr;

		       if(ptr->left != NULL)
		       ptr = ptr->left;
       		
			else
		        ptr = ptr->right;
       			
			delete tempPtr;
    		}
    
		return true;
	}
  return true;
}
/***************************************************************
   FUNCTION: void printLeftLeaves()

   USE: It prints the left leaves of the tree

   ARGUMENTS: None

   RETURNS: None
***************************************************************/
void BST::printLeftLeaves()
{
   printLeftLeaves(root);
}
/***************************************************************
   FUNCTION: void printLeftLeaves(Node*)

   USE: It prints the left leaves of the tree

   ARGUMENTS: ptr - a pointer to the Node class

   RETURNS: None

***************************************************************/
void BST::printLeftLeaves(Node* ptr)
{

	if(ptr == NULL)
   	return;
  
	if(ptr->left != NULL && ptr->left->left == NULL && ptr->left->right == NULL)
     		cout << ptr->left->data << " ";

	printLeftLeaves(ptr->left);

	printLeftLeaves(ptr->right);

}
/***********************************************************************
   FUNCTION: void sumAncestors(int, int&)

   USE: It takes the sum of ancestors of an item

   ARGUMENTS: item - an integer for the node 

   sum - integer for the summation of the item's ancestors

   RETURNS: No Value
************************************************************************/
void BST::sumAncestors(int item, int& sum)
{

	sumAncestors(root, item, sum);

}
/*******************************************************************************************
   FUNCTION: void sumAncestors(Node*, int, int&)

   USE: It takes the sum of ancestors of an item

   ARGUMENTS: item - an integer for the node 
              sum - a reference to an integer for the summation of the item's ancestors

   RETURNS: The summation of the item's ancestors as a reference
********************************************************************************************/
bool BST::sumAncestors(Node* ptr, int item, int& sum)
{
	if(ptr == NULL)
	   return false;
	
	else if(ptr->data == item)
  	{
	    return true;
  	}

	if(sumAncestors(ptr->left, item, sum) || sumAncestors(ptr->right, item, sum))
  	{
	
	   sum += ptr->data;
  	
	}
}

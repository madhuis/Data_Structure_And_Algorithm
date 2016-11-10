/**************************************************************************************************************
PROGRAM: Assignment 5
AUTHOR: Ishan Madhu
LOGON ID: z1763923
DUE DATE: October 18, 2015
FUNCTION: The class declaration of the binTree and Node 
***************************************************************************************************************/

#ifndef ASSIGNMENT5
#define ASSIGNMENT5
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
//--------------------------
// You need to add definition of the Node class
//--------------------------
class Node
{
   friend class binTree;
   friend class BST;
   public:
   Node(int d)
   {
     data = d;
     left = NULL;
     right = NULL;
   }

   private:
   int data;
   Node *left;
   Node *right;
};
class binTree {
    public:
        binTree();
        virtual void insert( int );
        unsigned height() const;
	unsigned size() const;
        void inorder( void(*)(int) );
        void preorder( void(*)(int) );
        void postorder( void(*)(int) );

    protected:
        Node* root;
    private:
        void insert( Node*&, int );
        unsigned height( Node* ) const;
        unsigned size( Node* ) const;
        void inorder( Node*, void(*)(int) );
        void preorder( Node*, void(*)(int) );
        void postorder( Node*, void(*)(int) );
};

#endif


/**************************************************************************************************************
PROGRAM: Assignment 6
AUTHOR: ISHAN MADHU
LOGON ID: z1763923
DUE DATE: October 27, 2015
FUNCTION: Class declaration of the BST class
***************************************************************************************************************/

#ifndef ASSIGNMENT6
#define ASSIGNMENT6
#include "assign5.h"

class BST : public binTree {
    public:
        BST() : binTree() {}
        void insert( int );
        bool search( int );
        bool remove( int );

	void printLeftLeaves();
	void sumAncestors(int, int&);

    private:
        void insert( Node*&, int );
        bool search( Node*&, int );
        bool remove( Node*&, int );

	void printLeftLeaves(Node*);
	bool sumAncestors(Node*, int, int&);
};
#endif

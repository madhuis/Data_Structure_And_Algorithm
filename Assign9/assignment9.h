/**************************************************************************************************************
PROGRAM: Assignment 9

AUTHOR: ISHAN MADHU

LOGON ID: z1763923

DUE DATE: 12.02.2015

FUNCTION: Use of Graph Algorithms 

***************************************************************************************************************/
#ifndef ASSIGNMENT9_H
#define ASSIGNMENT9_H
#include <vector>
#include <list>

class graph {
    private:
        int size;
        std::vector< std::list<int> > adj_list;
        std::vector< char > labels;
        void depth_first( int ) const;
    public:
        graph( const char* filename );
        ~graph();
        int get_size() const;
        void traverse( ) const;
        void print ( ) const;
};

#endif


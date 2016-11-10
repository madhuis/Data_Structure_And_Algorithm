/**************************************************************************************************************
PROGRAM: Assignment 9

AUTHOR: ISHAN MADHU

LOGON ID: z1763923

DUE DATE: 12.02.2015

FUNCTION: Use of Graph Algorithm
***************************************************************************************************************/

#include <iostream>

#include <fstream>

#include <vector>

#include <list>

#include <cstdlib>

#include <string>

#include "assignment9.h"

using namespace std;

/*************************************************************************

FUNCTION: graph(const char*)

ARGUMENTS: filename - a const char pointer input file

RETURNS:  No value

NOTES: Use of graph constructor

**************************************************************************/
graph::graph(const char* filename)
{
	ifstream myfile;

	char buffer;

  	myfile.open(filename, ios::in);

  	myfile >> size;

  	for(int i = 0; i < size; i++)
  	{
    		myfile >> buffer;
  	}
  
	int read;
  
	for(int i = 0; i < size; i++)
  	{
     		list <int> tempList;
     
		myfile >> buffer;
     
		for(int c = 0; c < size; c++)
     		{
       		myfile >> read;
		
		     if(read == 1)
       		{
		          tempList.push_back(c);
       		}
	
     		}

	     adj_list.push_back(tempList);
  	}
  
	labels.resize(size);
  
	labels[0] = 'A';
  
	for(int i = 1; i < size; i++)
  	{
     
		labels[i] = labels[i - 1] + 1;
  	}

  
	myfile.close();
}
/*************************************************************************

FUNCTION: graph()

ARGUMENTS: None

RETURNS:  No value

NOTES: Graph Destructor
**************************************************************************/
graph::~graph()
{
	adj_list.clear();
  
	labels.clear();
}
/*************************************************************************
FUNCTION: get_size() const

ARGUMENTS: None

RETURNS:  Size of graph

NOTES: Getting size of graph
**************************************************************************/
int graph::get_size() const
{
	return size;
}

//Global Variables

bool* visited;

string edge;

/*************************************************************************
FUNCTION: traverse() const

ARGUMENTS: None

RETURNS:  Nothing

NOTES: It traverses the Graph and invokes depth_first
**************************************************************************/
void graph::traverse() const
{
	edge = "";
	
	visited = new bool[size];

	for(int i = 0; i < size; i++)
  	{
     
		visited[i] = false;
  	}
  
	for(int i = 0; i < size; i++)
  	{
    		if(!visited[i])
    		{
	      		depth_first(i);
    		}
  	}
  	
	cout << endl;
  
	cout << edge << endl;
  
	delete [] visited;
}

/*************************************************************************
FUNCTION: print() const

ARGUMENTS: None

RETURNS:  Nothing

NOTES: It prints Adjacency List for the Graph
**************************************************************************/

void graph::print() const
{
	cout << "Number of Vertices in the Graph: " << size << endl;

	cout << "------- graph -------" << endl;

	for(unsigned int i = 0; i < labels.size(); i++)
  	{
     
		cout << labels[i] << ": ";
     
		for(list<int>::const_iterator c = adj_list[i].begin(); c != adj_list[i].end(); ++c)
 		{
          		cout << labels[*c] << ", ";
     		}

     		cout << endl;

  	}
  
	cout << "------- end of graph -------" << endl;
  
	cout << endl;
  
	cout << "------- traverse of graph -------" << endl;
}

/*************************************************************************

FUNCTION: depth_first(int i)

ARGUMENTS: i - vertex value of graph

RETURNS:  No value

NOTES: It implements Depth First Search Algorithm

**************************************************************************/
void graph::depth_first(int i) const
{
	visited[i] = true;

	cout << labels[i] << " ";

	list<int>::const_iterator it;

	for(it = adj_list[i].begin(); it != adj_list[i].end(); ++it)
  	{

		int w = *it;

		if(!visited[w])
     		{

		       edge = edge + "(" + labels[i] + ", " + labels[w] + ") ";
		
		       depth_first(w);
     		}
  	}
}


#define ASSIGNMENT9_TEST

#ifdef  ASSIGNMENT9_TEST

int main(int argc, char** argv) {
    if ( argc < 2 ) {
        cerr << "args: input-file-name\n";
        return 1;
    }

    graph g(argv[1]);

    g.print();

    g.traverse();

    return 0;
}

#endif


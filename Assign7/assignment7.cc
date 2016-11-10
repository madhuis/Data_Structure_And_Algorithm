/**************************************************************************************************************
PROGRAM: Assignment 7
AUTHOR: Ishan Madhu
LOGON ID: z1763923
DUE DATE: 11/06/2015
FUNCTION: Use of heap sort algorithm
***************************************************************************************************************/

#include <iostream>

#include <iomanip>

#include <vector>

#include <algorithm>

using namespace std;

/*
Function declaration

*/

void build_heap(vector<int>& v, int heap_size, bool (*compar)(int, int));

void heapify(vector<int>& v, int heap_size, int r, bool (*compar)(int, int));

bool less_than(int e1, int e2);


bool greater_than(int e1, int e2);

void heap_sort(vector<int>& v, int heap_size, bool (*compar)(int, int));


int extract_heap(vector<int>& v, int& heap_size, bool (*compar) (int, int));

void print_vector (vector <int>& v, int pos, int size);


int main(int argc, char** argv) {
    // ------- creating input vector --------------
   vector<int> v;
   v.push_back(-1000000);    // first element is fake    
    int heap_size = 24;
    for (int i=1; i<=heap_size; i++)
        v.push_back( i );
    random_shuffle( v.begin()+1, v.begin()+heap_size+1 );
    cout << "\nCurrent input numbers: " << endl;
    print_vector( v, 1, heap_size );

    // ------- testing min heap ------------------
    cout << "\nBuilding a min heap..." << endl;
    build_heap(v, heap_size, less_than);
    cout << "Min heap: " << endl;
    print_vector( v, 1, heap_size );
    heap_sort( v, heap_size, less_than);
    cout << "Heap sort result (in ascending order): " << endl;
    print_vector( v, 1, heap_size );
    
    // ------- testing max heap ------------------
    cout << "\nBuilding a max heap..." << endl;
    build_heap(v, heap_size, greater_than);
    cout << "Max heap: " << endl;
    print_vector( v, 1, heap_size );
    heap_sort( v, heap_size, greater_than);
    cout << "Heap sort result (in descending order): " << endl;
    print_vector( v, 1, heap_size );
                        
    return 0;
}

// Function Definition


/*************************************************************************
FUNCTION: build_heap(vector<int>& v, int heap_size, bool(*compar)(int, int))

ARGUMENTS: v - vector integer address
           heap_size - integer for the size of the heap
           compar - a function pointer that compares two integers

RETURNS:  No Value

USE: This function will help us to construct a heap
**************************************************************************/
void build_heap(vector<int>& v, int heap_size, bool (*compar)(int, int))
{

for(int i = heap_size/2; i >= 1; i--)
{
	heapify(v, heap_size, i, compar);
  
}

}
/*************************************************************************

FUNCTION: heapify(vector<int>& v, int heap_size, int r, bool(*compar)(int, int))

ARGUMENTS: v - vector integer address
           heap_size - integer for the size of the heap
	   r - integer for the root position
           compar - a function pointer that compares two integers

RETURNS:  No Value

Use : we use this function to heapify
**************************************************************************/
void heapify(vector<int>& v, int heap_size, int r, bool (*compar)(int, int))
{
	int left = 2 * r;

     	int right = 2 * r + 1;

     	int largest;

     	int temp;

     	if(left <= heap_size && compar(v[left], v[r]))
	largest = left;
     
	else
        largest = r;

	if(right <= heap_size && compar(v[right], v[largest]))
	largest = right;

     	if(largest != r)
     	{
		temp = v[r];
	
		v[r] = v[largest];
		
		v[largest] = temp;
        
		heapify(v, heap_size, largest, compar); 
     	}

}

/******************************************************************************
FUNCTION: less_than(int e1, int e2)

ARGUMENTS: e1,e2 - integers for comparison

RETURNS:  boolean [T/F] value

USE: This function compares two integers  and returns True or False value

*******************************************************************************/
bool less_than(int e1, int e2)
{
	if(e1 < e2)
		return true;
	
	else
		return false;
}

/********************************************************************************

FUNCTION: greater_than(int e1, int e2)

ARGUMENTS: e1,e2 - integers for comparison

RETURNS:  boolean [T/F] value

USE: This function compares two integers  and returns True or False value

**********************************************************************************/
bool greater_than(int e1, int e2)
{
	if(e1 > e2)
	     return true;
  
	else
	     return false;
}
/*************************************************************************
FUNCTION: heap_sort(vector<int>& v, int heap_size, bool(*compar)(int, int))

ARGUMENTS: v vector integer address
           heap_size - integer for the size of the heap
           *compar - a function pointer for comparison

RETURNS:  No Value

USE: Heap sort
**************************************************************************/

void heap_sort(vector<int>& v, int heap_size, bool (*compar)(int, int))
{

	int i;

  	for(i = heap_size; i >= 2; i--)
  	{

		v[i] = extract_heap(v, heap_size, compar);

	}
  
	reverse(v.begin() + 1, v.end());

}
/*************************************************************************
FUNCTION: extract_heap(vector<int>& v, int heap_size, bool(*compar)(int, int))

ARGUMENTS: v - vector integer address
           heap_size - int value of size of heap
           *compar - a function pointer that compares two integers

RETURNS:  int value [ Root of heap]

USE: This Function extracts the root of a heap recorded in v
**************************************************************************/
int extract_heap(vector<int>& v, int& heap_size, bool (*compar) (int, int))
{
	int extract;
   	
	if(heap_size < 1)
       		cout << "Error" << endl;
   	
	extract = v[1];

	v[1] = v[heap_size];
	
	heap_size = heap_size - 1;
	
	heapify(v, heap_size, 1, compar);
		
	return extract;
}
/*************************************************************************

FUNCTION: print_vector(vector<int>& v, int pos, int size)

ARGUMENTS: v - a vector integer address
           pos - starting position of a vector
           size - size of a vector

RETURNS:  No Value

USE: This function prints the elements of v.
**************************************************************************/
void print_vector (vector <int>& v, int pos, int size)
{
	for(; pos <= size; pos++)
   	{
      
		cout << setw(4) << v[pos] << " ";
      
		if((pos % 10) == 0)
      		{
			 cout << endl;
      		}
   	}
	
	cout << endl;
}


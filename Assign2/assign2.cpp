/************************************************************************************************
PROGRAM: Assignment 2

AUTHOR: Ishan Madhu

LOGON ID: z1763923

DUE DATE: 09/11/15

FUNCTION: This program generates creates random numbers in a vector and implements two search algorithms

*************************************************************************************************/
#include <iostream>

#include <vector>

#include <cstdlib>

#include <iomanip>

#include <algorithm>

using namespace std;

// Global constants

const int TOBE_SEARCHED = 5000;
const int LOW = 1;
const int MAX = 10000;

/*************************************************************************

FUNCTION: genRndNums(vector<int>& v, int vec_size, int seed)

ARGUMENTS: vector<int>& v - referenced vector
		   int vec_size - size of the vector
		   int seed - generate random numbers
RETURNS:  VOID so no return values

NOTES: random number generator and creates random integers

**************************************************************************/
void genRndNums(vector<int>& v, int vec_size, int seed)
{
	srand(seed); // generate random integers with seed value
	
	for (int i = 0; i < vec_size; i++) // loop to generate random integers to store in the vector
	{
	
		v.push_back(rand() % (MAX - LOW + 1) + LOW);
	}
}
/*************************************************************************

FUNCTION: linearSearch(const vector<int>& v, int x)

ARGUMENTS: vector<int> & v - referenced vector
			int x - to search
RETURNS:  True/False value
NOTES: Linear search algorithm
**************************************************************************/
bool linearSearch(const vector<int>& v, int x)
{
	
	vector<int>::const_iterator it; // Declare an iterator
	
	it = find(v.begin(), v.end(), x);
	
	if (it == v.end())
		return false;
	
	else
		return true;
}
/*************************************************************************

FUNCTION: binarySearch(const vector<int>& v, int x)

ARGUMENTS: vector<int> & v - referenced vector

		   int x - searched for in the vector

RETURNS:  True/ False value

NOTES: Binary search algorithm
**************************************************************************/

bool binarySearch(const vector<int>& v, int x)
{

	return binary_search(v.begin(), v.end(), x);

}

/******************************************************************************************************************

FUNCTION: search(const vector<int>& container, const vector<int>& searchNums, bool(*p) (const vector<int>&, int))

ARGUMENTS: const vector<int>& container - constant container
		   const vector<int>& searchNums - constant searchNums
			boolbool(*p)(const vector<int>&, int))		   

			
RETURNS:  The number of successful searches

NOTES: Generic search algorithm, computes total number of successful searches and returns that value
********************************************************************************************************************/
int search(const vector<int>& container, const vector<int>& searchNums, bool(*p)(const vector<int>&, int))
{
	int count = 0;

	for (unsigned int i = 0; i < searchNums.size(); i++) // looping through the vector to search for the numbers
	{
		if (p(container, searchNums[i]))
		{
			count++;
		}
	}
	return count;
}
/*************************************************************************

FUNCTION: sortVec(vector<int>& v)

ARGUMENTS: vector<int>& v - referenced vector

RETURNS:  No Value

NOTES: Sort elements of vector in ascending order
**************************************************************************/
void sortVec(vector<int>& v)
{
	sort(v.begin(), v.end());
}

/********************************************************************************************

FUNCTION: printStat(int totalSucCnt, int vec_size)

ARGUMENTS: int totalSucCnt - an integer for total number of successful comparisons

		int vec_size - size of the vector

RETURNS:  No values

NOTES: Prints the percent of successful searches as floating point numbers on standard output
*********************************************************************************************/
void printStat(int totalSucCnt, int vec_size)
{
	float avg = (float)totalSucCnt / (float)vec_size;

	cout << "Successful Searches: " << avg * 100 << "%" << endl;

}
int main() {
	vector<int> container, tobeSearched;

	genRndNums(container, 10000, 9);

	genRndNums(tobeSearched, TOBE_SEARCHED, 3);

	cout << "\nConducting linear search ..." << endl;

	int linear_search_count = search(container, tobeSearched, linearSearch);

	printStat(linear_search_count, TOBE_SEARCHED);

	cout << "\nConducting binary search on unsorted container ..." << endl;

	int binary_search_count = search(container, tobeSearched, binarySearch);

	printStat(binary_search_count, TOBE_SEARCHED);

	sortVec(container);

	cout << "\nConducting binary search on sorted container ..." << endl;

	binary_search_count = search(container, tobeSearched, binarySearch);

	printStat(binary_search_count, TOBE_SEARCHED);

	cout << endl;

	return 0;
}


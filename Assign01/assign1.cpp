/*********************************************************************
   PROGRAM:    CSCI 340  Assignment 1
   PROGRAMMER: Ishan Madhu
   LOGON ID:   z1763923
   DUE DATE:   09/06/2015
   FUNCTION:   This program uses the fuction to generate the random numbers 
	       and Print in the other function and use it in the main 
	       function by sorted order.
*********************************************************************/
#include <iostream>

#include <algorithm>

#include <iomanip>  // For manipulation use of setw

#include <cstdlib>  // To Produce the random number

#include <vector>  // TO Produce the vectors 

#include <ctime>   // To set the range of the random number

// To set the minimum and maximum range of the random numbers
const int HIGH = 10000; 	// Maximum

const int LOW = 1;		//  Minumum

using namespace std;


/****************************************************************

   FUNCTION:   void genRndNums(vector<int>& v, int vec_size, int seed)

   ARGUMENTS:  3 arguments
		vector<int>& v, int vec_size, int seed

   RETURNS:    No value because of void function

   NOTES:      Creates random numbers within the range of 0 to 1000.
****************************************************************/
void genRndNums(vector<int>& v, int vec_size, int seed)
{

//	seed = time(NULL);
	srand(seed);
	
	for (int i = 0; i < vec_size; i++)


	{

		v.push_back(rand() % (HIGH - LOW + 1) + LOW); 
		// To generate the random numbers and save it in the v.

	}

}
/****************************************************************

   FUNCTION:   void printVec(const vector<int>& v, int vec_size)

   ARGUMENTS:  2 arguments
		const vector<int>& v, int vec_size

   RETURNS:    No value because of the void function

   NOTES:      prints the  result of the generated random function
****************************************************************/
void printVec(const vector<int>& v, int vec_size)

{
	int count = 0; // To count the number
	for (int i = 0; i < vec_size; ++i)

	{
		count++;
		cout << setw(5) << v[i];
		if (count >=  12)
		{
			cout << endl;
			count = 0; 
		}


	}

}

int main()
{

	vector<int> v;

	genRndNums(v, 100, 9); // Pass the arguments

	sort(v.begin(), v.end()); // Sort the  vectors in the accending order

	printVec(v, 100); // Passing the arguments

	cout  << "\n";

	return 0;

}

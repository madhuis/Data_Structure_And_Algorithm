/**************************************************************************************************
PROGRAM: Assignment 3
AUTHOR: Ishan Madhu
LOGON ID: Z1763923
DUE DATE: 09/21/15
FUNCTION: This program finds and prints all prime numbers using the Sieve of Eratosthenes algorithm
****************************************************************************************************/

#include <iostream>
#include <set>
#include <algorithm>
#include <iomanip>
using namespace std;
// Constants
const int NO_ITEMS = 10;
const int ITEM_W = 5;

/**********************************************************************************************
FUNCTION: sieve(set<int>& s, int n)
ARGUMENTS:set<int>& s - a set of integers address
	  n - an integer value
RETURNS:  No Value
NOTES: It uses the Sieve of Eratosthenes algorithm to remove all non prime integers from the set.
************************************************************************************************/
void sieve( set<int>& s, int n)
{

	for(int i = 2; i <= n; i++) 
  	{
     		s.insert(i);
  	}

  	for(int j = 2; j < *s.rbegin(); j++) 
  	{

    		for(int k = j; k <= n; k++) 
    		{
	   	s.erase(j * k);
    		}
  	}
}

/*************************************************************************
FUNCTION: print_primes(const set<int>& s)
ARGUMENTS: const set<int>& s - constant set of integers address
RETURNS:  No value
NOTES: Prints the prime numbers in the integer set
**************************************************************************/
void print_primes( const set<int>& s)
{
	int endLine = 1;

	typedef set<int>::iterator s_iter;

	for(s_iter it = s.begin(); it != s.end(); it++) 
	{
     		cout << setw(ITEM_W) << *it << " ";
     		
		if(endLine == NO_ITEMS)
     		{
        
		cout << endl;
        
		endLine = 0;
     		
		}
     		
		endLine++;
  	}
  	
	cout << endl;
}
// Main Function
int main() 
{
    set<int> s;

    sieve(s, 1000);

    cout << "There are 168 prime numbers:" << endl;

    print_primes(s);

    return 0;
}


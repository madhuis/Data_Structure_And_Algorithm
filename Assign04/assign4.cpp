/******************************************
PROGRAM: Assignment 4
AUTHOR: Ishan Madhu
LOGON ID: z1763923
DUE DATE: 10/01/15
FUNCTION: This program scan the word from the file
	  and find the punctuation and delete it and 
	  return the new word withour the any kind of punctuation mark.
*****************************/

#include <iostream>

#include <map>

#include <string>

#include <algorithm>

#include <iomanip>

#include <cctype>

#include <string>

#include <iterator>

#include <fstream> // For the use of file

#include <ctype.h>
using namespace std;

// global constants
const int NO_ITEMS = 3;

const int ITEM_W = 16;

/*******************************************************************************************************
FUNCTION: print(const map<string, int>& printWord)
ARGUMENTS: printWord - It is the map that hold the word
RETURNS:  Nothing because of void function
NOTES: It Prints list of the words and non-empty and distinct word from the file.
****************************************/

void print_words( const map<string, int>& printWord )
{
  typedef map<string, int> M1;

  M1::const_iterator it;
  
  int notEmptyW = 0; // For non-empty words

  int count = 0;

  for(it = printWord.begin(); it != printWord.end(); it++) 
  {
     cout << left << setw(ITEM_W) << it->first <<" : " << setw(ITEM_W) << it->second;

     count++;

     notEmptyW += it->second;

     if(count == NO_ITEMS)
     {
       cout << endl;

       count = 0;
     }
  }

  cout << "no of the words in input stream: " << notEmptyW << endl;

  cout << "no of the words on output list: " << printWord.size();
}

/**********************************************************************************************
FUNCTION: lowerCase(char& ch)
ARGUMENTS:ch - a character address
RETURNS:  No Value
NOTES: Converts the character from clean_entry to lower case
************************************************************************************************/

void LowerCase(char& ch)
{
   ch = tolower(ch);
}

/**********************************************************************************************
FUNCTION: clean_entry(const string& wordIn, string& cleanWord)
ARGUMENTS:wordIn - word string from input stream
          cleanWord - processed word 
RETURNS:  Nothing
NOTES: It cleans the punctuation of the word.
************************************************************************************************/

void clean_entry( const string& wordIn, string& cleanWord)
{
  unsigned int start;

  unsigned int end;

  for(start = 0; start < wordIn.length(); start++) 
  {

    if(isalnum(wordIn[start]))
       break;
  }

  for(end = start; end < wordIn.length(); end++)  
  {

    if(!isalnum(wordIn[end]))
       break;
  }

  cleanWord = wordIn.substr(start, end - start);

  for_each(cleanWord.begin(), cleanWord.end(), LowerCase);
}
/**********************************************************************************************
FUNCTION: get_words(map<string, int>& m, ifstream& file)
ARGUMENTS:m - map variable that holds strings and integers          
	  file - input variable
RETURNS:  No value
NOTES: Gets words from an input stream and removes their punctuation
************************************************************************************************/
void get_words( map<string, int>& m, ifstream& file)
{
   string Dword;

   string cleanWord;

   while(file >> Dword) // get words from the file
   {
      clean_entry(Dword, cleanWord); // invoke clean_entry

      if(cleanWord.size() > 0)
        m[cleanWord]++;
   }

}


int main(int argc, char** argv) {
    if ( argc < 2 ) {
        cerr << "command line argument: input-file-name" << endl;
        return 1;
    }

    ifstream infile(argv[1], ios::in);

    map<string, int> m;

    get_words( m, infile );

    infile.close();

    print_words( m );

    return 0;
}


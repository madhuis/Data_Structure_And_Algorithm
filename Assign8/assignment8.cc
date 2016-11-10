/**************************************************************************************************************
PROGRAM: Assignment no 8

AUTHOR: Ishan Madhu

LOGON ID: z1763923

DUE DATE: 11.17.15

Use: Hash table

***************************************************************************************************************/

#include<iostream>

#include<iomanip>

#include<vector>

#include<algorithm>

#include<string>

#include <fstream>

#include "assignment8.h"

using namespace std;

/*************************************************************************
FUNCTION: get_entry(const string&)

ARGUMENTS: line - reference to a string

RETURNS:  an input line
**************************************************************************/

Entry* get_entry(const string& line)
{

	Entry* ptr = new Entry;

	ptr->key = line.substr(2, 3);

	ptr->description = line.substr(6);

	return ptr;

}
/*************************************************************************
FUNCTION: get_key(const string&)

ARGUMENTS: line - reference to a string

RETURNS:  key
**************************************************************************/

string get_key(const string& line)
{

	string key;

	key = line.substr(2, 3);

	return key;

}

// key is in form of letter-letter-digit

// compute sum <-- ascii(pos1)+ascii(pos2)+ascii(pos3)

// compute sum%htable_size

int HT::hashing(const string& key) 
{

	return ((int)key[0] + (int)key[1] + (int)key[2])%table_size;
}

/*************************************************************************
FUNCTION: HT(int)

ARGUMENTS: s - integer for size of hash table

RETURNS:  Nothing

NOTES: constructor
**************************************************************************/
HT :: HT (int s=11)
{
	hTable = new vector<Entry>(s);
	
	table_size = s;
	
	item_count = 0;
}

/*************************************************************************
FUNCTION: ~HT()

ARGUMENTS: None

RETURNS:  No value

NOTES: destructor
**************************************************************************/

HT :: ~HT ( )
{
	
	delete hTable;

}
/*********************************************************************************
FUNCTION: search(const string&)

ARGUMENTS: key - reference to a string constant

RETURNS:  Position of searched item

NOTES: It searches the table for record.
**********************************************************************************/

int HT::search(const string& key)
{
	int index = hashing(key);
  
	for(int i = 0; i < table_size; i++)
  	{
     
		if((*hTable)[(index + i)%table_size].key == key)
	     {
     			return (index + i)%table_size;
      	}

      	if((*hTable)[(index + i)%table_size].key == "---")
      	{
         		return -1;
      	}
  	}
  
	return -1;
}

/*********************************************************************************

FUNCTION: insert(const Entry&)

ARGUMENTS: e - reference to an Entry constant

RETURNS:  True/False

NOTES: It inserts item in the hash table
**********************************************************************************/

bool HT::insert(const Entry& e)
{
 	int index = hashing(e.key);
  	
	for(int i = 0; i < table_size; i++)
  	{
     
		if((*hTable)[(index + i)%table_size].key == "---" || (*hTable)[(index + i)%table_size].key == "+++")
     		{
         		(*hTable)[(index+i) % table_size] = e;
	 
			item_count++;
	 
			return true;
      	}
	
     		if((*hTable)[(index + i) % table_size].key == e.key)
      	{
          	
			cout << "Duplicate key" << endl;
          
			return false;
      	}
      
		if(i == table_size)
      		return false;
  	}
  
	return true;

}
/*********************************************************************************

FUNCTION: remove(const Entry&)

ARGUMENTS: s - reference to an Entry constant

RETURNS:  True/False

NOTES: It removes item from hash table
**********************************************************************************/
bool HT::remove(const string& s)
{
	int index = hashing(s);
  
	for(int i = 0; i < table_size; i++)
  	{
	     if((*hTable)[(index + i)%table_size].key == "---")
     		{
	   		break;
       	}
       	
		if(s == (*hTable)[(index + i)%table_size].key)
       	{
           
           	(*hTable)[(index + i)%table_size].key = "+++";
	   
			item_count--;
		
			return true;
       	}

  	}
  
	return false;
}
/*********************************************************************************
FUNCTION: print()

ARGUMENTS: None

RETURNS:  No Value

NOTES: It will print the hash table
**********************************************************************************/
void HT::print()
{
	cout << "-----Hash Table-----" << endl;

	for(int i = 0; i < table_size; i++)
  	{
     
		if((*hTable)[i].key != "---" && (*hTable)[i].key != "+++")
     	{
       cout << i << ": " << (*hTable)[i].key << " " << (*hTable)[i].description << endl;
     }
  }
  cout << "--------------------" << endl;
}

int main(int argc, char** argv ) {
    if ( argc < 2 ) {
        cerr << "argument: file-name\n";
        return 1;
    }

    HT ht;
    ifstream infile(argv[1], ios::in);
    string line;
    infile >> line;    
    while ( !infile.eof() ) {
        if ( line[0] == 'A' ) { 
            Entry* e = get_entry( line );
            ht.insert( *e );
            delete e;
        }
        else {
            string key = get_key(line);
            if ( line[0] == 'D' ) {
                cout << "Removing " << key << "...\n";
                bool removed = ht.remove( key );
                if ( removed )
                    cout << key << " is removed successfully...\n\n";
                else
                    cout << key << " does not exist, no key is removed...\n\n";
            }
            else if ( line[0] == 'S' ) {
                int found = ht.search( key );
                if ( found < 0 ) 
                    cout << key << " does not exit in the hash table ..." << endl << endl;
                else
                   cout << key << " is found at table position " << found << endl << endl;
            }
            else if ( line[0] == 'P' ) {
                cout << "\nDisplaying the table: " << endl;
                ht.print();
            }
            else
                cerr << "wrong input: " << line << endl;
        }
        infile >> line;
 
    }

    infile.close();
    return 0;
}

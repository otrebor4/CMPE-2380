#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
using namespace std;

#include "filedb.h"

// takes a file name, returns true if the file can be read,
//  false otherwise
bool FileDB::Init( string fname )
{
	string line;
	ifstream in( fname.c_str() );
	
	if( !in )
	{
		cout << "Failed to open file " << fname << endl;
		return false;
	}
	
	// file opened, read all lines into this object's "data" member
	while( in )
	{
		getline( in, line );
		data.push_back( line );
	}
	
	in.close();
	
	// seed the random generator for later
	srand( static_cast<int>( time( NULL ) ) );
	
	return true;
}

string FileDB::RandomLine()
{
	if( data.empty() )
	{
		return "";
	}
	
	// get a random value from the "data" member
	return data[ rand()%data.size() ];  
}
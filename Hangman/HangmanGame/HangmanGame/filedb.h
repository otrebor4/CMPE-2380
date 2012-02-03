#include <string>
using namespace std;

#include <vector>

#ifndef FILEDB_H
#define FILEDB_H

class FileDB
{
 public:
	// takes a file name, returns true if the file can be read,
	//  false otherwise
	bool Init( string fname );
	// gets a random line from that file
	string RandomLine();
	
 private:
	// store the file name
	string fname;

	// and the lines from the file
	// vector is a useful c++ class, like an array not fixed size
	//  (we'll talk about it more in the next module)
	vector<string> data;
	
};

#endif
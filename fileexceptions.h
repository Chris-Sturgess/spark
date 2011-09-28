// fileexceptions.h
// defines the file error exceptions

#pragma once

// thrown on any file related error
class fileerror : exception
{
public:
	// constructs the file error from the file involved, and an error string
	fileerror( const string& file, const char* what ) : exception( what ), _file( file ) {}

	// gets the file in question
	string file() const { return _file; }

private:
	// the file involved
	string _file;
};

// thrown when a file can not be found
class filenotfound : fileerror
{
public:
	filenotfound( const string& file ) : fileerror( file, "Failed to find requested file" ) {}
};
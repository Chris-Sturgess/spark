// sprite.cpp
// sprite wrapper class implementation

#include "pch.h"
#include "sprite.h"
#include "fileexceptions.h"

sprite::sprite(void) {}
sprite::~sprite(void) {} // todo handle sytem resources

void sprite::load( const string& file )
{
	// load the file into memory
	bool result = _image.LoadFromFile( file );

	// handle failure
	if( !result ) {
		cerr << "Failed to load sprite \"" << file << "\"" << endl;
		throw fileerror( file, "Failed to load sprite" );
	}
	clog << "Successfully loaded image \"" << file << "\"" << endl;
}
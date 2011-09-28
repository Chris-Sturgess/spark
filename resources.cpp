#include "pch.h"
#include "resources.h"
#include "fileexceptions.h"

namespace resources
{
	/* static data */
	// images
	static map< string, resource<sf::Image> > IMAGES;

	// loads an image from a file
	resource<sf::Image> loadImage( const string& file )
	{
		// check if the image is already loaded
		if( IMAGES.count( file ) > 0 ) {
			return IMAGES.at( file );
		}

		// load a new image
		sf::Image* pimage = new sf::Image();
		if( !pimage->LoadFromFile( file ) ) {
			// destroy the image
			delete pimage; pimage = nullptr;

			// throw an exception
			throw fileerror( file, "Failed to load sprite" );
		}

		// create a new resource from it
		auto r = resource<sf::Image>( pimage );

		// store it and return
		IMAGES.insert( make_pair( file, r ) );

		clog << "Successfully loaded image resource \"" << file << "\"" << endl;
		return r;
	}
}
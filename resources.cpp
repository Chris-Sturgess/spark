#include "pch.h"
#include "resources.h"
#include "fileexceptions.h"

namespace resources
{
	/* static data */
	// images
	typedef map< string, resource<sf::Image> > IMAGELIST;
	static IMAGELIST IMAGES;

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
		IMAGES.insert( make_pair(file, r) );

		clog << "Successfully loaded image resource \"" << file << "\"" << endl;
		return r;
	}

	// cleans resources for ones that are no longer used
	void clean( )
	{
		clog << "Staring with " << IMAGES.size() << " images, cleaned down to ";

		// cleans out resources now only owned by the IMAGES list
		auto i = IMAGES.cbegin();
		for(; i != IMAGES.cend(); )
		{
			if( i->second.instances() == 1 ) IMAGES.erase(i++);
			else ++i;
		}

		clog << IMAGES.size() << " images" << endl;
	}
}
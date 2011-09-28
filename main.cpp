// main.cpp
// Program entry point, it is responsible for creating the environment
//  and initializing the game
#include "pch.h"
#include "game.h"
#include "resources.h"

int main()
{
	// result of execution
	int result = 0;

	try
	{
		// create the rendering window
		sf::RenderWindow app(sf::VideoMode(800,600), "Test Window");

		// create and run the game
		game g( app );
		result = g.loop();
	}
	catch( const exception& e )
	{
		cerr << "Unhandled exception caught in main: " << e.what() << endl;
		result = EXIT_FAILURE;
	}

	// ensure all resources are cleaned
	resources::clean();

	// return
	return result;
}
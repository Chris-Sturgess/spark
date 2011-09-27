// main.cpp
// Program entry point, it is responsible for creating the environment
//  and initializing the game
#include "pch.h"
#include "game.h"

int main()
{
	try
	{
		//Create the rendering window
		sf::RenderWindow app(sf::VideoMode(800,600), "Test Window");

		//create and run the game
		game g( app );
		return g.loop();
	}
	catch( const exception& e )
	{
		cerr << "Unhandled exception caught in main: " << e.what() << endl;
	}
}
// game.h
// is responsible for rendering and updating the game
// is a wrapper around the entire world
#include "gamestate.h"

#pragma once
class game
{
public:
	//creates a new game instance given a render window
	game(sf::RenderWindow&);
	
	//deconstructs the instance
	~game(void);

	//runs the game loop
	void loop( );

private:
	/* internal functions */

	//renders the game instance
	void render( );

	//updates the game state, given the elapsed frame time
	void update( double );


	/* private data */

	//game window
	sf::RenderWindow& _window;

	//the current game state
	GameState _state;
};


// game.h
// is responsible for rendering and updating the game
// is a wrapper around the entire world
#include "gamestate.h"

#pragma once
#include "cell.h"
#include "messagesystem.h"
#include "quest.h"
#include "triggerablemanager.h"

class game
{
public:
	// creates a new game instance given a render window
	game(sf::RenderWindow&);
	
	// destroys the instance
	~game(void);

	// runs the game loop
	int loop( );

private:
	/* internal functions */

	// draws the game instance
	void render( );

	// updates the game state, given the elapsed frame time
	void update( float );

	// processes a single event, returns false if there were none to handle
	bool process( );


	/* private data */

	// game window
	sf::RenderWindow& _window;

	// the current game state
	GameState _state;

	// a cell
	cell _world;

	msgs::messagesystem* _ms;
	shared_ptr<quests::quest> _qs;
	trigger::ptriggerablemanager _triggerManager;
};


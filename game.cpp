// game.h
// is responsible for rendering and updating the game
#include "pch.h"
#include "game.h"

using namespace ents;

game::game( sf::RenderWindow& window ) : _window(window), _state(GS_WORLD)
{
	_world.add("test", shipEntity(new ship()));
}

game::~game(void)
{
	//todo what if somehow this hits while the game loop is in progress? (kinda rare but possible?)
}

void game::update( float elapsed ) {} //todo handle update
void game::render( )
{
	//clear the display surface
	_window.Clear();

	//todo render stuff
	_world.render(_window);

	//flip the buffers
	_window.Display();
}

int game::loop()
{
	//start the clock
	sf::Clock clock;

	//run while the game is still running
	while( _window.IsOpened() )
	{
		//update the game state and reset the timer
		update( clock.GetElapsedTime() );
		clock.Reset();

		//render the game
		render( );

		//process all events in cue
		while( process() ) ;
	}

	return EXIT_SUCCESS;
}

bool game::process()
{
	using sf::Event;

	//Get the next event, and return if there are none
	Event e;
	if( !_window.GetEvent(e) ) return false;

	//handle the event
	switch( e.Type ) {

	case Event::Closed:	//window close button is clicked
		clog << "Window closing" << endl;
		_window.Close();
		break;
	}

	return true;
}
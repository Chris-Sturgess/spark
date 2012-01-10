// game.h
// is responsible for rendering and updating the game
#include "pch.h"
#include "game.h"
#include "player.h"
#include "celldrawer.h"

using namespace ents;

game::game( sf::RenderWindow& window ) : _window(window), _state(GS_WORLD), _qs(new quests::quest())
{
	_world.add("test", pplayer(new player()));
	_ms = new msgs::messagesystem(_qs);
	auto ent = pship(new ship());
	ent->position(b2Vec2(30, 30));
	_world.add("test2", ent);
	_ms = new msgs::messagesystem();
	msgs::dialoguebox* db = _ms->createDialogueBox();
	_ms->loadScript("test.in");
}

game::~game(void)
{
	// todo what if somehow this hits while the game loop is in progress? (kinda rare but possible?)
}

void game::update( float elapsed ) 
{
	_world.update(elapsed, _window.GetInput());
	_ms->update(elapsed, _window.GetInput());
}
void game::render( )
{
	// clear the display surface
	_window.Clear();

	// todo render stuff
	visuals::celldrawer drawer;
	drawer.renderCell(_world, _window);
	_ms->render(_window);

	// flip the buffers
	_window.Display();
}

int game::loop()
{
	// start the clock
	sf::Clock clock;

	// run while the game is still running
	while( _window.IsOpened() )
	{
		// update the game state and reset the timer
		if( clock.GetElapsedTime() > 1.0f/30.0f	)
		{
			update( 1.0f/30.0f );
			clock.Reset();
		}

		// render the game
		render( );

		// process all events in cue
		while( process() ) ;
	}

	return EXIT_SUCCESS;
}

bool game::process()
{
	using sf::Event;

	// get the next event, and return if there are none
	Event e;
	if( !_window.GetEvent(e) ) return false;

	// handle the event
	switch( e.Type ) {

	case Event::Closed:	// window close button is clicked
		clog << "Window closing" << endl;
		_window.Close();
		break;
	}

	return true;
}
// game.h
// is responsible for rendering and updating the game
#include "pch.h"
#include "game.h"
#include "player.h"
#include "trigger.h"
#include "celldrawer.h"

using namespace ents;
using namespace placeholders;

game::game( sf::RenderWindow& window ) : _window(window), _state(GS_WORLD), _qs(new quests::quest()), _triggerManager(new ::trigger::triggerablemanager())
{
	_world.add(pplayer(new player(_triggerManager, "player")));
	auto ent = pship(new ship(_triggerManager, "other"));
	ent->position(b2Vec2(30, 30));
	_world.add(ent);
	//_world.add(ptrigger(new ents::trigger(_triggerManager, "trigger", 0, 30, 0, 20, 20)));
	_triggerManager->findTriggerable("other")->linkOutput("use", "dialog", "run", arglist().push("test.in"));
	_ms = new msgs::messagesystem(_qs, _triggerManager);

	_dialogTriggerable = _triggerManager->createTriggerable("dialog");
	_dialogTriggerable->registerInput("run", [this](const string&, const ::trigger::arglist& params) {
		_ms->loadScript(params.extract<string>(0));
		_ms->parseNextLine();
	});
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

	case Event::MouseButtonReleased:
		if( e.MouseButton.Button == sf::Mouse::Button::Right )
		{
			ents::pship result;
			if( _world.trace(b2Vec2(e.MouseButton.X/7.0f, e.MouseButton.Y/7.0f), result) )
			{
				result->use(nullptr);
			}
		}
		break;

	case Event::Closed:	// window close button is clicked
		clog << "Window closing" << endl;
		_window.Close();
		break;
	}

	return true;
}
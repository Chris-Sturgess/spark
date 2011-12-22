// player.h
// a special ship controlled by the PC

#pragma once

#include "ship.h"

namespace ents
{
	class player : public ship
	{
		virtual void update( float elapsed, const sf::Input& );
	};

	typedef shared_ptr<player> pplayer;
}
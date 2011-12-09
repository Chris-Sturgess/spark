// ship.h
// represents a single ship in the game world
#pragma once

#include "resources.h"

namespace ents
{
	class ship
	{
	public:
		ship();

		// draws the object to the screen
		void render(sf::RenderTarget&);

	private:
		// unique name within a cell
		string _cellName;

		// position information
		sf::Vector2f _position;
		float _angle;

		// sprite
		sf::Sprite _sprite;
		image _image;
	};

	typedef shared_ptr<ship> shipEntity;
}
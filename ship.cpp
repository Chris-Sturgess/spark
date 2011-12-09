// physical.cpp
// implements the physical fundamental entity
// found in physical.h
#include "pch.h"
#include "ship.h"

namespace ents
{
	ship::ship() : _angle(0.0f), _position(0.0f, 0.0f)
	{
		_image = resources::loadImage("ship.png");
		_sprite = sf::Sprite( *_image );
	}

	void ship::render(sf::RenderTarget& target)
	{
		target.Draw(_sprite);
	}
}
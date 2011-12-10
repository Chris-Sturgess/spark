// player.cpp
// implements the player class
#include "pch.h"
#include "player.h"

void ents::player::update( float elapsed, const sf::Input& input )
{
	ship::update(elapsed, input);

	// respond to input
	if(input.IsKeyDown(sf::Key::W)) {
		this->thrust(elapsed*10000.0f);
	}
	if (input.IsKeyDown(sf::Key::S)) {
		this->thrust(-elapsed*10000.0f);
	}
	if( input.IsKeyDown(sf::Key::A)) {
		this->angularThrust(elapsed*5000.0f);
	}
	if( input.IsKeyDown(sf::Key::D)) {
		this->angularThrust(-elapsed*5000.0f);
	}
}

// player.cpp
// implements the player class
#include "pch.h"
#include "player.h"

void ents::player::update( float elapsed, const sf::Input& input )
{
	ship::update(elapsed, input);

	const static float newtonsForward = 10.0f;
	const static float torqueAngle = 10000.0f;

	// respond to input
	if(input.IsKeyDown(sf::Key::W)) {
		this->thrust(newtonsForward);
	}
	if (input.IsKeyDown(sf::Key::S)) {
		this->thrust(-newtonsForward);
	}
	if( input.IsKeyDown(sf::Key::A)) {
		this->angularThrust(torqueAngle);
	}
	if( input.IsKeyDown(sf::Key::D)) {
		this->angularThrust(-torqueAngle);
	}
}

ents::player::player( b2World& world ) : ship(world) {}

// cell.h
// defines a class which represents a "cell" of the game world
// where objects may interact directly
#pragma once

// include fundamental entity types
#include "ship.h"
#include "trigger.h"

class cell
{
public:
	cell();

	// draws the cell
	void render(sf::RenderTarget&) const;

	// updates the cell
	void update(float elapsed, const sf::Input&);

	// adds a new ship to the cell
	void add(ents::pship);
	void add(ents::ptrigger);

	// returns the cell's physically simulated world
	b2World& world();

	// calls a for each on the ships
	void foreachShip( function<void(ents::pship)> ) const;

private:
	// list of all ships within the cell
	map< string, ents::pship > _ships;
	map< string, ents::ptrigger > _triggers;

	// physics world
	b2World _world;
};
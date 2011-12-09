// cell.h
// defines a class which represents a "cell" of the game world
// where objects may interact directly
#pragma once

// include fundamental entity types
#include "ship.h"

class cell
{
public:
	cell();

	// draws the cell
	void render(sf::RenderTarget&) const;

	// updates the cell
	void update();

	// adds a new ship to the cell
	void add(string name, ents::shipEntity);

private:
	// list of all ships within the cell
	map< string, ents::shipEntity > _ships;
};
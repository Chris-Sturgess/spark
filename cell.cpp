// cell.cpp
// implements the cell class
#include "pch.h"
#include "cell.h"

cell::cell() : _ships() {}

void cell::render(sf::RenderTarget& target) const
{
	auto begin = _ships.begin(),
		end = _ships.end();
	for( auto i = begin; i != end; i++ )
	{
		i->second->render(target);
	}
}

void cell::add(string name, ents::shipEntity ent)
{
	_ships[name] = ent;
}

void cell::update() {}
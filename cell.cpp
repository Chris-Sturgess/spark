// cell.cpp
// implements the cell class
#include "pch.h"
#include "cell.h"

cell::cell() : _ships(), _world(b2Vec2(0,0))
{
	_world.SetAllowSleeping(true);
}

void cell::render(sf::RenderTarget& target) const
{
	auto begin = _ships.begin(),
		end = _ships.end();
	for( auto i = begin; i != end; i++ )
	{
		target.Draw(*i->second.get());
	}
}

void cell::add(string name, ents::pship ent)
{
	_ships[name] = ent;
}

void cell::update(float elapsed, const sf::Input& input)
{
	_world.Step( 1.0f / elapsed, 6, 2);
	auto begin = _ships.begin(),
		end = _ships.end();
	for( auto i = begin; i != end; i++ )
	{
		i->second->update(elapsed, input);
	}
}

b2World& cell::world()
{
	return _world;
}

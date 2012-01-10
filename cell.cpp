// cell.cpp
// implements the cell class
#include "pch.h"
#include "cell.h"

cell::cell() : _ships(), _world(b2Vec2(0,0))
{
	_world.SetAllowSleeping(true);
}

void cell::add(string name, ents::pship ent)
{
	_ships[name] = ent;
	ent->loadIntoWorld(_world);
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

void cell::foreachShip( function<void(ents::pship)> f ) const
{
	auto begin = _ships.begin(),
		end = _ships.end();
	for( auto iter = begin; iter != end; iter++ )
	{
		f(iter->second);
	}
}

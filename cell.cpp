// cell.cpp
// implements the cell class
#include "pch.h"
#include "cell.h"

cell::cell() : _ships(), _world(b2Vec2(0,0))
{
	_world.SetAllowSleeping(true);
}

void cell::add(ents::pship ent)
{
	_ships[ent->name()] = ent;
	ent->loadIntoWorld(_world);
}

void cell::add(ents::ptrigger ent)
{
	_triggers[ent->name()] = ent;
	ent->loadIntoWorld(_world);
}

void cell::update(float elapsed, const sf::Input& input)
{
	_world.Step( 1.0f / elapsed, 6, 2);
	{
		auto begin = _ships.begin(),
			end = _ships.end();
		for( auto i = begin; i != end; i++ )
		{
			i->second->update(elapsed, input);
		}
	}
	{
		auto begin = _triggers.begin(),
			end = _triggers.end();
		for( auto i = begin; i != end; i++ )
		{
			i->second->update(elapsed);
		}
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

bool cell::trace( const b2Vec2& p, ents::pship& out ) const
{
	auto begin = _ships.begin(),
		end = _ships.end();
	for( auto iter = begin; iter != end; iter++ )
	{
		if(iter->second->trace(p))
		{
			out = iter->second;
			return true;
		}
	}
	return false;
}

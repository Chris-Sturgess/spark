// entity.h
// base class for all objects in the game world
#pragma once
#include "cell.h"

namespace ents
{
	namespace construction
	{
		struct entityConstruct
		{
			string localName;
			string globalName;
			b2Vec2 position;
			float32 rotation;
		};
	}

	class entity
	{
	public:
		// creates a new entity
		entity( const construction::entityConstruct& );

		// attaches the entity to a cell
		virtual void attach( cell& );

		// removes the entity from a cell
		virtual void detach();

		// run every frame to update the object
		virtual void update( float elapsed );

		// local name
		string name() const;

		// global name
		string global() const;

		// position
		b2Vec2 position() const;

		// rotation
		float32 rotation() const;
	private:
		string _name;
		string _global;
	};
}
// ship.h
// represents a single ship in the game world
#pragma once

#include "resources.h"

namespace ents
{
	class ship
	{
	public:
		ship();

		// loads the ship into a physics world
		void loadIntoWorld( b2World& );

		// unloads the physics from a world
		void unloadPhysics( );

		// updates the ship each frame
		virtual void update(float elapsed, const sf::Input&);

		// gets or sets the position
		b2Vec2 position() const;
		void position(const b2Vec2&);

		// gets or sets the angle of rotation
		float32 rotation() const;
		void rotation(float32);

		// calculates the forward vector
		b2Vec2 forward() const;

		// adds thrust
		void thrust( float amount );

		// adds angular thrust
		void angularThrust( float amount );

		// gets the image associated with the ship
		string imageName() const;
	private:
		// physics data which is held persistently
		struct 
		{
			b2Vec2 _position;
			float32 _angle;
			b2Vec2 _linearVel;
			float32 _angularVel;
		} _data;
		
		// image name
		string _imageName;

		// unique name within a cell
		string _cellName;

		// rigid body
		b2Body* _physicsBody;
	};

	typedef shared_ptr<ship> pship;
}
// trigger.h
// represents a trigger which can be triggered by things
#pragma once

namespace ents
{
	class trigger
	{
	public:
		// creates a trigger centered at x,y with the width and height half extents
		trigger( float x, float y, float angle, float whe, float hhe );

		// checks for contacts
		void update( float elapsed );

		// loads the ship into a physics world
		void loadIntoWorld( b2World& );

		// unloads the physics from a world
		void unloadPhysics( );
	private:
		// data persisting before/after physics unloading
		struct  
		{
			b2Vec2 _position;
			float32 _angle;
			float32 _width, _height;
		} _data;

		// the body for the trigger
		b2Body* _physicsBody;
	};
}
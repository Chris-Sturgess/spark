// ship.h
// represents a single ship in the game world
#pragma once

#include "resources.h"

namespace ents
{
	class ship : public sf::Sprite
	{
	public:
		ship(b2World&);

		// updates the ship each frame
		virtual void update(float elapsed, const sf::Input&);

		// calculates the forward vector
		b2Vec2 forward() const;

		// adds thrust
		void thrust( float amount );

		// adds angular thrust
		void angularThrust( float amount );

		virtual void SetPosition(float X, float Y);
		virtual void SetPosition(const sf::Vector2f& v);

	protected:
		// draws our object
		void Render(sf::RenderTarget&);

	private:
		// creates the physics portion of the ship
		void createPhysics(b2World&);

		// unique name within a cell
		string _cellName;

		// our image
		image _image;

		// rigid body
		b2Body* _physicsBody;
	};

	typedef shared_ptr<ship> pship;
}
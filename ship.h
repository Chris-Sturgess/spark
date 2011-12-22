// ship.h
// represents a single ship in the game world
#pragma once

#include "resources.h"

namespace ents
{
	class ship : public sf::Sprite
	{
	public:
		ship();

		// updates the ship each frame
		virtual void update(float elapsed, const sf::Input&);

		// calculates the forward vector
		sf::Vector2f forward() const;

		// adds thrust
		void thrust( float amount );

		// adds angular thrust
		void angularThrust( float amount );

	protected:
		// draws our object
		void Render(sf::RenderTarget&);

	private:		
		// unique name within a cell
		string _cellName;

		// movement information
		sf::Vector2f _linearVelocity;
		float _angularVelocity;

		// our image
		image _image;
	};

	typedef shared_ptr<ship> pship;
}
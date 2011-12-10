// physical.cpp
// implements the physical fundamental entity
// found in physical.h
#include "pch.h"
#include "ship.h"

namespace ents
{
	ship::ship() : _angularVelocity(0.0f)
	{
		_image = resources::loadImage("ship.png");
		this->SetImage( *_image );
		this->SetCenter( _image->GetWidth()/2.0f, _image->GetHeight()/2.0f);
	}

	void ship::update( float elapsed, const sf::Input& input )
	{
		Move(_linearVelocity*elapsed);
		Rotate(_angularVelocity*elapsed);

		// dampen
		_linearVelocity *= 0.99f;
		_angularVelocity *= 0.99f;
	}

	void ship::Render( sf::RenderTarget& target )
	{
		sf::Sprite::Render(target);
	}

	sf::Vector2f ship::forward() const
	{
		float angle = GetRotation() / 180.0f * 3.14159265f;
		return sf::Vector2f(
			cosf(angle),
			-sinf(angle));
	}

	void ship::thrust( float amount )
	{
		_linearVelocity += forward()*amount;
	}

	void ship::angularThrust( float amount )
	{
		_angularVelocity += amount;
	}

}
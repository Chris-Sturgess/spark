// physical.cpp
// implements the physical fundamental entity
// found in physical.h
#include "pch.h"
#include "ship.h"

namespace ents
{
	ship::ship(b2World& world)
	{
		_image = resources::loadImage("ship.png");
		this->SetImage( *_image );
		this->SetCenter( _image->GetWidth()/2.0f, _image->GetHeight()/2.0f);
		createPhysics(world);
		_physicsBody->SetLinearDamping(0.001f);
		_physicsBody->SetAngularDamping(0.001f);
	}

	void ship::update( float elapsed, const sf::Input& input )
	{
		b2Vec2 position = _physicsBody->GetPosition();
		SetX(position.x);
		SetY(position.y);
		SetRotation(_physicsBody->GetAngle());
	}

	void ship::Render( sf::RenderTarget& target )
	{
		sf::Sprite::Render(target);
	}

	b2Vec2 ship::forward() const
	{
		float angle = GetRotation() / 180.0f * 3.14159265f;
		return b2Vec2(
			cosf(angle),
			-sinf(angle));
	}

	void ship::thrust( float amount )
	{
		b2Vec2 forw = forward();
		forw *= amount;
		_physicsBody->ApplyForceToCenter(forw);
	}

	void ship::angularThrust( float amount )
	{
		_physicsBody->ApplyTorque(amount);
	}

	void ship::createPhysics( b2World& world )
	{
		// create the definition
		b2BodyDef def;
		def.type = b2_dynamicBody;
		def.position.Set(0, 0);
		_physicsBody = world.CreateBody(&def);

		// create a shape for the entity
		b2PolygonShape shape;
		shape.SetAsBox(50, 50);

		b2FixtureDef fixture;
		fixture.shape = &shape;
		fixture.friction = 0.0f;
		fixture.density = 1.0f;
		_physicsBody->CreateFixture(&fixture);
	}

	void ship::SetPosition( float X, float Y )
	{
		_physicsBody->SetTransform( b2Vec2(X,Y), GetRotation());
	}

	void ship::SetPosition( const sf::Vector2f& v )
	{
		_physicsBody->SetTransform( b2Vec2(v.x, v.y), GetRotation());
	}

}
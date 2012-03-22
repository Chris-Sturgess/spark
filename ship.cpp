// physical.cpp
// implements the physical fundamental entity
// found in physical.h
#include "pch.h"
#include "ship.h"

using namespace placeholders;

namespace ents
{
	ship::ship(::trigger::ptriggerablemanager manager, const string& n) : _physicsBody(nullptr), _imageName("ship.png"), _uniqueName(n)
	{
		_data._position = b2Vec2(0,0);
		_data._linearVel = b2Vec2(0,0);
		_data._angle = 0;
		_data._angularVel = 0;
		
		_trigger = manager->createTriggerable(n);
		_trigger->registerInput("thrust", [this](const string&, const ::trigger::arglist& params) { 
			thrust(params.extract<float>(0));
		});
	}

	void ship::update( float elapsed, const sf::Input& input )
	{
		// copy information from the physics object into the persistent data
		if( _physicsBody )
		{
			_data._position = _physicsBody->GetPosition();
			_data._angle = _physicsBody->GetAngle();
			_data._linearVel = _physicsBody->GetLinearVelocity();
			_data._angularVel = _physicsBody->GetAngularVelocity();
		}
	}

	b2Vec2 ship::forward() const
	{
		float angle = rotation();
		return b2Vec2(
			cosf(angle),
			-sinf(angle));
	}

	void ship::thrust( float amount )
	{
		if( _physicsBody == nullptr ) return;
		b2Vec2 forw = forward();
		forw *= amount;
		_physicsBody->ApplyForceToCenter(forw);
	}

	void ship::angularThrust( float amount )
	{
		if( _physicsBody == nullptr ) return;
		//_physicsBody->ApplyTorque(amount);
		_physicsBody->ApplyAngularImpulse(amount);
	}

	void ship::loadIntoWorld( b2World& world )
	{
		if( _physicsBody != nullptr )
		{
			throw exception("Oh shit...");
		}

		// create the definition
		b2BodyDef def;
		def.type = b2_dynamicBody;

		// restore data from previous load
		def.position = _data._position;
		def.angle = _data._angle;
		def.linearVelocity = _data._linearVel;
		def.angularVelocity = _data._angularVel;

		// setup damping
		def.linearDamping = 0.005f;
		def.angularDamping = 0.005f;

		// create the body
		_physicsBody = world.CreateBody(&def);
		_physicsBody->SetSleepingAllowed(false);

		// create a shape for the entity
		b2PolygonShape shape;
		shape.SetAsBox(5, 5);

		b2FixtureDef fixture;
		fixture.shape = &shape;
		fixture.friction = 0.1f;
		fixture.density = 50.0f;
		_physicsBody->CreateFixture(&fixture);
	}

	b2Vec2 ship::position() const
	{
		return _data._position;
	}

	void ship::position( const b2Vec2& v )
	{
		if( _physicsBody )
		{
			_physicsBody->SetTransform(v, rotation());
		}
		_data._position = v;
	}

	float32 ship::rotation() const
	{
		return _data._angle;
	}

	void ship::rotation( float32 angle )
	{
		if( _physicsBody )
		{
			_physicsBody->SetTransform(position(), angle);
		}
		_data._angle = angle;
	}

	void ship::unloadPhysics()
	{
		if( _physicsBody == nullptr )
		{
			throw exception("oh shit...");
		}
		_physicsBody->GetWorld()->DestroyBody(_physicsBody);
		_physicsBody = nullptr;
	}

	std::string ship::imageName() const
	{
		return _imageName;
	}

	std::string ship::name() const
	{
		return _uniqueName;
	}

}
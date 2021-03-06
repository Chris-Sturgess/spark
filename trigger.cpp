// trigger.h
// represents a trigger which can be triggered by things
#include "pch.h"
#include "trigger.h"


ents::trigger::trigger( ::trigger::ptriggerablemanager manager, const string& name, float x, float y, float angle, float whe, float hhe ) : _physicsBody(nullptr), _bHasRun(false), _uniqueName(name)
{
	_data._position = b2Vec2(x, y);
	_data._angle = angle;
	_data._width = whe;
	_data._height = hhe;

	_trigger = manager->createTriggerable(name);
	_trigger->registerOutput("hit");
}

void ents::trigger::loadIntoWorld( b2World& world )
{
	if( _physicsBody != nullptr )
	{
		throw exception("Oh shit...");
	}

	// create the definition
	b2BodyDef def;
	def.type = b2_staticBody;

	// restore data from previous load
	def.position = _data._position;
	def.angle = _data._angle;

	// create the body
	_physicsBody = world.CreateBody(&def);

	// create a shape for the entity
	b2PolygonShape shape;
	shape.SetAsBox(_data._width, _data._height);

	b2FixtureDef fixture;
	fixture.shape = &shape;
	fixture.isSensor = true;
	_physicsBody->CreateFixture(&fixture);
}

void ents::trigger::update( float elapsed )
{
	/*auto contact = _physicsBody->GetContactList();
	for(; contact != nullptr; contact = contact->next )
	{
		contact->contact->GetFixtureB()->GetBody()
	}*/
	if( _bHasRun ) return;
	if( _physicsBody->GetContactList() != nullptr ) 
	{
		_trigger->callOutput("hit");
		_bHasRun = true;
	}
}

void ents::trigger::unloadPhysics()
{
	if( _physicsBody == nullptr )
	{
		throw exception("oh shit...");
	}
	_physicsBody->GetWorld()->DestroyBody(_physicsBody);
	_physicsBody = nullptr;
}

std::string ents::trigger::name() const
{
	return _uniqueName;
}

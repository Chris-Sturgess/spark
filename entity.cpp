// entity.cpp
// implementation of the entity class
#include "pch.h"
#include "entity.h"

ents::entity::entity( const construction::entityConstruct& construct )
	: _name(construct.localName), _global(construct.globalName)
{}

void ents::entity::attach( cell& )
{

}

std::string ents::entity::name() const
{
	return _name;
}

std::string ents::entity::global() const
{
	return _global;
}

void ents::entity::detach()
{

}

void ents::entity::update( float elapsed )
{

}

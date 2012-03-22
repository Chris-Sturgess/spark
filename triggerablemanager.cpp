// triggerablemanager.cpp
// manages the triggerables
#pragma once

#include "pch.h"
#include "triggerablemanager.h"
#include "entityexceptions.h"

trigger::ptriggerable trigger::triggerablemanager::createTriggerable( const string& name )
{
	if( _triggerables.count(name) > 0 ) throw entityalreadyexists("triggerable", name);
	ptriggerable result = ptriggerable(new triggerable(shared_from_this()));
	_triggerables.insert( make_pair(name, result) );
	return result;
}

trigger::ptriggerable trigger::triggerablemanager::findTriggerable( const string& name )
{
	auto ptr = _triggerables.find(name);
	if( ptr == _triggerables.end() ) throw entitynotfound("triggerable", name);
	return ptr->second;
}

void trigger::triggerablemanager::runInput( const string& destinationEntity, const string& inputName, const arglist& params )
{
	findTriggerable(destinationEntity)->triggerInput(inputName, params);
}

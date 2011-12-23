// triggerable.cpp
// contains functionality for registering and running
// triggers, as well as hooking inputs to outputs
#include "pch.h"
#include "triggerable.h"
#include "triggerexceptions.h"
#include "triggerablemanager.h"

void trigger::triggerable::registerInput( const string& name, const inputfunction& func )
{
	// ensure it is not already in the list of inputs
	if( _inputs.count( name ) > 0 ){
		throw triggeralreadyregistered(name);
	}

	// insert the new trigger
	_inputs.insert( make_pair(name, func) );
}

void trigger::triggerable::getRegisteredInputs( stringlist& out ) const
{
	out.clear();

	// add each input to the out list
	auto begin = _inputs.begin(),
		end = _inputs.end();
	for ( auto i = begin; i != end; i++ )
	{
		out.push_back(i->first);
	}
}

void trigger::triggerable::triggerInput( const string& name, const stringlist& args ) const
{
	// gets an iterator to the input
	auto input = _inputs.find(name);
	if( input == _inputs.end() ) {
		throw triggerdoesnotexist(name);
	}

	// run the trigger
	input->second( name, args );
}

void trigger::triggerable::registerOutput( const string& name )
{
	// add the output to the mapping
	_outputs.insert( make_pair(name, vector<linkage>()) );
}

void trigger::triggerable::linkOutput( const string& outputName, const string& entName, const string& inputName, const stringlist& params /*= stringlist() */ )
{
	// check to ensure this output actually exists
	auto output = _outputs.find( outputName );
	if( output == _outputs.end() ) throw triggerdoesnotexist(outputName);

	// create a new linkage
	output->second.push_back(linkage());

	//Add data to that linkage
	auto link = output->second.rend();
	link->destination = entName;
	link->inputName = inputName;
	link->parameters = params;
}

trigger::triggerable::triggerable( ptriggerablemanager manager ) : _parent(manager) {}

void trigger::triggerable::callOutput( const string& outputName ) const
{
	// check to ensure this output actually exists
	auto output = _outputs.find( outputName );
	if( output == _outputs.end() ) throw triggerdoesnotexist(outputName);

	// call every link
	auto begin = output->second.begin(),
		end = output->second.end();
	for( auto i = begin; i != end; i++ )
	{
		_parent->runInput(i->destination, i->inputName, i->parameters);
	}
}

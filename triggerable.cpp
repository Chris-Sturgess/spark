// triggerable.cpp
// contains functionality for registering and running
// triggers, as well as hooking inputs to outputs
#include "pch.h"
#include "triggerable.h"
#include "triggerexceptions.h"

void triggerable::registerInput( const string& name, const inputfunction& func )
{
	// ensure it is not already in the list of inputs
	if( _inputs.count( name ) > 0 ){
		throw triggeralreadyregistered(name);
	}

	// insert the new trigger
	_inputs.insert( make_pair(name, func) );
}

void triggerable::getRegisteredInputs( stringlist& out ) const
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

void triggerable::triggerInput( const string& name, const stringlist& args ) const
{
	// gets an iterator to the input
	auto input = _inputs.find(name);
	if( input == _inputs.end() ) {
		throw inputdoesnotexist(name);
	}

	// run the trigger
	input->second( name, args );
}

void triggerable::registerOutput( const string& name )
{
	// create a blank linkage structure
	auto ptr = new linkage();
	ptr->destination = nullptr; ptr->inputName = string(); ptr->parameters = stringlist();

	// add the output to the mapping
	_outputs.insert( make_pair(name, new auto_ptr<linkage>(ptr)) );
}

void triggerable::linkOutput( const string& outputName, shared_ptr<triggerable> destination, const string& inputName, const stringlist& params /*= stringlist() */ )
{
	// create a new linkage object
	auto ptr = new linkage();
	ptr->destination = destination; ptr->inputName = inputName; ptr->parameters = params;

	// check to ensure this output actually exists
	auto output = _outputs.find( outputName );
	if( output == _outputs.end() ) throw triggerdoesnotexist(outputName);


}

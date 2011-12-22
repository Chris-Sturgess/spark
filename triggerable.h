// triggerable.h
// An interface for all classes which can be triggered via
// the trigger system. They will have "inputs" and "outputs"
#pragma once

class triggerablemanager;

class triggerable
{
public:
	// type signature for a function which accepts an input
	// string: the name of the input being called
	// string[]: parameters
	typedef function< void( const string&, const stringlist& ) > inputfunction;

	// registers and creates the triggerable
	triggerable( shared_ptr<triggerablemanager> );

	// registers a new input for the current class
	void registerInput( const string& name, const inputfunction& );

	// gets a list of all the inputs registered for this entity
	void getRegisteredInputs( stringlist& out ) const;

	// checks if this entity has a specific input registered
	bool hasInput( const string& name ) const;

	// calls an input on the given entity via the given parameters
	void triggerInput(const string& name, const stringlist& args ) const;

	// registers a new output for the current class
	void registerOutput( const string& name );

	// links an output with another classes input
	void linkOutput( const string& outputName, const string& entName, const string& inputName, const stringlist& params = stringlist() );

	// calls an output
	void callOutput( const string& name ) const;
private:
	// inputs
	map< string, inputfunction > _inputs;
	
	// manager parent
	shared_ptr<triggerablemanager> _parent;

	// represents a link to an entities input
	struct linkage
	{
		string destination;
		string inputName;
		stringlist parameters;
	};

	// outputs
	map< string, auto_ptr<linkage> > _outputs;
};

typedef shared_ptr<triggerable> ptriggerable;
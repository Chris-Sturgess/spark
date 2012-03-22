// triggerable.h
// An interface for all classes which can be triggered via
// the trigger system. They will have "inputs" and "outputs"
#pragma once

namespace trigger
{
	class triggerablemanager;

	// represents a list of arguments which can be extracted
	class arglist
	{
	public:
		arglist() {}
		arglist( const stringlist& args ) : _internalList(args) {}

		// converter function
		template<typename T> static void convert( const string& value, T& out )
		{
			stringstream(value) >> out;
		}

		// push function
		template<typename T>
		void push( const T& item )
		{
			stringstream str = stringstream();
			str << item;
			_internalList.push_back(str.str());
		}

		// extracts an argument (copy & return)
		template<typename T>
		T extract( size_t item ) const
		{
			T result = T();
			convert<T>( _internalList[item], result );
			return result;
		}

		// extracts an argument (no copy & return by reference)
		template<typename T>
		void extract( size_t i, T& out ) const
		{
			convert<T>( _internalList[item], out );
		}

	private:
		// internal strings representing arguments
		stringlist _internalList;
	};

	// represents a series of inputs/outputs that can hook up to other
	// input/outputs
	class triggerable
	{
	public:
		// type signature for a function which accepts an input
		// string: the name of the input being called
		// string[]: parameters
		typedef function< void( const string&, const arglist& ) > inputfunction;

		// registers and creates the triggerable
		triggerable( shared_ptr<triggerablemanager> );

		// registers a new input for the current class
		void registerInput( const string& name, const inputfunction& );

		// gets a list of all the inputs registered for this entity
		void getRegisteredInputs( stringlist& out ) const;

		// checks if this entity has a specific input registered
		bool hasInput( const string& name ) const;

		// calls an input on the given entity via the given parameters
		void triggerInput(const string& name, const arglist& args ) const;

		// registers a new output for the current class
		void registerOutput( const string& name );

		// links an output with another classes input
		void linkOutput( const string& outputName, const string& entName, const string& inputName, const arglist& params = arglist() );

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
			arglist parameters;
		};

		// outputs
		map< string, vector<linkage> > _outputs;
	};

	typedef shared_ptr<triggerable> ptriggerable;
}
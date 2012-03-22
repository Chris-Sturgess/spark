// triggerablemanager.h
// handles all triggerables and allows them to communicate
#pragma once
#pragma once

#include "triggerable.h"

namespace trigger
{
	// responsible for managing all triggerables
	// serves as their factory and inter-communication class
	class triggerablemanager : public enable_shared_from_this<triggerablemanager>
	{
	public:
		// creates a new triggerable for the system
		ptriggerable createTriggerable( const string& name );

		// grabs a triggerable by name lookup
		ptriggerable findTriggerable( const string& name );

		// runs an input on a triggerable (by name)
		void runInput( const string& destinationEntity, const string& inputName, const arglist& params );
	private:
		// map of triggerables
		map< string, ptriggerable > _triggerables;
	};

	typedef shared_ptr<triggerablemanager> ptriggerablemanager;
}
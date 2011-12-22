// triggerexceptions.h
// defines exceptions used in the trigger system of the game engine

// thrown when attempting to register an input or output which already exists
class triggeralreadyregistered : public exception
{
public:
	// constructs a new exception given the name of the trigger to be registered
	triggeralreadyregistered( const string& triggerName ) : exception("Attempting to register trigger that already exists"), _triggerName(triggerName) {}

	// gets the name of the trigger which caused the problem
	string triggerName() const { return _triggerName; }
private:
	// the trigger which caused the problem
	string _triggerName;
};

// thrown when attempting to access a trigger (input or output) that does not exist
class triggerdoesnotexist : public exception
{
public:
	// constructs a new exception given the name of the trigger to be registered
	triggerdoesnotexist( const string& triggerName ) : exception("Attempting to use trigger which does not exist"), _triggerName(triggerName) {}

	// gets the name of the trigger which caused the problem
	string triggerName() const { return _triggerName; }
private:
	// the trigger which caused the problem
	string _triggerName;
};
// triggerexceptions.h
// defines exceptions used in the trigger system of the game engine

// base exception
class triggerexception : public exception
{
public:
	// constructs a new exception given the name of the trigger
	triggerexception( const string& triggerName, const char* message ) : exception(message), _triggerName(triggerName) {}

	// gets the name of the trigger which caused the problem
	string triggerName() const { return _triggerName; }
private:
	// the trigger which caused the problem
	string _triggerName;
};

// thrown when attempting to register an input or output which already exists
class triggeralreadyregistered : public triggerexception
{
public:
	triggeralreadyregistered( const string& triggerName ) : triggerexception(triggerName, "Trigger has already been registered") {}
};

// thrown when attempting to access a trigger (input or output) that does not exist
class triggerdoesnotexist : public triggerexception
{
public:
	triggerdoesnotexist( const string& triggerName ) : triggerexception(triggerName, "Trigger does not exist") {}
};
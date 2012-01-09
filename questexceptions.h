// questexceptions.h
// all exceptions related to the questing system

// base exception
class questexception : public exception
{
public:
	// constructs a new exception given the name of the trigger
	questexception( const string& questName, const char* message ) : exception(message), _questName(questName) {}

	// gets the name of the quest which caused the problem
	string questName() const { return _questName; }
private:
	// the trigger which caused the problem
	string _questName;
};
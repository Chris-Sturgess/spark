// entityexceptions.h
// entity related exception classes

// base exception class
class entityexception : public exception
{
public:
	entityexception( const string& type, const string& name, const char* message ) : exception(message),
		_name(name), _type(type) {}

	string name() const { return _name; }
	string type() const { return _type; }
private:
	string _name;
	string _type;
};


// thrown when attempting to register an entity of some kind which already exists
class entityalreadyexists : public entityexception
{
public:
	entityalreadyexists(const string& type, const string& name) : entityexception(type, name, "Entity of this name already exists") {}
};

// thrown when attempting to access an entity that does not exist
class entitynotfound : public entityexception
{
public:
	entitynotfound(const string& type, const string& name) : entityexception(type, name, "Entity of that name does not exist") {}
};
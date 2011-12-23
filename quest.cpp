// quest.cpp
// implements the questing system

#include "pch.h"
#include "quest.h"

void quests::quest::setQuest( const string& name, int value )
{
	_database[name] = value;
}

int quests::quest::getQuest( const string& name ) const
{
	auto ptr = _database.find(name);
	if( ptr == _database.end() ) return 0;
	else return ptr->second;
}

void quests::quest::deltaQuest( const string& name, int delta )
{
	setQuest( name, getQuest(name) + delta );
}
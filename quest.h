// quest.h
// defines a class for handling quest data
#pragma once

namespace quests
{
	class quest
	{
	public:
		// sets a quest variable
		void setQuest( const string& name, int value );

		// gets a quest variable
		int getQuest( const string& name ) const;

		// modifies a quest value using a delta
		void deltaQuest( const string& name, int delta );

	private:
		// quest database
		hash_map<string, int> _database;
	};
}
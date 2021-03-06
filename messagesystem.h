// messagesystem.h
// the system through which all text is passed

#pragma once
#include <fstream>
#include "dialoguebox.h"
#include "quest.h"
#include "triggerablemanager.h"

namespace msgs
{
	class messagesystem
	{
	public:
		messagesystem(shared_ptr<quests::quest> qs, shared_ptr<trigger::triggerablemanager> tm);
		~messagesystem();
		dialoguebox* createDialogueBox();
		void loadScript(const string& s);
		void parseNextLine();
		void render(sf::RenderTarget& target) const;
		void update(float elapsed, const sf::Input& input);
	private:
		dialoguebox* _curDialogue;
		vector<string> _curScript;
		unsigned int _curLine;
		hash_map<string, int> _labels;
		bool _toAdvance;
		sf::Music music;
		shared_ptr<quests::quest> _qs;
		shared_ptr<trigger::triggerablemanager> _tm;
	};
}
// messagesystem.h
// the system through which all text is passed

#pragma once
#include <fstream>
#include "dialoguebox.h"

namespace msgs
{
	class messagesystem
	{
	public:
		messagesystem();
		~messagesystem();
		dialoguebox* createDialogueBox();
		void loadScript(const string& s);
		void parseNextLine();
		void render(sf::RenderTarget& target) const;
		void update(float elapsed, const sf::Input& input);
	private:
		dialoguebox* _curDialogue;
		ifstream* _curScript;
		bool _toAdvance;
	};
}
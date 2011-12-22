#include "pch.h"
#include "messagesystem.h"

namespace msgs
{
	messagesystem::messagesystem()
	{
		_toAdvance = false;
	}
	messagesystem::~messagesystem()
	{
		if (_curDialogue)
			delete _curDialogue;
		if (_curScript)
			delete _curScript;
	}
	dialoguebox* messagesystem::createDialogueBox()
	{
		_curDialogue = new dialoguebox();
		return _curDialogue;
	}
	void messagesystem::loadScript(const string& s)
	{
		_curScript = new ifstream(s);
	}
	void messagesystem::parseNextLine()
	{
		if (!_curScript) throw new exception("no script loaded");
		string s;
		if (!_curScript->fail())
		{
			getline(*_curScript, s);
			_curDialogue->setText(s);
		}
	}
	void messagesystem::render(sf::RenderTarget& target) const
	{
		if (_curDialogue)
			_curDialogue->render(target);
	}
	void messagesystem::update(float elapsed, const sf::Input& input)
	{
		if (_curDialogue)
			if (input.IsKeyDown(sf::Key::Return))
				_toAdvance = true;
			else if (_toAdvance)
			{
				_toAdvance = false;
				parseNextLine();
			}
	}
}
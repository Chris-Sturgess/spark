#include "pch.h"
#include "messagesystem.h"

namespace msgs
{
	messagesystem::messagesystem()
	{
		_curDialogue = NULL;
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
		bool repeat = false;
		do
		{
			repeat = false;
			string s;
			if (!_curScript->fail())
			{
				getline(*_curScript, s);

				stringstream ss;
				ss << s;
				string cmd;
				ss >> cmd;

				if (cmd == "print")
				{
					char cur;
					do
					{
						cur = ss.get();
					} while (cur != '"');
					string toPrint = "";
					while (true)
					{
						cur = ss.get();
						if (cur == '"')
							break;
						toPrint += cur;
					}
					_curDialogue->appendText(toPrint);
				}
				if (cmd == "clr")
				{
					_curDialogue->clearText();
				}
				if (cmd == "clra")
				{
					_curDialogue->clearText();
					repeat = true;
				}
				if (cmd == "opendiag")
				{
					_curDialogue = createDialogueBox();
					repeat = true;
				}
				if (cmd == "closediag")
				{
					delete _curDialogue;
					_curDialogue = NULL;
				}
			}
		} while (repeat == true);
	}
	void messagesystem::render(sf::RenderTarget& target) const
	{
		if (_curDialogue)
			_curDialogue->render(target);
	}
	void messagesystem::update(float elapsed, const sf::Input& input)
	{
		if (input.IsKeyDown(sf::Key::Return))
			_toAdvance = true;
		else if (_toAdvance)
		{
			_toAdvance = false;
			parseNextLine();
		}
	}
}
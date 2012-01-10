#include "pch.h"
#include "messagesystem.h"

namespace msgs
{
	messagesystem::messagesystem(shared_ptr<quests::quest> qs, shared_ptr<trigger::triggerablemanager> tm)
	{
		_curDialogue = NULL;
		_qs = qs;
		_tm = tm;
		_toAdvance = false;
	}
	messagesystem::~messagesystem()
	{
		if (_curDialogue)
			delete _curDialogue;
	}
	dialoguebox* messagesystem::createDialogueBox()
	{
		_curDialogue = new dialoguebox();
		return _curDialogue;
	}
	void messagesystem::loadScript(const string& s)
	{
		ifstream fin(s);
		while (!fin.fail())
		{
			string line;
			getline(fin, line);
			_curScript.push_back(line);
			if (line.size() != 0 && line[0] == ':')
			{
				_labels[line] = _curScript.size();
			}
		}
		_curLine = 0;
	}
	void messagesystem::parseNextLine()
	{
		if (_curScript.empty()) throw new exception("no script loaded");
		bool repeat = false;
		do
		{
			repeat = false;
			string s;
			if (_curLine < _curScript.size())
			{
				s = _curScript.at(_curLine);

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
				else if (cmd == "clr")
				{
					_curDialogue->clearText();
				}
				else if (cmd == "clra")
				{
					_curDialogue->clearText();
					repeat = true;
				}
				else if (cmd == "opendiag")
				{
					_curDialogue = createDialogueBox();
					repeat = true;
				}
				else if (cmd == "closediag")
				{
					delete _curDialogue;
					_curDialogue = NULL;
				}
				else if (cmd == "goto")
				{
					string label;
					ss >> label;
					_curLine = _labels[label] - 1;
					repeat = true;
				}
				else if (cmd == "set")
				{
					string varName;
					int value;
					ss >> varName >> value;
					_qs->setQuest(varName, value);
					repeat = true;
				}
				else if (cmd == "add")
				{
					string varName;
					int value;
					ss >> varName >> value;
					_qs->deltaQuest(varName, value);
					repeat = true;
				}
				else if (cmd == "playmusic")
				{
					string s;
					ss >> s;
					if (!music.OpenFromFile(s))
						throw exception("Oh shit...");
					music.Play();
					repeat = true;
				}
				else if (cmd == "stopmusic")
				{
					music.Stop();
					repeat = true;
				}
				else if (cmd == "if")
				{
					string varName, label1, label2;
					char op;	
					int value;
					ss >> varName >> op >> value >> label1 >> label2;
					switch (op)
					{
					case '<':
						if (_qs->getQuest(varName) < value)
						{
							_curLine = _labels[label1] - 1;
							repeat = true;
						}
						else
						{
							if (label2 != "")
								_curLine = _labels[label2] - 1;
							repeat = true;
						}
						break;
					case '>':
						if (_qs->getQuest(varName) > value)
						{
							_curLine = _labels[label1] - 1;
							repeat = true;
						}
						else
						{
							if (label2 != "")
								_curLine = _labels[label2] - 1;
							repeat = true;
						}
						break;
					case '=':
						if (_qs->getQuest(varName) == value)
						{
							_curLine = _labels[label1] - 1;
							repeat = true;
						}
						else
						{
							if (label2 != "")
								_curLine = _labels[label2] - 1;
							repeat = true;
						}
						break;
					}
				}
				else
					repeat = true;
				_curLine++;
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
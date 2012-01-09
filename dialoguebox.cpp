#include "pch.h"
#include "dialoguebox.h"

namespace msgs
{
	dialoguebox::dialoguebox()
	{
		_curText = "";
		_curImage = 0;
		_background = sf::Shape::Rectangle(30, 400, 770, 570, sf::Color::Color(145, 216, 230, 170));
		if (!_font.LoadFromFile("arial.ttf", 50)) throw new exception("ahhhhhhhhhhhhhhhhhhh");
	}

	dialoguebox::~dialoguebox()
	{
		if (_curImage)
			delete _curImage;
	}
	
	void dialoguebox::setText(const string& s)
	{
		_curText = s;
	}
	void dialoguebox::appendText(const string& s)
	{
		_curText += s;
	}
	// void showImage(sf::Image i);
	void dialoguebox::clearText()
	{
		_curText = "";
	}
	// void clearImage();
	void dialoguebox::render(sf::RenderTarget& target) const
	{
		target.Draw(_background);
		sf::String text(_curText, _font, 20);
		text.SetColor(sf::Color::White);
		text.SetX(40);
		text.SetY(400);
		target.Draw(text);
	}
}
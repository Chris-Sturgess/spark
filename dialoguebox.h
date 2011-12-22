// dialoguebox.h
// mostly used for displaying conversations

#pragma once
#include "resources.h"

namespace msgs
{
	class dialoguebox
	{
	public:
		dialoguebox();
		~dialoguebox();
		void setText(const string& s);
		void showImage(sf::Image i);
		void clearText();
		void clearImage();
		void render(sf::RenderTarget& target) const;
		//void update(float elapsed, const sf::Input& input);
	private:
		string _curText;
		sf::Image* _curImage;
		sf::Shape _background;
		sf::Font _font;
	};
}
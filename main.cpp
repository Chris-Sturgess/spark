// main.cpp
// Program entry point, it is responsible for creating the environment
//  and initializing the game

#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow App(sf::VideoMode(800,600), "Test Window");

	sf::Font Arial;
	if( !Arial.LoadFromFile("arial.ttf") )
		return EXIT_FAILURE;
	sf::String Text("Hello World!", Arial, 50);

	while( App.IsOpened())
	{
		sf::Event Event;
		while( App.GetEvent(Event) )
		{
			if( Event.Type == sf::Event::Closed )
				App.Close();
		}

		App.Clear();
		App.Draw(Text);
		App.Display();
	}

	return EXIT_SUCCESS;
}
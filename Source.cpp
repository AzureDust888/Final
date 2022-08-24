#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 400), "This");
	sf::Event e;
	while (window.isOpen())
	{
		window.clear(sf::Color::Cyan);
		window.display();
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				window.close();
		}
	}
}
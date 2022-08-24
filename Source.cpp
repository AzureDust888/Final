#include <iostream>
#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>
using namespace std;
int main()
{	
	cout << "Slava Ukraini\n";
	sf::RenderWindow window(sf::VideoMode(800, 400), "This");
	sf::Event e;
	while (window.isOpen())
	{

		window.clear(sf::Color::Yellow);
		window.display();
		this_thread::sleep_for(chrono::milliseconds(500));
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::Blue);
		window.display();
		this_thread::sleep_for(chrono::milliseconds(500));
	}
}
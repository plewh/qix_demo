#pragma once

#include <SFML/Graphics.hpp>

struct plApp {

	plApp();
	~plApp();
	void Run();

	private:
	sf::RenderWindow window;
	bool running;
	void HandleEvents();

};

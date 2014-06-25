#pragma once

#include <SFML/Graphics.hpp>
struct plTime {

	plTime();
	double Update();

	private:
	sf::Clock	clock;
	double		ticks;
	double		lastTicks;
	double		delta;

};

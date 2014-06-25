#pragma once

#include <SFML/Graphics.hpp>
#include "defs.h"

struct element_t {

	sf::Vector2f	vertexA;
	int vertA_xDir;
	int vertA_yDir;

	sf::Vector2f	vertexB;
	int vertB_xDir;
	int vertB_yDir;

};

struct qix_t {

	element_t head;
	element_t tail[NUM_OF_LINES];
	int buffHead;
	int buffTail;

};

qix_t* NewQix();
void DestroyQix( qix_t* qix );
void TickQix( qix_t* qix );
void DrawQix( sf::RenderWindow* window, qix_t* qix );

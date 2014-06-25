#include "app.h"
#include "qix.h"
#include "time.h"
#include <cstdio>
#include "defs.h"

plApp::plApp() {

	window.create( sf::VideoMode( WIN_MAX_X, WIN_MAX_Y ), TITLE, sf::Style::Titlebar | sf::Style::Close );
	running = true;

}

plApp::~plApp() {

	window.close();

}

void plApp::Run() {

	qix_t* qix = NewQix();
	plTime time;
	double lag = 0;

	while ( running ) {

		HandleEvents();
		lag += time.Update();

		while ( lag > UPDATE_FREQ ) {

			TickQix( qix );
			lag -= UPDATE_FREQ;

		}

		window.clear( sf::Color::White );
		DrawQix( &window, qix );
		window.display();

	}

	DestroyQix( qix );

}

void plApp::HandleEvents() {

	sf::Event event;

	while ( window.pollEvent( event ) ) {

		switch ( event.type ) {

			case sf::Event::Closed:

				running = false;
				break;

			case sf::Event::KeyPressed:

				if ( event.key.code == sf::Keyboard::Q ) {

					running = false;
					break;

				}

			default:
				break;

		}

	}

}

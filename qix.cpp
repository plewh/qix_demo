#include "qix.h"
#include <cstdio>
#include <cstdlib>
#include <cmath>

qix_t* NewQix() {

	qix_t* newQix = new qix_t;

	newQix->head.vertexA.x = VRT_A_INIT_X;
	newQix->head.vertexA.y = VRT_A_INIT_Y;
	newQix->head.vertexB.x = VRT_B_INIT_X;
	newQix->head.vertexB.y = VRT_B_INIT_Y;

	newQix->head.vertA_xDir = VRT_A_INIT_X_DIR;
	newQix->head.vertA_yDir = VRT_A_INIT_Y_DIR;
	newQix->head.vertB_xDir = VRT_B_INIT_X_DIR;
	newQix->head.vertB_yDir = VRT_B_INIT_Y_DIR;

	for ( int j = 0; j < NUM_OF_LINES; ++j ) {

		newQix->tail[j].vertexA.x = VRT_A_INIT_X;
		newQix->tail[j].vertexA.y = VRT_A_INIT_Y;
		newQix->tail[j].vertexB.x = VRT_B_INIT_X;
		newQix->tail[j].vertexB.y = VRT_B_INIT_Y;

		newQix->tail[j].vertA_xDir = VRT_A_INIT_X_DIR;
		newQix->tail[j].vertA_yDir = VRT_A_INIT_Y_DIR;
		newQix->tail[j].vertB_xDir = VRT_B_INIT_X_DIR;
		newQix->tail[j].vertB_yDir = VRT_B_INIT_Y_DIR;

	}

	newQix->buffHead = 0;
	newQix->buffTail = 0;

	return newQix;

}

void DestroyQix( qix_t* qix ) {

	delete( qix );
	qix = NULL;

}

static bool CheckBoundCollisionHorizontal( sf::Vector2f vert ) {

	if ( vert.x < WIN_MIN_X || vert.x > WIN_MAX_X ) {

		return true;

	}

	return false;

}

static bool CheckBoundCollisionVertical( sf::Vector2f vert ) {

	if ( vert.y < WIN_MIN_Y || vert.y > WIN_MAX_Y ) {

		return true;

	}

	return false;

}

void TickQix( qix_t* qix ) {

	static int tickCount;

	if ( ++tickCount > TAIL_UPDATE_TICKS ) {

		qix->tail[qix->buffHead].vertexA.x = qix->head.vertexA.x;
		qix->tail[qix->buffHead].vertexA.y = qix->head.vertexA.y;
		qix->tail[qix->buffHead].vertexB.x = qix->head.vertexB.x;
		qix->tail[qix->buffHead].vertexB.y = qix->head.vertexB.y;
		qix->buffHead = ++qix->buffHead % NUM_OF_LINES;

		tickCount = 0;

	}

	// Move end points
	qix->head.vertexA.x += qix->head.vertA_xDir * VERT_SPEED;
	qix->head.vertexA.y += qix->head.vertA_yDir * VERT_SPEED;

	qix->head.vertexB.x += qix->head.vertB_xDir * VERT_SPEED;
	qix->head.vertexB.y += qix->head.vertB_yDir * VERT_SPEED;

	// test end points for boundary collisions

	// VERT A
	if ( CheckBoundCollisionHorizontal( qix->head.vertexA ) ) {

		qix->head.vertA_xDir = -qix->head.vertA_xDir;

	}

	if ( CheckBoundCollisionVertical( qix->head.vertexA ) ) {

		qix->head.vertA_yDir = -qix->head.vertA_yDir;

	}

	// VERT B
	if ( CheckBoundCollisionHorizontal( qix->head.vertexB ) ) {

		qix->head.vertB_xDir = -qix->head.vertB_xDir;

	}

	if ( CheckBoundCollisionVertical( qix->head.vertexB ) ) {

		qix->head.vertB_yDir = -qix->head.vertB_yDir;

	}

}

static float FindAngleInDegs( sf::Vector2f deltas ) {

	return atan2( deltas.x, deltas.y ) * 180 / M_PI;

}

static float Pow( float f ) {

	return f * f;

}

static void RenderElement( sf::RenderWindow* window, element_t* elem ) {

	sf::Vector2f vrtA;
	sf::Vector2f vrtB;
	sf::Vector2f vrtDelta;

	vrtA = elem->vertexA;
	vrtB = elem->vertexB;

	// Find opposite and adjacent
	vrtDelta.x = vrtA.x - vrtB.x;
	vrtDelta.y = vrtA.y - vrtB.y;

	// Find hypotenuse
	float lineLength = sqrt( Pow( vrtDelta.x ) + Pow( vrtDelta.y ) );

	// Find angle with respect to horizontal plane
	float angle = -FindAngleInDegs( vrtDelta );

	sf::RectangleShape line ( sf::Vector2f( LINE_WIDTH, lineLength ) );
	sf::RectangleShape vertex( sf::Vector2f( LINE_VERTICES_WIDTH, LINE_VERTICES_HEIGHT ) );

	// render line to screen
	line.setPosition( vrtA.x, vrtA.y );
	line.setFillColor( sf::Color::Red );
	line.rotate( angle - 180 );
	window->draw( line );

	// render both endpoints to screen
	if ( RENDER_VERTS ) {

		vertex.setOrigin( LINE_VERTICES_WIDTH / 2, LINE_VERTICES_HEIGHT / 2 );
		vertex.setPosition( vrtA );
		vertex.setFillColor( sf::Color::Red );
		window->draw( vertex );

		vertex.setPosition( vrtB );
		vertex.setFillColor( sf::Color::Red );
		window->draw( vertex );

	}

}

void DrawQix( sf::RenderWindow* window, qix_t* qix ) {

	RenderElement( window, &qix->head );

	for ( int j = 0; j < NUM_OF_LINES; ++j ) {

		RenderElement( window, &qix->tail[j] );

	}

}

#include "time.h"
#include <cstdio>

plTime::plTime() {

	ticks = 0;
	lastTicks = 0;
	delta = 0;

}

double plTime::Update() {

	ticks = clock.getElapsedTime().asMicroseconds() / 1000;
	delta = ticks - lastTicks;
	lastTicks = ticks;

	return delta;

}

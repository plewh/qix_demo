#pragma once

/* WINDOW */
#define WIN_MIN_X				0
#define WIN_MAX_X				800
#define WIN_MIN_Y				0
#define WIN_MAX_Y				600

#define TITLE					"QUICKS"

#define UPDATE_FREQ				16		// ms

/* LINE */
#define NUM_OF_LINES			80
#define LINE_WIDTH				1		// in pixels

#define TAIL_UPDATE_TICKS		1		// distance between lines

/* END POINT VERTICES */
#define VRT_A_INIT_X			WIN_MIN_X + 10
#define VRT_A_INIT_Y			WIN_MIN_Y + 10
#define VRT_A_INIT_X_DIR		1
#define VRT_A_INIT_Y_DIR		1
#define VRT_B_INIT_X			WIN_MAX_X / 2
#define VRT_B_INIT_Y			WIN_MAX_Y / 2
#define VRT_B_INIT_X_DIR		1
#define VRT_B_INIT_Y_DIR		-1

#define VERT_SPEED				5

#define RENDER_VERTS			1		// toggle drawing the end points of each line
#define LINE_VERTICES_WIDTH		2		// if RENDER_VERTS == 1, how big are the points (in pixels)
#define LINE_VERTICES_HEIGHT	2

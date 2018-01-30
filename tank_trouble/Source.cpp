#include <iostream>
#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_primitives.h>
#include <vector>

using namespace std;

//this function kinda sucks
bool wallCollide(int x, int y, int angle, int dir, int size, int map[64][48]);

const float FPS = 60;
const int SCREEN_W = 640;
const int SCREEN_H = 480;
const int player1_SIZE = 32;

enum MYKEYS {
	KEY_UP,KEY_DOWN,KEY_LEFT,KEY_RIGHT,KEY_M
};
enum DIRECTION {
	RIGHT,LEFT,UP,DOWN
};



int main() {

	//the map
	int level[64][48];
	//initialize to all 0s
	for (int m = 0; m < 64; m++)
		for (int n = 0; n < 48; n++) {
			//fill in permimeter
			if (m == 0 || n == 0)
				level[m][n] = 1;
			else if (m == 63 || n == 47)
				level[m][n] = 1;
			//draw interior maze walls
			else if (m == 20 && n < 30)
				level[m][n] = 1;
			else if (m > 20 && n == 35)
				level[m][n] = 1;
			else if (m > 35 && n == 15)
				level[m][n] = 1;
			//leave rest of map blank
			else
				level[m][n] = 0;
		}
	///// print for testing
	//for (int m = 0; m < 64; m++)
	// for (int n =0; n < 48; n ++)
	// cout<<level[m][n];

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *player1 = NULL;
	float player1_x = SCREEN_W / 2.0 - player1_SIZE / 2.0;
	float player1_y = SCREEN_H / 2.0 - player1_SIZE / 2.0;
	bool key[5] = { false,false,false,false,false };
	bool redraw = true;
	bool doexit = false;
	double angle = 0; //increases or decreases with left and right arrow
	int justfired = 0; //an extra variable to stop all the bullets from coming out at once

	al_init();
	al_init_image_addon();
	al_init_primitives_addon();
}
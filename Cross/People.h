#pragma once
#include "libs.h"
#define DEFAULT_X 10
#define DEFAULT_Y 10

class People {
private:
	bool _State;
	int flagMove;
public:
	int _X, _Y;
private:
	void up();
	void down();
	void left();
	void right();
public:
	People();
	People(int, int);
	void draw();
	bool redrawAndCheck(bool flagG[WIDTH][HEIGHT]);
	void clear();
	void setFlag(int f) { flagMove = f; }
	void kill() { _State = 0; }
	bool isDead();
	bool checkWon();
	void save(FILE *&);
	~People();
};

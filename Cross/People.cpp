#include "People.h"



People::People() {
	_X = DEFAULT_X;
	_Y = DEFAULT_Y;
	_State = 1;
	flagMove = -1;
}

People::People(int x, int y) {
	_X = x;
	_Y = y;
	_State = 1;
	flagMove = -1;
}

People::~People() {
}

void People::draw() {
	textcolor(12);
	GotoXY(_X + 13, _Y + 3);
	cout << char(219);
	GotoXY(_X + 1 + 13, _Y + 3);
	cout << char(219);

	textcolor(6);
	GotoXY(_X + 13, _Y + 1 + 3);
	cout << char(180);
	GotoXY(_X + 1 + 13, _Y + 1 + 3);
	cout << char(195);
}

void People::clear() {
	textcolor(0);
	GotoXY(_X + 13, _Y + 3);
	cout << char(219);
	GotoXY(_X + 1 + 13, _Y + 3);
	cout << char(219);

	GotoXY(_X + 13, _Y + 1 + 3);
	cout << char(219);
	GotoXY(_X + 1 + 13, _Y + 1 + 3);
	cout << char(219);
}

void People::up() {
	if (_Y > 0)
		_Y--;
}

void People::down() {
	if (_Y < HEIGHT - 1)
	_Y++;
}

void People::left() {
	if (_X > 0)
		_X--;
}

void People::right() {
	if (_X < WIDTH - 2)
		_X++;
}

bool People::isDead() {
	return !_State;
}

//return 1 if won
bool People::checkWon() {
	if (flagMove == -1)
		return 0;

	return (_Y == 0);
}

//return 0 if people die
bool People::redrawAndCheck(bool flagG[WIDTH][HEIGHT]) {
	if (flagMove == -1)
		return 1;

	clear();

	if (flagMove == 0)
		left();
	else if (flagMove == 1)
		right();
	else if (flagMove == 2)
		down();
	else if (flagMove == 3)
		up();

	flagMove = -1;
	draw();

	if (flagG[_X][_Y] || flagG[_X + 1][_Y] || flagG[_X][_Y + 1] || flagG[_X + 1][_Y + 1]) {
		_State = 0;
		return 0;
	}
	else
		return 1;
}

void People::save(FILE *&out) {
	fwrite(&_X, sizeof(int), 1, out);
	fwrite(&_Y, sizeof(int), 1, out);
}
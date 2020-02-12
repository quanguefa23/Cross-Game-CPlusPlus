#include "Animal.h"



Animal::Animal() {
	_X = _Y = 0;
	_type = 0;
	flagMove = 0;
}

Animal::Animal(int x, int y, bool t) {
	_X = x;
	_Y = y;
	_type = t;
	flagMove = 0;
}

Animal::~Animal() {
}

void Animal::move() {
	flagMove = 1;
}

bool Animal::redrawAndCheck(bool flag[WIDTH][HEIGHT], People &p) {
	if (!flagMove)
		return 1;

	clear(flag);

	if (_type) {
		_X++;
		if (_X >= WIDTH)
			_X = 0;
	}
	else {
		_X--;
		if (_X < 0)
			_X = WIDTH - 1;
	}

	draw(flag);
	flagMove = 0;

	if (flag[p._X][p._Y] || flag[p._X + 1][p._Y] || flag[p._X][p._Y + 1] || flag[p._X + 1][p._Y + 1]) {
		p.kill();
		return 0;
	}
	else
		return 1;
}

void Animal::save(FILE *&out) {
	fwrite(&_X, sizeof(int), 1, out);
	fwrite(&_Y, sizeof(int), 1, out);
	fwrite(&_type, sizeof(bool), 1, out);
}
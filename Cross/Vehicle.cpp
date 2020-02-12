#include "Vehicle.h"



Vehicle::Vehicle() {
	_X = _Y = 0;
	flagMove = 0;
}

Vehicle::Vehicle(int x, int y, bool t) {
	_X = x;
	_Y = y;
	_type = t;
	flagMove = 0;
}

Vehicle::~Vehicle() {
}

void Vehicle::move() {
	flagMove = 1;
}

bool Vehicle::redrawAndCheck(bool flag[WIDTH][HEIGHT], People &p) {
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

void Vehicle::save(FILE *&out) {
	fwrite(&_X, sizeof(int), 1, out);
	fwrite(&_Y, sizeof(int), 1, out);
	fwrite(&_type, sizeof(bool), 1, out);
}
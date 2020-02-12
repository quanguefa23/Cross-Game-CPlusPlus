#include "Dinausor.h"



Dinausor::Dinausor() {
}

Dinausor::Dinausor(int x, int y, bool t) : Animal(x, y, t) {

}

Dinausor::~Dinausor() {
}

void Dinausor::draw(bool flag[WIDTH][HEIGHT]) {
	textcolor(11);
	if (_type) {
		for (int i = 2; i < 6; i++) {
			if (_X + i >= WIDTH)
				break;
			flag[_X + i][_Y] = 1;
			GotoXY(_X + i + 13, _Y + 3);
			cout << char(219);
		}

		for (int i = 0; i < 5; i++) {
			if (_X + i >= WIDTH)
				break;
			flag[_X + i][_Y + 1] = 1;
			GotoXY(_X + i + 13, _Y + 1 + 3);
			cout << char(219);
		}

		for (int i = 4; i < 6; i++) {
			if (_X + i >= WIDTH)
				break;
			flag[_X + i][_Y - 1] = 1;
			GotoXY(_X + i + 13, _Y - 1 + 3);
			cout << char(219);
		}
	}
	else {
		for (int i = 2; i < 6; i++) {
			if (_X - i < 0)
				break;
			flag[_X - i][_Y] = 1;
			GotoXY(_X - i + 13, _Y + 3);
			cout << char(219);
		}

		for (int i = 0; i < 5; i++) {
			if (_X - i < 0)
				break;
			flag[_X - i][_Y + 1] = 1;
			GotoXY(_X - i + 13, _Y + 1 + 3);
			cout << char(219);
		}

		for (int i = 4; i < 6; i++) {
			if (_X - i < 0)
				break;
			flag[_X - i][_Y - 1] = 1;
			GotoXY(_X - i + 13, _Y - 1 + 3);
			cout << char(219);
		}
	}
}

void Dinausor::clear(bool flag[WIDTH][HEIGHT]) {
	textcolor(0);
	if (_type) {
		for (int i = 2; i < 6; i++) {
			if (_X + i >= WIDTH)
				break;
			flag[_X + i][_Y] = 0;
			GotoXY(_X + i + 13, _Y + 3);
			cout << char(219);
		}

		for (int i = 0; i < 5; i++) {
			if (_X + i >= WIDTH)
				break;
			flag[_X + i][_Y + 1] = 0;
			GotoXY(_X + i + 13, _Y + 1 + 3);
			cout << char(219);
		}

		for (int i = 4; i < 6; i++) {
			if (_X + i >= WIDTH)
				break;
			flag[_X + i][_Y - 1] = 0;
			GotoXY(_X + i + 13, _Y - 1 + 3);
			cout << char(219);
		}
	}
	else {
		for (int i = 2; i < 6; i++) {
			if (_X - i < 0)
				break;
			flag[_X - i][_Y] = 0;
			GotoXY(_X - i + 13, _Y + 3);
			cout << char(219);
		}

		for (int i = 0; i < 5; i++) {
			if (_X - i < 0)
				break;
			flag[_X - i][_Y + 1] = 0;
			GotoXY(_X - i + 13, _Y + 1 + 3);
			cout << char(219);
		}

		for (int i = 4; i < 6; i++) {
			if (_X - i < 0)
				break;
			flag[_X - i][_Y - 1] = 0;
			GotoXY(_X - i + 13, _Y - 1 + 3);
			cout << char(219);
		}
	}
}
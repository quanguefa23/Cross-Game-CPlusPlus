#include "Bird.h"



Bird::Bird(){
}

Bird::Bird(int x, int y, bool t) : Animal(x, y, t) {

}

Bird::~Bird() {
}

void Bird::draw(bool flag[WIDTH][HEIGHT]) {
	textcolor(5);

	if (_type) {
		for (int i = 0; i < 6; i++) {
			if (_X + i >= WIDTH)
				break;

			if (i == 2 || i == 3) {
				flag[_X + i][_Y + 1] = 1;
				GotoXY(_X + i + 13, _Y + 1 + 3);
				cout << char(219);
			}
			else {
				flag[_X + i][_Y] = 1;
				GotoXY(_X + i + 13, _Y + 3);
				cout << char(219);
			}
		}
	}
	else {
		for (int i = 0; i < 6; i++) {
			if (_X - i < 0)
				break;

			if (i == 2 || i == 3) {
				flag[_X - i][_Y + 1] = 1;
				GotoXY(_X - i + 13, _Y + 1 + 3);
				cout << char(219);
			}
			else {
				flag[_X - i][_Y] = 1;
				GotoXY(_X - i + 13, _Y + 3);
				cout << char(219);
			}
		}
	}
}

void Bird::clear(bool flag[WIDTH][HEIGHT]) {
	textcolor(0);

	if (_type) {
		for (int i = 0; i < 6; i++) {
			if (_X + i >= WIDTH)
				break;

			if (i == 2 || i == 3) {
				flag[_X + i][_Y + 1] = 0;
				GotoXY(_X + i + 13, _Y + 1 + 3);
				cout << char(219);
			}
			else {
				flag[_X + i][_Y] = 0;
				GotoXY(_X + i + 13, _Y + 3);
				cout << char(219);
			}
		}
	}
	else {
		for (int i = 0; i < 6; i++) {
			if (_X - i < 0)
				break;

			if (i == 2 || i == 3) {
				flag[_X - i][_Y + 1] = 0;
				GotoXY(_X - i + 13, _Y + 1 + 3);
				cout << char(219);
			}
			else {
				flag[_X - i][_Y] = 0;
				GotoXY(_X - i + 13, _Y + 3);
				cout << char(219);
			}
		}
	}
}
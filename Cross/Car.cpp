#include "Car.h"



Car::Car() {
}

Car::Car(int x, int y, bool t) : Vehicle(x, y, t) {
}

Car::~Car() {
}

void Car::draw(bool flag[WIDTH][HEIGHT]) {

	textcolor(6);

	if (_type) {
		for (int i = 0; i < 8; i++) {
			if (_X + i >= WIDTH)
				break;

			if (i > 1 && i < 6) {
				flag[_X + i][_Y] = 1;
				GotoXY(_X + i + 13, _Y + 3);
				cout << char(219);
			}
			
			flag[_X + i][_Y + 1] = 1;
			GotoXY(_X + i + 13, _Y + 1 + 3);
			cout << char(219);
		}
	}
	else {
		for (int i = 0; i < 8; i++) {
			if (_X - i < 0)
				break;

			if (i > 1 && i < 6) {
				flag[_X - i][_Y] = 1;
				GotoXY(_X - i + 13, _Y + 3);
				cout << char(219);
			}

			flag[_X - i][_Y + 1] = 1;
			GotoXY(_X - i + 13, _Y + 1 + 3);
			cout << char(219);
		}
	}
}

void Car::clear(bool flag[WIDTH][HEIGHT]) {
	textcolor(0);

	if (_type) {
		for (int i = 0; i < 8; i++) {
			if (_X + i >= WIDTH)
				break;

			if (i > 1 && i < 6) {
				flag[_X + i][_Y] = 0;
				GotoXY(_X + i + 13, _Y + 3);
				cout << char(219);
			}

			flag[_X + i][_Y + 1] = 0;
			GotoXY(_X + i + 13, _Y + 1 + 3);
			cout << char(219);
		}
	}
	else {
		for (int i = 0; i < 8; i++) {
			if (_X - i < 0)
				break;

			if (i > 1 && i < 6) {
				flag[_X - i][_Y] = 0;
				GotoXY(_X - i + 13, _Y + 3);
				cout << char(219);
			}

			flag[_X - i][_Y + 1] = 0;
			GotoXY(_X - i + 13, _Y + 1 + 3);
			cout << char(219);
		}
	}
}

//void Car::draw(bool flag[WIDTH][HEIGHT]) {
//	int x = _X + 13, y = _Y + 3;
//	textcolor(0);
//	GotoXY(x, y);
//	cout << "    ";
//	GotoXY(x - 2, y + 1);
//	cout << "        ";
//}
//
//void Car::clear(bool flag[WIDTH][HEIGHT]) {
//	int x = _X + 13, y = _Y + 3;
//	textcolor(8);
//	GotoXY(x, y);
//	cout << "    ";
//	GotoXY(x - 2, y + 1);
//	cout << "        ";
//}
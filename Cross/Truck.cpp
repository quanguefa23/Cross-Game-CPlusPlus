#include "Truck.h"



Truck::Truck() {
}

Truck::Truck(int x, int y, bool t) : Vehicle(x, y, t) {
}

Truck::~Truck() {
}

void Truck::draw(bool flag[WIDTH][HEIGHT]) {
	textcolor(3);

	if (_type) {
		for (int i = 0; i < 6; i++) {
			if (_X + i >= WIDTH)
				break;

			if (i < 4) {
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
		for (int i = 0; i < 6; i++) {
			if (_X - i < 0)
				break;

			if (i < 4) {
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

void Truck::clear(bool flag[WIDTH][HEIGHT]) {
	textcolor(0);

	if (_type) {
		for (int i = 0; i < 6; i++) {
			if (_X + i >= WIDTH)
				break;

			if (i < 4) {
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
		for (int i = 0; i < 6; i++) {
			if (_X - i < 0)
				break;

			if (i < 4) {
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

//void Truck::draw(bool flag[WIDTH][HEIGHT]) {
//	int x = _X + 13, y = _Y + 3;
//	GotoXY(x, y);
//	textcolor(0);
//	if (_type) {
//		cout << "    ";
//		GotoXY(x, y + 1);
//		cout << "      ";
//	}
//	else {
//		cout << "    ";
//		GotoXY(x - 2, y + 1);
//		cout << "      ";
//	}
//}
//
//void Truck::clear(bool flag[WIDTH][HEIGHT]) {
//	int x = _X + 13, y = _Y + 3;
//	GotoXY(x, y);
//	textcolor(8);
//	if (_type) {
//		cout << "    ";
//		GotoXY(x, y + 1);
//		cout << "      ";
//	}
//	else {
//		cout << "    ";
//		GotoXY(x - 2, y + 1);
//		cout << "      ";
//	}
//}
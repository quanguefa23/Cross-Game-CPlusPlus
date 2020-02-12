#include "Redlight.h"



Redlight::Redlight() {
	_color = 1;
	_X = _Y = 0;
	flagColor = 0;
}

Redlight::Redlight(int x, int y, bool c) {
	_X = x;
	_Y = y;
	_color = c;
	flagColor = 0;
}

Redlight::~Redlight() {
}

void Redlight::draw() {
	textcolor(15);
	GotoXY(_X - 1, _Y - 1);
	cout << char(218) << char(196) << char(196) << char(191);
	GotoXY(_X - 1, _Y + 2);
	cout << char(192) << char(196) << char(196) << char(217);
	GotoXY(_X - 1, _Y);
	cout << char(179);
	GotoXY(_X + 2, _Y);
	cout << char(179);
	GotoXY(_X - 1, _Y + 1);
	cout << char(179);
	GotoXY(_X + 2, _Y + 1);
	cout << char(179);

	if (_color == RED) {
		textcolor(4);
		GotoXY(_X, _Y);
		cout << char(219) << char(219);
	}
	else {
		textcolor(2);
		GotoXY(_X, _Y + 1);
		cout << char(219) << char(219);
	}

}

void Redlight::changeColor() {
	_color = !_color;
}

void Redlight::redraw() {
	if (!flagColor)
		return;

	if (_color == RED) {
		textcolor(0);
		GotoXY(_X, _Y + 1);
		cout << char(219) << char(219);

		textcolor(4);
		GotoXY(_X, _Y);
		cout << char(219) << char(219);
	}
	else {
		textcolor(0);
		GotoXY(_X, _Y);
		cout << char(219) << char(219);

		textcolor(2);
		GotoXY(_X, _Y + 1);
		cout << char(219) << char(219);
	}

	flagColor = 0;
}

//void Redlight::save(ofstream &out) {
//	out << _X << " " << _Y << " " << _color << " " << endl;
//}

void Redlight::save(FILE *&out) {
	fwrite(&_X, sizeof(int), 1, out);
	fwrite(&_Y, sizeof(int), 1, out);
	fwrite(&_color, sizeof(bool), 1, out);
}
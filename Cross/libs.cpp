#include "libs.h"

void firstHandle() {
	postionConsole();
	resizeConsole(1600, 970);
	FixConsoleWindow();
	setcursor(false);
}

int selection(int k) {
	GotoXY(79, 18);
	if (k == 1) textcolor(10);
	else   		textcolor(15);
	cout << "1. New game";

	GotoXY(79, 20);
	if (k == 2) textcolor(10);
	else   		textcolor(15);
	cout << "2. Load game";

	GotoXY(79, 22);
	if (k == 3) textcolor(10);
	else   		textcolor(15);
	cout << "3. Settings";

	GotoXY(79, 24);
	if (k == 4) textcolor(10);
	else   		textcolor(15);
	cout << "4. Exit";


	/* ---------------------------------- */

	//Nh?p t? bàn phím vô ch
	int ch = _getch();
	switch (ch) {
	case 224:
		ch = _getch();
		if (ch == 72) 
			return selection(k > 1 ? k - 1 : 4); //M?i tên lên, tr? k
		else if (ch == 80) 
			return selection(k < 4 ? k + 1 : 1); //M?i tên xu?ng, c?ng k
		else 
			return selection(k); //M?i tên qua l?i thì k gi? nguyên
	case 13:
		return k;
	default: 
		return selection(k); //Nh?p ký t? khác thì k gi? nguyên
	}
}

void drawRectangle(int X, int Y, int W, int H) {
	GotoXY(X, Y);
	cout << char(218);
	for (int i = 1; i < W; i++) {
		GotoXY(X + i, Y);
		cout << char(196);
	}
	GotoXY(X + W, Y);
	cout << char(191);

	for (int i = 1; i < H; i++) {
		GotoXY(X, Y + i);
		cout << char(179);
	}
	GotoXY(X, Y + H);
	cout << char(192);

	for (int i = 1; i < H; i++) {
		GotoXY(X + W, Y + i);
		cout << char(179);
	}
	GotoXY(X + W, Y + H);
	cout << char(217);

	for (int i = 1; i < W; i++) {
		GotoXY(X + i, Y + H);
		cout << char(196);
	}
}

void loadingBar() {
	textcolor(2);
	GotoXY(60, 20);
	cout << "LOADING ";
	for (int i = 0; i < 40; i++) {
		GotoXY(69 + i, 20);
		cout << char(219);
		Sleep(10);
	}
	Sleep(300);
	system("cls");
}

void settings(int level, bool &sound, int k) {
	GotoXY(79, 19);
	if (k == 1) textcolor(10);
	else   		textcolor(15);
	if (sound) 	cout << "1. Sound: ON ";
	else cout << "1. Sound: OFF";

	GotoXY(79, 21);
	if (k == 2) textcolor(10);
	else   		textcolor(15);
	cout << "2. Level: " << level;

	GotoXY(79, 23);
	if (k == 3) textcolor(10);
	else   		textcolor(15);
	cout << "3. Save";
	/* ---------------------------------- */

	int ch = _getch();
	switch (ch) {
	case 80:
		return settings(level, sound, k < 3 ? k + 1 : 1); 
	case 72:
		return settings(level, sound, k > 1 ? k - 1 : 3); 
	case 13:
		if (k == 3)
			return;
		if (k == 1) 
			sound = !sound;
		return settings(level, sound, k);
	default:
		return settings(level, sound, k); 
	}
}


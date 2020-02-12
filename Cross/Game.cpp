#include "Game.h"

void Game::deleteVectors() {
	int i, j;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < level; j++) {
			delete veh[i][j];
			delete ani[i][j];
		}
	}

	for (i = 0; i < 4; i++) {
		for (j = 0; j < level; j++) {
			veh[i].pop_back();
			ani[i].pop_back();
		}
	}
}

Game::~Game() {
	deleteVectors();
}

Game::Game(int l, bool s) {
	initial(l, s);
}

void Game::initial(int l, bool s) {
	int i, j, type;
	Random r;

	//set state, WON
	state = 1;
	WON = 0;
	sound = s;

	//set level, number of elements each array = level index
	level = l;
	int delta = (WIDTH / level);

	//mark entire playzone are empty
	for (i = 0; i < HEIGHT; i++)
		for (j = 0; j < WIDTH; j++)
			flag[i][j] = 0;

	//create Redlight
	int xR1 = 9, yR1 = 5, xR2 = 9, yR2 = 25;
	for (i = 0; i < 4; i++) {
		if (i % 2)
			xR1 = xR2 = 111;
		else
			xR1 = xR2 = 9;

		Redlight tRL1(xR1, yR1, i % 2);
		Redlight tRL2(xR2, yR2, i % 2);

		RLveh[i] = tRL1;
		RLani[i] = tRL2;
		yR1 += 4;
		yR2 += 4;
		if (i == 1) {
			yR1 += 2;
			yR2 += 2;
		}		
	}

	//create animal and vehicle with random position and speed
	int x1 = -delta, y1 = 2, x2 = -delta, y2 = 22;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < level; j++) {
			x1 += (delta + r.Next(10 / level + 1));
			type = r.Next(2);
			if (type) 
				veh[i].push_back(new Car(x1, y1, i % 2));
					
			else
				veh[i].push_back(new Truck(x1, y1, i % 2));
				

			x2 += (delta + r.Next(10 / level + 1));
			type = r.Next(2);
			if (type)
				ani[i].push_back(new Bird(x2, y2, i % 2));
			else
				ani[i].push_back(new Dinausor(x2, y2, i % 2));
		}

		x1 = x2 = -delta;
		y1 += 4;
		y2 += 4;
		if (i == 1) {
			y1 += 2;
			y2 += 2;
		}
	}

	//create player
	People tPlayer(WIDTH / 2, HEIGHT - 1);
	player = tPlayer;
}

void Game::reset(int l, bool s) {
	textcolor(0);
	system("cls");
	deleteVectors();
	initial(l, s);
}

void Game::drawBackground() {
	loadingBar();
	textcolor(6);
	drawRectangle(132, 4, 21, 3);
	drawRectangle(129, 3, 27, 5);
	GotoXY(134, 5);
	cout << "Current level  : " << level;
	GotoXY(134, 6);
	cout << "Elements on air: " << level * 8;

	textcolor(3);
	drawRectangle(126, 34, 25, 3);
	GotoXY(128, 35);
	cout << "Press 'L' to save game";
	GotoXY(128, 36);
	cout << "Press 'T' to load game";

	textcolor(15);
	GotoXY(127, 39);
	cout << "Use W, A, S, D key to move";
	GotoXY(127, 40);
	cout << "Play skilfully to come to the finish";

	textcolor(7);
	GotoXY(127, 42);
	cout << "An OOP'S project";
	GotoXY(127, 43);
	cout << "Author: Dark Prince";

	int i, j, k;
	int x = 44, y = 1;
	GotoXY(x, y);
	textcolor(6);
	cout << char(36) << " WINNER WINNER CHICKEN DINNER " << char(36);

	textcolor(15);

	x = 13, y = 3;
	for (i = 0; i < WIDTH; i++) {
		GotoXY(x++, y);
		cout << char(177);
	}

	x = 12, y = 3;
	for (i = 0; i < HEIGHT + 1; i++) {
		GotoXY(x, y++);
		cout << char(186);
	}

	x += (WIDTH + 1);
	y = 3;
	for (i = 0; i < HEIGHT + 1; i++) {
		GotoXY(x, y++);
		cout << char(186);
	}

	x = 12;
	y = 4 + HEIGHT;
	GotoXY(x++, y);
	cout << char(200);
	for (i = 0; i < WIDTH; i++) {
		GotoXY(x++, y);
		cout << char(205);
	}
	GotoXY(x, y);
	cout << char(188);
}

void Game::drawElement() {
	int i, j;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < level; j++) {
			veh[i][j]->draw(flag);
			ani[i][j]->draw(flag);
		}
		RLveh[i].draw();
		RLani[i].draw();
	}

	player.draw();
}

void Game::playGame() {
	int i, j;
	drawBackground();
	drawElement();

	while (!player.isDead())
		drawGame();
}

void Game::handleWin() {
	if (sound)
		cout << char(7);
	textcolor(2);
	GotoXY(127, 20);
	if (level < MAX_LEVEL)
		cout << "LEVEL UP! PRESS ANY KEY TO CONTINUE";
	else
		cout << "WINNER WINNER CHICKEN DINNER";
	WON = 1;
	player.kill();
}

void Game::drawGame() {
	int i, j;
	while (!player.isDead()) {
		for (i = 0; i < 4; i++) {
			RLveh[i].redraw();
			RLani[i].redraw();

			for (j = 0; j < level; j++) {
				if (!player.redrawAndCheck(flag)) {
					handleCollision(player._X, player._Y);
					return;
				}
				if (player.checkWon()) {
					handleWin();
					return;
				}				
				if (!veh[i][j]->redrawAndCheck(flag, player)) {
						handleCollision(player._X, player._Y);
						return;
					}
				if (player.checkWon()) {
					handleWin();
					return;
				}
			}

			for (j = 0; j < level; j++) {
				if (!player.redrawAndCheck(flag)) {
					handleCollision(player._X, player._Y);
					return;
				}
				if (player.checkWon()) {
					handleWin();
					return;
				}
				if (!ani[i][j]->redrawAndCheck(flag, player)) {
					handleCollision(player._X, player._Y);
					return;
				}
				if (player.checkWon()) {
					handleWin();
					return;
				}
			}
		}
	}
}

void Game::changeRedlight() {
	while (!player.isDead()) {
		Sleep(3000);
		for (int i = 0; i < 4; i++) {
			RLveh[i].changeColor();
			RLveh[i].setFlagColor(1);
			RLani[i].changeColor();
			RLani[i].setFlagColor(1);
		}
	}
}

void Game::moveElement() {
	int i, j, timeS = 15 - level;

	while (!player.isDead()) {
		for (i = 0; i < 4; i++) {
			if (RLveh[i].currentStatus() == GREEN)
				for (j = 0; j < level; j++)
					veh[i][j]->move();
			if (RLani[i].currentStatus() == GREEN) 
				for (j = 0; j < level; j++) 
					ani[i][j]->move();
			Sleep(timeS);
		}
	}
}

void Game::drawFlag() {
	int i, j;
	for (i = 0; i < WIDTH; i++) {
		for (j = 0; j < HEIGHT; j++) {
			if (flag[i][j]) {
				GotoXY(i + 13, j + 3);
				cout << '1';
			}
		}
	}
}

void Game::movePlayer(char const &move) {
	if (move == 'a')
		player.setFlag(0);
	else if (move == 'd')
		player.setFlag(1);
	else if (move == 's')
		player.setFlag(2);
	else if (move == 'w')
		player.setFlag(3);
}

void Game::handleCollision(int x, int y) {
	drawFlag();
	if (sound)
		Beep(523, 500);

	for (int i = 0; i < 2; i++) {
		textcolor(15);
		GotoXY(x + 13, y + 3);
		cout << char(219) << char(219);
		Sleep(200);

		textcolor(2);
		GotoXY(127, 20);
		cout << "DO YOU WANT TO PLAY AGAIN?";

		textcolor(17);
		GotoXY(x + 13, y + 3);
		cout << char(219) << char(219);
		Sleep(200);

		textcolor(4);
		GotoXY(127, 20);
		cout << "DO YOU WANT TO PLAY AGAIN?";
	}

	GotoXY(127, 21);
	cout << "PRESS 'Y' (YES) OR 'N' (NO)";
}

void Game::checkOut(char const &M) {
	if (M != 'y')
		state = 0;
}

void Game::saveGame() {
	string filename;
	textcolor(3);
	GotoXY(127, 24);
	cout << "SAVING GAME";
	GotoXY(127, 25);
	cout << "Please input file name: ";

	setcursor(true);
	cin >> filename;
	setcursor(false);

	//save game
	//ofstream out;
	//out.open(filename);
	//out << level << endl;
	//int i, j;
	//for (i = 0; i < 4; i++) {
	//	for (j = 0; j < level; j++)
	//		veh[i][j]->save(out);
	//	RLveh[i].save(out);
	//}
	//for (i = 0; i < 4; i++) {
	//	for (j = 0; j < level; j++)
	//		ani[i][j]->save(out);
	//	RLani[i].save(out);
	//}
	//player.save(out);

	FILE *out = fopen(filename.c_str(), "wb");
	fwrite(&level, sizeof(int), 1, out);
	int i, j;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < level; j++)
			veh[i][j]->save(out);
		RLveh[i].save(out);
	}
	for (i = 0; i < 4; i++) {
		for (j = 0; j < level; j++)
			ani[i][j]->save(out);
		RLani[i].save(out);
	}
	player.save(out);
	fclose(out);


	GotoXY(127, 26);
	cout << "Saved! Press any key to continue";
	char t = _getch();

	textcolor(3);
	GotoXY(127, 24);
	cout << "                ";
	GotoXY(127, 25);
	cout << "                                               ";
	GotoXY(127, 26);
	cout << "                                               ";
}

void Game::loadGame() {
	string filename;
	textcolor(3);
	GotoXY(127, 24);
	cout << "LOADING GAME";
	GotoXY(127, 25);
	cout << "Please input file name: ";

	setcursor(true);
	cin >> filename;
	setcursor(false);

	//load game
	FILE *in = fopen(filename.c_str(), "rb");
	handleLoading(in);
	fclose(in);

	GotoXY(127, 26);
	cout << "Loaded! Press any key to continue";
	char t = _getch();

	system("cls");
	drawBackground();
	drawElement();
}

void Game::handleLoading(FILE *&in) {
	deleteVectors();
	fread(&level, sizeof(int), 1, in);
	int i, j, x, y;
	bool b;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < level; j++) {
			fread(&x, sizeof(int), 1, in);
			fread(&y, sizeof(int), 1, in);
			fread(&b, sizeof(bool), 1, in);
			if (b)
				veh[i].push_back(new Car(x, y, b));
			else
				veh[i].push_back(new Truck(x, y, b));
		}
		fread(&x, sizeof(int), 1, in);
		fread(&y, sizeof(int), 1, in);
		fread(&b, sizeof(bool), 1, in);
		Redlight tRL(x, y, b);
		RLveh[i] = tRL;
	}
	for (i = 0; i < 4; i++) {
		for (j = 0; j < level; j++) {
			fread(&x, sizeof(int), 1, in);
			fread(&y, sizeof(int), 1, in);
			fread(&b, sizeof(bool), 1, in);
			if (b)
				ani[i].push_back(new Bird(x, y, b));
			else
				ani[i].push_back(new Dinausor(x, y, b));
		}
		fread(&x, sizeof(int), 1, in);
		fread(&y, sizeof(int), 1, in);
		fread(&b, sizeof(bool), 1, in);
		Redlight tRL(x, y, b);
		RLani[i] = tRL;
	}
	fread(&x, sizeof(int), 1, in);
	fread(&y, sizeof(int), 1, in);
	People tPlayer(x, y);
	player = tPlayer;
}
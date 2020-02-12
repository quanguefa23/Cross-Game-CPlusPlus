#include "libs.h"
#include "Game.h"

char MOVING;
Game g(1, 1);

void changeRL() {
	g.changeRedlight();
}

void moveEle() {
	g.moveElement();
}

void playG() {
	g.playGame(); 
}

void main() {
	firstHandle();
	int s = 1; 
	int level = 1;
	bool sound = 1;
	string filename;

	while (s != 4) {
		system("cls");
		//drawBanner();
		textcolor(15);
		drawRectangle(75, 17, 19, 8);
		s = selection(1); //draw menu and input selection
		switch (s) {
		case 1: case 2:
			if (s == 2) {
				system("cls");
				textcolor(3);
				GotoXY(75, 18);
				cout << "Please input file name: ";

				setcursor(true);
				cin >> filename;
				setcursor(false);

				GotoXY(75, 19);
				cout << "Loaded! Press any key to continue";
				char t = _getch();
				system("cls");
			}

			do {
				if (s == 1)
					g.reset(level, sound);

				thread t1(playG);
				thread t2(moveEle);
				thread t3(changeRL);

				if (s == 2) {
					SuspendThread(t1.native_handle());
					SuspendThread(t2.native_handle());
					SuspendThread(t3.native_handle());

					FILE *in = fopen(filename.c_str(), "rb");
					g.handleLoading(in);
					fclose(in);
					level = g.level;
					s = 1;

					ResumeThread(t1.native_handle());
					ResumeThread(t2.native_handle());
					ResumeThread(t3.native_handle());
				}

				while (!g.playerIsDead()) {
					MOVING = _getch();
					if (MOVING == 'l') {
						SuspendThread(t1.native_handle());
						SuspendThread(t2.native_handle());
						SuspendThread(t3.native_handle());

						g.saveGame();
						ResumeThread(t1.native_handle());
						ResumeThread(t2.native_handle());
						ResumeThread(t3.native_handle());			
						continue;
					}
					if (MOVING == 't') {
						SuspendThread(t1.native_handle());
						SuspendThread(t2.native_handle());
						SuspendThread(t3.native_handle());

						g.loadGame();
						level = g.level;

						ResumeThread(t1.native_handle());
						ResumeThread(t2.native_handle());
						ResumeThread(t3.native_handle());
						continue;
					}
					g.movePlayer(MOVING);
				}

				t1.join();
				t2.join();
				t3.join();

				MOVING = _getch();
				if (!g.WON) {
					while (MOVING != 'y' && MOVING != 'n')
						MOVING = _getch();
					g.checkOut(MOVING);
					level = 1;
				}
				else 
					level = (level < MAX_LEVEL) ? level + 1 : 1;
			} while (!g.isFinish());

			break;
		case 3: 
			system("cls");
			textcolor(15);
			drawRectangle(75, 17, 19, 8);
			settings(level, sound, 1); 
			break;
		case 4: break;
		default: break;
		}
	}
}
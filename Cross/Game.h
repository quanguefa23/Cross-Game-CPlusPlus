#pragma once
#include "libs.h"
#include "Truck.h"
#include "Car.h"
#include "Bird.h"
#include "Dinausor.h"
#include "People.h"
#include "Redlight.h"
#include "Random.h"

class Game {
private:
	vector<Vehicle*> veh[4];
	vector<Animal*> ani[4];
	Redlight RLveh[4];
	Redlight RLani[4];
	People player;
	bool state;
	bool sound;
	bool flag[WIDTH][HEIGHT];
public:
	int level;
	bool WON;
private:
	void handleWin();
	void drawBackground();
	void drawElement();
	void drawFlag();
	void handleCollision(int, int);
	void deleteVectors();
	void initial(int l, bool);
public:
	Game(int, bool);
	void playGame();
	void changeRedlight();
	bool isFinish() { return !state; }
	void drawGame();
	void moveElement();
	void movePlayer(char const &);
	bool playerIsDead() { return player.isDead(); }
	void reset(int, bool);
	void checkOut(char const &);
	void handleLoading(FILE *&in);
	void saveGame();
	void loadGame();
	~Game();
};


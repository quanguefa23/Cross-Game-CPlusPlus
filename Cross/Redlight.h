#pragma once
#include "libs.h"
#define RED 0
#define GREEN 1

class Redlight {
private:
	int _X, _Y;
	bool _color;
	bool flagColor; //1 if need to redraw redlight
public:
	Redlight();
	Redlight(int, int, bool);
	void setFlagColor(bool f) { flagColor = f; }
	void draw();
	void redraw();
	void changeColor(); //change color and draw again
	void save(FILE *&);
	bool currentStatus() { return _color; }
	~Redlight();
};


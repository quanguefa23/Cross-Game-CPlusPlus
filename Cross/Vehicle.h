#pragma once
#include "libs.h"
#include "People.h"

class Vehicle {
protected:
	int _X, _Y;
	bool _type;
	bool flagMove;
public:
	Vehicle();
	Vehicle(int, int, bool);
	virtual void draw(bool flag[WIDTH][HEIGHT]) = 0;
	virtual void clear(bool flag[WIDTH][HEIGHT]) = 0;
	bool redrawAndCheck(bool flag[WIDTH][HEIGHT], People &);
	void move();
	void save(FILE *&);
	virtual ~Vehicle();
};
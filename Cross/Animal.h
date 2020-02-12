#pragma once
#include "People.h"
#include "libs.h"

class Animal {
protected:
	int _X, _Y;
	bool _type;
	bool flagMove; //1 if need to redraw
public:
	Animal();
	Animal(int, int, bool);
	virtual void draw(bool flag[WIDTH][HEIGHT]) = 0;
	virtual void clear(bool flag[WIDTH][HEIGHT]) = 0;
	void move();
	void save(FILE *&);
	bool redrawAndCheck(bool flag[WIDTH][HEIGHT], People &);
	virtual ~Animal();
};


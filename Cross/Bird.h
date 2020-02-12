#pragma once
#include "Animal.h"

class Bird : public Animal {
public:
	void draw(bool flag[WIDTH][HEIGHT]);
	void clear(bool flag[WIDTH][HEIGHT]);
	Bird();
	Bird(int, int, bool);
	~Bird();
};

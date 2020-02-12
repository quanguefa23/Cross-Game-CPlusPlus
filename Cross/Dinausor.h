#pragma once
#include "Animal.h"

class Dinausor : public Animal {
public:
	void draw(bool flag[WIDTH][HEIGHT]);
	void clear(bool flag[WIDTH][HEIGHT]);
	Dinausor();
	Dinausor(int, int, bool);
	~Dinausor();
};


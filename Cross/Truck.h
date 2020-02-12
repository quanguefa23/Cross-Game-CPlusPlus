#pragma once
#include "Vehicle.h"

class Truck : public Vehicle {
public:
	void draw(bool flag[WIDTH][HEIGHT]);
	void clear(bool flag[WIDTH][HEIGHT]);
	Truck();
	Truck(int, int, bool);
	~Truck();
};


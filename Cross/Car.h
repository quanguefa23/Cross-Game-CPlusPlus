#pragma once
#include "Vehicle.h"

class Car : public Vehicle {
public:
	void draw(bool flag[WIDTH][HEIGHT]);
	void clear(bool flag[WIDTH][HEIGHT]);
	Car();
	Car(int, int, bool);
	~Car();
};



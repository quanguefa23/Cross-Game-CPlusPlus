#pragma once
#include <time.h>
#include <iostream>
using namespace std;

class Random {
public:
	Random();
	~Random();
	int Next();
	int Next(int max);
};


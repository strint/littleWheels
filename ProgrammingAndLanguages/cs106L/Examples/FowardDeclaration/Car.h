#pragma once
#include "Wheel.h"
#include <vector>

class Car
{
public:
	Car(int i);
	~Car(void);
	void Run();

	int id;
	std::vector<Wheel> wheels;
};


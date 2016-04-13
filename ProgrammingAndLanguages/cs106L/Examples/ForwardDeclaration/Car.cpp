#include "Car.h"
#include <iostream>


Car::Car(int i) : id(i)
{
	for(size_t i = 0; i < 4; ++i) {
		Wheel w;
		w.car = this;
		wheels.push_back(w);
	}
}


Car::~Car(void)
{
}

void Car::Run(void) {
	for(size_t i = 0; i < wheels.size(); ++i) {
		wheels[i].Run();
	}
	std::cout << "Car " << id << " run." << std::endl;	
}

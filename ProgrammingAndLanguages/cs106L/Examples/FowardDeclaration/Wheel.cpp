#include "Wheel.h"
#include "Car.h" //在这里引用需要的头文件，调用类方法
#include <iostream>

int Wheel::count = 0;

Wheel::Wheel(void)
{
	id = count;
	++count;
}


Wheel::~Wheel(void)
{
}

void Wheel::Run(void) {
	std::cout << "wheel " << id << " run for car " << car->id << std::endl;
}

#pragma once
#include "Car.h"

class Mazda : public Car
{
public:
	Mazda();
	~Mazda();
	void set_fuel_capacity(int value);
	void set_fuel_consumption(int value);
};
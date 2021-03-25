#pragma once
#include "Car.h"

class Dacia : public Car
{
public:
	Dacia();
	~Dacia();
	void set_fuel_capacity(int value);
	void set_fuel_consumption(int value);
};
#pragma once
#include "Car.h"

class Toyota : public Car
{
public:
	Toyota();
	~Toyota();
	void set_fuel_capacity(int value);
	void set_fuel_consumption(int value);
};
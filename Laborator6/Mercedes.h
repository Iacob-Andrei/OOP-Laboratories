#pragma once
#include "Car.h"

class Mercedes : public Car
{
public:
	Mercedes();
	~Mercedes();
	void set_fuel_capacity(int value);
	void set_fuel_consumption(int value);
};
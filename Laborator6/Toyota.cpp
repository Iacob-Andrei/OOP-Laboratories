#define _CRT_SECURE_NO_WARNINGS
#include "Toyota.h"

Toyota::Toyota()
{
	name = new char[strlen("Toyota") + 1];
	memcpy(name, "Toyota", strlen("Toyota") + 1);
	speed_sunny = 65;
	speed_rainy = 50;
	speed_snowy = 45;
	fuel_consumption = 15;
	fuel_capacity = 28;
}

Toyota::~Toyota()
{
	delete[] name;
}

void Toyota::set_fuel_capacity(int value)
{
	fuel_capacity = value;
}

void Toyota::set_fuel_consumption(int value)
{
	fuel_consumption = value;
}
#define _CRT_SECURE_NO_WARNINGS
#include "Mazda.h"

Mazda::Mazda()
{
	name = new char[strlen("Mazda") + 1];
	memcpy(name, "Mazda", strlen("Mazda") + 1);
	speed_sunny = 110;
	speed_rainy = 70;
	speed_snowy = 55;
	fuel_consumption = 30;
	fuel_capacity = 45;
}

Mazda::~Mazda()
{
	delete[] name;
}

void Mazda::set_fuel_capacity(int value)
{
	fuel_capacity = value;
}

void Mazda::set_fuel_consumption(int value)
{
	fuel_consumption = value;
}
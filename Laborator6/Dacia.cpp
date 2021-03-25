#define _CRT_SECURE_NO_WARNINGS
#include "Dacia.h"

Dacia::Dacia()
{
	name = new char[strlen("Dacia") + 1];
	memcpy(name, "Dacia", strlen("Dacia") + 1);
	speed_sunny = 43;
	speed_rainy = 40;
	speed_snowy = 35;
	fuel_consumption = 45;
	fuel_capacity = 30;
}

Dacia::~Dacia()
{
	delete[] name;
}

void Dacia::set_fuel_capacity(int value)
{
	fuel_capacity = value;
}

void Dacia::set_fuel_consumption(int value)
{
	fuel_consumption = value;
}
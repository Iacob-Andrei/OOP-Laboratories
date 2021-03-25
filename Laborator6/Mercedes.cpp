#define _CRT_SECURE_NO_WARNINGS
#include "Mercedes.h"

Mercedes::Mercedes()
{
	name = new char[strlen("Mercedes") + 1];
	memcpy(name, "Mercedes", strlen("Mercedes") + 1);
	speed_sunny = 80;
	speed_rainy = 80;
	speed_snowy = 65;
	fuel_consumption = 25;
	fuel_capacity = 25;
}

Mercedes::~Mercedes()
{
	delete[] name;
}

void Mercedes::set_fuel_capacity(int value)
{
	fuel_capacity = value;
}

void Mercedes::set_fuel_consumption(int value)
{
	fuel_consumption = value;
}
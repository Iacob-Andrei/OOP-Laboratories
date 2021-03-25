#pragma once
#include<iostream>

class Car
{
protected:
	int fuel_capacity;
	int fuel_consumption;
	int speed_sunny;
	int speed_rainy;
	int speed_snowy;
	char* name;

public:
	virtual void set_fuel_capacity(int value) = 0;
	virtual void set_fuel_consumption(int value) = 0;
	
	void get_name() { std::cout << name; }
	int get_fuel_capacity() { return fuel_capacity; }
	int get_fuel_consumption() { return fuel_consumption; }
	int speed(int val)
	{
		if (val == 0) return speed_sunny;
		else
			if (val == 1) return speed_rainy;
			else
				return speed_snowy;
	}
};
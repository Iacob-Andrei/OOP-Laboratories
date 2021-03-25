#include "Circuit.h"
#include <malloc.h>
#include<iostream>

void Circuit::Set_Length(int value)
{
	length = value;
}

void Circuit::Add_Car(Car* new_car)
{
	if (car_count == 0) 
	{
		car_count++;
		car_list = (Car**)malloc(sizeof(Car*) * car_count);
		car_list[0] = new_car;
	}
	else
	{
		car_count++;
		car_list = (Car**)realloc(car_list, sizeof(Car*) * car_count);
		car_list[car_count - 1] = new_car;
		
	}

}

void Circuit::Set_Weather(Weather vreme)
{
	this->vreme = vreme;
}

void Circuit::Race()
{
	lim_finish = 0;
	Car* aux;
	
	for (int i = 0; i < car_count; ++i)
	{
		int consum = car_list[i]->get_fuel_consumption();
		int combustibil = car_list[i]->get_fuel_capacity();
		float neccesary_fuel = length * consum / 100;

		if (neccesary_fuel <= combustibil)
		{
			aux = car_list[lim_finish];
			car_list[lim_finish] = car_list[i];
			car_list[i] = aux;
			lim_finish++;
		}
	}

	for (int i = 0; i < lim_finish - 1; i++) 
		for (int j = 0; j < lim_finish - i - 1; j++)
		{
			float timp1 = 1.0 * length / car_list[j]->speed(vreme);
			float timp2 = 1.0 * length / car_list[j + 1]->speed(vreme);
			if (timp1 > timp2)
			{
				aux = car_list[j];
				car_list[j] = car_list[j + 1];
				car_list[j + 1] = aux;
			}	
		}
}

void Circuit::Show_Final_Ranks()
{
	for (int i = 0; i < lim_finish; ++i)
	{
		std::cout << "Locul " << i + 1 << " ";
		car_list[i]->get_name();
		std::cout << " a terminat in: ";
		int viteza = car_list[i]->speed(vreme);
		float time = (float)this->length / (float)viteza;
		std::cout << time;
		std::cout << std::endl;
	}
}

void Circuit::Show_Consumption_Ranks()
{
	Car* aux;
	for (int i = 0; i < car_count - 1; i++)
		for (int j = 0; j <car_count - i - 1; j++)
		{
			int consum1 = car_list[j]->get_fuel_consumption();
			int consum2 = car_list[j + 1]->get_fuel_consumption();
			if (consum1 > consum2)
			{
				aux = car_list[j];
				car_list[j] = car_list[j + 1];
				car_list[j + 1] = aux;
			}
		}

	for (int i = 0; i < car_count ; i++)
	{
		car_list[i]->get_name();
		std::cout << " are consumul de " << car_list[i]->get_fuel_consumption();
		std::cout << std::endl;
	}
}

void Circuit::Show_Who_Did_Not_Finish()
{
	if (lim_finish == car_count)
		std::cout << "Toate masinile au terminat curs!";
	else
		for (int i = lim_finish; i < car_count; ++i)
		{
			car_list[i]->get_name();
			std::cout << " nu a temrinat cursa." << std::endl;
		}
}

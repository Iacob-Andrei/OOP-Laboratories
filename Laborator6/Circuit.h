#pragma once
#include "Car.h"

enum Weather {
	sunny, rainy, snowy
};

class Circuit
{
	int length = 0;
	Weather vreme;
	Car** car_list;
	int car_count = 0;
	int lim_finish = 0;
	
public:
	~Circuit() { delete[] car_list; }
	void Add_Car(Car* nou);
	void Set_Length(int lenght);
	void Set_Weather(Weather vreme);
	void Race();
	void Show_Final_Ranks();
	void Show_Consumption_Ranks();
	void Show_Who_Did_Not_Finish();
};
#include "Circuit.h"
#include "Car.h"
#include "Dacia.h"
#include "Mazda.h"
#include "Toyota.h"
#include "Mercedes.h"
#include <iostream>

int main()
{
	Circuit c;
	c.Set_Length(100);
	c.Set_Weather(Weather::sunny);
	c.Add_Car(new Dacia());
	c.Add_Car(new Mazda());
	c.Add_Car(new Mercedes());
	c.Add_Car(new Toyota());
	c.Race();
	c.Show_Final_Ranks();
	c.Show_Who_Did_Not_Finish();
	c.Show_Consumption_Ranks();

	return 0;
}
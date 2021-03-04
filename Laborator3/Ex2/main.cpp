#include "Canvas.h"

int main()
{
	Canvas Forma(30, 30);

	//Forma.FillCircle(15, 15, 10, 'x'); Forma.Print();
	//Forma.DrawCircle(15, 15, 10, 'x'); Forma.Print();
	//Forma.SetPoint(12, 13, 'q');       Forma.Print();
	//Forma.FillRect(5, 5, 20, 10, 'x'); Forma.Print();
	//Forma.DrawRect(5, 5, 20, 10, 'x'); Forma.Print();
	Forma.DrawLine(10, 1, 1, 10, 'x'); Forma.Print();

	return 0;
}
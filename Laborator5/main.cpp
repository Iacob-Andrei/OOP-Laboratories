#include "Number.h"
#include<iostream>

int main()
{
	
	Number n1("F5", 16);
	//n1.Print();
	n1.SwitchBase(2);
	//n1.Print();

	Number n2("101", 5);
	n2.Print();

	if (n1 > n2)
		std::cout << "n1 are valoarea mai mare decat n2" << '\n';
	else
		std::cout << "n2 are valoarea mai mare decat n1" << '\n';

	std::cout << n2[2] << '\n';
	
	Number n3("45", 6);
	n3 += n2;
	//n3.Print();

	Number n4("135", 10);
	--n4;					// elimina cel mai din dreapta bit
	//n4.Print();

	Number n5("456", 10);	// elimina cel mai din stanga bit
	n5--;
	//n5.Print();

	Number n6 = 45;
	//n6.Print();

	n6 = 60;
	//n6.Print();
	
	n4 = n6 + n5;		// 60 + 56
	//n4.Print();

	n4 = n6 - n5;		// 60 - 56
	//n4.Print();
	
	
	n2 = n1 | n2;
	n2.Print();

	return 0;
}
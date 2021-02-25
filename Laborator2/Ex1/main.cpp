#include "NumberList.h"
#include<iostream>
using namespace std;

int main()
{
	NumberList Lista;
	Lista.Init();

	Lista.Add(5);
	Lista.Add(7);
	Lista.Add(2);
	Lista.Add(2);
	Lista.Add(3);

	Lista.Sort();
	Lista.Print();

	if (Lista.Insert(3, 4))
		Lista.Print();
	else
		std::cout << "Lista plina!" << '\n';

	Lista.RemoveAllElements(2);
	Lista.Print();

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string.h>
#include "Math.h"

int main()
{
	std::cout << Math::Add(2, 5) << '\n';
	std::cout << Math::Add(3, 4, 5) << '\n';
	std::cout << Math::Add(2.5, 3.4) << '\n';
	std::cout << Math::Add(2.5, 3.2,1.5) << '\n';

	std::cout << Math::Mul(2, 5) << '\n';
	std::cout << Math::Mul(3, 4, 5) << '\n';
	std::cout << Math::Mul(2.5, 3.4) << '\n';
	std::cout << Math::Mul(2.5, 3.2, 1.5) << '\n';

	std::cout << Math::Add(7, 1, 5, 6, 8, 7, 6, 8) << '\n';
	
	if (Math::Add("125", nullptr) == nullptr) std::cout << "Eroare" << '\n';

	std::cout<<Math::Add("90", "10");

	return 0;
}
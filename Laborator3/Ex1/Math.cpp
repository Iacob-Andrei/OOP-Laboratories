#define _CRT_SECURE_NO_WARNINGS

#include "Math.h"
#include <cstring>
#include <iostream>
#include <cstdarg>


int Math::Add(int x, int y)
{
	return x + y;
}

int Math::Add(int x, int y, int z)
{
	return x + y + z;
}

double Math::Add(double x, double y)
{
	return x + y;
}

double Math::Add(double x, double y, double z)
{
	return x + y + z;
}

int Math::Mul(int x, int y)
{
	return x* y;
}

int Math::Mul(int x, int y, int z)
{
	return x* y* z;
}

double Math::Mul(double x, double z)
{
	return x * z;
}

double Math::Mul(double x, double y, double z)
{
	return x * y * z;
}

int Math::Add(int count, ...)
{
	int val, suma = 0;
	va_list vl;
	va_start(vl, count);

	for (int i = 0; i < count; ++i)
	{
		val = va_arg(vl, int);
		suma += val;
	}
	va_end(vl);
	return suma;
}

const char* Math::Add(const char* sir1, const char* sir2)
{
	if (sir1 == nullptr || sir2 == nullptr)
		return nullptr;

	int cifra1, cifra2, cifra3, rest = 0, lungime_sir_1, lungime_sir_2, lungime_noua, lungime_nou_2;
	char* sir3 = new char[25];

	lungime_sir_1 = strlen(sir1) - 1;
	lungime_sir_2 = strlen(sir2) - 1;



	if (lungime_sir_1 >= lungime_sir_2)
		lungime_noua = lungime_sir_1;
	else
		lungime_noua = lungime_sir_2;

	lungime_nou_2 = lungime_noua;



	while (lungime_sir_1 >= 0 && lungime_sir_2 >= 0)
	{
		cifra1 = sir1[lungime_sir_1] - '0';
		cifra2 = sir2[lungime_sir_2] - '0';
		cifra3 = cifra1 + cifra2 + rest;

		if (cifra3 > 9)
		{
			rest = 1;
			cifra3 = cifra3 - 10;
		}
		else
			rest = 0;

		sir3[lungime_noua] = '0' + cifra3;
		lungime_sir_1--;
		lungime_sir_2--;
		lungime_noua--;
	}

	if (lungime_sir_1 < 0 && lungime_sir_2 >= 0)
		while (lungime_sir_2 >= 0)
		{
			cifra2 = sir2[lungime_sir_2] - '0';
			cifra3 = cifra2 + rest;
			if (cifra3 > 9)
			{
				rest = 1;
				cifra3 = cifra3 - 10;
			}
			else
				rest = 0;

			sir3[lungime_noua] = '0' + cifra3;
			lungime_noua--;
			lungime_sir_2--;
		}

	if (lungime_sir_2 < 0 && lungime_sir_1 >= 0)
		while (lungime_sir_1 >= 0)
		{
			cifra1 = sir1[lungime_sir_1] - '0';
			cifra3 = cifra1 + rest;

			if (cifra3 > 9)
			{
				rest = 1;
				cifra3 = cifra3 - 10;
			}
			else
				rest = 0;

			sir3[lungime_noua] = '0' + cifra3;
			lungime_noua--;
			lungime_sir_1--;
		}

	sir3[lungime_nou_2 + 1] = '\0';
	
	if (rest != 0)
	{
		for (int i = lungime_nou_2 + 1; i >= 0; i--)
			sir3[i + 1] = sir3[i];
		sir3[0] = '1';
	}

	return sir3;
}
#define _CRT_SECURE_NO_WARNINGS
#include "Number.h"
#include<cstring>
#include<iostream>
#include<stdio.h>

Number::Number(const char * value, int baza)
{
	number = new char[strlen(value) + 1];
	memcpy(number, value, strlen(value) + 1);
	base = baza;
	nr = 0;

	int power = 1 ;
	for (int i = strlen(number) - 1; i >= 0; i--)
	{
		if (baza <= 10)
			nr += power * (number[i] - '0');
		else
		{
			if (number[i] == 'A')
				nr += power * 10;
			else
				if (number[i] == 'B')
					nr += power * 11;
			else
				if (number[i] == 'C')
					nr += power * 12;
			else
				if (number[i] == 'D')
					nr += power * 13;
			else
				if (number[i] == 'E')
					nr += power * 14;
			else
				if(number[i] == 'F')
					nr += power * 15;
			else
				nr += power * (number[i] - '0');
		}
		power = power * baza;
	}
}

Number::Number(int value)
{
	nr = value;
	base = 10;
	char sir[33];
	_itoa(value, sir, 10);
	number = new char[strlen(sir) + 1];
	memcpy(number, sir, strlen(sir) + 1);
}

Number::~Number()
{
	if (number != NULL)
	{
		delete[] number;
		number = nullptr;
	}
}

bool Number::operator>(Number& value)
{
	if (this->number > value.number)
		return true;
	else
		return false;
}

char Number::operator [] (int index)
{
	if ((unsigned)index > strlen(number))
		return 'X';

	return this->number[index];
}

void Number::operator = (int value)
{
	nr = value;
	base = 10;
	char sir[33];
	_itoa(value, sir, 10);
	number = new char[strlen(sir) + 1];
	memcpy(number, sir, strlen(sir) + 1);
}

void operator += (Number &value1, Number &value2)
{
	if (value1.base < value2.base)
		value1.base = value2.base;

	value1.nr = value1.nr + value2.nr;
	int aux = value1.nr;
	
	char number_nou[25];
	int i = 0;

	while (aux)
	{
		int r = aux % value1.base;
		aux /= value1.base;

		if (r == 10)
			number_nou[i] = 'A';
		else
			if (r == 11)
				number_nou[i] = 'B';
		else
			if (r == 12)
				number_nou[i] = 'C';
		else
			if (r == 13)
				number_nou[i] = 'D';
		else
			if (r == 14)
				number_nou[i] = 'E';
		else
			if (r == 15)
				number_nou[i] = 'F';
		else
				number_nou[i] = r + '0';
		i++;
	}
	number_nou[i] = '\0';

	for (int j = 0; j < i / 2; j++)
	{
		char copie = number_nou[j];
		number_nou[j] = number_nou[i - j - 1];
		number_nou[i - j - 1] = copie;
	}

	value1.number = new char[strlen(number_nou) + 1];
	memcpy(value1.number, number_nou, strlen(number_nou) + 1);
}

// remove the first (most significant digit) from the number
void Number::operator -- (int value)
{
	nr = 0;
	for (unsigned int i = 0; i < strlen(number); i++)
		number[i] = number[i + 1];

	int power = 1;
	for (int i = strlen(number) - 1; i >= 0; i--)
	{
		if (base <= 10)
			nr += power * (number[i] - '0');
		else
		{
		if (number[i] == 'A')
			nr += power * 10;
		else
			if (number[i] == 'B')
				nr += power * 11;
		else
			if (number[i] == 'C')
				nr += power * 12;
		else
			if (number[i] == 'D')
				nr += power * 13;
		else
			if (number[i] == 'E')
				nr += power * 14;
		else
			if (number[i] == 'F')
				nr += power * 15;
		else
			nr += power * (number[i] - '0');
		}

		power = power * base;
	}

}

// remove the last (least significant) digit from the number
void Number::operator -- ()		
{
	number[strlen(number) - 1] = '\0';
	nr = 0;

	int power = 1;
	for (int i = strlen(number) - 1; i >= 0; i--)
	{
		if (base <= 10)
			nr += power * (number[i] - '0');
		else
		{
			if (number[i] == 'A')
				nr += power * 10;
		else
			if (number[i] == 'B')
				nr += power * 11;
		else
			if (number[i] == 'C')
				nr += power * 12;
		else
			if (number[i] == 'D')
				nr += power * 13;
		else
			if (number[i] == 'E')
				nr += power * 14;
		else
			if (number[i] == 'F')
				nr += power * 15;
		else
			nr += power * (number[i] - '0');
		}

		power = power * base;
	}
}

void Number::SwitchBase(int baza)
{
	int aux = nr;
	base = baza;
	delete[] number;

	char number_nou[25];
	int i = 0;
	while (aux)
	{
		int r = aux % baza;
		aux /= baza;

		if (r == 10)
			number_nou[i] = 'A';
		else
			if (r == 11)
				number_nou[i] = 'B';
			else
				if (r == 12)
					number_nou[i] = 'C';
				else
					if (r == 13)
						number_nou[i] = 'D';
					else
						if (r == 14)
							number_nou[i] = 'E';
						else
							if (r == 15)
								number_nou[i] = 'F';
							else
								number_nou[i] = r + '0';
		i++;
	}
	number_nou[i] = '\0';
	
	for(int j = 0 ; j < i/2 ; j++)
	{
		char copie = number_nou[j];
		number_nou[j] = number_nou[i - j - 1];
		number_nou[i - j - 1] = copie;
	}

	number = new char[i + 1];
	memcpy(number, number_nou, i + 1);
}

void Number::Print()
{
	std::cout << "Numarul " << nr << " scris in baza " << base << " este: " << number << '\n';
}

int Number::GetBase()
{
	return base;
}

int Number::GetDigitsCount()
{
	return strlen(number);
}

Number operator + (Number& value1, Number& value2)
{
	int suma = value1.nr + value2.nr;
	int newbase = value1.base;
	int aux = suma;

	if (value1.base < value2.base)
		newbase = value2.base;

	char number_nou[25];
	int i = 0;

	while (aux)
	{
		int r = aux % newbase;
		aux /= newbase;

		if (r == 10)
			number_nou[i] = 'A';
		else
			if (r == 11)
				number_nou[i] = 'B';
		else
			if (r == 12)
				number_nou[i] = 'C';
		else
			if (r == 13)
				number_nou[i] = 'D';
		else
			if (r == 14)
				number_nou[i] = 'E';
		else
			if (r == 15)
				number_nou[i] = 'F';
		else
				number_nou[i] = r + '0';
		i++;
	}
	number_nou[i] = '\0';

	for (int j = 0; j < i / 2; j++)
	{
		char copie = number_nou[j];
		number_nou[j] = number_nou[i - j - 1];
		number_nou[i - j - 1] = copie;
	}

	return Number(number_nou, newbase);
}

Number operator - (Number& value1, Number& value2)
{
	int suma = abs(value1.nr - value2.nr);
	int newbase = value1.base;
	int aux = suma;

	if (value1.base < value2.base)
		newbase = value2.base;

	char number_nou[25];
	int i = 0;

	while (aux)
	{
		int r = aux % newbase;
		aux /= newbase;

		if (r == 10)
			number_nou[i] = 'A';
		else
			if (r == 11)
				number_nou[i] = 'B';
			else
				if (r == 12)
					number_nou[i] = 'C';
				else
					if (r == 13)
						number_nou[i] = 'D';
					else
						if (r == 14)
							number_nou[i] = 'E';
						else
							if (r == 15)
								number_nou[i] = 'F';
							else
								number_nou[i] = r + '0';
		i++;
	}
	number_nou[i] = '\0';

	for (int j = 0; j < i / 2; j++)
	{
		char copie = number_nou[j];
		number_nou[j] = number_nou[i - j - 1];
		number_nou[i - j - 1] = copie;
	}

	return Number(number_nou, newbase);
}

void Number::operator = ( const Number& value)
{
	this->nr = value.nr;
	this->base = value.base;

	number = new char[strlen(value.number)+1];
	memcpy(number, value.number, strlen(value.number) + 1);
}

Number Number::operator|(Number& value)
{
	int aux = value.nr;
	int concat = this->nr;
	while (aux)
	{
		concat *= 10;
		aux /= 10;
	}
	concat = concat + value.nr;

	char number_nou[25];
	int i = 0;
	aux = concat;
	int newbase = std::max(this->base, value.base);

	while (aux)
	{
		int r = aux % newbase;
		aux /= newbase;

		if (r == 10)
			number_nou[i] = 'A';
		else
			if (r == 11)
				number_nou[i] = 'B';
			else
				if (r == 12)
					number_nou[i] = 'C';
				else
					if (r == 13)
						number_nou[i] = 'D';
					else
						if (r == 14)
							number_nou[i] = 'E';
						else
							if (r == 15)
								number_nou[i] = 'F';
							else
								number_nou[i] = r + '0';
		i++;
	}
	number_nou[i] = '\0';

	for (int j = 0; j < i / 2; j++)
	{
		char copie = number_nou[j];
		number_nou[j] = number_nou[i - j - 1];
		number_nou[i - j - 1] = copie;
	}

	return Number(number_nou, newbase);
}
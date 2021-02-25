#pragma once

#include<iostream>
#include "NumberList.h"

void NumberList::Init()
{
	this->count = 0;
	for (int i = 1; i < 10; i++)
		this->numbers[i] = 0;
}

bool NumberList::Add(int x)
{
	if (this->count >= 10) 
		return false;

	this->numbers[ this->count ] = x;
	this->count++;
	return true;
}

void NumberList::Sort()
{
	int i, j, aux ;

	for (i = 0; i < this->count - 1 ; i++)
		for (j = 0; j < this->count - i - 1 ; j++)
			if (this->numbers[j] > this->numbers[j + 1])
			{
				aux = this->numbers[j];
				this->numbers[j] = this->numbers[j + 1];
				this->numbers[j + 1] = aux;
			}
}

void NumberList::Print()
{
	for (int i = 0; i < this->count; ++i)
	{
		std::cout << this->numbers[i] << " ";
	}
	std::cout << '\n';
}

void NumberList::RemoveAllElements(int x)
{
	for (int i = 0; i < this->count; ++i)
	{
		if ( this->numbers[i] == x)
		{
			for (int j = i; j < this->count - 1; ++j)
				this->numbers[j] = this->numbers[j + 1];

			this->count--;
			i--;
		}
	}
}

bool NumberList::Insert(int pozitie, int x)
{
	if (this->count >= 10) 
		return false;

	for (int i = count; i > pozitie; i--)
	{
		this->numbers[i] = this->numbers[i - 1];
	}
	this->numbers[pozitie] = x;
	this->count++;
	return true;
}
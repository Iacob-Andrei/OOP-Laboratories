#pragma once

class Number
{
	int nr;
	int base;
	char* number;

public:
	Number(const char* value, int baza); 
	Number(int value);
	~Number();

	friend Number operator + (Number& value1 , Number& value2);
	friend Number operator - (Number &value1, Number &value2);
	friend void operator += (Number &value1, Number &value2);
	
	Number operator|(Number& value);
	void operator = ( const Number& value);
	void operator = (int value);
	bool operator > (Number& value);
	char operator [] (int index);

	void operator -- ();					// apelez ca --n
	void operator -- (int value);			// apelez ca n--

	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); 
	int  GetBase(); 
};
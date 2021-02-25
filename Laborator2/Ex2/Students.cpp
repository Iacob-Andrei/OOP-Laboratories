#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstring>
#include "Students.h"

Student::Student()
{
	this->GradeMath = 0;
	this->GradeEng = 0;
	this->GradeHis = 0;
}

bool Student::CheckValid(float nota)
{
	if (nota < 1 || nota > 10)
		return false;
	return true;
}

void Student::SetName(char nume[25])
{
	strcpy(this->name, nume);
}

char* Student::GetName()
{
	return this->name;
}

void Student::SetGradeMath(float nota)
{
	if ( !CheckValid(nota) )
	{
		std::cout << "Nota incorecta! ";
		return;
	}

	this->GradeMath = nota;
}

float Student::GetGradeMath()
{
	return this->GradeMath;
}

void Student::SetGradeEng(float nota)
{
	if ( !CheckValid(nota) )
	{
		std::cout << "Nota incorecta! ";
		return;
	}

	this->GradeEng = nota;
}

float Student::GetGradeEng()
{
	return this->GradeEng;
}

void Student::SetGradeHis(float nota)
{
	if ( !CheckValid(nota) )
	{
		std::cout << "Nota incorecta! ";
		return;
	}

	this->GradeHis = nota;
}

float Student::GetGradeHis()
{
	return this->GradeHis;
}

float Student::AvgGrade()
{
	return (this->GradeEng + this->GradeHis + this->GradeMath) / 3;
}
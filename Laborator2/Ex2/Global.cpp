#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstring>
#include "Students.h"

int Student::CompareName(Student* p1, Student* p2)
{
	int var = strcmp(p1->name, p2->name);
	if (var == 0)
		return 0;
	else if (var > 0)
		return -1;
	else
		return 1;
}

int Student::CompareGradeMath(Student* p1, Student* p2)
{
	if (p1->GradeMath == p2->GradeMath)
		return 0;
	else if (p1->GradeMath > p2->GradeMath)
		return 1;
	else
		return -1;
}

int Student::CompareGradeEng(Student* p1, Student* p2)
{
	if (p1->GradeEng == p2->GradeEng)
		return 0;
	else if (p1->GradeEng > p2->GradeEng)
		return 1;
	else
		return -1;
}

int Student::CompareGradeHis(Student* p1, Student* p2)
{
	if (p1->GradeHis == p2->GradeHis)
		return 0;
	else if (p1->GradeHis > p2->GradeHis)
		return 1;
	else
		return -1;
}

int Student::CompareAvgGrade(Student* p1, Student* p2)
{
	if (p1->AvgGrade() == p2->AvgGrade())
		return 0;
	else if (p1->AvgGrade() > p2->AvgGrade())
		return 1;
	else
		return -1;
}
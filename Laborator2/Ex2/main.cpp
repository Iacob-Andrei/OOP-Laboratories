#include<iostream>
#include "Students.h"


int main()
{
	Student Elev, Elev2 ;

	Elev2.SetName((char*)"Andra");
	Elev2.SetGradeMath(6);
	Elev2.SetGradeEng(9.3f);
	Elev2.SetGradeHis(7.2f);

	std::cout << "Date primul elev:" << '\n';
	Elev.SetName((char*)"Ionica");
	std::cout << Elev.GetName() << '\n';

	Elev.SetGradeMath(10);
	std::cout << Elev.GetGradeMath() << '\n' ;

	Elev.SetGradeEng(8.3f);
	std::cout << Elev.GetGradeEng() << '\n' ;

	Elev.SetGradeHis(6.6f);
	std::cout << Elev.GetGradeHis() << '\n' ;

	std::cout << Elev.AvgGrade() << '\n' << '\n' ;

	std::cout << "Comparari:" << '\n';
	std::cout << "Nume: "<< Student::CompareName( &Elev, &Elev2 ) << '\n' ;          // Compar "Ionica" cu "Andra"
	std::cout << "Nota mate: " << Student::CompareGradeMath(&Elev, &Elev2) << '\n' ;

	return 0;
}
#pragma once

class Student {
private:
	char name[25];
	float GradeMath;
	float GradeEng;
	float GradeHis;
	bool CheckValid(float nota);

public:
	Student();
	void SetName(char nume[25]);
	char* GetName();
	void SetGradeMath(float nota);
	float GetGradeMath();
	void SetGradeEng(float nota);
	float GetGradeEng();
	void SetGradeHis(float nota);
	float GetGradeHis();
	float AvgGrade();

	static int CompareName( Student *p1 , Student *p2 );
	static int CompareGradeMath(Student* p1, Student* p2);
	static int CompareGradeEng(Student* p1, Student* p2);
	static int CompareGradeHis(Student* p1, Student* p2);
	static int CompareAvgGrade(Student* p1, Student* p2);

};

#include "Sort.h"
#include<iostream>


int main()
{
	
	// lista cu initialization list
	Sort l;
	std::cout << "Lista nesortata declarata prin initialization list: ";
	l.Print();

	// lista cu min/max
	Sort l1(7, 10, 30);
	std::cout << "Lista nesortata cu valori random:  ";
	l1.Print();
	
	// lista din tablou unidimensional
	int v[6] = { 45,2,8,32,5,77 };
	Sort l2(6, v);
	l2.InsertSort();
	std::cout << "Lista sortata crescator cu InsertionSort:  ";
	l2.Print();

	//lista cu v_start
	Sort l3(4, 5, 6, 7, 9);
	l3.BubbleSort();
	std::cout << "Lista sortata descrescator cu Bubbblesort:  ";
	l3.Print();

	// lista cu const char*
	Sort l4("45,2,6,22,35,78,9,10,10,78,78");
	l4.QuickSort(false);
	std::cout << "Lista sortata cu Quicksort:  ";
	l4.Print();
	l4.GetElementsCount();
	

	Sort s4("45,2,6,22,78");	   // initializare cu const char*
	Sort s5(4, 5, 6, 7, 9);        // initializare cu ...
	s4.Merge(s5);
	s4.Print();
	
	return 0;
}
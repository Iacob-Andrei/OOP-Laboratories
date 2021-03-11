#include "Sort.h"
#include<random>
#include<iostream>
#include<cstdarg>

Sort::~Sort()
{
	if (lista != NULL)
		delete[] lista;
}

Sort::Sort(int number, int mini, int maxi)
{
	lista = new int[number];
	count = number;

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distr(mini, maxi);
	
	for (int i = 0; i < number; i++)
		//lista[i] = mini + (std::rand() % (maxi - mini + 1));
		lista[i] = distr(gen);

	stanga = 0;
	dreapta = count - 1;
}

Sort::Sort(int number, int v[])
{
	lista = new int[number];
	count = number;

	for (int i = 0; i < number; i++)
		lista[i] = v[i];

	stanga = 0;
	dreapta = count - 1;
}

Sort::Sort(int number, ...)
{
	lista = new int[number];
	count = number;

	va_list v1;
	va_start(v1, number);

	for (int i = 0; i < number; i++)
		lista[i] = va_arg(v1, int);

	stanga = 0;
	dreapta = count - 1;
}

Sort::Sort(const char* sir)
{
	count = 1;
	int i = 0;

	while (sir[i] != NULL)
	{
		if (sir[i] == ',')
			count++;
		i++;
	}

	lista = new int[count];

	i = 0;
	for (int j = 0; j < count; j++)
	{
		int valoare = 0, p = 1;
		while (sir[i] != NULL && sir[i] != ',')
		{
			valoare = valoare * p + (sir[i] - '0');
			p = p * 10;
			i++;
		}
		lista[j] = valoare;
		i++;
	}

	stanga = 0;
	dreapta = count - 1;
}

void Sort::BubbleSort(bool ascendent)
{
	for (int i = 0; i < count - 1; i++)
		for (int j = 0; j < count - i - 1; j++)
			if (ascendent == true)
			{
				if (lista[j] > lista[j + 1])
				{
					int aux = lista[j];
					lista[j] = lista[j + 1];
					lista[j + 1] = aux;
				}
			}
			else
				if (lista[j] < lista[j + 1])
				{
					int aux = lista[j];
					lista[j] = lista[j + 1];
					lista[j + 1] = aux;
				}


}

void Sort::InsertSort(bool ascendent)
{

	for (int i = 1; i < count; i++)
	{
		int k = lista[i];
		int j = i - 1;

		if(ascendent == true)
			while (j >= 0 && lista[j] > k)
			{
				lista[j + 1] = lista[j];
				j = j - 1;
			}
		else
			while (j >= 0 && lista[j] < k)
			{
				lista[j + 1] = lista[j];
				j = j - 1;
			}

		lista[j + 1] = k;
	}
}

int Sort::partition(bool ascendent)
{
	int i = stanga - 1, aux, pivot = lista[dreapta];

	if(ascendent == true )
		for (int j = stanga; j <= dreapta - 1; j++)
		{
			if (lista[j] < pivot)
			{
				i++;
				aux = lista[i];
				lista[i] = lista[j];
				lista[j] = aux;
			}
		}
	else
		for (int j = dreapta; j > stanga; j--)
		{
			if (lista[j] > pivot)
			{
				i++;
				aux = lista[i];
				lista[i] = lista[j];
				lista[j] = aux;
			}
		}
		
	aux = lista[i + 1];
	lista[i + 1] = lista[dreapta];
	lista[dreapta] = aux;
		
	return i + 1;
}

void Sort::QuickSort(bool ascendent)
{
	if (stanga < dreapta)
	{
		int aux = dreapta;
		int pivot = partition(ascendent);

		dreapta = pivot - 1;
		QuickSort(ascendent);            // quickSort(lista, stanga, pivot - 1); 

		dreapta = aux;
		stanga = pivot + 1;
		QuickSort(ascendent);            // quickSort(lista, pivot + 1, dreapta); 
	}
}

void Sort::GetElementsCount()
{
	int cnt = 1;

	for (int i = 1; i < count; i++)
	{
		if (lista[i] == lista[i - 1])
			cnt++;
		else
		{
			std::cout << "Elementul " << lista[i - 1] << " apare de " << cnt << " ori" << '\n';
			cnt = 1;
		}
	}
	std::cout << "Elementul " << lista[count - 1] << " apare de " << cnt << " ori" << '\n';
}

int  Sort::GetElementFromIndex(int index)
{
	return lista[index];
}

void Sort::Merge(Sort& s)
{
	this->InsertSort(true);
	s.InsertSort(true);

	this->dreapta = this->count + s.count - 1;
	int aux = this->count;

	int* copie ;
	copie = new int[aux];
	for (int i = 0; i < this->count; ++i)
		copie[i] = this->lista[i];

	delete[] this->lista;
	this->count = this->count + s.count;
	this->lista = new int[this->count];

	int i = 0, j = 0, k = 0;
	while (i < aux && j < s.count)
	{
		if (copie[i] < s.lista[j])
		{
			this->lista[k] = copie[i];
			i++;
			k++;
		}
		else if (copie[i] > s.lista[j])
		{
			this->lista[k] = s.lista[j];
			j++;
			k++;
		}
		else if (copie[i] == s.lista[j])
		{
			this->lista[k] = copie[i];
			k++;
			this->lista[k] = copie[i];
			i++;
			j++;
			k++;
		}
	}

	while (i < aux)
	{
		this->lista[k] = copie[i];
		i++;
		k++;
	}

	while (j < s.count)
	{
		this->lista[k] = s.lista[j];
		j++;
		k++;
	}
}

void Sort::Print()
{
	for (int i = 0; i < count; i++)
		std::cout << lista[i] << ' ';
	std::cout << '\n' << '\n';

}
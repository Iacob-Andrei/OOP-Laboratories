#include<stdlib.h>
#include<exception>
using namespace std;

class ExceptieIndex : public exception
{
public:
	virtual const char* what() const throw()
	{

		return "Exceptie la index!";

	}
};

class ExceptieSize : public exception
{
public:
	virtual const char* what() const throw()
	{

		return "Size depasit";

	}
};

template<class T>

class ArrayIterator
{
public:
	T* Current;
	ArrayIterator& operator ++ () { Current++; return *this; }
	bool operator!=(ArrayIterator<T>& m) { return Current != m.Current;}
	T operator* () { return *Current; }
};


template<class T>

class Array
{
	T* list; 
	int capacity;
	int size; 
public:

	Array() // Lista nu e alocata, Capacity si Size = 0
	{
		capacity = 0;
		size = 0;
	}

	~Array() // destructor
	{
		delete list;
	}

	Array(int capacity) // Lista e alocata cu 'capacity' elemente
	{
		this->capacity = capacity;
		size = 0;
		list = (T*)malloc(sizeof(T) * capacity);
	}

	Array(const Array<T>& otherArray) // constructor de copiere
	{
		capacity = otherArray.capacity;
		size = otherArray.size;
		list = (T**)malloc(sizeof(T*) * this->capacity);

		for (int i = 0; i < size; ++i)
			this->list[i] = otherArray.list[i];
	}

	T& operator[] (int index) 
	{
		if (index < 0 || index > size)
		{
			ExceptieIndex e;
			throw e;
		}
		return list[index];
	}

	const Array<T>& operator+=(const T& newElem) // adauga un element de tipul T la sfarsitul listei si returneaza this
	{
		if (size == capacity)
		{	
			ExceptieSize e;
			throw e;
		}

		list[size] = newElem;
		size++;

		return *this;
	}

	const Array<T>& Insert(int index, const T& newElem) // adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
	{
		if (index < 0 || index > size)
			throw ExceptieIndex;

		for (int i = size; i >= index; i--)
			list[i + 1] = list[i];
		size++;
		list[index] = newElem;

		return *this;
	}

	const Array<T>& Delete(int index) // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie
	{
		if (index < 0 || index > size)
			throw ExceptieIndex;

		for (int i = index; i < size - 1; ++i)
			list[i] = list[i + 1];
		size--;

		return *this;
	}

	bool operator=(const Array<T>& otherArray)
	{
		this->list = (T*)realloc(list, (otherArray.capacity + 1) * sizeof(T));
		this->size = otherArray.size;
		this->capacity = otherArray.capacity;

		for (int i = 0; i < size; ++i)
			this->list[i] = otherArray.list[i];

		return true;
	}

	void Sort(){
		int aux;

		for (int i = 0; i < size - 1; ++i)
			for (int j = i + 1; j < size; ++j)
				if (list[i] > list[j])
				{
					aux = list[i];
					list[i] = list[j];
					list[j] = aux;
				}
	}

	int BinarySearch(const T& elem) // cauta un element folosind binary search in Array
	{
		int stanga = 0;
		int dreapta = size - 1;

		while (stanga < dreapta)
		{
			int mijloc = (stanga + dreapta) / 2;

			if (list[mijloc] == elem)
				return mijloc;

			if (elem > list[mijloc])
				stanga = mijloc + 1;
			else
				dreapta = mijloc - 1;
		}

		return -1;
	}

	int Find(const T& elem) // cauta un element in Array
	{
		for (int i = 0; i < size; ++i)
			if ( list[i] == elem )
				return elem;

		return -1;
	}

	int GetSize()
	{
		return size;
	}

	int GetCapacity()
	{
		return capacity;
	}

	ArrayIterator<T> begin() { ArrayIterator<T> tmp; tmp.Current = &list[0]; return tmp; }

	ArrayIterator<T> end() { { ArrayIterator<T> tmp; tmp.Current = &list[this->size]; return tmp; } }

};
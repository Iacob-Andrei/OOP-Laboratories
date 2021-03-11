#pragma once

class Sort
{
    int* lista;
    int count;
    int stanga, dreapta;
public:
    Sort(int number, int mini, int maxi);
    Sort(int number, int v[]);
    Sort(int number, ...);
    Sort(const char* sir);
    Sort() : count{ 5 }, stanga{ 0 }, dreapta{ 4 }, lista(new int[5]{ 17,5,23,1,8 }) { }
    ~Sort();
   
    int  partition(bool ascendent);
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Merge(Sort& s);

    void Print();
    void GetElementsCount();
    int  GetElementFromIndex(int index);
};
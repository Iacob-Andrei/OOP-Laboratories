#include <iostream>
#include "Map.h"

using namespace std;
int main()
{

    Map<int, const char*> m,s;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";
   
    cout << "Map ul 'm' este: " << endl;
    for (auto [key, value, index] : m)
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    cout << "\n";


    m.Delete(10);
    m[20] = "result";
    m.Set(40, "ananas");

    cout << "Map ul 'm' modificat: " << endl;
    for (auto [key, value, index] : m)
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    cout << endl;


    const char* valoare = "banana";
    m.Get(20, valoare);
    cout << valoare << endl << endl;
    

    s[40] = "C";
    s[20] = "SO";
    s[30] = "Poo";

    cout << "Map ul 's' este: " << endl;
    for (auto [key, value, index] : s)
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    cout << "\n";

    if (m.Includes(s))
        cout << "Map ul 'm' se regaseste in 's'." << endl;
    else
        cout << "Map ul 'm' nu se regaseste in 's'." << endl;

    return 0;
}
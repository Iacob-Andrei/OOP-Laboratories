#include <iostream>
using namespace std;

float operator"" _Kelvin(unsigned long long int x)
{
    return (float)(x + (-273.15));
}

float operator"" _Fahrenheit(unsigned long long int x)
{
    return (float)(x + (-17.7));
}

int main()
{
    cout << 300_Kelvin << "\n";
    cout << 0_Fahrenheit << "\n";


    return 0;
}

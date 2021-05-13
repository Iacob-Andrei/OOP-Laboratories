#include<iostream>
using namespace std;

class MyVector 
{  
    int list[100];
    int index;

public:

    MyVector() { index = 0; }
    bool Add(int elem) 
    {
        if( index == 99 )
            return false;
        else
        {
            list[index] = elem;
            index++;
            return true;
        }
    }

    bool Delete(int poz) 
    {
        if( poz >= index )
            return false;
        
        for( int i = poz ; i < index - 1 ; ++i )
            list[i] = list[i+1];
        index--;

        return true;
    }

    void Iterate( int(*lambda_function)(int x) )
    {
        for( int i = 0 ; i < index ; ++i )
            list[i] = lambda_function( list[i] );
    }

    void Filter( bool(*lambda_function)(int x) )
    {
        for(int i = 0 ; i < index ; ++i )
            if( lambda_function( list[i] ) == true )
                {
                    this->Delete( i );
                    i--;
                }
    }

    void Print()
    {
        for( int i = 0 ; i < index ; ++i )
            cout << list[i] << ' ';
        cout << endl;
    }

};

int main()
{
    MyVector vec;
    vec.Add(5); vec.Add(65); vec.Add(2); vec.Add(4); vec.Add(12);

    vec.Print();

    vec.Iterate( [] ( int elem ) { if( elem % 2 == 1 ) return 99; else return elem; } );

    vec.Print();

    vec.Filter( [] ( int elem) { if( elem % 2 == 0) return true; else return false; } );

    vec.Print();

    return 0;
}
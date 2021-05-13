#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    vector<string> a;
    a.push_back("oop");
    a.push_back("so");
    a.push_back("statistics");
    a.push_back("design");
    a.push_back("books");

    sort( a.begin() , a.end() , []( string s1 , string s2) { return s1.length() > s2.length(); } );

    for( auto &it : a )
        cout << it << ' ';

    cout << endl;

    sort( a.begin() , a.end() , []( string s1 , string s2) { return s1 < s2; } );

    for( auto &it : a )
        cout << it << ' ';

    cout << endl;

    vector<int> b;
    b.push_back(5); b.push_back(45); b.push_back(9); b.push_back(12); b.push_back(0);

    auto f = [] (vector<int> b)
    {
        int maxim = 0;
        for( auto &it : b )
            if( it > maxim )
                maxim = it;
        return maxim;
    };

    cout << f(b);

    return 0;
}
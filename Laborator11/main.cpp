#include<iostream>
#include "prb.h"

int main()
{
	Array<int> v1(50);

	try {
		v1 += 6; v1 += 2; v1 += 4; v1 += 12; v1 += 20;
		
		for ( auto it : v1 )
			cout << it << ' ';

		cout << endl;
		cout << v1[20];
	}
	catch ( ExceptieIndex e)
	{
		cout << e.what();
	}
	catch (ExceptieSize e)
	{
		cout << e.what();
	}



	return 0;
}
// multiplicationTables.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char* argv[])
{
	for (int i = 1; i < 13; ++i)
	{
		for (int j = 1; j < 13; ++j)
		{
			cout << setw(4) << j*i;
		}
		cout << endl;
	}
	return 0;
}


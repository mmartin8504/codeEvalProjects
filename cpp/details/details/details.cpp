#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	ifstream stream(argv[1]);
	string line;
	string delimeter = ",";

	while (getline(stream, line))
	{
		// Do something with the line
		size_t pos = 0;
		vector<string> rows;
		while ((pos = line.find(delimeter)) != string::npos)
		{
			rows.push_back(line.substr(0, pos));
			line = line.substr(pos + delimeter.length());
		}
		rows.push_back(line);
	
		int closestPos = rows[0].length();
		for (vector<string>::size_type i = 0; i < rows.size(); ++i)
		{
			int spaceBetween = 0;
			for (int j = 0; j < rows[i].length(); ++j)
			{
				if (rows[i][j] == '.')
					++spaceBetween;
				else if (rows[i][j] == 'Y')
				{
					if (closestPos >= spaceBetween)
						closestPos = spaceBetween;
					continue;
				}
			}
		}
		cout << closestPos << endl;
	}

	return 0;
}
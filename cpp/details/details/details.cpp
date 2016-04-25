#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int solveSplit(string line)
{
	string delimeter = ",";

	size_t pos = 0;
	vector<string> rows;
	while ((pos = line.find(delimeter)) != string::npos)
	{
		// split on delimiter
		rows.push_back(line.substr(0, pos));
		line = line.substr(pos + delimeter.length());
	}
	// add each row to the vector
	rows.push_back(line);

	// for each row, find the space between the first . and the first Y
	int closestPos = rows[0].length();
	for (vector<string>::size_type i = 0; i < rows.size(); ++i)
	{
		int spaceBetween = 0;
		for (string::size_type j = 0; j < rows[i].length(); ++j)
		{
			if (spaceBetween < closestPos)
			{
				if (rows[i][j] == '.')
					++spaceBetween;
				else if (rows[i][j] == 'Y')
				{
					// update closestPos if space is less than current closest
					if (closestPos >= spaceBetween)
						closestPos = spaceBetween;
					break;
				}
			}
			else
				break; // go ahead and stop looking at this row if we've exceeded closestPos
		}
	}

	return closestPos;
}

int solveNoSplit(string line)
{
	int lineLen = line.length();
	int closestPos = lineLen;
	int spaceBetween = 0;
	bool keepCounting = true;
	for (int i = 0; i < lineLen; ++i)
	{
		// Handle the case X....Y,X..Y.Y
		if (keepCounting && line[i] == 'Y')
		{
			// need to stop counting . after the first Y
			// but also don't come in here if keepCounting is
			// false since Y can be the last character and we
			// need to go into the else if on the last char
			// to update closestPos for the last row in the line
			keepCounting = false;
		}
		else if (keepCounting && line[i] == '.')
		{
			// count the . if we're still doing that
			++spaceBetween;
		}
		else if (line[i] == ',' || i == lineLen-1) // end of a row OR the end of the line
		{
			// if the space we just counted was less than our closest,
			// update the closest value
			if (spaceBetween < closestPos)
				closestPos = spaceBetween;
			// reset the space counter for the next row
			spaceBetween = 0;
			// we need to start counting . again
			keepCounting = true;
		}
	}
	
	return closestPos;
}

int main(int argc, char *argv[])
{
	ifstream stream(argv[1]);
	string line;

	while (getline(stream, line))
	{
		int ans = solveNoSplit(line);
		//int ans = solveSplit(line);
		cout << ans << endl;
	}
	return 0;
}
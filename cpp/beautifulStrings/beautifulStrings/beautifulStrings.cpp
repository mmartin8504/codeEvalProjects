// beautifulStrings.cpp : main project file.

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;

    while (getline(stream, line)) {
		char max = '\0';
		map<char, int> charCount;
		int score = 0;
		for (string::size_type i=0; i<line.length(); ++i)
		{
			char c = toupper(line[i]);
			line[i] = c;
			if (isalpha(c))
			{
				pair<map<char,int>::iterator,bool> ret;
				ret = charCount.insert(pair<char, int>(c,1));
				if (!ret.second)
					ret.first->second += 1;
			}
		}
		
		vector<int> values;
		for (map<char,int>::iterator it=charCount.begin(); it!=charCount.end(); ++it)
		{
			values.push_back(it->second);
		}

		sort(values.begin(), values.end());
		int multiplier = 26;
		for (vector<int>::reverse_iterator it=values.rbegin(); it!=values.rend(); ++it, --multiplier)
		{
			score += multiplier*(*it);
		}

		cout << score << endl;
    }

    return 0;
}

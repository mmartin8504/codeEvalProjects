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
        // count the number of unique letters
		map<char, int> charCount;
		int score = 0;
        // look at each character
		for (string::size_type i=0; i<line.length(); ++i)
		{
            // don't care about case
			char c = toupper(line[i]);
			line[i] = c;
            // only care about letters
			if (isalpha(c))
			{
				pair<map<char,int>::iterator,bool> ret;
                // Insert returns a pair, ret.second is true if a new element was inserted
				ret = charCount.insert(pair<char, int>(c,1));
                // if that wasn't a new element, increment the existing count
				if (!ret.second)
					ret.first->second += 1;
			}
		}
		
        // Get the counts of each letter. We don't really care about which letter had the most/least
        // just the total number of each.
		vector<int> values;
		for (map<char,int>::iterator it=charCount.begin(); it!=charCount.end(); ++it)
		{
			values.push_back(it->second);
		}

        // Sort the counts (ascending)
		sort(values.begin(), values.end());

        // To max the score, the letter with the highest count gets the highest possible score, and
        // so on as the counts decrease
		int multiplier = 26;
		for (vector<int>::reverse_iterator it=values.rbegin(); it!=values.rend(); ++it, --multiplier)
		{
			score += multiplier*(*it);
		}

		cout << score << endl;
    }

    return 0;
}

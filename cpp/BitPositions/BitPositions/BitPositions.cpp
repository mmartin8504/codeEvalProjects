#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
	ifstream stream(argv[1]);
	string line;
	string delimeter = ",";
	string tokens[3];
	while (getline(stream, line)) {
	size_t pos = 0;
	int i = 0;
	while ((pos = line.find(delimeter)) != string::npos) {
		tokens[i] = line.substr(0, pos);
		line = line.substr(pos + delimeter.length());
		++i;
	}
	tokens[i] = line;
	int num, p1, p2;
	num = stoi(tokens[0]);
	p1 = stoi(tokens[1]);
	p2 = stoi(tokens[2]);

	int bit1 = (num & (1<<p1-1)) >> p1-1;
	int bit2 = (num & (1<<p2-1)) >> p2-1;
	if (!(bit1 ^ bit2))
		cout << "true" << endl;
	else
		cout << "false" << endl;
	}
	return 0;
}
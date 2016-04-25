#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

bool parseInput(const char *filename, vector<pair<string, string>>& interactions)
{
	ifstream stream(filename);
	string line;
	while (getline(stream, line))
	{
		cout << line << endl;
	}

	return true;
}
int main(int argc, char *argv[])
{
	vector<pair<string, string>> interactions;
	parseInput(argv[1], interactions);
	system("pause");
	return 0;
}
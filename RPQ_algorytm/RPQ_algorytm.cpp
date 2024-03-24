#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <time.h>
#include "Dane.h"
#include "Result.h"

using namespace std;

/*
d1 sortR
d2 calier
d3 calier
d4 calier

*/


int main()
{
	int c = 0;
	string filenameTab[4] = { "dane1.txt" , "dane2.txt", "dane3.txt", "dane4.txt" };
	vector<Dane> dataTab;
	for (int i = 0; i < 4; i++)
	{
		Dane temp = Dane(filenameTab[i]);
		dataTab.push_back(temp);
	}
	
	
	for (int i = 0; i < 4; i++)
	{
		if (i == 1) {
			std::vector<RPQ> TS1 = dataTab.at(i).schargePmtn();
		}
		else {
			std::vector<RPQ> TS1 = dataTab.at(i).TabuSearch();
		}
		
		c += dataTab.at(i).c_max;
		cout << "czas " << i+1 << " = " << dataTab.at(i).c_max << endl;
	
	}
	cout << "czas = " << c << endl;
	cout << "----------------------\n";
}
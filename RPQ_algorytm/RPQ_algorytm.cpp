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
		dataTab.at(i).schrage();
		c += dataTab.at(i).c_max;

	}
	
	cout << "czas = " << c << endl;
	
	/*for (auto x : sh_Dane1)
	{
		cout << x << " ";
	}
	cout << "----------------------\n";
	vector<RPQ> sh_Dane2 = dataTab.at(0).schrage();
	for (auto x : sh_Dane2)
	{
		cout << x.index << " ";
	}*/
		//cout << endl << endl;
	//vector<RPQ> sortR_Dane2 = data1.sortR(data2.getList());
	//vector<RPQ> sortR_Dane3 = data1.sortR(data3.getList());
	//vector<RPQ> sortR_Dane4 = data1.sortR(data4.getList());

	//vector<vector<RPQ>> SortR_All;
	//SortR_All.push_back(sortR_Dane1);
	//SortR_All.push_back(sortR_Dane2);
	//SortR_All.push_back(sortR_Dane3);
	//SortR_All.push_back(sortR_Dane4);

	/*cout << "SortR: " << endl;
	for (auto x : SortR_All)
	{
		//cout<<"Data: "<< <<endl
		for (auto y : x)
		{
			cout << y.index << " ";
		}
		cout << endl << endl;
	}
	cout << endl << endl;*/

	//vector<RPQ> sortR_Dane1 = data1.sortR();

	//ut << "SortRQ: " << endl;
	//for (auto x : sortR_Dane1)
	//{
		//c += x.P;
		//cout << x.index << " ";
	//}
	//cout << endl << endl;
}
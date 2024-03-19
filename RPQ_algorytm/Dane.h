#pragma once
#include "RPQ.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>


class Dane
{
	std::vector <RPQ> list;
	int number_of_data;
	std::string file_path;
	

public:
	int c_max;
	Dane(std::string fp);

	std::vector<RPQ> getList();
	
	void GetData();

	void printDane();

	friend bool comparatorR(const RPQ& r1, const RPQ& r2);
	friend bool comparatorQ(const RPQ& r1, const RPQ& r2);

	std::vector<RPQ> inOrder();

	std::vector<RPQ> sortR();

	std::vector<RPQ> schrage();

	std::vector<RPQ> schargePmtn();

	std::vector<RPQ> c100();

	std::vector<RPQ> carlier();



	
	
};



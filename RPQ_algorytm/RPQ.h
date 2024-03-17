#pragma once
#include <iostream>

class RPQ
{
public:
	int index;
	int R;
	int P;
	int Q;

	RPQ(int r, int p, int q);

	

	friend std::ostream& operator<<(std::ostream& out, const RPQ& d);

	
};



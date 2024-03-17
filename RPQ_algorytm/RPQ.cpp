#include "RPQ.h"

RPQ::RPQ(int r, int p, int q) {
	this->R = r;
	this->P = p;
	this->Q = q;
	this->index = 1;
}



std::ostream& operator<<(std::ostream& out, const RPQ& d)
{

	return out << "ID: " << d.index << "\tR: " << d.R << "\tP : " << d.P << "\tQ : " << d.Q << "\n";
}
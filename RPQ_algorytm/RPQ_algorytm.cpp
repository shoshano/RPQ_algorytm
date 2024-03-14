#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class RPQ {
public:
	int index;
	int R;
	int P;
	int Q;

	RPQ(int r, int p, int q) {
		this->R = r;
		this->P = p;
		this->Q = q;
		this->index = 1;
	}
};
ostream& operator<<(ostream& out, const RPQ& d)
{
	return out << "ID: " << d.index << "\tR: " << d.R << "\tP : " << d.P << "\tQ : " << d.Q << endl;
}

class Dane {
	vector<RPQ> lista;
	int number_of_data;
	string file_path;

public:
	Dane(string fp) {
		file_path = fp;
		GetData();
	}

	vector<RPQ> getList()
	{
		return this->lista;
	}

	void GetData() {
		number_of_data = 0;
		string n;
		fstream file;
		file.open(file_path);
		string line, chunk;
		vector<string> tmp;
		if (file.is_open()) {
			getline(file, line);
			number_of_data = stoi(line);
			for (int i = 0; i < number_of_data; i++) {
				RPQ d = RPQ(0, 0, 0);
				getline(file, line);
				stringstream s(line);
				while (getline(s, chunk, ' '))
				{
					tmp.push_back(chunk);
				}
				d.index = i + 1;
				d.R = stoi(tmp.at(0));
				d.P = stoi(tmp.at(1));
				d.Q = stoi(tmp.at(2));

				lista.push_back(d);
				tmp.erase(tmp.begin(), tmp.end());
			}
		}
		else {
			cout << "Plik nie otwarty";
		}
	}

	void printDane() {
		cout << "NR: " << number_of_data << endl;
		for (auto r : lista)
		{
			cout << r;
		}
	}

	vector<RPQ> sortR(vector<RPQ> lista)
	{
		//vector<RPQ> lis = lista;

		sort(lista.begin(), lista.end(), [](const RPQ l, const RPQ r) {
			return l.R < r.R;
			});

		return lista;
	}
};

int main()
{
	Dane data1 = Dane("dane1.txt");
	data1.printDane();

	cout << "=======================================\n";

	Dane data2 = Dane("dane2.txt");
	data2.printDane();

	cout << "=======================================\n";

	Dane data3 = Dane("dane3.txt");
	data3.printDane();

	cout << "=======================================\n";

	Dane data4 = Dane("dane4.txt");
	data4.printDane();

	vector<RPQ> sortR_Dane1 = data1.sortR(data1.getList());

	for (auto x : sortR_Dane1)
	{
		cout << x.index << " ";
	}
}
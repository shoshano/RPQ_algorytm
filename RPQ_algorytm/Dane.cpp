#include "Dane.h"

Dane::Dane(std::string fp) {
	file_path = fp;
	GetData();
	c_max = 0;
}

std::vector<RPQ> Dane::getList()
{
	return this->list;
}

void Dane::GetData() {
	number_of_data = 0;
	std::string n;
	std::fstream file;
	file.open(file_path);
	std::string line, chunk;
	std::vector<std::string> tmp;
	if (file.is_open()) {
		getline(file, line);
		number_of_data = stoi(line);
		for (int i = 0; i < number_of_data; i++) {
			RPQ d = RPQ(0, 0, 0);
			getline(file, line);
			std::stringstream s(line);
			while (getline(s, chunk, ' '))
			{
				tmp.push_back(chunk);
			}
			d.index = i + 1;
			d.R = stoi(tmp.at(0));
			d.P = stoi(tmp.at(1));
			d.Q = stoi(tmp.at(2));

			list.push_back(d);
			tmp.erase(tmp.begin(), tmp.end());
		}
	}
	else {
		std::cout << "Plik nie otwarty";
	}
}

void Dane::printDane() {
	std::cout << "NR: " << number_of_data << "\n";
	for (auto r : list)
	{
		std::cout << r;
	}
}

bool comparatorR(const RPQ& r1, const RPQ& r2) {
	return r1.R < r2.R;
}

bool comparatorQ(const RPQ& r1, const RPQ& r2) {
	return r1.Q < r2.Q;
}

std::vector<RPQ> Dane::inOrder() {
	return this->list;
}

std::vector<RPQ> Dane::sortR()
{

	std::vector<RPQ> temp = this->list;
	sort(temp.begin(), temp.end(), [](const RPQ left, const RPQ right) {
		return left.R < right.R;
	});

	return temp;
}

std::vector<RPQ> Dane::schrage() {
	std::vector<RPQ> orgin = this->list;
	std::vector<RPQ> ready;
	std::vector<RPQ> result;
	c_max = 0;
	int t = 0;
	while (!orgin.empty() || !ready.empty()) {

		auto min_ele = std::min_element(orgin.begin(), orgin.end(), comparatorR);

		while (!orgin.empty() && min_ele->R <= t) {
			RPQ temp1 = *min_ele;
			ready.push_back(temp1);
			orgin.erase(min_ele);
			min_ele = std::min_element(orgin.begin(), orgin.end(), comparatorR);
		}
		if (ready.empty()) {
			t = min_ele->R;
			continue;
		}
		auto max_ele = std::max_element(ready.begin(), ready.end(), comparatorQ);
		t = t + max_ele->P;
		c_max = std::max(c_max, (t + max_ele->Q));
		RPQ temp2 = *max_ele;
		result.push_back(temp2);
		ready.erase(max_ele);
	}
	return result;
}

std::vector<RPQ> Dane::schargePmtn() {
	c_max = 0;
	std::vector<RPQ> orgin = list;
	std::vector<RPQ> ready;
	std::vector<RPQ> result;
	RPQ l = *(std::min_element(orgin.begin(), orgin.end(), comparatorR));
	int t = 0;

	while (!orgin.empty() || !ready.empty()) {
		auto min_ele = std::min_element(orgin.begin(), orgin.end(), comparatorR);

		while (!orgin.empty() && min_ele->R <= t) {
			RPQ temp1 = *min_ele;
			ready.push_back(temp1);
			orgin.erase(min_ele);
			if (temp1.Q > l.Q) {
				l.P = t - temp1.R;
				t = temp1.R;
				if (l.P > 0) {
					ready.push_back(l);
					result.pop_back();
				}
				
			}
			min_ele = std::min_element(orgin.begin(), orgin.end(), comparatorR);
		}
		if (ready.empty()) {
			t = min_ele->R;
			continue;
		}
		auto max_ele = std::max_element(ready.begin(), ready.end(), comparatorQ);

		l = *max_ele;
		t = t + max_ele->P;
		c_max = std::max(c_max, (t + max_ele->Q));
		RPQ temp2 = *max_ele;
		result.push_back(temp2);
		ready.erase(max_ele);
	}
	return result;
}

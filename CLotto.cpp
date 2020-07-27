#include <iostream>
#include "CLotto.h"
#include "CZufall.h"

using namespace std;

CLotto::CLotto(int n) {
	if (n < 0) { hilfe.initialisiere(time(NULL)); }
	else { hilfe.initialisiere(n); };
}

vector<int> CLotto::Simulation() {
	vector<int> ergebnis;
	vector<int> end;
	end.resize(6);
	bool mehrfach = false;
	do {
		mehrfach = false;
		ergebnis = hilfe.test(1, 49, 6);
		for (unsigned int i = 0; i < ergebnis.size(); i++) {
			if (ergebnis[i] > 1) {
				mehrfach = true;
			}
		}
	} while (mehrfach);
	int k = 0;
	for (int j = 0; j < ergebnis.size(); j++)
	{
		if (ergebnis[j] == 1) {
			end[k] = j;
			k++;
		}
	}
	return end;
}

void CLotto::setTippzettel(vector<int> tippzettel) {
	Tippzettel = tippzettel;
}
int CLotto::Moeglichkeit_eins() {
	vector<int> tmp;
	tmp.resize(6);
	tmp = Simulation();
	int k = 0;
	int j = 0;
	int i = 0;
	/*do{
		if (Tippzettel[i] > tmp[j]) {
			j++;
		}
		else if (Tippzettel[i] < tmp[j]) {
			i++;
		}
		else {
			k++;
			i++;
			j++;
		}
	} while (i != Tippzettel.size() && j != tmp.size());*/
	

	for  (unsigned int i = 0; i < tmp.size(); i++){
		for (unsigned int j = 0; j < Tippzettel.size(); j++)
		{
			if (tmp[i] == Tippzettel[j]) {
				k++;
				break;
			}
		}
	}
	return k;
}

int CLotto::Moeglichkeit_zwei() {
	vector<int> tmp1;
	tmp1.resize(6);
	tmp1 = Simulation();
	vector<int> tmp2;
	tmp2.resize(6);
	tmp2 = Simulation();
	int k = 0;
	int j = 0;
	int i = 0;
	do {
		if (tmp1[i] > tmp2[j]) {
			j++;
		}
		else if (tmp1[i] < tmp2[j]) {
			i++;
		}
		else {
			k++;
			i++;
			j++;
		}
	} while (i != tmp1.size() && j != tmp2.size());

	/*for (unsigned int i = 0; i < tmp1.size(); i++) {
		for (unsigned int j = 0; j < Tippzettel.size(); j++)
		{
			if (tmp1[i] == Tippzettel[j]) {
				k++;
				break;
			}
		}
	}
	for (unsigned int i = 0; i < tmp2.size(); i++) {
		for (unsigned int j = 0; j < Tippzettel.size(); j++)
		{
			if (tmp2[i] == Tippzettel[j]) {
				k++;
				break;
			}
		}
	}*/
	return k;
}
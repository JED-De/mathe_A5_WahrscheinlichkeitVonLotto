#pragma once
#include <iostream>
#include "CZufall.h"

using namespace std;

class CLotto {
private:
	vector<int> Tippzettel;
	CZufall hilfe;
	vector<int> Simulation();
public:
	CLotto(int n);
	void setTippzettel(vector<int> tippzettel);
	int Moeglichkeit_eins();
	int Moeglichkeit_zwei();
};
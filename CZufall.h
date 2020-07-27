#pragma once
#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

class CZufall {
public:
	int wert(int a, int b); //gleichverteilte Zufallszahl
	void initialisiere(int n); //zufallgenerator mit srand(n)
	vector<int> test(int a, int b, int N); //die N mal eine Zufallszahl zwischen a und b
	vector<int> test_falsch(int a, int b, int N); //test funktioniert aber Zufallsgenerator neu initialisiert
};
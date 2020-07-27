#include <iostream>
#include <vector>
#include <stdlib.h>
#include "CZufall.h"

using namespace std;

int CZufall::wert(int a, int b) {
	return (rand() % (b - a + 1)) + a;
}

void CZufall::initialisiere(int n) {
	srand(n);
}

vector<int> CZufall::test(int a, int b, int N) {
	vector<int> test;
	test.resize(b-a+1);
	int tmp = 0;
	for (int i = 0; i < N; i++) {
		tmp = wert(a, b);
		test[tmp - a]++;
	}
	//for (int i = 0; i < test.size(); i++) {
	//	cout << i + a << " " << "Anzahl: " << test.at(i) << endl;
	//}
	//cout << endl;
	return test;
}

vector<int> CZufall::test_falsch(int a, int b, int N) {
	vector<int> test;
	test.resize(b - a + 1);
	int tmp = 0;
	for (int i = 0; i < N; i++) {
		initialisiere(time(NULL));
		tmp = wert(a, b);
		test[tmp - a]++;
	}
	/*for (int i = 0; i < test.size(); i++) {
		cout << i + a << " " << "Anzahl: " << test.at(i) << endl;
	}
	cout << endl;*/
	return test;
}


#include <iostream>
#include "CZufall.h"
#include "CLotto.h"
#include <fstream>

using namespace std;

void werte_ausgeben(const char *dateiname, int anzahl1, int anzahl2)
{
	// File oeffnen
	ofstream fp;
	fp.open(dateiname);
	// Eintraege in das File schreiben
	fp << "Frequenz von eine Ziehung: " << anzahl1 << endl << "Frequenz von zwei Ziehungen: " << anzahl2;
	// File schliessen
	fp.close();
}


int main() {
	/*CZufall test;
	test.initialisiere(4);
	test.test(3, 7, 10000);

	test.initialisiere(4);
	test.test(3, 7, 10000);

	test.initialisiere(4);
	test.test(3, 7, 10000);

	test.initialisiere(0);
	test.test(3, 7, 10000);

	test.initialisiere(1);
	test.test(3, 7, 10000);

	test.initialisiere(2);
	test.test(3, 7, 10000);

	test.initialisiere(time(NULL));
	test.test(3, 7, 10000);

	test.initialisiere(time(NULL));
	test.test(3, 7, 10000);

	test.initialisiere(time(NULL));
	test.test(3, 7, 10000);


	test.test_falsch(3, 7, 1000);*/


	CLotto Test(0);
	vector<int> TippZettel;
	TippZettel.resize(6);
	TippZettel[0] = 12;
	TippZettel[1] = 1;
	TippZettel[2] = 23;
	TippZettel[3] = 44;
	TippZettel[4] = 26;
	TippZettel[5] = 35;
	Test.setTippzettel(TippZettel);
	//cout << "Bei ein Spiel, gibt es " << Test.Moeglichkeit_eins() << " uebereinstimmenden Zahlen." << endl;

	//cout << "Bei zwei Spiele, gibt es " << Test.Moeglichkeit_zwei() << " uebereinstimmenden Zahlen." << endl;

	/*Monte-Carlo-Simulation
	aufgabe 3a*/
	double anzahl1 = 0, anzahl2 = 0;
	for (int i = 0; i < 10000; i++) {
		if (Test.Moeglichkeit_eins() == 3) {
			anzahl1++;
		}
	}
	double t = anzahl1 / 10000;
	cout << t << endl;
	//aufgabe 3b
	for (int i = 0; i < 10000; i++) {
		if (Test.Moeglichkeit_zwei() == 3) {
			anzahl2++;
		}
	}
	cout << "Frequenz von eine Ziehung: " << anzahl1/ 10000 << endl << "Frequenz von zwei Ziehungen: " << anzahl2 << endl;
	werte_ausgeben("Result4.txt", anzahl1, anzahl2);
	system("PAUSE");
	return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "Fahrzeug.h"
#include "Fahrrad.h"
#include "PKW.h"
#include "Weg.h"
#include "SimuClient.h"
#include <random>
#include "vertagt_liste - Vorlage.h"

using namespace std;

static std::mt19937 device(0);
std::uniform_int_distribution<int> dist(0, 9);

//void vAufgabe_1();
//void vAufgabe_1a();
//void vAufgabe_2();
//void vAufgabe_3();
//void vAufgabe_AB1();
//void vAufgabe_4();
//void vAufgabe_5();
//void vAufgabe_6();
//void vAufgabe_6Grafik_AB2();
//void vAufgabe_6a();
//void AB2Test4();
void vAufgabe6_AB3();

double dGlobaleZeit = 0.0;
double dEpsilon = 0.001;


int main() {
	vAufgabe6_AB3();
}

void vAufgabe6_AB3()
{
	//Wege und Fahrzeuge erzeugen
	Weg hinweg("Hinweg", 500);
	Weg rueckweg("Rueckweg", 500);
	auto bmw = make_unique<PKW>("BMW", 150, 2, 60);
	auto audi = make_unique<PKW>("Audi", 250, 10, 100);
	auto fahrrad = make_unique<Fahrrad>("BMX", 55);
	auto krassesf = make_unique<Fahrrad>("KrassesFah", 100);
	cout << endl << endl;

	//Fahrzeuge auf Weg setzen
	hinweg.vAnnahme(move(bmw));
	hinweg.vAnnahme(move(audi), 3);
	hinweg.vAnnahme(move(fahrrad));
	hinweg.vAnnahme(move(krassesf), 2);

	//Men�
	cout << endl << endl;
	cout << "	1) Einen Schritt (s)imulieren (-> Dauer)\n	2) (M)ehrere Schritte simulieren (-> Schrittweite, Anzahl, Verzoegerung)\n	3) (a)usgeben (-> H/R)\n	4) Globale (Z)eit ausgeben\n	5) (K)�pfe erneut anzeigen" << endl;

	//K�pfe
	cout << endl << endl;
	Fahrzeug::vKopf();
	Weg::vKopf();
	cout << endl;

	//Grafik, Weg
	bInitialisiereGrafik(800, 500);
	int pKoordinaten[] = { 700, 250, 100, 250 };
	bZeichneStrasse("Hinweg", "Rueckweg", 500, 2, pKoordinaten);

	char c; //multipurpose
	double dauer;
	int anzahl;
	int verzoegerung;

	//Operationsschleife
	while (true) {
		//passt semantisch eher ans Ende, aber damit beim ersten Mal auch gezeichnet wird:
		vSetzeZeit(dGlobaleZeit);
		hinweg.vFahrzeugeZeichnen();
		rueckweg.vFahrzeugeZeichnen();

		//Operationen ausf�hren
		cin >> c;
		switch (c) {
			//Mehrere Schritte simulieren
		case 'm':
		case 'M':
			cin >> dauer;
			cin >> anzahl;
			cin >> verzoegerung;
			for (int j = 0; j < anzahl; j++) {
				dGlobaleZeit += dauer;
				vSetzeZeit(dGlobaleZeit);
				hinweg.vSimulieren();
				rueckweg.vSimulieren();
				hinweg.vFahrzeugeZeichnen();
				rueckweg.vFahrzeugeZeichnen();
				vSleep(verzoegerung);
			}
			break;

			//Einen Schritt simulieren
		case 's':
		case 'S':
			cin >> dauer;
			dGlobaleZeit += dauer;
			hinweg.vSimulieren();
			rueckweg.vSimulieren();
			break;

			//Einen Weg ausgeben
		case 'a':
		case 'A':
			cin >> c;
			switch (c) {
			case 'h':
			case 'H':
				hinweg.vAusgeben(cout);
				break;
			case 'r':
			case 'R':
				rueckweg.vAusgeben(cout);
				break;
			}
			break;

			//Zeit ausgeben
		case 'z':
		case 'Z':
			cout << dGlobaleZeit << endl;
			break;

			//K�pfe ausgeben
		case 'k':
		case 'K':
			Fahrzeug::vKopf();
			Weg::vKopf();
			break;
		}
	}
}

/*void AB2Test4() {
	vertagt::VListe<int> li;
	for (int i = 0; i < 10; ++i)
		li.push_back(i);
	li.vAktualisieren();
	for (auto it = li.begin(); it != li.end(); ++it)
		if (*it % 2 == 1)
			li.erase(it);
	li.push_back(10);
	li.push_front(-1);
	return;
}*/

/*void vAufgabe_6a() {
	vertagt::VListe<int> list;
	for (int i = 0; i < 10; i++) {
		list.push_back(dist(device));
	}
	list.vAktualisieren();
	cout << "Vor dem Filtern: ";
	for (auto element : list) {
		cout << element << " ";
	}
	cout << endl;

	auto it = list.begin();
	while (it != list.end()) {
		if (*it > 5) {
			list.erase(it);
		}
		it++;
	}
	cout << "Nach dem Filtern: ";
	for (auto element : list) {
		cout << element << " ";
	}
	cout << endl;

	list.vAktualisieren();
	cout << "Nach dem Aktualisieren: ";
	for (auto element : list) {
		cout << element << " ";
	}
	cout << endl;
}*/

/*void vAufgabe_6Grafik_AB2()
{
	//Wege und Fahrzeuge erzeugen
	Weg hinweg("Hinweg", 500);
	Weg rueckweg("Rueckweg", 500);
	auto bmw = make_unique<PKW>("BMW", 150, 2, 60);
	auto audi = make_unique<PKW>("Audi", 250, 10, 100);
	auto fahrrad = make_unique<Fahrrad>("BMX", 55);
	auto krassesf = make_unique<Fahrrad>("KrassesFah", 100);
	cout << endl << endl;

	//Fahrzeuge auf Weg setzen
	hinweg.vAnnahme(move(bmw));
	hinweg.vAnnahme(move(audi), 3);
	hinweg.vAnnahme(move(fahrrad));
	hinweg.vAnnahme(move(krassesf), 2);

	//Men�
	cout << endl << endl;
	cout << "	1) Einen Schritt (s)imulieren (-> Dauer)\n	2) (M)ehrere Schritte simulieren (-> Schrittweite, Anzahl, Verzoegerung)\n	3) (a)usgeben (-> H/R)\n	4) Globale (Z)eit ausgeben\n	5) (K)�pfe erneut anzeigen" << endl;

	//K�pfe
	cout << endl << endl;
	Fahrzeug::vKopf();
	Weg::vKopf();
	cout << endl ;

	//Grafik, Weg
	bInitialisiereGrafik(800, 500);
	int pKoordinaten[] = { 700, 250, 100, 250 };
	bZeichneStrasse("Hinweg", "Rueckweg", 500, 2, pKoordinaten);

	char c; //multipurpose
	double dauer;
	int anzahl;
	int verzoegerung;

	//Operationsschleife
	while (true) {
		//passt semantisch eher ans Ende, aber damit beim ersten Mal auch gezeichnet wird:
		vSetzeZeit(dGlobaleZeit);
		hinweg.vFahrzeugeZeichnen();
		rueckweg.vFahrzeugeZeichnen();

		//Operationen ausf�hren
		cin >> c;
		switch (c) {
			//Mehrere Schritte simulieren
		case 'm':
		case 'M':
			cin >> dauer;
			cin >> anzahl;
			cin >> verzoegerung;
			for (int j = 0; j < anzahl; j++) {
				dGlobaleZeit += dauer;
				vSetzeZeit(dGlobaleZeit);
				hinweg.vSimulieren();
				rueckweg.vSimulieren();
				hinweg.vFahrzeugeZeichnen();
				rueckweg.vFahrzeugeZeichnen();
				vSleep(verzoegerung);
			}
			break;

			//Einen Schritt simulieren
		case 's':
		case 'S':
			cin >> dauer;
			dGlobaleZeit += dauer;
			hinweg.vSimulieren();
			rueckweg.vSimulieren();
			break;

			//Einen Weg ausgeben
		case 'a':
		case 'A':
			cin >> c;
			switch (c) {
			case 'h':
			case 'H':
				hinweg.vAusgeben(cout);
				break;
			case 'r':
			case 'R':
				rueckweg.vAusgeben(cout);
				break;
			}
			break;

			//Zeit ausgeben
		case 'z':
		case 'Z':
			cout << dGlobaleZeit << endl;
			break;

			//K�pfe ausgeben
		case 'k':
		case 'K':
			Fahrzeug::vKopf();
			Weg::vKopf();
			break;
		}
	}
}*/

/*void vAufgabe_6() {
	Weg boxgraben("Boxgraben", 200, Tempolimit::innerorts);
	Weg autobahn("A 1", 800);
	vector<unique_ptr<Fahrzeug>> fahrzeuge;
	fahrzeuge.push_back(make_unique<PKW>("BMW", 160, 9, 60));
	fahrzeuge.push_back(make_unique<PKW>("Audi", 250, 10, 100));
	fahrzeuge.push_back(make_unique<Fahrrad>("BMX", 55));
	fahrzeuge.push_back(make_unique<Fahrrad>("Krasses F.", 100));
	Fahrzeug::vKopf();
	Weg::vKopf();
	cout << "(s)imulieren (-> Dauer)\n(a)usgeben (-> ID)\nvAnnahme (F)ahren (-> ID, Weg-Anfangsbuchstabe)\nvAnnahme (P)arken (-> ID, Startzeitpunkt, Weg-Anfangsbuchstabe)\nGlobale (Z)eit ausgeben\n(K)�pfe erneut anzeigen" << endl;

	while (true) {
		char operation;
		char streetLetter;
		double deltaT;
		int id;
		double startzeit;
		cin >> operation;
		switch (operation) {
		case 's':
		case 'S':
			cin >> deltaT;
			dGlobaleZeit += deltaT;
			autobahn.vSimulieren();
			boxgraben.vSimulieren();
			break;
		case 'a':
		case 'A':
			cin >> id;
			id -= 2;
			if (id == -2)
				boxgraben.vAusgeben(cout);
			else if (id == -1)
				autobahn.vAusgeben(cout);
			if (id < fahrzeuge.size()) {
				try {
					fahrzeuge[id]->vAusgeben(cout);
				}
				catch (exception e) {
					cout << "Bitte nur Fahrzeuge abfragen, die nicht auf dem Weg sind (Besitz des unique_ptr wurde abgegeben)." << endl;
				}
			}
			break;
		case 'f':
		case 'F':
			cin >> id;
			id-= 2;
			cin >> streetLetter;
			if (id < 0)
				continue;
			if (id < fahrzeuge.size()) {
				switch (streetLetter) {
				case 'b':
				case 'B':
					boxgraben.vAnnahme(move(fahrzeuge[id]));
					break;
				case 'a':
				case 'A':
					autobahn.vAnnahme(move(fahrzeuge[id]));
					break;
				}
			}
			break;
		case 'p':
		case 'P':
			cin >> id;
			cin >> startzeit;
			id -= 2;
			cin >> streetLetter;
			if (id < 0)
				continue;
			if (id < fahrzeuge.size()) {
				switch (streetLetter) {
				case 'b':
				case 'B':
					boxgraben.vAnnahme(move(fahrzeuge[id]), startzeit);
					break;
				case 'a':
				case 'A':
					autobahn.vAnnahme(move(fahrzeuge[id]), startzeit);
					break;
				}
			}
			break;
		case 'z':
		case 'Z':
			cout << dGlobaleZeit << endl;
			break;
		case 'k':
		case 'K':
			Fahrzeug::vKopf();
			Weg::vKopf();
			break;
		}
	}
}*/

/*void vAufgabe_5() {
	Weg weg("Templergraben", 300);
	vector<unique_ptr<Fahrzeug>> fahrzeuge;
	fahrzeuge.push_back(make_unique<PKW>("BMW", 160, 9, 60));
	fahrzeuge.push_back(make_unique<PKW>("Audi", 250, 10, 100));
	fahrzeuge.push_back(make_unique<Fahrrad>("BMX", 55));
	Fahrzeug::vKopf();
	Weg::vKopf();
	cout << "(s)imulieren (-> Dauer), (a)usgeben (-> ID), vAnnahme (F)ahren (-> ID), vAnnahme (P)arken (-> ID, Startzeitpunkt), Globale (Z)eit ausgeben, (K)�pfe erneut anzeigen" << endl;
	while (true) {
		char operation;
		double deltaT;
		int id;
		double startzeit;
		cin >> operation;
		switch (operation) {
		case 's':
		case 'S':
			cin >> deltaT;
			dGlobaleZeit += deltaT;
			weg.vSimulieren();
			break;
		case 'a':
		case 'A':
			cin >> id;
			id--;
			if (id == -1)
				weg.vAusgeben(cout);
			if (id < fahrzeuge.size()) {
				try {
					fahrzeuge[id]->vAusgeben(cout);
				}
				catch (exception e) {
					cout << "Bitte nur Fahrzeuge abfragen, die nicht auf dem Weg sind (Besitz des unique_ptr wurde abgegeben)." << endl;
				}
			}
			break;
		case 'f':
		case 'F':
			cin >> id;
			id--;
			if (id == -1)
				continue;
			if (id < fahrzeuge.size())
				weg.vAnnahme(move(fahrzeuge[id]));
			break;
		case 'p':
		case 'P':
			cin >> id;
			cin >> startzeit;
			id--;
			if (id == -1)
				continue;
			if (id < fahrzeuge.size())
				weg.vAnnahme(move(fahrzeuge[id]), startzeit);
			break;
		case 'z':
		case 'Z':
			cout << dGlobaleZeit << endl;
			break;
		case 'k':
		case 'K':
			Fahrzeug::vKopf();
			Weg::vKopf();
			break;
		}
	}
}*/

/*void vAufgabe_4() {
	Weg weg("Mein Weg", 100, Tempolimit::innerorts);
	Weg::vKopf();
	cout << weg;
}*/

/*void vAufgabe_3() {
	vector<unique_ptr<Fahrzeug>> f;
	for (int i = 0; i < 2; i++) {
		cout << "Bitte Fahrzeugtyp (F, P) eingeben, dann den Namen und dann die Maximalgeschwindigkeit. Beim PKW auch den Verbrauch und das Tankvolumen (-1 => 55)" << endl;
		char c;
		cin >> c;
		string sName;
		cin >> sName;
		double dMaxGeschwindigkeit;
		cin >> dMaxGeschwindigkeit;
		switch (c) {
		case 'F':
			f.push_back(make_unique<Fahrrad>(sName, dMaxGeschwindigkeit));
			break;
		case 'P':
			double dVerbrauch;
			cin >> dVerbrauch;
			double dTankvolumen;
			cin >> dTankvolumen;
			if (dTankvolumen < 0)
				dTankvolumen = 55;
			f.push_back(make_unique<PKW>(sName, dMaxGeschwindigkeit, dVerbrauch, dTankvolumen));
			break;
		}
	}
	bool bFilled = false;
	for (;;) {
		double dDeltaTime;
		cin >> dDeltaTime;
		if (dDeltaTime <= 0) {
			return;
		}
		else {
			dGlobaleZeit += dDeltaTime;
			Fahrzeug::vKopf();
			auto it = f.cbegin();
			while (it != f.cend()) {
				(*it)->vSimulieren();
				if (!bFilled && dGlobaleZeit >= 3) {
					(*it)->dTanken();
				}
				cout << *(*it) << endl;
				it++;
			}
			if (!bFilled && dGlobaleZeit >= 3) {
				bFilled = true;
			}
		}
		if (*(f[0]) < *(f[1])) {
			cout << "Das Fahrzeug der ID 0 ist weniger weit gefahren" << endl;
		}
	}
}*/

/*void vAufgabe_2() {
	vector<unique_ptr<Fahrzeug>> f;
	for (int i = 0; i < 2; i++) {
		cout << "Bitte Fahrzeugtyp (F, P) eingeben, dann den Namen und dann die Maximalgeschwindigkeit. Beim PKW auch den Verbrauch und das Tankvolumen (-1 => 55)" << endl;
		char c;
		cin >> c;
		string sName;
		cin >> sName;
		double dMaxGeschwindigkeit;
		cin >> dMaxGeschwindigkeit;
		switch (c) {
		case 'F':
			f.push_back(make_unique<Fahrrad>(sName, dMaxGeschwindigkeit));
			break;
		case 'P':
			double dVerbrauch;
			cin >> dVerbrauch;
			double dTankvolumen;
			cin >> dTankvolumen;
			if (dTankvolumen < 0)
				dTankvolumen = 55;
			f.push_back(make_unique<PKW>(sName, dMaxGeschwindigkeit, dVerbrauch, dTankvolumen));
			break;
		}
	}
	bool bFilled = false;
	for (;;) {
		double dDeltaTime;
		cin >> dDeltaTime;
		if (dDeltaTime <= 0) {
			return;
		}
		else {
			dGlobaleZeit += dDeltaTime;
			Fahrzeug::vKopf();
			auto it = f.cbegin();
			while (it != f.cend()) {
				(*it)->vSimulieren();
				if (!bFilled && dGlobaleZeit >= 3) {
					(*it)->dTanken();
				}
				(*it)->vAusgeben();
				it++;
			}
			if (!bFilled && dGlobaleZeit >= 3) {
				bFilled = true;
			}
		}
	}
}*/

/*void vAufgabe_1a() {
	vector<unique_ptr<Fahrzeug>> v;
	for (int i = 0; i < 3; i++) {
		cout << "Bitte Name und H�chstgeschwindigkeit f�r Fahrzeug " << i + 1 << " eingeben" << endl;
		string name = "";
		double speed;
		cin >> name;
		cin >> speed;
		v.push_back(make_unique<Fahrzeug>(name, speed));
	}
	Fahrzeug::vKopf();
	cout << endl;
	for (double d = 0.1; d < 2; d *= 1.3) {
		dGlobaleZeit += d;
		v[0]->vSimulieren();
		v[2]->vSimulieren();
		v[1]->vSimulieren();
		v[2]->vSimulieren();
		v[0]->vAusgeben();
		cout << endl;
		v[1]->vAusgeben();
		cout << endl;
		v[2]->vAusgeben();
		cout << endl;
	}
}

void vAufgabe_1() {
	vector<unique_ptr<Fahrzeug>> v;
	v.push_back(make_unique<Fahrzeug>("BMW123 4", 30));
	v.push_back(make_unique<Fahrzeug>("au"));
	v.push_back(make_unique<Fahrzeug>());
	v.push_back(make_unique<Fahrzeug>());
	Fahrzeug::vKopf();
	cout << endl;
	v[0]->vAusgeben();
	cout << endl;
	v[1]->vAusgeben();
	cout << endl;
}*/

/*void vAufgabe_AB1() {

	int l = 0; // Laufindex f�r gezielte AUsgabe
	vector<int> ausgabe{ 13 };
	double dTakt = 0.4;

	std::vector<unique_ptr<Fahrzeug>> vecFahrzeuge;
	vecFahrzeuge.push_back(make_unique <PKW>("Audi", 229, 9.6));
	vecFahrzeuge.push_back(make_unique <Fahrrad>("BMX", 24.7));
	for (dGlobaleZeit = 0; dGlobaleZeit < 10; dGlobaleZeit += dTakt)
	{
		auto itL = find(ausgabe.begin(), ausgabe.end(), l);
		if (itL != ausgabe.end()) {
			std::cout << std::endl << l << " Globalezeit = " << dGlobaleZeit << std::endl;
			Fahrzeug::vKopf();
		}

		for (int i = 0; i < vecFahrzeuge.size(); i++)
		{
			vecFahrzeuge[i]->vSimulieren();
			if (fabs(dGlobaleZeit - 3.0) < dTakt / 2)
			{
				vecFahrzeuge[i]->dTanken();
			}
			if (itL != ausgabe.end()) {
				std::cout << *(vecFahrzeuge[i]) << endl;
			}
		}
		l++;
	}
	char c;
	std::cin >> c;
}*/
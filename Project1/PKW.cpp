#include "PKW.h"
#include "SimuClient.h"

extern double dGlobaleZeit;

PKW::PKW(string sName, double dMaxGeschwindigkeit, double dVerbrauch, double dTankvolumen):
	p_dVerbrauch(dVerbrauch),
	Fahrzeug(sName, dMaxGeschwindigkeit, dTankvolumen)
{
	cout << "PKW " << sName << " mit Maximalgeschwindigkeit " << dMaxGeschwindigkeit << ", Verbrauch " << dVerbrauch << " l/100km, Tankvolumen " << dTankvolumen << " l und ID " << p_iID << " erstellt\n";
}

PKW::~PKW()
{
	cout << "PKW " << p_sName << " gel�scht\n";
}

void PKW::vSimulieren()
{
	if (dGlobaleZeit > 2.9999 && p_dZeit <= 2.9999)
		dTanken(); //nach 3h nachtanken
	if (dGlobaleZeit - p_dZeit > 0)
		// Es wird angenommen, dass f�r den gesamten Simulationsschritt noch genug Reserve da ist
		if (p_dTankinhalt > 0.00001) { //falls der PKW nur epsilon im Tank hat, soll es nicht fahren.
			double dStreckeVorher = p_dGesamtStrecke;
			Fahrzeug::vSimulieren();
			double dDeltaStrecke = p_dGesamtStrecke - dStreckeVorher;
			p_dTankinhalt -= dDeltaStrecke * p_dVerbrauch / 100;
			if (p_dTankinhalt < 0) p_dTankinhalt = 0; //Tankinhalt < 0 l�st Fehler aus
		}
		else {
			p_dZeit = dGlobaleZeit;
		}
}

void PKW::vAusgeben(ostream& o) const
{
	Fahrzeug::vAusgeben(o);
	o << ' ' << setprecision(2) << setw(12) << p_dVerbrauch * p_dGesamtStrecke / 100 << endl;
}

void PKW::vZeichnen(const Weg& aWeg) const
{
	bZeichnePKW(p_sName, aWeg.getName(), p_dAbschnittStrecke / aWeg.getLaenge(), dGeschwindigkeit(), p_dTankinhalt);
}

PKW& PKW::operator=(const PKW& p)
{
	Fahrzeug::operator=(p);
	p_dVerbrauch = p.p_dVerbrauch;
	return *this;
}

ostream& operator<<(ostream& o, const PKW& p) {
	p.vAusgeben(o);
	return o;
}

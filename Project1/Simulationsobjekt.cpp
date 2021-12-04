#include "Simulationsobjekt.h"


int Simulationsobjekt::p_iMaxID = 0;

Simulationsobjekt::Simulationsobjekt(string sName):
	p_sName(sName),
	p_iID(p_iMaxID++)
{
	cout << "Simulationsobjekt " << p_sName << " mit ID " << p_iID << " erstellt\n";
}

Simulationsobjekt::~Simulationsobjekt()
{
	cout << "Simulationsobjekt " << p_sName << " mit ID " << p_iID << " gel�scht\n";
}

bool Simulationsobjekt::operator==(Simulationsobjekt& f)
{
	return this->p_iID == f.p_iID;
}

Simulationsobjekt& Simulationsobjekt::operator=(const Simulationsobjekt &s)
{
	this->p_sName = s.p_sName;
	return *this;
}

string Simulationsobjekt::getName()
{
	return p_sName;
}

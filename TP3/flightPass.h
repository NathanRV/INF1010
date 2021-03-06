/*
* Titre : membrePremium.h - Travail Pratique #3
* Date : 20 Septembre 2019
* Auteur : Jeffrey Lavallee
*/

#ifndef FLIGHT_PASS_H
#define FLIGHT_PASS_H

#include "billet.h"

class FlightPass : public Billet {
public:
	//constructeur par parametres
	FlightPass(const string& pnr, const string& nomPassager, double prix, const string& od, TarifBillet tarif, TypeBillet typeBillet);

	//fait
	void decrementeNbUtilisations();

	//fait
	 int getNbUtilisationsRestante() const;

	 //Surcharge operateur <<
	friend ostream& operator<<(ostream& os ,const FlightPass& flightpass);

private:
	 int nbUtilisationsRestante_;
};

#endif
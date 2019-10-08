/*
* Titre : billetRegulier.h - Travail Pratique #3
* Date : 20 Septembre 2019
* Auteur : Jeffrey Lavallee
 * Mise à jour le : 4 Octobre 2019
 * Par : Nathan RAMSAY-VEJLENS
*/

#ifndef BILLET_REGULIER_H
#define BILLET_REGULIER_H
#include "billet.h"

class BilletRegulier : public Billet {

public:
	
	//Constructeur par parametres
	BilletRegulier(const string& pnr, const string& nomPassager, double prix, const string& od, TarifBillet tarif, const string& dateVol, TypeBillet typeBillet);
	//Accesseur dateVol
	string getDateVol() const;
	//Modificateur dateVol
	void setDateVol(string dateVol);

	//surcharge operateur <<
	friend ostream& operator<<(ostream& o, const BilletRegulier& billet);
private:
	string dateVol_;
};

#endif
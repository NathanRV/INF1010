/********************************************
* Titre: Travail pratique #6 - billetRegulier.h
* Date: 21 novembre 2019
* Auteur: Allan BEDDOUK
*******************************************/

#ifndef BILLET_REGULIER_H
#define BILLET_REGULIER_H

#include <iomanip>

#include "billet.h"

class BilletRegulier : public Billet {

public:
	// Constructeur
	BilletRegulier(const string& pnr, double prix, const string& od, TarifBillet tarif, const string& dateVol);

	// Getter
	string getDateVol() const;

	// Setter
	void setDateVol(string dateVol);

	BilletRegulier* clone() const override;

	void afficher(ostream& o) const override;
private:
	string dateVol_;
};
#endif // !BILLET_REGULIER_H

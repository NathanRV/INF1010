/*
 * Date : 4 Octobre 2019
 * Auteur : Nathan RAMSAY-VEJLENS
 */

#include "billet.h"
#include "billetRegulier.h"

//Constructeur par paramètre
BilletRegulier::BilletRegulier(const string& pnr, const string& nomPassager, double prix, const string& od, TarifBillet tarif, const string& dateVol, TypeBillet typeBillet) 
	:	Billet(pnr, nomPassager, prix, od, tarif, typeBillet),
	dateVol_(dateVol)
{}


//Accesseur dateVol
string BilletRegulier::getDateVol() const {
	return dateVol_;
}

//Modificateur dateVol
void BilletRegulier::setDateVol(string dateVol) {
	dateVol_ = dateVol;
}

//Surcharge opérateur << (appeller afficheur de billet
ostream& operator<<(ostream& o, const BilletRegulier& billet) {
	o << billet.dateVol_ << endl;
	return o;
}

/*
 * Date : 4 Octobre 2019
 * Auteur : Nathan RAMSAY-VEJLENS
 */

#include "billetRegulier.h"

 /**
 *	Constructeur par parametres
 *	\param [in] const string&	pnr
 *	\param [in] const string&	nomPassager
 *	\param [in] double			prix
 *	\param [in] const string&	od
 *	\param [in] TarifBillet		tarif
 *	\param [in] const string&	dateVol
 *	\param [in]	TypeBillet		typeBillet
 */
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

//Surcharge opérateur << 
ostream& operator<<(ostream& o, const BilletRegulier& billet) {
	o << "\t\t- Billet " << billet.getPnr() << " (Classe : " << billet.formatTarif(billet.getTarif()) << ")" << endl;
	o << left << "\t\t\t" << setw(11) << "- Passager " << ": " << billet.getNomPassager() << endl;
	o << "\t\t\t" << setw(11) << "- Prix" << ": " << billet.getPrix() << "$" << endl;
	o << "\t\t\t" << setw(11) << "- Trajet" << ": " << billet.getOd() << endl;
	//affichage demandé sans la date de vol alors commenté
	//o << "\t\t\t" << setw(11) << "- Vol le" << ": " << billet.getDateVol() << endl;
	return o;
}

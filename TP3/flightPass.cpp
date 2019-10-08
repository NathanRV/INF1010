/*
 * Date : 4 Octobre 2019
 * Auteur : Nathan RAMSAY-VEJLENS
 */

#include "flightPass.h"

 /**
 *	Constructeurs par parametres
 *	\param [in] const string&	pnr
 *	\param [in]	const string&	nomPassager
 *	\param [in]	double			prix
 *	\param [in]	const string&	od
 *	\param [in] TarifBillet		tarifBillet
 *	\param [in] TypeBillet		typeBillet
 */
FlightPass::FlightPass(const string& pnr, const string& nomPassager, double prix, const string& od, TarifBillet tarif, TypeBillet typeBillet)
	:	Billet(pnr,nomPassager,prix,od,tarif,typeBillet),
	nbUtilisationsRestante_(NB_UTILISATIONS_INITIALE)
{}

//Decremente nbUtilisationsRestante
void FlightPass::decrementeNbUtilisations() {
	nbUtilisationsRestante_--;
}

//Accesseur de nbUtilisationsRestante_
int FlightPass::getNbUtilisationsRestante() const {
	return nbUtilisationsRestante_;
}


//Surcharge operateur <<
ostream& operator<<(ostream& os, const FlightPass& flightpass) {
	os << "\t\t- Billet " << flightpass.getPnr() << " (Classe : " << flightpass.formatTarif(flightpass.getTarif()) << ")" << endl;
	os << left << "\t\t\t" << setw(11) << "- Passager " << ": " << flightpass.getNomPassager() << endl;
	os << "\t\t\t" << setw(11) << "- Prix" << ": " << flightpass.getPrix() << "$" << endl;
	os << "\t\t\t" << setw(11) << "- Trajet" << ": " << flightpass.getOd() << endl;
	os << "\t\t\t" << setw(11) << "- Utilisation restantes" << ": " << flightpass.nbUtilisationsRestante_ << endl;
	return os;
}

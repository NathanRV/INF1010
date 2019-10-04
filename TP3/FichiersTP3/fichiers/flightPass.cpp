/*
 * Date : 4 Octobre 2019
 * Auteur : Nathan RAMSAY-VEJLENS
 */

#include "flightPass.h"

FlightPass::FlightPass(const string& pnr, const string& nomPassager, double prix, const string& od, TarifBillet tarif, TypeBillet typeBillet)
	:	Billet(pnr,nomPassager,prix,od,tarif,typeBillet),
	nbUtilisationsRestante_(NB_UTILISATIONS_INITIALE)
{}

//Modificateur nbr d'utilisations
void FlightPass::decrementeNbUtilisations() {
	nbUtilisationsRestante_--;
}

//Accesseur de nbUtilisationsRestante_
int FlightPass::getNbUtilisationsRestante() const {
	return nbUtilisationsRestante_;
}


//à faire
ostream& operator<<(ostream& os, const FlightPass& flightpass) {
	return os;
}

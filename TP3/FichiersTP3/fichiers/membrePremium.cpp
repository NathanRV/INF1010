/*
 * Date : 4 Octobre 2019
 * Auteur : Nathan RAMSAY-VEJLENS
 */

#include "membrePremium.h"

//Constructeur par parametre (a verifier)
MembrePremium::MembrePremium(const string& nom) 
	:	MembreRegulier(nom,TypeMembre::Membre_Premium),
	joursRestants_(JOUR_RESTANT_INITIALE),
	pointsCumules_(0)
{}

//Modificateurs

//jourRestants
void MembrePremium::setJourRestants(unsigned int joursRestants) {
	joursRestants_ = joursRestants;
}

//pointsCumulee
void MembrePremium::modifierPointsCumules(unsigned int pointCumulee) {
	pointsCumules_ = pointCumulee;
}


//Accesseurs

//jourRestants
unsigned int MembrePremium::getJourRestants() const {
	return joursRestants_;
}

//pointsCumule
unsigned int MembrePremium::getpointsCumulee() const {
	return pointsCumules_;
}

//Autres methodes

//AjouterBillet (À VÉRIFIER)
void MembrePremium::ajouterBillet(const string& pnr, double prix, const string& od, TarifBillet tarifBillet, TypeBillet typeBillet, const string& dateVol) {
	Billet* billet = nullptr;
	if (typeBillet == TypeBillet::Billet_Base) {
		billet = new Billet(pnr, nom_, prix, od, tarifBillet, typeBillet);
	}
	else if (typeBillet == TypeBillet::Billet_Regulier) {
		billet = new BilletRegulier(pnr, nom_, prix, od, tarifBillet, dateVol, typeBillet);
	}
	else if (typeBillet == TypeBillet::Flight_Pass) {
		billet = new FlightPass(pnr, nom_, prix, od, tarifBillet, typeBillet);
	}
	billets_.push_back(billet);
	modifierPoints(calculerPoints(billet));
}

//AcheterCoupon (À VÉRIFIER)
void MembrePremium::acheterCoupon(Coupon* coupon) {

}

//Affichage (À FINALISER)
ostream& operator<<(ostream& os, const MembrePremium& membrePremium) {
	
	return os;
}

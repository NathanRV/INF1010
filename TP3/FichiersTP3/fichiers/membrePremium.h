/*
* Titre : membrePremium.h - Travail Pratique #3
* Date : 20 Septembre 2019
* Auteur : Jeffrey Lavallee
*/


#ifndef MEMBRE_PREMIUM_H
#define MEMBRE_PREMIUM_H


#include "membreRegulier.h"

class MembrePremium : public MembreRegulier {
public:
	//à faire
	MembrePremium(const string& nom);

	//setters
	//Fait
	void setJourRestants(unsigned int joursRestants);
	//Fait
	void modifierPointsCumules(unsigned int pointCumulee);


	//getters
	//Fait
	unsigned int getJourRestants() const;
	//Fait
	unsigned int getpointsCumulee() const;

	//Fait (à vérifier)
	void ajouterBillet(const string& pnr, double prix, const string& od, TarifBillet tarif, TypeBillet typeBillet, const string& dateVol);
	//à faire
	void acheterCoupon(Coupon* coupon);

	//à faire
	friend ostream& operator<<(ostream& os, const MembrePremium& membrePremium);

private:
	unsigned int joursRestants_;
	unsigned int pointsCumules_;

};

#endif
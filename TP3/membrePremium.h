/*
* Titre : membrePremium.h - Travail Pratique #3
* Date : 20 Septembre 2019
* Auteur : Jeffrey Lavallee
 * Mise à jour le : 4 Octobre 2019
 * Par : Nathan RAMSAY-VEJLENS
*/


#ifndef MEMBRE_PREMIUM_H
#define MEMBRE_PREMIUM_H


#include "membreRegulier.h"

class MembrePremium : public MembreRegulier {
public:
	//constructeur par parametres
	MembrePremium(const string& nom);

	//Modificateurs
	//Fait
	void setJourRestants(unsigned int joursRestants);
	//Fait
	void modifierPointsCumules(unsigned int pointCumulee);

	//Surcharge modifierPoints

	//Accesseurs
	//Fait
	unsigned int getJourRestants() const;
	//Fait
	unsigned int getpointsCumulee() const;

	//ajouteBillet selon type
	void ajouterBillet(const string& pnr, double prix, const string& od, TarifBillet tarif, TypeBillet typeBillet, const string& dateVol) override;
	//achete coupon
	void acheterCoupon(Coupon* coupon) override;

	//surcharge operateur <<
	friend ostream& operator<<(ostream& os, const MembrePremium& membrePremium);

private:
	unsigned int joursRestants_;
	unsigned int pointsCumules_;

};

#endif
/*
* Titre : membreRegulier.h - Travail Pratique #3
* Date : 20 Septembre 2019
* Auteur : Jeffrey Lavallee
 * Mise à jour le : 4 Octobre 2019
 * Par : Nathan RAMSAY-VEJLENS
*/


#ifndef MEMBRE_REGULIER_H
#define MEMBRE_REGULIER_H


#include "membre.h"

class MembreRegulier : public Membre {
public:

	//constructeur par parametres
	MembreRegulier(const string& nom, TypeMembre typeMembre);

	int getPoints() const;
	vector<Coupon*> getCoupons() const;
	

	virtual void acheterCoupon(Coupon* coupon);
	Membre& operator+=(Coupon* coupon);
	Membre& operator-=(Coupon* coupon);
	void modifierPoints(int points);

	//ajouteBillet selon type
	void ajouterBillet(const string& pnr, double prix, const string& od, TarifBillet tarif, TypeBillet typeBillet, const string& dateVol) override;


	double calculerPoints(Billet* billet) const;

	//surcharge operateur <<
	friend ostream& operator<<(ostream& os, const MembreRegulier& membreRegulier);

protected:
	int points_;
	vector<Coupon*> coupons_;
};

#endif
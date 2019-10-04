/*
* Titre : membreRegulier.h - Travail Pratique #3
* Date : 20 Septembre 2019
* Auteur : Jeffrey Lavallee
 * Mise � jour le : 4 Octobre 2019
 * Par : Nathan RAMSAY-VEJLENS
*/


#ifndef MEMBRE_REGULIER_H
#define MEMBRE_REGULIER_H


#include "membre.h"

class MembreRegulier : public Membre {
public:

	//Fait
	MembreRegulier(const string& nom, TypeMembre typeMembre);

	int getPoints() const;
	vector<Coupon*> getCoupons() const;
	

	void acheterCoupon(Coupon* coupon);
	Membre& operator+=(Coupon* coupon);
	Membre& operator-=(Coupon* coupon);
	void modifierPoints(int points);

	//fait (� v�rifier)
	void ajouterBillet(const string& pnr, double prix, const string& od, TarifBillet tarif, TypeBillet typeBillet, const string& dateVol);


	double calculerPoints(Billet* billet) const;

	//� faire
	friend ostream& operator<<(ostream& os, const MembreRegulier& membreRegulier);

protected:
	int points_;
	vector<Coupon*> coupons_;
};

#endif
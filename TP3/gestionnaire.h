/*
 * Date : 12 Septembre 2019
 * Auteur : Philippe CÔTÉ-MORNEAULT
 * Mise à jour le : 4 Octobre 2019
 * Par : Nathan RAMSAY-VEJLENS
 */

#ifndef GESTIONNAIRE_H
#define	GESTIONNAIRE_H

#include <vector>

#include "membrePremium.h"

class Gestionnaire {
public:
	// Constructeurs
	Gestionnaire();

	~Gestionnaire();

	// Accesseurs
	vector<Membre*> getMembres() const;
	vector<Coupon*> getCoupons() const;

	//AjouteMembre
	void ajouterMembre(const string& nomMembre, TypeMembre);

	void ajouterCoupon(const string& code, double rabais, int cout);

	Membre* trouverMembre(const string& nomMembre) const;

	//assigneBillet à un membre
	void assignerBillet(const string& nomMembre, const string& pnr, double prixBase, const string& od, TarifBillet tarif, const string& dateVol, bool utiliserCoupon, TypeBillet typeBillet);

	//applique coupon à un prix
	double appliquerCoupon(Membre* membre, double prix);
	
	//achete coupon
	void acheterCoupon(const string& nomMembre);

	//surcharge operateur <<
	friend ostream& operator<<(ostream& o, const Gestionnaire& gestionnaire);
private:
	vector<Membre*> membres_;
	vector<Coupon*> coupons_;
};

#endif // !GESTIONNAIRE_H




/*
 * Date : 12 Septembre 2019
 * Auteur : Philippe CÔTÉ-MORNEAULT
 */

#ifndef MEMBRE_H
#define MEMBRE_H

#include <string>
#include <vector>

#include "billet.h"
#include "coupon.h"

using namespace std;

class Membre {
public:
	// Constructeurs
	Membre();
	Membre(const string& nom);
	// TODO: Ajouter un constructeur par copie si necessaire
	Membre(const Membre& membre);

	~Membre();

	// Getters
	string getNom() const;
	int getPoints() const;
	vector<Billet*> getBillets() const;
	vector<Coupon*> getCoupons() const;

	// Setters
	void setNom(const string& nom);

	void modifierPoints(int points);
	void ajouterBillet(const string& pnr, double prix, const string& od, TarifBillet tarif, const string& dateVol);
	void acheterCoupon(Coupon* coupon);
	double calculerPoints(Billet* billet) const;

	// Remplacer cette methode(ajouterCoupon) par l'operateur +=
	Membre& operator+=(Coupon* coupon);

	// Remplace cette methode(retirerCoupon) par l'operateur -=
	Membre& operator-=(Coupon* coupon);
	
	// TODO: Surcharger l'operateur == (operande de gauche est un membre et droite est un string)
	bool operator==(const string nom) const;
	// TODO: Surcharger l'operateur == (operande de gauche est un string et droite est un membre)
	friend bool operator==(const string nom, const Membre& membre);
	// TODO: Surcharger l'operateur =
	Membre& operator=(const Membre& membre);

	// TODO: Remplacer cette methode par l'operateur <<
	//void afficherMembre() const;
	friend ostream& operator<<(ostream& os, const Membre& membre);

private:
	string nom_;
	int points_;
	vector<Billet*>billets_;
	vector<Coupon*>coupons_;
};
#endif // !MEMBRE_H

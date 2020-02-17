/********************************************
* Titre: Travail pratique #5 - membreRegulier.h
* Date: 30 octobre 2019
* Auteur: Allan BEDDOUK & Jeffrey LAVALLEE
* Modification : Nathan RAMSAY-VEJLENS
* Modifié le : 13 novembre 2019
*******************************************/

#ifndef MEMBRE_REGULIER_H
#define MEMBRE_REGULIER_H

#include "membre.h"

class MembreRegulier : public Membre {
public:
	// Constructeur
	MembreRegulier(const string& nom);

	// Getters
	int getPoints() const;
	vector<Coupon*> getCoupons() const;
	
	Membre& operator+=(Coupon* coupon);

	/****************************************************************************
	* Fonction:		MembreRegulier::operator-=
	* Description:	Permet d'enlever un coupon du vecteur de coupon
	* Paramètres:	Coupon* coupon
	* Retour:		Membre&
	****************************************************************************/
	Membre& operator-=(Coupon* coupon);
	void modifierPoints(int points);
	void ajouterBillet(Billet* billet) override;

	double calculerPoints(Billet* billet) const;
	virtual bool peutAcheterCoupon(Coupon* coupon) const;
	virtual void acheterCoupon(Coupon* coupon);
	/****************************************************************************
	* Fonction:		MembreRegulier::afficher
	* Description:	Permet d'afficher les attributs d'un MembreRegulier
	* Paramètres:	ostream& o
	* Retour:		aucun
	****************************************************************************/
	void afficher(ostream& o) const override;
protected:
	int points_;
	vector<Coupon*> coupons_;
};
#endif // !MEMBRE_REGULIER_H
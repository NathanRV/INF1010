/*
* Titre : membreRegulier.h - Travail Pratique #4
* Date : 5 Octobre 2019
* Auteur : Philippe CÔTÉ-MORNEAULT
*/

#ifndef MEMBRE_REGULIER_H
#define MEMBRE_REGULIER_H

#include "membre.h"
#include "debogageMemoire.hpp"

class MembreRegulier : public Membre {
public:
	// Constructeur
	/****************************************************************************
* Fonction:		MembreRegulier::MembreRegulier()
* Description:	Constructeur par paramètres
* Paramètres:	const string& nom
* Retour:		aucun
****************************************************************************/
	MembreRegulier(const string& nom);

	// Getters
	/****************************************************************************
* Fonction:		MembreRegulier::getPoints() const
* Description:	Retourne nombre de points
* Paramètres:	Aucun
* Retour:		int
****************************************************************************/
	int getPoints() const;

	/****************************************************************************
* Fonction:		MembreRegulier::getCoupons() const
* Description:	Retourne vecteur de pointeur de coupons
* Paramètres:	Aucun
* Retour:		vector<Coupon*>
****************************************************************************/
	vector<Coupon*> getCoupons() const;
	
	/****************************************************************************
* Fonction:		MembreRegulier::operator+=() 
* Description:	surcharge opérateur += pour ajouter un coupon
* Paramètres:	Coupon* coupon
* Retour:		Membre&
****************************************************************************/
	Membre& operator+=(Coupon* coupon);

	/****************************************************************************
* Fonction:		MembreRegulier::operator-=()
* Description:	surcharge opérateur -= pour supprimer un coupon
* Paramètres:	Coupon* coupon
* Retour:		Membre&
****************************************************************************/
	Membre& operator-=(Coupon* coupon);

	/****************************************************************************
* Fonction:		MembreRegulier::modifierPoints()
* Description:	Modifier point en ajoutant la valeur de points
* Paramètres:	int points
* Retour:		aucun
****************************************************************************/
	void modifierPoints(int points);

	/****************************************************************************
* Fonction:		MembreRegulier::ajouterBillet()
* Description:	appel fonction ajouterBillet de Membre et modifier points
* Paramètres:	Billet* billet
* Retour:		aucun
****************************************************************************/
	void ajouterBillet(Billet* billet) override;

	/****************************************************************************
* Fonction:		MembreRegulier::calculerPoints()
* Description:	Calcule le nombre de points que rapporte le billet
* Paramètres:	Billet* billet
* Retour:		double
****************************************************************************/
	double calculerPoints(Billet* billet) const;
	
	/****************************************************************************
* Fonction:		MembreRegulier::peutAcheterCoupon()
* Description:	Verifie si assez de points pour acheter le coupon
* Paramètres:	Coupon* coupon
* Retour:		bool
****************************************************************************/
	bool peutAcheterCoupon(Coupon* coupon);

	/****************************************************************************
* Fonction:		MembreRegulier::acheterCoupon()
* Description:	Achete le coupon
* Paramètres:	Coupon* coupon
* Retour:		aucun
****************************************************************************/
	virtual void acheterCoupon(Coupon* coupon);

	/****************************************************************************
  * Fonction:	MembreRegulier::afficher()
  * Description:Fonction affichage de la classe
  * Paramètres:	ostream& o
  * Retour:		aucun
  ****************************************************************************/
	void afficher(ostream& o);
protected:
	int points_;
	vector<Coupon*> coupons_;
};
#endif // !MEMBRE_REGULIER_H
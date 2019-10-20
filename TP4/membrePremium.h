/*
* Titre : membrePremium.h - Travail Pratique #4
* Date : 5 Octobre 2019
* Auteur : Philippe CÔTÉ-MORNEAULT
*/

#ifndef MEMBRE_PREMIUM_H
#define MEMBRE_PREMIUM_H

#include "membreRegulier.h"
#include "debogageMemoire.hpp"

class MembrePremium : public MembreRegulier {
public:
	// Constructeur
	/****************************************************************************
* Fonction:		MembrePremium::MembrePremium()
* Description:	Constructeur par paramètres
* Paramètres:	const string& nom
* Retour:		aucun
****************************************************************************/
	MembrePremium(const string& nom);

	// Setters
	/****************************************************************************
* Fonction:		MembrePremium::setJoursRestants()
* Description:	Modifie le nombre de jours restants pour la valeur passée
* Paramètres:	unsigned int joursRestants
* Retour:		aucun
****************************************************************************/
	void setJourRestants(unsigned int joursRestants);

	/****************************************************************************
* Fonction:		MembrePremium::modifierPointsCumulee()
* Description:	Modifie le nombre de points cumulee en ajoutant la valeur passée en paramètres
* Paramètres:	unsigned int pointCumulee
* Retour:		aucun
****************************************************************************/
	void modifierPointsCumulee(unsigned int pointCumulee);

	// Getters
	/****************************************************************************
* Fonction:		MembrePremium::getJourRestants() const
* Description:	Retourne le nombre de jours restants en tant que membre premium
* Paramètres:	Aucun
* Retour:		unsigned int
****************************************************************************/
	unsigned int getJourRestants() const;

	/****************************************************************************
* Fonction:		MembrePremium::getpointsCumulee() const
* Description:	Retourne le nombre de points cumulées
* Paramètres:	Aucun
* Retour:		unsigned int
****************************************************************************/
	unsigned int getpointsCumulee() const;


	/****************************************************************************
	* Fonction:		MembrePremium::ajouterBillet()
	* Description:	Ajouter un billet au vecteur de billet du membre
	* Paramètres:	Billet* billet
	* Retour:		aucun
	****************************************************************************/
	void ajouterBillet(Billet* billet) override;

	/****************************************************************************
* Fonction:		MembrePremium::calculerCoutCoupon()
* Description:	Calcule le nombre de points que coute le coupon
* Paramètres:	Coupon* coupon
* Retour:		double
****************************************************************************/
	double calculerCoutCoupon(Coupon* coupon);

	/****************************************************************************
	* Fonction:		MembrePremium::peutAcheterCoupon()
	* Description:	Verifie si assez de points pour acheter le coupon
	* Paramètres:	Coupon* coupon
	* Retour:		bool
	****************************************************************************/
	bool peutAcheterCoupon(Coupon* coupon);

	/****************************************************************************
* Fonction:		MembrePremium::acheterCoupon()
* Description:	Achete le coupon et modifie points
* Paramètres:	Coupon* coupon
* Retour:		aucun
****************************************************************************/
	void acheterCoupon(Coupon* coupon) override;

	/****************************************************************************
* Fonction:	MembrePremium::afficher()
* Description:Fonction affichage de la classe
* Paramètres:	ostream& o
* Retour:		aucun
****************************************************************************/
	void afficher(ostream& o);
private:
	unsigned int joursRestants_;
	unsigned int pointsCumulee_;
};
#endif // !MEMBRE_PREMIUM_H
/*
* Titre : membrePremium.h - Travail Pratique #4
* Date : 5 Octobre 2019
* Auteur : Philippe C�T�-MORNEAULT
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
* Description:	Constructeur par param�tres
* Param�tres:	const string& nom
* Retour:		aucun
****************************************************************************/
	MembrePremium(const string& nom);

	// Setters
	/****************************************************************************
* Fonction:		MembrePremium::setJoursRestants()
* Description:	Modifie le nombre de jours restants pour la valeur pass�e
* Param�tres:	unsigned int joursRestants
* Retour:		aucun
****************************************************************************/
	void setJourRestants(unsigned int joursRestants);

	/****************************************************************************
* Fonction:		MembrePremium::modifierPointsCumulee()
* Description:	Modifie le nombre de points cumulee en ajoutant la valeur pass�e en param�tres
* Param�tres:	unsigned int pointCumulee
* Retour:		aucun
****************************************************************************/
	void modifierPointsCumulee(unsigned int pointCumulee);

	// Getters
	/****************************************************************************
* Fonction:		MembrePremium::getJourRestants() const
* Description:	Retourne le nombre de jours restants en tant que membre premium
* Param�tres:	Aucun
* Retour:		unsigned int
****************************************************************************/
	unsigned int getJourRestants() const;

	/****************************************************************************
* Fonction:		MembrePremium::getpointsCumulee() const
* Description:	Retourne le nombre de points cumul�es
* Param�tres:	Aucun
* Retour:		unsigned int
****************************************************************************/
	unsigned int getpointsCumulee() const;


	/****************************************************************************
	* Fonction:		MembrePremium::ajouterBillet()
	* Description:	Ajouter un billet au vecteur de billet du membre
	* Param�tres:	Billet* billet
	* Retour:		aucun
	****************************************************************************/
	void ajouterBillet(Billet* billet) override;

	/****************************************************************************
* Fonction:		MembrePremium::calculerCoutCoupon()
* Description:	Calcule le nombre de points que coute le coupon
* Param�tres:	Coupon* coupon
* Retour:		double
****************************************************************************/
	double calculerCoutCoupon(Coupon* coupon);

	/****************************************************************************
	* Fonction:		MembrePremium::peutAcheterCoupon()
	* Description:	Verifie si assez de points pour acheter le coupon
	* Param�tres:	Coupon* coupon
	* Retour:		bool
	****************************************************************************/
	bool peutAcheterCoupon(Coupon* coupon);

	/****************************************************************************
* Fonction:		MembrePremium::acheterCoupon()
* Description:	Achete le coupon et modifie points
* Param�tres:	Coupon* coupon
* Retour:		aucun
****************************************************************************/
	void acheterCoupon(Coupon* coupon) override;

	/****************************************************************************
* Fonction:	MembrePremium::afficher()
* Description:Fonction affichage de la classe
* Param�tres:	ostream& o
* Retour:		aucun
****************************************************************************/
	void afficher(ostream& o);
private:
	unsigned int joursRestants_;
	unsigned int pointsCumulee_;
};
#endif // !MEMBRE_PREMIUM_H
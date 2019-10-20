/*
* Titre : membrePremium.cpp - Travail Pratique #4
* Date : 5 Octobre 2019
* Auteur : Philippe C�T�-MORNEAULT
* Mise � jour : Nathan Ramsay-Vejlens
* Date mise � jour : 17 octobre 2019
*/

#include "membrePremium.h"

/****************************************************************************
* Fonction:		MembrePremium::MembrePremium()
* Description:	Constructeur par param�tres
* Param�tres:	const string& nom
* Retour:		aucun
****************************************************************************/
MembrePremium::MembrePremium(const string& nom) : 
	MembreRegulier(nom), joursRestants_(JOUR_RESTANT_INITIALE), pointsCumulee_(0)
{
}

/****************************************************************************
* Fonction:		MembrePremium::setJoursRestants()
* Description:	Modifie le nombre de jours restants pour la valeur pass�e
* Param�tres:	unsigned int joursRestants
* Retour:		aucun
****************************************************************************/
void MembrePremium::setJourRestants(unsigned int joursRestants)
{
	joursRestants_ = joursRestants;
}

/****************************************************************************
* Fonction:		MembrePremium::modifierPointsCumulee()
* Description:	Modifie le nombre de points cumulee en ajoutant la valeur pass�e en param�tres
* Param�tres:	unsigned int pointCumulee
* Retour:		aucun
****************************************************************************/
void MembrePremium::modifierPointsCumulee(unsigned int pointCumulee)
{
	pointsCumulee_ += pointCumulee;
}

/****************************************************************************
* Fonction:		MembrePremium::getJourRestants() const
* Description:	Retourne le nombre de jours restants en tant que membre premium
* Param�tres:	Aucun
* Retour:		unsigned int
****************************************************************************/
unsigned int MembrePremium::getJourRestants() const
{
	return joursRestants_;
}

/****************************************************************************
* Fonction:		MembrePremium::getpointsCumulee() const
* Description:	Retourne le nombre de points cumul�es
* Param�tres:	Aucun
* Retour:		unsigned int
****************************************************************************/
unsigned int MembrePremium::getpointsCumulee() const
{
	return pointsCumulee_;
}

/****************************************************************************
	* Fonction:		MembrePremium::ajouterBillet()
	* Description:	Ajouter un billet au vecteur de billet du membre et modifie les points cumul�es
	* Param�tres:	Billet* billet
	* Retour:		aucun
	****************************************************************************/
void MembrePremium::ajouterBillet(Billet* billet)
{
	MembreRegulier::ajouterBillet(billet);
	modifierPointsCumulee(calculerPoints(billets_.back()));
}

/****************************************************************************
* Fonction:		MembrePremium::calculerCoutCoupon()
* Description:	Calcule le nombre de points que coute le coupon
* Param�tres:	Coupon* coupon
* Retour:		double
****************************************************************************/
double MembrePremium::calculerCoutCoupon(Coupon* coupon)
{
	double rabais = 0.01 * pointsCumulee_ / 1000;

	if (rabais > 0.2)
		rabais = 0.2;

	return coupon->getCout() * (1 - rabais);
}

/****************************************************************************
* Fonction:		MembrePremium::peutAcheterCoupon()
* Description:	Verifie si assez de points pour acheter le coupon
* Param�tres:	Coupon* coupon
* Retour:		bool
****************************************************************************/
bool MembrePremium::peutAcheterCoupon(Coupon* coupon)
{
	if(points_>=calculerCoutCoupon(coupon))
	{
		return true;
	}
	return false;
}

/****************************************************************************
* Fonction:		MembrePremium::acheterCoupon()
* Description:	Achete le coupon et modifie points
* Param�tres:	Coupon* coupon
* Retour:		aucun
****************************************************************************/
void MembrePremium::acheterCoupon(Coupon* coupon)
{
	if (peutAcheterCoupon(coupon)) {
		*this += coupon;
		modifierPoints(-calculerCoutCoupon(coupon));
	}
}

/****************************************************************************
* Fonction:	MembrePremium::afficher()
* Description:Fonction affichage de la classe
* Param�tres:	ostream& o
* Retour:		aucun
****************************************************************************/
void MembrePremium::afficher(ostream& o)
{
	dynamic_cast<MembreRegulier*>(this)->afficher(o);
	o << "\t- Points cumulee: " << pointsCumulee_ << endl;
	o << "\t- Jours premium restant: " << joursRestants_ << endl;
}
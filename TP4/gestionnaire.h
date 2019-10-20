/*
* Titre : gestionnaire.h - Travail Pratique #4
* Date : 5 Octobre 2019
* Auteur : Philippe C�T�-MORNEAULT
* Mise � jour : Nathan Ramsay-Vejlens
* Date mise � jour : 17 octobre 2019
*/

#ifndef GESTIONNAIRE_H
#define	GESTIONNAIRE_H

#include <vector>

#include "membrePremium.h"
#include "solde.h"
#include "debogageMemoire.hpp"

class Gestionnaire {
public:
	// Constructeur
	/****************************************************************************
* Fonction:		Gestionnaire::Gestionnaire()
* Description:	Constructeur par d�faut
* Param�tres:	aucun
* Retour:		aucun
****************************************************************************/
	Gestionnaire();

	/****************************************************************************
* Fonction:		Gestionnaire::~Gestionnaire()
* Description:	destructeur virtuel
* Param�tres:	aucun
* Retour:		aucun
****************************************************************************/
	~Gestionnaire();

	// Getters
	/****************************************************************************
* Fonction:		Gestionnaire::getMembres() const
* Description:	retourne vecteur de pointeurs de membres 
* Param�tres:	aucun
* Retour:		vector<Membre*>
****************************************************************************/
	vector<Membre*> getMembres() const;

	/****************************************************************************
* Fonction:		Gestionnaire::getCoupons() const
* Description:	retourne vecteur de pointeurs de coupons
* Param�tres:	aucun
* Retour:		vector<Coupon*>
****************************************************************************/
	vector<Coupon*> getCoupons() const;

	/****************************************************************************
* Fonction:		Gestionnaire::ajouterMembre()
* Description:	Ajoute un membre au vecteur de pointeur de membre
* Param�tres:	Membre* membre
* Retour:		aucun
****************************************************************************/
	void ajouterMembre(Membre* membre);

	/****************************************************************************
* Fonction:		Gestionnaire::ajouterCoupon()
* Description:	Ajoute un coupon au vecteur de pointeur de coupon
* Param�tres:	Coupon* coupon
* Retour:		aucun
****************************************************************************/
	void ajouterCoupon(Coupon* coupon);

	/****************************************************************************
* Fonction:		Gestionnaire::trouverMembre() const
* Description:	Cherche membre dans le veceteur de pointeur de membre avec son nom
* Param�tres:	const string& nomMembre
* Retour:		Membre*
****************************************************************************/
	Membre* trouverMembre(const string& nomMembre) const;
	
	/****************************************************************************
* Fonction:		Gestionnaire::assignerBillet()
* Description:	Assigne un billet � un membre en utilisant(ou pas) un coupon
* Param�tres:	Billet* billet, const string& nomMembre, bool utiliserCoupon
* Retour:		aucun
****************************************************************************/
	void assignerBillet(Billet* billet, const string& nomMembre, bool utiliserCoupon);

	/****************************************************************************
* Fonction:		Gestionnaire::appliquerCoupon()
* Description:	Applique un coupon du membre � un prix pass� en valeur 
* Param�tres:	Membre* membre, double prix
* Retour:		double
****************************************************************************/
	double appliquerCoupon(Membre* membre, double prix);

	/****************************************************************************
* Fonction:		Gestionnaire::acheterCoupon()
* Description:	Achete un coupon pour le membre
* Param�tres:	const string& nomMembre
* Retour:		aucun
****************************************************************************/
	void acheterCoupon(const string& nomMembre);

	/****************************************************************************
* Fonction:		Gestionnaire::calculerRevenu()
* Description:	Calcule le revenu fait sur les billets achet�s
* Param�tres:	aucun
* Retour:		double
****************************************************************************/
	double calculerRevenu();
	
	/****************************************************************************
* Fonction:		Gestionnaire::calculerNombreBilletsEnSolde()
* Description:	Calcule nombre de billets en solde
* Param�tres:	aucun
* Retour:		int
****************************************************************************/
	int calculerNombreBilletsEnSolde();

	/****************************************************************************
* Fonction:		Gestionnaire::afficher()
* Description:	Fonction affichage de la classe
* Param�tres:	ostream& o
* Retour:		aucun
****************************************************************************/
	void afficher(ostream& o);
private:
	vector<Membre*> membres_;
	vector<Coupon*> coupons_;
};
#endif // !GESTIONNAIRE_H




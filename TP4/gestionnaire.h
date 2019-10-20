/*
* Titre : gestionnaire.h - Travail Pratique #4
* Date : 5 Octobre 2019
* Auteur : Philippe CÔTÉ-MORNEAULT
* Mise à jour : Nathan Ramsay-Vejlens
* Date mise à jour : 17 octobre 2019
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
* Description:	Constructeur par défaut
* Paramètres:	aucun
* Retour:		aucun
****************************************************************************/
	Gestionnaire();

	/****************************************************************************
* Fonction:		Gestionnaire::~Gestionnaire()
* Description:	destructeur virtuel
* Paramètres:	aucun
* Retour:		aucun
****************************************************************************/
	~Gestionnaire();

	// Getters
	/****************************************************************************
* Fonction:		Gestionnaire::getMembres() const
* Description:	retourne vecteur de pointeurs de membres 
* Paramètres:	aucun
* Retour:		vector<Membre*>
****************************************************************************/
	vector<Membre*> getMembres() const;

	/****************************************************************************
* Fonction:		Gestionnaire::getCoupons() const
* Description:	retourne vecteur de pointeurs de coupons
* Paramètres:	aucun
* Retour:		vector<Coupon*>
****************************************************************************/
	vector<Coupon*> getCoupons() const;

	/****************************************************************************
* Fonction:		Gestionnaire::ajouterMembre()
* Description:	Ajoute un membre au vecteur de pointeur de membre
* Paramètres:	Membre* membre
* Retour:		aucun
****************************************************************************/
	void ajouterMembre(Membre* membre);

	/****************************************************************************
* Fonction:		Gestionnaire::ajouterCoupon()
* Description:	Ajoute un coupon au vecteur de pointeur de coupon
* Paramètres:	Coupon* coupon
* Retour:		aucun
****************************************************************************/
	void ajouterCoupon(Coupon* coupon);

	/****************************************************************************
* Fonction:		Gestionnaire::trouverMembre() const
* Description:	Cherche membre dans le veceteur de pointeur de membre avec son nom
* Paramètres:	const string& nomMembre
* Retour:		Membre*
****************************************************************************/
	Membre* trouverMembre(const string& nomMembre) const;
	
	/****************************************************************************
* Fonction:		Gestionnaire::assignerBillet()
* Description:	Assigne un billet à un membre en utilisant(ou pas) un coupon
* Paramètres:	Billet* billet, const string& nomMembre, bool utiliserCoupon
* Retour:		aucun
****************************************************************************/
	void assignerBillet(Billet* billet, const string& nomMembre, bool utiliserCoupon);

	/****************************************************************************
* Fonction:		Gestionnaire::appliquerCoupon()
* Description:	Applique un coupon du membre à un prix passé en valeur 
* Paramètres:	Membre* membre, double prix
* Retour:		double
****************************************************************************/
	double appliquerCoupon(Membre* membre, double prix);

	/****************************************************************************
* Fonction:		Gestionnaire::acheterCoupon()
* Description:	Achete un coupon pour le membre
* Paramètres:	const string& nomMembre
* Retour:		aucun
****************************************************************************/
	void acheterCoupon(const string& nomMembre);

	/****************************************************************************
* Fonction:		Gestionnaire::calculerRevenu()
* Description:	Calcule le revenu fait sur les billets achetés
* Paramètres:	aucun
* Retour:		double
****************************************************************************/
	double calculerRevenu();
	
	/****************************************************************************
* Fonction:		Gestionnaire::calculerNombreBilletsEnSolde()
* Description:	Calcule nombre de billets en solde
* Paramètres:	aucun
* Retour:		int
****************************************************************************/
	int calculerNombreBilletsEnSolde();

	/****************************************************************************
* Fonction:		Gestionnaire::afficher()
* Description:	Fonction affichage de la classe
* Paramètres:	ostream& o
* Retour:		aucun
****************************************************************************/
	void afficher(ostream& o);
private:
	vector<Membre*> membres_;
	vector<Coupon*> coupons_;
};
#endif // !GESTIONNAIRE_H




#pragma once
/********************************************
* Titre: Travail pratique #5 - gestionnaireMembres.h
* Date: 30 octobre 2019
* Auteur: Allan BEDDOUK & Jeffrey LAVALLEE
* Modification : Nathan RAMSAY-VEJLENS
* Modifi� le : 12 novembre 2019
*******************************************/

#ifndef GESTIONNAIREMEMBRES_H
#define	GESTIONNAIREMEMBRES_H

#include <vector>
#include <map>
#include <string>
#include "membrePremium.h"
#include "solde.h"
#include "gestionnaireGenerique.h"
#include "foncteur.h"
#include "billet.h"

class GestionnaireMembres: public GestionnaireGenerique <pair<string, Membre*>, map<string, Membre*>, AjouterMembre> 
{
public:
	/****************************************************************************
	* Fonction:		GestionnaireCoupons::assignerBillet()
	* Description:	assigne un billet � un membre en appliquant un coupon
	* Param�tres:	Billet8 billet, const string& nomMembre, int rabaisCoupon
	* Retour:		aucun
	****************************************************************************/
	void assignerBillet(Billet* billet, const string& nomMembre, int rabaisCoupon);

	/****************************************************************************
	* Fonction:		GestionnaireMembres::~GestionnaireMembres()
	* Description:	Destructeur
	* Param�tres:	aucun
	* Retour:		aucun
	****************************************************************************/
	virtual ~GestionnaireMembres();

	/****************************************************************************
	* Fonction:		GestionnaireMembres::calculerRevenu() const
	* Description:	calcule la somme de tous les prix de billets achet�s
	* Param�tres:	aucun
	* Retour:		double
	****************************************************************************/
	double calculerRevenu() const;

	/****************************************************************************
	* Fonction:		GestionnaireMembres::calculerNombreBilletsEnSolde() const
	* Description:	calcule le nombre de billets en solde
	* Param�tres:	aucun
	* Retour:		int
	****************************************************************************/
	int calculerNombreBilletsEnSolde() const;

	/****************************************************************************
	* Fonction:		GestionnaireMembres::getBilletMin() const
	* Description:	Retourne pointeur sur billet le moins cher
	* Param�tres:	string nomMembre
	* Retour:		Billet*
	****************************************************************************/
	Billet* getBilletMin(string nomMembre) const ;

	/****************************************************************************
	* Fonction:		GestionnaireMembres::getBilletMax() const
	* Description:	Retourne pointeur sur billet le plus cher
	* Param�tres:	string nomMembre
	* Retour:		Billet*
	****************************************************************************/
	Billet* getBilletMax(string nomMembre) const ;

	/****************************************************************************
	* Fonction:		GestionnaireMembres::trouverBilletParIntervalle() const
	* Description:	Retourne les billets dans l'intervalle
	* Param�tres:	Membre* membre, double prixInf, double prixSup
	* Retour:		vector<Billet*>
	****************************************************************************/
	vector<Billet*>trouverBilletParIntervallle(Membre* membre, double prixInf, double prixSup) const;

	/****************************************************************************
	* Fonction:		GestionnaireMembres::afficher() const
	* Description:	Affiche les membres et leurs attributs
	* Param�tres:	ostream& o
	* Retour:		aucun
	****************************************************************************/
	void afficher(ostream& o) const;
};
#endif // !GESTIONNAIREMEMBRES_H




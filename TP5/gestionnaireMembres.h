#pragma once
/********************************************
* Titre: Travail pratique #5 - gestionnaireMembres.h
* Date: 30 octobre 2019
* Auteur: Allan BEDDOUK & Jeffrey LAVALLEE
* Modification: Nathan RAMSAY-VEJLENS & 
*******************************************/

#ifndef GESTIONNAIREMEMBRES_H
#define	GESTIONNAIREMEMBRES_H

#include <vector>
#include <map>
#include <string>
#include "membrePremium.h"
#include "membreRegulier.h"
#include "solde.h"
#include "gestionnaireGenerique.h"
#include "foncteur.h"
#include "billet.h"

class GestionnaireMembres: public GestionnaireGenerique <pair<string, Membre*>, map<string, Membre*>, AjouterMembre> 
{
public:

	void assignerBillet(Billet* billet, const string& nomMembre, int rabaisCoupon);

	//fait
	double calculerRevenu() const;

	//fait
	int calculerNombreBilletsEnSolde() const;

	//TODO
	Billet* getBilletMin(string nomMembre) const ;

	//TODO
	Billet* getBilletMax(string nomMembre) const ;

	//TODO
	vector<Billet*>trouverBilletParIntervallle(Membre* membre, double prixInf, double prixSup) const;

	//TODO
	void afficher(ostream& o) const;
};
#endif // !GESTIONNAIREMEMBRES_H




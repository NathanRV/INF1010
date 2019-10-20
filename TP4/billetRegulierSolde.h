/*
* Titre : billetRegulierSolde.h - Travail Pratique #4
* Date : 5 Octobre 2019
* Auteur : Philippe CÔTÉ-MORNEAULT
* Mise à jour : Nathan Ramsay-Vejlens
* Date mise à jour : 17 octobre 2019
*/

#ifndef BILLET_REGULIER_SOLDE_H
#define BILLET_REGULIER_SOLDE_H

#include <iomanip>

#include "billetRegulier.h"
#include "solde.h"

using namespace std;

class BilletRegulierSolde : public BilletRegulier, public Solde {
public:
	/****************************************************************************
* Fonction:		BilletRegulierSolde::BilletRegulierSolde()
* Description:	Constructeur par paramètres
* Paramètres:	const string& pnr, double prix, const string& od, TarifBillet tarif, const string& dateVol, double pourcentageSolde
* Retour:		aucun
****************************************************************************/
	BilletRegulierSolde(const string& pnr, double prix, const string& od, TarifBillet tarif, const string& dateVol, double pourcentageSolde);

	// Getter
	/****************************************************************************
* Fonction:		BilletRegulierSolde::getPrix()
* Description:	Retourne prix avec solde
* Paramètres:	Aucun
* Retour:		double
****************************************************************************/
	double getPrix() const override;
	/****************************************************************************
* Fonction:		BilletRegulierSolde::getPrixBase()
* Description:	Retourne prix avant solde
* Paramètres:	Aucun
* Retour:		double
****************************************************************************/
	double getPrixBase() const override;

	/****************************************************************************
* Fonction:		BilletRegulierSolde::clone()
* Description:	Retourne copie alloué dynamiquement
* Paramètres:	Aucun
* Retour:		BilletRegulierSolde*
****************************************************************************/
	BilletRegulierSolde* clone();

	/****************************************************************************
  * Fonction:	BilletRegulierSolde::afficher()
  * Description:Fonction affichage de la classe
  * Paramètres:	ostream& o
  * Retour:		aucun
  ****************************************************************************/
	void afficher(ostream& o);
};
#endif // !BILLET_REGULIER_SOLDE_H
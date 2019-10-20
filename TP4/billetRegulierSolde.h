/*
* Titre : billetRegulierSolde.h - Travail Pratique #4
* Date : 5 Octobre 2019
* Auteur : Philippe C�T�-MORNEAULT
* Mise � jour : Nathan Ramsay-Vejlens
* Date mise � jour : 17 octobre 2019
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
* Description:	Constructeur par param�tres
* Param�tres:	const string& pnr, double prix, const string& od, TarifBillet tarif, const string& dateVol, double pourcentageSolde
* Retour:		aucun
****************************************************************************/
	BilletRegulierSolde(const string& pnr, double prix, const string& od, TarifBillet tarif, const string& dateVol, double pourcentageSolde);

	// Getter
	/****************************************************************************
* Fonction:		BilletRegulierSolde::getPrix()
* Description:	Retourne prix avec solde
* Param�tres:	Aucun
* Retour:		double
****************************************************************************/
	double getPrix() const override;
	/****************************************************************************
* Fonction:		BilletRegulierSolde::getPrixBase()
* Description:	Retourne prix avant solde
* Param�tres:	Aucun
* Retour:		double
****************************************************************************/
	double getPrixBase() const override;

	/****************************************************************************
* Fonction:		BilletRegulierSolde::clone()
* Description:	Retourne copie allou� dynamiquement
* Param�tres:	Aucun
* Retour:		BilletRegulierSolde*
****************************************************************************/
	BilletRegulierSolde* clone();

	/****************************************************************************
  * Fonction:	BilletRegulierSolde::afficher()
  * Description:Fonction affichage de la classe
  * Param�tres:	ostream& o
  * Retour:		aucun
  ****************************************************************************/
	void afficher(ostream& o);
};
#endif // !BILLET_REGULIER_SOLDE_H
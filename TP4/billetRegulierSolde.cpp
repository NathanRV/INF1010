/*
* Titre : billetRegulierSolde.cpp - Travail Pratique #4
* Date : 5 Octobre 2019
* Auteur : Philippe C�T�-MORNEAULT
* Mise � jour : Nathan Ramsay-Vejlens
* Date mise � jour : 17 octobre 2019
*/

#include "billetRegulierSolde.h"

/****************************************************************************
* Fonction:		BilletRegulierSolde::BilletRegulierSolde()
* Description:	Constructeur par param�tres
* Param�tres:	const string& pnr, double prix, const string& od, TarifBillet tarif, const string& dateVol, double pourcentageSolde
* Retour:		aucun
****************************************************************************/
BilletRegulierSolde::BilletRegulierSolde(const string& pnr, double prix, const string& od, TarifBillet tarif, const string& dateVol, double pourcentageSolde)
	:BilletRegulier(pnr,prix,od,tarif,dateVol) , Solde(pourcentageSolde)
{
}

/****************************************************************************
* Fonction:		BilletRegulierSolde::getPrix()
* Description:	Retourne prix avec solde
* Param�tres:	Aucun
* Retour:		double
****************************************************************************/
double BilletRegulierSolde::getPrix() const
{
	return (prix_ * (1 - pourcentageSolde_));
}

/****************************************************************************
* Fonction:		BilletRegulierSolde::getPrixBase()
* Description:	Retourne prix avant solde
* Param�tres:	Aucun
* Retour:		double
****************************************************************************/
double BilletRegulierSolde::getPrixBase() const
{
	return prix_;
}

/****************************************************************************
* Fonction:		BilletRegulierSolde::clone()
* Description:	Retourne copie allou� dynamiquement
* Param�tres:	Aucun
* Retour:		BilletRegulierSolde*
****************************************************************************/
BilletRegulierSolde* BilletRegulierSolde::clone()
{
	return new BilletRegulierSolde(pnr_, prix_, od_, tarif_,getDateVol(), pourcentageSolde_);
}

/****************************************************************************
  * Fonction:	BilletRegulierSolde::afficher()
  * Description:Fonction affichage de la classe
  * Param�tres:	ostream& o
  * Retour:		aucun
  ****************************************************************************/
void BilletRegulierSolde::afficher(ostream& o)
{
	dynamic_cast<BilletRegulier*>(this)->afficher(o);
	o << "\t\t\t" << setw(11) << "- Pourcentage solde" << ": " << pourcentageSolde_ << "%" << endl;
}
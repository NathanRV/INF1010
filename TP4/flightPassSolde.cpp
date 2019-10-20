/*
* Titre : flightPassSolde.cpp - Travail Pratique #4
* Date : 5 Octobre 2019
* Auteur : Philippe C�T�-MORNEAULT
* Mise � jour : Nathan Ramsay-Vejlens
* Date mise � jour : 17 octobre 2019
*/

#include "flightPassSolde.h"

/****************************************************************************
* Fonction:		FlightPassSolde::FlightPassSolde()
* Description:	Constructeur par param�tres
* Param�tres:	const string& pnr, double prix, const string& od, TarifBillet tarif,double pourcentageSolde
* Retour:		aucun
****************************************************************************/
FlightPassSolde::FlightPassSolde(const string& pnr, double prix, const string& od, TarifBillet tarif, double pourcentageSolde)
	:FlightPass(pnr,prix,od,tarif),Solde(pourcentageSolde)
{}

/****************************************************************************
* Fonction:		FlightPassSolde::getPrix()
* Description:	Retourne prix avec solde
* Param�tres:	Aucun
* Retour:		double
****************************************************************************/ 
double FlightPassSolde::getPrix() const
{
	return prix_ * (1 - pourcentageSolde_);
}

/****************************************************************************
* Fonction:		FlightPassSolde::getPrixBase()
* Description:	Retourne prix avant solde
* Param�tres:	Aucun
* Retour:		double
****************************************************************************/
double FlightPassSolde::getPrixBase() const
{
	return prix_;
}

/****************************************************************************
* Fonction:		FlightPassSolde::clone()
* Description:	Retourne copie allou� dynamiquement
* Param�tres:	Aucun
* Retour:		FlightPassSolde*
****************************************************************************/
FlightPassSolde* FlightPassSolde::clone()
{
	return new FlightPassSolde(pnr_, prix_, od_, tarif_, pourcentageSolde_);
}

/****************************************************************************
* Fonction:	FlightPassSolde::afficher()
* Description:Fonction affichage de la classe
* Param�tres:	ostream& o
* Retour:		aucun
****************************************************************************/
void FlightPassSolde::afficher(ostream& o)
{
	dynamic_cast<FlightPass*>(this)->afficher(o);
	o << "\t\t\t" << setw(11) << "- Pourcentage solde" << ": " << pourcentageSolde_ << "%" << endl;
}
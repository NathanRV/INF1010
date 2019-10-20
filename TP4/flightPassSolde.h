/*
* Titre : flightPassSolde.h - Travail Pratique #4
* Date : 5 Octobre 2019
* Auteur : Philippe CÔTÉ-MORNEAULT
* Mise à jour : Nathan Ramsay-Vejlens
* Date mise à jour : 17 octobre 2019
*/

#ifndef FLIGHT_PASS_SOLDE_H
#define FLIGHT_PASS_SOLDE_H

#include <iomanip>

#include "flightPass.h"
#include "solde.h"

using namespace std;

class FlightPassSolde : public FlightPass, public Solde {
public:
	// Constructeur
	/****************************************************************************
* Fonction:		FlightPassSolde::FlightPassSolde()
* Description:	Constructeur par paramètres
* Paramètres:	const string& pnr, double prix, const string& od, TarifBillet tarif,double pourcentageSolde
* Retour:		aucun
****************************************************************************/
	FlightPassSolde(const string& pnr, double prix, const string& od, TarifBillet tarif, double pourcentageSolde);

	// Getter
	/****************************************************************************
* Fonction:		FlightPassSolde::getPrix()
* Description:	Retourne prix avec solde
* Paramètres:	Aucun
* Retour:		double
****************************************************************************/
	double getPrix() const override;

	/****************************************************************************
* Fonction:		FlightPassSolde::getPrixBase()
* Description:	Retourne prix avant solde
* Paramètres:	Aucun
* Retour:		double
****************************************************************************/
	double getPrixBase() const override;

	/****************************************************************************
	* Fonction:		FlightPassSolde::clone()
	* Description:	Retourne copie alloué dynamiquement
	* Paramètres:	Aucun
	* Retour:		FlightPassSolde*
	****************************************************************************/
	FlightPassSolde* clone();

	/****************************************************************************
	* Fonction:	FlightPassSolde::afficher()
	* Description:Fonction affichage de la classe
	* Paramètres:	ostream& o
	* Retour:		aucun
	****************************************************************************/
	void afficher(ostream& o);
};
#endif // !FLIGHT_PASS_SOLDE_H

/*
* Titre : flightPass.h - Travail Pratique #4
* Date : 5 Octobre 2019
* Auteur : Philippe CÔTÉ-MORNEAULT
*/

#ifndef FLIGHT_PASS_H
#define FLIGHT_PASS_H

#include <iomanip>

#include "billet.h"

class FlightPass : public Billet {
public:

	/****************************************************************************
* Fonction:		FlightPass::FlightPass()
* Description:	Constructeur par paramètres
* Paramètres:	const string& pnr, double prix, const string& od, TarifBillet tarif,
* Retour:		aucun
****************************************************************************/
	FlightPass(const string& pnr, double prix, const string& od, TarifBillet tarif);

	/****************************************************************************
* Fonction:		FlightPass::getNbUtilisationsRestante() const
* Description:	Retourne le nombre d'utilisations restantes
* Paramètres:	aucun
* Retour:		int
****************************************************************************/
	int getNbUtilisationsRestante() const;

	/****************************************************************************
* Fonction:		FlightPass::decrementNbUtilisations() 
* Description:	Décremente le nombre d'utilisations restantes
* Paramètres:	aucun
* Retour:		aucun
****************************************************************************/
	void decrementeNbUtilisations();

	/****************************************************************************
	* Fonction:		FlightPass::clone()
	* Description:	Retourne copie alloué dynamiquement
	* Paramètres:	Aucun
	* Retour:		FlightPass*
	****************************************************************************/
	FlightPass* clone();

	/****************************************************************************
  * Fonction:	FlightPass::afficher()
  * Description:Fonction affichage de la classe
  * Paramètres:	ostream& o
  * Retour:		aucun
  ****************************************************************************/
	void afficher(ostream& o);
private:
	 int nbUtilisationsRestante_;
};
#endif // !FLIGHT_PASS_H
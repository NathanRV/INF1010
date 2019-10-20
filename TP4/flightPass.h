/*
* Titre : flightPass.h - Travail Pratique #4
* Date : 5 Octobre 2019
* Auteur : Philippe C�T�-MORNEAULT
*/

#ifndef FLIGHT_PASS_H
#define FLIGHT_PASS_H

#include <iomanip>

#include "billet.h"

class FlightPass : public Billet {
public:

	/****************************************************************************
* Fonction:		FlightPass::FlightPass()
* Description:	Constructeur par param�tres
* Param�tres:	const string& pnr, double prix, const string& od, TarifBillet tarif,
* Retour:		aucun
****************************************************************************/
	FlightPass(const string& pnr, double prix, const string& od, TarifBillet tarif);

	/****************************************************************************
* Fonction:		FlightPass::getNbUtilisationsRestante() const
* Description:	Retourne le nombre d'utilisations restantes
* Param�tres:	aucun
* Retour:		int
****************************************************************************/
	int getNbUtilisationsRestante() const;

	/****************************************************************************
* Fonction:		FlightPass::decrementNbUtilisations() 
* Description:	D�cremente le nombre d'utilisations restantes
* Param�tres:	aucun
* Retour:		aucun
****************************************************************************/
	void decrementeNbUtilisations();

	/****************************************************************************
	* Fonction:		FlightPass::clone()
	* Description:	Retourne copie allou� dynamiquement
	* Param�tres:	Aucun
	* Retour:		FlightPass*
	****************************************************************************/
	FlightPass* clone();

	/****************************************************************************
  * Fonction:	FlightPass::afficher()
  * Description:Fonction affichage de la classe
  * Param�tres:	ostream& o
  * Retour:		aucun
  ****************************************************************************/
	void afficher(ostream& o);
private:
	 int nbUtilisationsRestante_;
};
#endif // !FLIGHT_PASS_H
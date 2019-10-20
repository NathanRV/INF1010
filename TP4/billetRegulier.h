/*
* Titre : billetRegulier.h - Travail Pratique #4
* Date : 5 Octobre 2019
* Auteur : Philippe CÔTÉ-MORNEAULT
* Mise à jour : Nathan Ramsay-Vejlens
* Date mise à jour : 17 octobre 2019
*/

#ifndef BILLET_REGULIER_H
#define BILLET_REGULIER_H

#include <iomanip>

#include "billet.h"

class BilletRegulier : public Billet {

public:
	// Constructeur
	/****************************************************************************
* Fonction:	BilletRegulier::BilletRegulier()
* Description:Constructeur par paramètres
* Paramètres:	const string& pnr, double prix, const string& od, TarifBillet tarif, const string& dateVol
* Retour:		aucun
****************************************************************************/
	BilletRegulier(const string& pnr, double prix, const string& od, TarifBillet tarif, const string& dateVol);


	// Getter
/****************************************************************************
* Fonction:	BilletRegulier::getDateVol() const
* Description:Retourne la date du vol
* Paramètres:	aucun
* Retour:		string
****************************************************************************/
	string getDateVol() const;

	// Setter
	/****************************************************************************
* Fonction:	BilletRegulier::setDateVol()
* Description:Modifie date du vol
* Paramètres:	string dateVol
* Retour:		aucun
****************************************************************************/
	void setDateVol(string dateVol);

	/****************************************************************************
* Fonction:		BilletRegulier::clone()
* Description:	Retourne copie alloué dynamiquement
* Paramètres:	Aucun
* Retour:		BilletRegulier*
****************************************************************************/
	BilletRegulier* clone();
	
	/****************************************************************************
  * Fonction:	BilletRegulier::afficher()
  * Description:Fonction affichage de la classe
  * Paramètres:	ostream& o
  * Retour:		aucun
  ****************************************************************************/
	void afficher(ostream& o);
private:
	string dateVol_;
};
#endif // !BILLET_REGULIER_H
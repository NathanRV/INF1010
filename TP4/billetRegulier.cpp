/*
* Titre : billetRegulier.cpp - Travail Pratique #4
* Date : 5 Octobre 2019
* Auteur : Philippe CÔTÉ-MORNEAULT
* Mise à jour : Nathan Ramsay-Vejlens
* Date mise à jour : 17 octobre 2019
*/

#include "billetRegulier.h"


/****************************************************************************
* Fonction:	BilletRegulier::BilletRegulier()
* Description:Constructeur par paramètres
* Paramètres:	const string& pnr, double prix, const string& od, TarifBillet tarif, const string& dateVol
* Retour:		aucun
****************************************************************************/
BilletRegulier::BilletRegulier(const string& pnr, double prix, const string& od, TarifBillet tarif, const string& dateVol) : 
	Billet(pnr, prix, od, tarif), dateVol_(dateVol)
{
}

/****************************************************************************
* Fonction:	BilletRegulier::getDateVol() const
* Description:Retourne la date du vol
* Paramètres:	aucun
* Retour:		string
****************************************************************************/
string BilletRegulier::getDateVol() const
{
	return dateVol_;
}

/****************************************************************************
* Fonction:	BilletRegulier::setDateVol()
* Description:Modifie date du vol
* Paramètres:	string dateVol
* Retour:		aucun
****************************************************************************/
void BilletRegulier::setDateVol(string dateVol)
{
	dateVol_ = dateVol;
}


/****************************************************************************
* Fonction:		BilletRegulier::clone()
* Description:	Retourne copie alloué dynamiquement
* Paramètres:	Aucun
* Retour:		BilletRegulier*
****************************************************************************/
BilletRegulier* BilletRegulier::clone()
{
	return new BilletRegulier(pnr_, prix_, od_, tarif_, dateVol_);
}

/****************************************************************************
  * Fonction:	BilletRegulier::afficher()
  * Description:Fonction affichage de la classe
  * Paramètres:	ostream& o
  * Retour:		aucun
  ****************************************************************************/
void BilletRegulier::afficher(ostream& o)
{
	dynamic_cast<Billet*>(this)->afficher(o);
	o << "\t\t\t" << setw(11) << "- Vol le" << ": " << dateVol_ << endl;
}
/*
* Titre : flightPass.cpp - Travail Pratique #4
* Date : 5 Octobre 2019
* Auteur : Philippe CÔTÉ-MORNEAULT
* Mise à jour : Nathan Ramsay-Vejlens
* Date mise à jour : 17 octobre 2019
*/
#include "flightPass.h"

/****************************************************************************
* Fonction:		FlightPass::FlightPass()
* Description:	Constructeur par paramètres
* Paramètres:	const string& pnr, double prix, const string& od, TarifBillet tarif,
* Retour:		aucun
****************************************************************************/
FlightPass::FlightPass(const string& pnr, double prix, const string& od, TarifBillet tarif) : 
	Billet(pnr, prix, od, tarif), nbUtilisationsRestante_(NB_UTILISATIONS_INITIALE)
{
}

/****************************************************************************
* Fonction:		FlightPass::getNbUtilisationsRestante() const
* Description:	Retourne le nombre d'utilisations restantes
* Paramètres:	aucun
* Retour:		int
****************************************************************************/
int FlightPass::getNbUtilisationsRestante() const
{
	return nbUtilisationsRestante_;
}

/****************************************************************************
* Fonction:		FlightPass::decrementNbUtilisations()
* Description:	Décremente le nombre d'utilisations restantes
* Paramètres:	aucun
* Retour:		aucun
****************************************************************************/
void FlightPass::decrementeNbUtilisations()
{
	--nbUtilisationsRestante_;
}

/****************************************************************************
* Fonction:		FlightPass::clone()
* Description:	Retourne copie alloué dynamiquement
* Paramètres:	Aucun
* Retour:		FlightPass*
****************************************************************************/
FlightPass* FlightPass::clone()
{
	return new FlightPass(pnr_,prix_,od_,tarif_);
}

/****************************************************************************
  * Fonction:	FlightPass::afficher()
  * Description:Fonction affichage de la classe
  * Paramètres:	ostream& o
  * Retour:		aucun
  ****************************************************************************/
void FlightPass::afficher(ostream& o)
{
	dynamic_cast<Billet*>(this)->afficher(o);
	o << "\t\t\t" << setw(11) << "- Utilisation restantes" << ": " << nbUtilisationsRestante_ << endl;
}
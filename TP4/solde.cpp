/*
* Titre : solde.cpp - Travail Pratique #4
* Date : 5 Octobre 2019
* Auteur : Philippe CÔTÉ-MORNEAULT
* Mise à jour : Nathan Ramsay-Vejlens
* Date mise à jour : 17 octobre 2019
*/

#include "solde.h"

/****************************************************************************
  * Fonction:	Solde::Solde()
  * Description:Constructeur par défaut, classe abstraite donc ne peut être appellé seul
  * Paramètres:	double pourcentageSolde
  * Retour:		aucun
  ****************************************************************************/
Solde::Solde(double pourcentageSolde)
{
	pourcentageSolde_ = pourcentageSolde;
}

/****************************************************************************
  * Fonction:	Solde::~Solde()
  * Description:Destructeur virtuel
  * Paramètres:	aucun
  * Retour:		aucun
  ****************************************************************************/
Solde::~Solde()
{
}

/****************************************************************************
  * Fonction:	Solde::getPourcentageSolde() const
  * Description:Retourne le pourcentage de solde
  * Paramètres:	aucun
  * Retour:		double
  ****************************************************************************/
double Solde::getPourcentageSolde() const
{
	return pourcentageSolde_;
}

/****************************************************************************
  * Fonction:	Solde::setPourcentageSolde()
  * Description:Modifie le pourcentage de solde
  * Paramètres:	double pourcentageSolde
  * Retour:		aucun
  ****************************************************************************/
void Solde::setPourcentageSolde(double pourcentageSolde)
{
	pourcentageSolde_ = pourcentageSolde;
}

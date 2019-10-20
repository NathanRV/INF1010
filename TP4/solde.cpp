/*
* Titre : solde.cpp - Travail Pratique #4
* Date : 5 Octobre 2019
* Auteur : Philippe C�T�-MORNEAULT
* Mise � jour : Nathan Ramsay-Vejlens
* Date mise � jour : 17 octobre 2019
*/

#include "solde.h"

/****************************************************************************
  * Fonction:	Solde::Solde()
  * Description:Constructeur par d�faut, classe abstraite donc ne peut �tre appell� seul
  * Param�tres:	double pourcentageSolde
  * Retour:		aucun
  ****************************************************************************/
Solde::Solde(double pourcentageSolde)
{
	pourcentageSolde_ = pourcentageSolde;
}

/****************************************************************************
  * Fonction:	Solde::~Solde()
  * Description:Destructeur virtuel
  * Param�tres:	aucun
  * Retour:		aucun
  ****************************************************************************/
Solde::~Solde()
{
}

/****************************************************************************
  * Fonction:	Solde::getPourcentageSolde() const
  * Description:Retourne le pourcentage de solde
  * Param�tres:	aucun
  * Retour:		double
  ****************************************************************************/
double Solde::getPourcentageSolde() const
{
	return pourcentageSolde_;
}

/****************************************************************************
  * Fonction:	Solde::setPourcentageSolde()
  * Description:Modifie le pourcentage de solde
  * Param�tres:	double pourcentageSolde
  * Retour:		aucun
  ****************************************************************************/
void Solde::setPourcentageSolde(double pourcentageSolde)
{
	pourcentageSolde_ = pourcentageSolde;
}

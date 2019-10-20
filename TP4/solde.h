/*
* Titre : solde.h - Travail Pratique #4
* Date : 5 Octobre 2019
* Auteur : Philippe CÔTÉ-MORNEAULT
* Mise à jour : Nathan Ramsay-Vejlens
* Date mise à jour : 17 octobre 2019
*/

#ifndef SOLDE_H
#define SOLDE_H

using namespace std;

class Solde {
public:
	// Constructeurs
	/****************************************************************************
  * Fonction:	Solde::Solde()
  * Description:Constructeur par défaut, classe abstraite donc ne peut être appellé seul
  * Paramètres:	double pourcentageSolde
  * Retour:		aucun
  ****************************************************************************/
	Solde(double pourcentageSolde);
	/****************************************************************************
  * Fonction:	Solde::~Solde()
  * Description:Destructeur virtuel
  * Paramètres:	aucun
  * Retour:		aucun
  ****************************************************************************/
	virtual ~Solde();

	// Getter
	/****************************************************************************
  * Fonction:	Solde::getPourcentageSolde() const
  * Description:Retourne le pourcentage de solde
  * Paramètres:	aucun
  * Retour:		double
  ****************************************************************************/
	double getPourcentageSolde() const;
	/****************************************************************************
  * Fonction:	Solde::getPrixBase() const =0
  * Description:Retourne le Prix de base une fois surchargé, fonction virtuelle pure
  * Paramètres:	aucun
  * Retour:		double
  ****************************************************************************/
	virtual double getPrixBase() const =0;

	// Setter
	/****************************************************************************
  * Fonction:	Solde::setPourcentageSolde()
  * Description:Modifie le pourcentage de solde
  * Paramètres:	double pourcentageSolde
  * Retour:		aucun
  ****************************************************************************/
	void setPourcentageSolde(double pourcentageSolde);
protected:
	double pourcentageSolde_;
};
#endif // !SOLDE_H
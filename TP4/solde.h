/*
* Titre : solde.h - Travail Pratique #4
* Date : 5 Octobre 2019
* Auteur : Philippe C�T�-MORNEAULT
* Mise � jour : Nathan Ramsay-Vejlens
* Date mise � jour : 17 octobre 2019
*/

#ifndef SOLDE_H
#define SOLDE_H

using namespace std;

class Solde {
public:
	// Constructeurs
	/****************************************************************************
  * Fonction:	Solde::Solde()
  * Description:Constructeur par d�faut, classe abstraite donc ne peut �tre appell� seul
  * Param�tres:	double pourcentageSolde
  * Retour:		aucun
  ****************************************************************************/
	Solde(double pourcentageSolde);
	/****************************************************************************
  * Fonction:	Solde::~Solde()
  * Description:Destructeur virtuel
  * Param�tres:	aucun
  * Retour:		aucun
  ****************************************************************************/
	virtual ~Solde();

	// Getter
	/****************************************************************************
  * Fonction:	Solde::getPourcentageSolde() const
  * Description:Retourne le pourcentage de solde
  * Param�tres:	aucun
  * Retour:		double
  ****************************************************************************/
	double getPourcentageSolde() const;
	/****************************************************************************
  * Fonction:	Solde::getPrixBase() const =0
  * Description:Retourne le Prix de base une fois surcharg�, fonction virtuelle pure
  * Param�tres:	aucun
  * Retour:		double
  ****************************************************************************/
	virtual double getPrixBase() const =0;

	// Setter
	/****************************************************************************
  * Fonction:	Solde::setPourcentageSolde()
  * Description:Modifie le pourcentage de solde
  * Param�tres:	double pourcentageSolde
  * Retour:		aucun
  ****************************************************************************/
	void setPourcentageSolde(double pourcentageSolde);
protected:
	double pourcentageSolde_;
};
#endif // !SOLDE_H
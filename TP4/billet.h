/*
* Titre : billet.h - Travail Pratique #4
* Date : 5 Octobre 2019
* Auteur : Philippe C�T�-MORNEAULT
* Mise � jour : Nathan Ramsay-Vejlens
* Date mise � jour : 17 octobre 2019
*/

#ifndef BILLET_H
#define BILLET_H

#include <string>
#include <iomanip>

#include "def.h"

using namespace std;

class Billet {
public:
	// Constructeurs
	/****************************************************************************
  * Fonction:	Billet::Billet()
  * Description:Constructeur par d�faut
  * Param�tres:	aucun
  * Retour:		aucun
  ****************************************************************************/
	Billet();
	/****************************************************************************
  * Fonction:	Billet::Billet()
  * Description:Constructeur par param�tres
  * Param�tres:	const string& pnr, double prix, const string& od, TarifBillet tarif
  * Retour:		aucun
  ****************************************************************************/
	Billet(const string& pnr, double prix, const string& od, TarifBillet tarif);

	/****************************************************************************
  * Fonction:	Billet::~Billet()
  * Description:Destructeur virtuel
  * Param�tres:	aucun
  * Retour:		aucun
  ****************************************************************************/
	virtual ~Billet();

	// Getters
	/****************************************************************************
  * Fonction:	Billet::getPnr() const
  * Description:Retourne valeur de pnr
  * Param�tres:	aucun
  * Retour:		string
  ****************************************************************************/
	string getPnr() const;
	/****************************************************************************
  * Fonction:	Billet::getNomPassager() const
  * Description:Retourne nom du passager
  * Param�tres:	aucun
  * Retour:		string
  ****************************************************************************/
	string getNomPassager() const;
	/****************************************************************************
  * Fonction:	Billet::getPrix() const
  * Description:Retourne prix du billet
  * Param�tres:	aucun
  * Retour:		double
  ****************************************************************************/
	virtual double getPrix() const;
	/****************************************************************************
  * Fonction:	Billet::getOd() const
  * Description:Retourne origine destination
  * Param�tres:	aucun
  * Retour:		string
  ****************************************************************************/
	string getOd() const;
	/****************************************************************************
  * Fonction:	Billet::getTarif() const
  * Description:Retourne type de tarif
  * Param�tres:	aucun
  * Retour:		TarifBillet
  ****************************************************************************/
	TarifBillet getTarif() const;

	// Setters
	/****************************************************************************
  * Fonction:	Billet::setPnr()
  * Description:Modifie pnr
  * Param�tres:	const string& pnr
  * Retour:		aucun
  ****************************************************************************/
	void setPnr(const string& pnr);
	/****************************************************************************
  * Fonction:	Billet::setNomPassager()
  * Description:Modifie nom du passager
  * Param�tres:	const string& nomPassager
  * Retour:		aucun
  ****************************************************************************/
	void setNomPassager(const string& nomPassager);
	/****************************************************************************
  * Fonction:	Billet::setPrix()
  * Description:Modifie prix du billet
  * Param�tres:	double prix
  * Retour:		aucun
  ****************************************************************************/
	void setPrix(double prix);
	/****************************************************************************
  * Fonction:	Billet::setOd()
  * Description:Modifie origine destination
  * Param�tres:	const string& od
  * Retour:		aucun
  ****************************************************************************/
	void setOd(const string& od);
	/****************************************************************************
  * Fonction:	Billet::setTarif()
  * Description:Modifie tarif du billet
  * Param�tres:	TarifBillet tarif
  * Retour:		aucun
  ****************************************************************************/
	void setTarif(TarifBillet tarif);

	/****************************************************************************
  * Fonction:	Billet::formatTarif() const
  * Description:Convertir tarif en string
  * Param�tres:	TarifBillet tarif
  * Retour:		string
  ****************************************************************************/
	string formatTarif(TarifBillet tarif) const;

	
	/****************************************************************************
  * Fonction:	virtual Billet::Billet clone()=0;
  * Description:Fonction virtuelle pure
  * Param�tres:	aucun
  * Retour:		Billet*
  ****************************************************************************/
	virtual Billet* clone()=0;

	/****************************************************************************
  * Fonction:	Billet::afficher()
  * Description:Fonction affichage de la classe
  * Param�tres:	ostream& o
  * Retour:		aucun
  ****************************************************************************/
	void afficher(ostream& o);
protected:
	string pnr_;
	string nomPassager_;
	double prix_;
	string od_;
	TarifBillet tarif_;
};
#endif // !BILLET_H
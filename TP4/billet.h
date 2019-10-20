/*
* Titre : billet.h - Travail Pratique #4
* Date : 5 Octobre 2019
* Auteur : Philippe CÔTÉ-MORNEAULT
* Mise à jour : Nathan Ramsay-Vejlens
* Date mise à jour : 17 octobre 2019
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
  * Description:Constructeur par défaut
  * Paramètres:	aucun
  * Retour:		aucun
  ****************************************************************************/
	Billet();
	/****************************************************************************
  * Fonction:	Billet::Billet()
  * Description:Constructeur par paramètres
  * Paramètres:	const string& pnr, double prix, const string& od, TarifBillet tarif
  * Retour:		aucun
  ****************************************************************************/
	Billet(const string& pnr, double prix, const string& od, TarifBillet tarif);

	/****************************************************************************
  * Fonction:	Billet::~Billet()
  * Description:Destructeur virtuel
  * Paramètres:	aucun
  * Retour:		aucun
  ****************************************************************************/
	virtual ~Billet();

	// Getters
	/****************************************************************************
  * Fonction:	Billet::getPnr() const
  * Description:Retourne valeur de pnr
  * Paramètres:	aucun
  * Retour:		string
  ****************************************************************************/
	string getPnr() const;
	/****************************************************************************
  * Fonction:	Billet::getNomPassager() const
  * Description:Retourne nom du passager
  * Paramètres:	aucun
  * Retour:		string
  ****************************************************************************/
	string getNomPassager() const;
	/****************************************************************************
  * Fonction:	Billet::getPrix() const
  * Description:Retourne prix du billet
  * Paramètres:	aucun
  * Retour:		double
  ****************************************************************************/
	virtual double getPrix() const;
	/****************************************************************************
  * Fonction:	Billet::getOd() const
  * Description:Retourne origine destination
  * Paramètres:	aucun
  * Retour:		string
  ****************************************************************************/
	string getOd() const;
	/****************************************************************************
  * Fonction:	Billet::getTarif() const
  * Description:Retourne type de tarif
  * Paramètres:	aucun
  * Retour:		TarifBillet
  ****************************************************************************/
	TarifBillet getTarif() const;

	// Setters
	/****************************************************************************
  * Fonction:	Billet::setPnr()
  * Description:Modifie pnr
  * Paramètres:	const string& pnr
  * Retour:		aucun
  ****************************************************************************/
	void setPnr(const string& pnr);
	/****************************************************************************
  * Fonction:	Billet::setNomPassager()
  * Description:Modifie nom du passager
  * Paramètres:	const string& nomPassager
  * Retour:		aucun
  ****************************************************************************/
	void setNomPassager(const string& nomPassager);
	/****************************************************************************
  * Fonction:	Billet::setPrix()
  * Description:Modifie prix du billet
  * Paramètres:	double prix
  * Retour:		aucun
  ****************************************************************************/
	void setPrix(double prix);
	/****************************************************************************
  * Fonction:	Billet::setOd()
  * Description:Modifie origine destination
  * Paramètres:	const string& od
  * Retour:		aucun
  ****************************************************************************/
	void setOd(const string& od);
	/****************************************************************************
  * Fonction:	Billet::setTarif()
  * Description:Modifie tarif du billet
  * Paramètres:	TarifBillet tarif
  * Retour:		aucun
  ****************************************************************************/
	void setTarif(TarifBillet tarif);

	/****************************************************************************
  * Fonction:	Billet::formatTarif() const
  * Description:Convertir tarif en string
  * Paramètres:	TarifBillet tarif
  * Retour:		string
  ****************************************************************************/
	string formatTarif(TarifBillet tarif) const;

	
	/****************************************************************************
  * Fonction:	virtual Billet::Billet clone()=0;
  * Description:Fonction virtuelle pure
  * Paramètres:	aucun
  * Retour:		Billet*
  ****************************************************************************/
	virtual Billet* clone()=0;

	/****************************************************************************
  * Fonction:	Billet::afficher()
  * Description:Fonction affichage de la classe
  * Paramètres:	ostream& o
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
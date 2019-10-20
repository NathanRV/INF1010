/*
* Titre : billet.cpp - Travail Pratique #4
* Date : 5 Octobre 2019
* Auteur : Philippe C�T�-MORNEAULT
* Mise � jour : Nathan Ramsay-Vejlens
* Date mise � jour : 17 octobre 2019
*/

#include "billet.h"

/****************************************************************************
* Fonction:	Billet::Billet()
* Description:Constructeur par d�faut
* Param�tres:	aucun
* Retour:		aucun
****************************************************************************/
Billet::Billet() :
	pnr_(""),
	nomPassager_(""),
	prix_(0),
	od_(""),
	tarif_(TarifBillet::Economie)
{
}

/****************************************************************************
* Fonction:	Billet::Billet()
* Description:Constructeur par d�faut
* Param�tres:	const string& pnr, double prix, const string& od, TarifBillet tarif
* Retour:		aucun
****************************************************************************/
Billet::Billet(const string& pnr, double prix, const string& od, TarifBillet tarif) :
	pnr_(pnr),
	nomPassager_(""),
	prix_(prix),
	od_(od),
	tarif_(tarif)
{
}

/****************************************************************************
* Fonction:	Billet::~Billet()
* Description:Destructeur virtuel
* Param�tres:	aucun
* Retour:		aucun
****************************************************************************/
Billet::~Billet()
{
}

/****************************************************************************
* Fonction:	Billet::getPnr() const
* Description:Retourne valeur de pnr
* Param�tres:	aucun
* Retour:		string
****************************************************************************/
string Billet::getPnr() const
{
	return pnr_;
}

/****************************************************************************
* Fonction:	Billet::getNomPassager() const
* Description:Retourne nom du passager
* Param�tres:	aucun
* Retour:		string
****************************************************************************/
string Billet::getNomPassager() const
{
	return nomPassager_;
}

/****************************************************************************
* Fonction:	Billet::getPrix() const
* Description:Retourne prix du billet
* Param�tres:	aucun
* Retour:		double
****************************************************************************/
double Billet::getPrix() const
{
	return prix_;
}

/****************************************************************************
* Fonction:	Billet::getOd() const
* Description:Retourne origine destination
* Param�tres:	aucun
* Retour:		string
****************************************************************************/
string Billet::getOd() const
{
	return od_;
}

/****************************************************************************
* Fonction:	Billet::getTarif() const
* Description:Retourne type de tarif
* Param�tres:	aucun
* Retour:		TarifBillet
****************************************************************************/
TarifBillet Billet::getTarif() const
{
	return tarif_;
}

/****************************************************************************
* Fonction:	Billet::setPnr()
* Description:Modifie pnr
* Param�tres:	const string& pnr
* Retour:		aucun
****************************************************************************/
void Billet::setPnr(const string& pnr)
{
	pnr_ = pnr;
}

/****************************************************************************
* Fonction:	Billet::setNomPassager()
* Description:Modifie nom du passager
* Param�tres:	const string& nomPassager
* Retour:		aucun
****************************************************************************/
void Billet::setNomPassager(const string& nomPassager)
{
	nomPassager_ = nomPassager;
}

/****************************************************************************
* Fonction:	Billet::setPrix()
* Description:Modifie prix du billet
* Param�tres:	double prix
* Retour:		aucun
****************************************************************************/
void Billet::setPrix(double prix)
{
	prix_ = prix;
}

/****************************************************************************
* Fonction:	Billet::setOd()
* Description:Modifie origine destination
* Param�tres:	const string& od
* Retour:		aucun
****************************************************************************/
void Billet::setOd(const string& od)
{
	od_ = od;
}

/****************************************************************************
* Fonction:	Billet::setTarif()
* Description:Modifie tarif du billet
* Param�tres:	TarifBillet tarif
* Retour:		aucun
****************************************************************************/
void Billet::setTarif(TarifBillet tarif)
{
	tarif_ = tarif;
}

/****************************************************************************
  * Fonction:	Billet::formatTarif() const
  * Description:Convertir tarif en string
  * Param�tres:	TarifBillet tarif
  * Retour:		string
  ****************************************************************************/
string Billet::formatTarif(TarifBillet tarif) const
{
	switch (tarif)
	{
		case TarifBillet::Economie:
			return "Economie";
		case TarifBillet::PremiumEconomie:
			return "Premium economie";
		case TarifBillet::Affaire:
			return "Affaire";
		case TarifBillet::Premiere:
			return "Premiere";
		default:
			return "";
	}
}

/****************************************************************************
  * Fonction:	Billet::afficher()
  * Description:Fonction affichage de la classe
  * Param�tres:	ostream& o
  * Retour:		aucun
  ****************************************************************************/
void Billet::afficher(ostream& o)
{
	o << "\t\t- Billet " << pnr_ << " (Classe : " << formatTarif(tarif_) << ")" << endl;
	o << left << "\t\t\t" << setw(11) << "- Passager " << ": " << nomPassager_ << endl;
	o << "\t\t\t" << setw(11) << "- Prix" << ": " << prix_ << "$" << endl;
	o << "\t\t\t" << setw(11) << "- Trajet" << ": " << od_ << endl;
}

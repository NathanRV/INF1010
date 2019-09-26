/****************************************************************************
 * Fichier: billet.cpp
 * Auteur: Nathan Ramsay-Vejlens,Freddy Some,Lorenzo Florenty
 * Date: 23 sept 2019
 * Mise a jour : 23 sept 2019
 * Description: Implémentation de la classe billet
 ****************************************************************************/
#include "billet.h"
 /****************************************************************************
  * Fonction:	Billet::Billet
  * Description: Constructeur par défaut
  * Paramètres:	aucun
  * Retour:		aucun
  ****************************************************************************/
Billet::Billet() :
	pnr_(""),
	nomPassager_(""),
	prix_(0),
	od_(""),
	tarif_(TarifBillet::Economie),
	dateVol_("")
{
}
/****************************************************************************
 * Fonction:	Billet::Billet
 * Description: Constructeur par parametre
 * Paramètres:	-(string&) pnr
                -(string) nomPassager
				-(double) prix
				-(string&) od
				-(TarifBillet) tarif
				-(const string&) dateVol
 * Retour:		aucun
 ****************************************************************************/
Billet::Billet(const string& pnr, const string& nomPassager, double prix, const string& od, TarifBillet tarif, const string& dateVol) :
	pnr_(pnr),
	nomPassager_(nomPassager),
	prix_(prix),
	od_(od),
	tarif_(tarif),
	dateVol_(dateVol)
{
}
/****************************************************************************
 * Fonction:	Billet::~Billet
 * Description: Destructeur 
 * Paramètres:	aucun
 * Retour:		aucun
 ****************************************************************************/
Billet::~Billet()
{}
/****************************************************************************
 * Fonction:	Billet::getPnr
 * Description: Retoune la valeur de pnr_
 * Paramètres:	aucun
 * Retour:		(string) la valeur de pnr_
 ****************************************************************************/
string Billet::getPnr() const
{
	return pnr_;
}
/****************************************************************************
 * Fonction:	Billet::getNomPassager
 * Description: Retourne la valeur de nomPassager_
 * Paramètres:	aucun
 * Retour:		(string) la valeur de nomPassager_
 ****************************************************************************/
string Billet::getNomPassager() const
{
	return nomPassager_;
}
/****************************************************************************
 * Fonction:	Billet::getPrix
 * Description: Retourne la valeur de Prix
 * Paramètres:	aucun
 * Retour:		(double) la valeur de prix_
 ****************************************************************************/
double Billet::getPrix() const
{
	return prix_;
}
/****************************************************************************
 * Fonction:	Billet::getOd
 * Description: Retourne la valeur de Prix
 * Paramètres:	aucun
 * Retour:		(string) la valeur de od_
 ****************************************************************************/
string Billet::getOd() const
{
	return od_;
}
/****************************************************************************
 * Fonction:	 Billet::getTarif
 * Description: Retourne la valeur de tarif_
 * Paramètres:	aucun
 * Retour:		(TarifBillet) la valeur de tarif_
 ****************************************************************************/
TarifBillet Billet::getTarif() const
{
	return tarif_;
}
/****************************************************************************
 * Fonction:	Billet::getDateVol
 * Description: Retoune la valeur de dateVol_
 * Paramètres:	aucun
 * Retour:		(string) la valeur de dateVol_
 ****************************************************************************/
string Billet::getDateVol() const
{
	return dateVol_;
}
/****************************************************************************
 * Fonction:	Billet::setPnr
 * Description: Modifie pnr_
 * Paramètres:	(string) la valeur de pnr_
 * Retour:		aucun
 ****************************************************************************/
void Billet::setPnr(const string& pnr)
{
	pnr_ = pnr;
}
/****************************************************************************
 * Fonction:	Billet::setNomPassager
 * Description: Modifie nomPassager_
 * Paramètres:	(string) la valeur de nomPassager
 * Retour:		aucun
 ****************************************************************************/
void Billet::setNomPassager(const string& nomPassager)
{
	nomPassager_ = nomPassager;
}
/****************************************************************************
 * Fonction:	Billet::setPrix
 * Description: Modifie la valeur de prix_
 * Paramètres:	(double) la valeur de prix
 * Retour:		aucun
 ****************************************************************************/
void Billet::setPrix(double prix)
{
	prix_ = prix;
}
/****************************************************************************
 * Fonction:	Billet::setOd
 * Description: Retourne la valeur de od_
 * Paramètres:	(string) la valeur de od
 * Retour:		aucun
 ****************************************************************************/
void Billet::setOd(const string& od)
{
	od_ = od;
}
/****************************************************************************
 * Fonction:	 Billet::setTarif
 * Description:  Modifie la valeur de tarif_
 * Paramètres:	(TarifBillet) la valeur de tarif
 * Retour:		aucun
 ****************************************************************************/
void Billet::setTarif(TarifBillet tarif)
{
	tarif_ = tarif;
}
/****************************************************************************
 * Fonction:	Billet::setDateVol
 * Description: Modifie la valeur de dateVol_
 * Paramètres:	(string) la valeur de dateVol
 * Retour:		aucun
 ****************************************************************************/
void Billet::setDateVol(const string& dateVol)
{
	dateVol_ = dateVol;
}
/****************************************************************************
 * Fonction:	Billet::formatTarif
 * Description: En fonction du tarif il renvoie un string specifique
 * Paramètres:	(TarifBillet) la valeur de tarif
 * Retour:		strinhg
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
 * Fonction:	operator<<
 * Description: Affiche les caracteristique du Billet
 * Paramètres:	(Billet) la valeur de billet
 * Retour:		ostream
 ****************************************************************************/
ostream& operator<<(ostream& o, const Billet& billet)
{
	o << "\t\t- Billet " << billet.pnr_ << " (Classe : " << billet.formatTarif(billet.tarif_) << ")" << endl;
	o << left << "\t\t\t" << setw(11) << "- Passager " << ": " << billet.nomPassager_ << endl;
	o << "\t\t\t" << setw(11) << "- Prix" << ": " << billet.prix_ << "$" << endl;
	o << "\t\t\t" << setw(11) << "- Trajet" << ": " << billet.od_ << endl;
	o << "\t\t\t" << setw(11) << "- Vol le" << ": " << billet.dateVol_ << endl;
	return o;
}

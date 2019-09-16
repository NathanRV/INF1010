/*
 * Date : 10 Septembre 2019
 * Auteur : Nathan Ramsay-Vejlens
 */

#include "billet.h"

//Constructeur par d�faut
Billet::Billet() :pnr_("A1B2C3"), nomPassager_("Passager"), prix_(999), 
od_("YUL-YYZ"), tarif_(TarifBillet::Economie), dateVol_("2019-12-25")
{
}

//Constructeur avec param�tres
Billet::Billet(const string& pnr, const string& nomPassager, double prix, const string& od, TarifBillet tarif, const string& dateVol)
	:pnr_(pnr), nomPassager_(nomPassager), prix_(prix), od_(od),tarif_(tarif),dateVol_(dateVol)
{
}

//Destructeur
Billet::~Billet()
{}

//Accesseurs

//Acc�de au num�ro de r�servation
string Billet::getPnr() const
{
	return pnr_;
}

//Acc�de au nom
string Billet::getNomPassager() const
{
	return nomPassager_;
}

//Acc�de au prix
double Billet::getPrix() const
{
	return prix_;
}

//Acc�de au trajet
string Billet::getOd() const
{
	return od_;
}

//Acc�de au tarif
TarifBillet Billet::getTarif() const
{
	return tarif_;
}

//Acc�de � la date du vol
string Billet::getDateVol() const
{
	return dateVol_;
}

//Modificateurs

//Modifie le num�ro de r�servation
void Billet::setPnr(const string& pnr)
{
	pnr_ = pnr;
}

//Modifie le nom
void Billet::setNomPassager(const string& nomPassager)
{
	nomPassager_ = nomPassager;
}

//Modifie le prix
void Billet::setPrix(double prix)
{
	prix_ = prix;
}

//Modifie le trajet
void Billet::setOd(const string& od)
{
	od_ = od;
}

//Modifie le tarif
void Billet::setTarif(TarifBillet tarif)
{
	tarif_ = tarif;
}

//Modifie la date du vol
void Billet::setDateVol(const string& dateVol)
{
	dateVol_ = dateVol;
}

//Autres m�thodes

//Conversion du format du tarif en string
string Billet::formatTarif(TarifBillet tarif) const
{
	if (tarif == TarifBillet::Economie)
	{
		return "Economie";
	}
	else if (tarif == TarifBillet::PremiumEconomie)
	{
		return "Premium economie";
	}
	else if (tarif == TarifBillet::Affaire)
	{
		return "Affaire";
	}
	else if (tarif == TarifBillet::Premiere)
	{
		return "Premiere";
	}
}

//Affichage
void Billet::afficherBillet() const
{
	cout << "		- Billet " << getPnr() << " (Classe : " << formatTarif(getTarif()) << ")\n";
	cout << "			- Passager  : " << getNomPassager() << endl;
	cout << "			- Prix      : " << getPrix() << endl;
	cout << "			- Trajet    : " << getOd() << endl;
	cout << "			- Vol le    : " << getDateVol() << endl;
}


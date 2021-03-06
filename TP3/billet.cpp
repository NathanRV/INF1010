/*
 * Date : 12 Septembre 2019
 * Auteur : Philippe C�T�-MORNEAULT
 * Mise � jour le : 4 Octobre 2019
 * Par : Nathan RAMSAY-VEJLENS
 */

#include "billet.h"

/**
*	Constructeur par defaut
*/
Billet::Billet() :
	pnr_(""),
	nomPassager_(""),
	prix_(0),
	od_(""),
	tarif_(TarifBillet::Economie),
	typeBillet_(TypeBillet::Billet_Base)
{
}

/**
*	Constructeur par parametres
*	\param [in] const string&	pnr
*	\param [in] const string&	nomPassager
*	\param [in] double			prix
*	\param [in] const string&	od
*	\param [in] TarifBillet		tarif
*	\param [in]	TypeBillet		typeBillet
*/
Billet::Billet(const string& pnr, const string& nomPassager, double prix, const string& od, TarifBillet tarif, TypeBillet typeBillet) :
	pnr_(pnr),
	nomPassager_(nomPassager),
	prix_(prix),
	od_(od),
	tarif_(tarif),
	typeBillet_(typeBillet)
{
}

Billet::~Billet()
{
}

string Billet::getPnr() const
{
	return pnr_;
}

string Billet::getNomPassager() const
{
	return nomPassager_;
}

double Billet::getPrix() const
{
	return prix_;
}

string Billet::getOd() const
{
	return od_;
}

TarifBillet Billet::getTarif() const
{
	return tarif_;
}

//Accesseur de typeBillet_
TypeBillet Billet::getTypeBillet() const {
	return typeBillet_;
}


void Billet::setPnr(const string& pnr)
{
	pnr_ = pnr;
}

void Billet::setNomPassager(const string& nomPassager)
{
	nomPassager_ = nomPassager;
}

void Billet::setPrix(double prix)
{
	prix_ = prix;
}

void Billet::setOd(const string& od)
{
	od_ = od;
}

void Billet::setTarif(TarifBillet tarif)
{
	tarif_ = tarif;
}

//Modificateur de typeBillet
void Billet::setTypeBillet(TypeBillet typeBillet)
{
	typeBillet_ = typeBillet;
}


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

/**
*	Surcharge operateur << 
*/
ostream& operator<<(ostream& o, const Billet& billet)
{
	o << "\t\t- Billet " << billet.pnr_ << " (Classe : " << billet.formatTarif(billet.tarif_) << ")" << endl;
	o << left << "\t\t\t" << setw(11) << "- Passager " << ": " << billet.nomPassager_ << endl;
	o << "\t\t\t" << setw(11) << "- Prix" << ": " << billet.prix_ << "$" << endl;
	o << "\t\t\t" << setw(11) << "- Trajet" << ": " << billet.od_ << endl;

	return o;
}

/*
 * Date : 12 Septembre 2019
 * Auteur : Philippe CÔTÉ-MORNEAULT
 */

#include "membre.h"

Membre::Membre() :
	nom_(""),
	points_(0),
	billets_(0),
	coupons_(0)
{
}

Membre::Membre(const string& nom) :
	nom_(nom),
	points_(0),
	billets_(0),
	coupons_(0)
{
}

//Constructeur par copie
Membre::Membre(const Membre& membre) :
	nom_(membre.nom_),
	points_(membre.points_),
	billets_(0),
	coupons_(membre.coupons_)
{
}

Membre::~Membre() //vecteurs à vérifier?
{
	while (!billets_.empty())
	{
		delete billets_.back();
		billets_.pop_back();
	}
}

string Membre::getNom() const
{
	return nom_;
}

int Membre::getPoints() const
{
	return points_;
}

vector<Billet*> Membre::getBillets() const
{
	return billets_;
}

vector<Coupon*> Membre::getCoupons() const
{
	return coupons_;
}

void Membre::setNom(const string& nom)
{
	nom_ = nom;
}

void Membre::modifierPoints(int points)
{
	points_ += points;
}

void Membre::ajouterBillet(const string& pnr, double prix, const string& od, TarifBillet tarif, const string& dateVol)
{
	Billet* billet = new Billet(pnr, nom_, prix, od, tarif, dateVol);
	billets_.push_back(billet);
	modifierPoints(calculerPoints(billet));
}

void Membre::acheterCoupon(Coupon* coupon)
{
	if (points_ > coupon->getCout()) {
		//Utilise la surcharge de l'operateur += de la classe Membre plutot qu'utiliser la methode ajouterCoupon
		*this += coupon;
		modifierPoints(-coupon->getCout());
	}
}

double  Membre::calculerPoints(Billet * billet) const
{
	double bonus = 0;
	switch (billet->getTarif()) {
	case TarifBillet::PremiumEconomie:
		bonus = 50;
		break;
	case TarifBillet::Affaire:
		bonus = 150;
		break;
	case TarifBillet::Premiere:
		bonus = 300;
		break;
	default:
		break;
	}

	return billet->getPrix()* 0.10 + bonus;
}

// Remplace methode(ajouterCoupon) par l'operateur += 
Membre& Membre::operator+=(Coupon* coupon)
{
	this->coupons_.push_back(coupon) ;
	return *this;
}

// Remplace cette methode(retirerCoupon) par l'operateur -=
Membre& Membre::operator-=(Coupon* coupon)
{
	for (unsigned int i = 0; i < coupons_.size(); i++) {
		if (coupons_[i] == coupon) {
			coupons_[i] = coupons_[coupons_.size()-1];
			coupons_.pop_back();
			coupons_.shrink_to_fit();
			return *this;
		}
	}
	return *this;
}
 
//Surcharge operateur == droite:string, gauche:membre
bool Membre::operator==(const string nom) const
{
	if (this->getNom() == nom)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Surcharge operateur == droite:membre, gauche:string
bool operator==(const string nom, const Membre& membre)
{
	return membre == nom;
}

//Surcharge operateur =
Membre& Membre::operator=(const Membre& membre)
{
	this->nom_ = membre.nom_;
	this->points_ = membre.points_;
	this->coupons_ = membre.coupons_;
	return *this;
}

// TODO: Remplacer cette methode(afficherMembre) par la surcharge de l'operateur <<
// void Membre::afficherMembre() const
ostream& operator<<(ostream& os, const Membre &membre)
{
	os << setfill(' ');
	os << "- Membre " << membre.nom_ << ":" << endl;
	os << "\t" << left << setw(10) << "- Points" << ": " << membre.points_ << endl;
	os << "\t" << "- Billets :" << endl;
	for (unsigned int i = 0; i < membre.billets_.size(); i++) {
		os << *membre.billets_[i];
	}
	os << "\t" << "- Coupons :" << endl;
	for (unsigned int i = 0; i < membre.coupons_.size(); i++) {
		os << *membre.coupons_[i];
	}
	os << endl;
	return os;
}
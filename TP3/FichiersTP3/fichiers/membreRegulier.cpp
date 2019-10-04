/*
 * Date : 4 Octobre 2019
 * Auteur : Nathan RAMSAY-VEJLENS
 */

#include "membreRegulier.h"

//Constructeur par parametres
MembreRegulier::MembreRegulier(const string& nom, TypeMembre typeMembre) 
	:Membre(nom,typeMembre),
	points_(0)
{}


int MembreRegulier::getPoints() const
{
	return points_;
}

vector<Coupon*> MembreRegulier::getCoupons() const
{
	return coupons_;
}

void MembreRegulier::acheterCoupon(Coupon* coupon)
{
	if (points_ > coupon->getCout()) {
		*this += coupon;
		modifierPoints(-coupon->getCout());
	}
}


Membre& MembreRegulier::operator+=(Coupon* coupon)
{
	coupons_.push_back(coupon);

	return *this;
}

Membre& MembreRegulier::operator-=(Coupon* coupon)
{
	for (unsigned int i = 0; i < coupons_.size(); i++) {
		if (coupons_[i] == coupon) {
			coupons_[i] = coupons_[coupons_.size() - 1];
			coupons_.pop_back();
			return *this;
		}
	}

	return *this;
}

void MembreRegulier::modifierPoints(int points)
{
	points_ += points;
}

void MembreRegulier::ajouterBillet(const string& pnr, double prix, const string& od, TarifBillet tarifBillet, TypeBillet typeBillet, const string& dateVol) {
	
	Billet* billet = nullptr;
	if (typeBillet == TypeBillet::Billet_Regulier) {
		billet = new BilletRegulier(pnr, nom_, prix, od, tarifBillet, dateVol, typeBillet);
	}
	else if (typeBillet == TypeBillet::Flight_Pass) {
		billet = new FlightPass(pnr, nom_, prix, od, tarifBillet, typeBillet);
	}
	else { //billet_base
		billet = new Billet(pnr, nom_, prix, od, tarifBillet, typeBillet);
	}
	billets_.push_back(billet); //ajout billet
	modifierPoints(calculerPoints(billet)); //ajout de points
}

double MembreRegulier::calculerPoints(Billet* billet) const
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

	return billet->getPrix() * 0.10 + bonus;
}


//à compléter
ostream& operator<<(ostream& os, const MembreRegulier& membreRegulier)
{
	
	// TODO: insérer une instruction return ici
	return os;
}

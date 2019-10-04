
#include "membreRegulier.h"

//Constructeur par parametres
MembreRegulier::MembreRegulier(const string& nom, TypeMembre typeMembre) 
	:Membre(nom,typeMembre)
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
	for (int i = 0; i < coupons_.size(); i++) {
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
	if (typeBillet = TypeBillet::Billet_Base) {
		Billet* billet = new Billet(pnr, nom_, prix, od, tarifBillet, typeBillet);
		double pts = calculerPoints(billet);
	}
	else if (typeBillet == TypeBillet::Billet_Regulier) {
		Billet* billet = new BilletRegulier(pnr, nom_, prix, od, tarifBillet, dateVol, typeBillet);
		double pts = calculerPoints(billet);
	}
	else if (typeBillet = TypeBillet::Flight_Pass) {
		Billet* billet = new FlightPass(pnr, nom_, prix, od, tarifBillet, typeBillet);
		double pts = calculerPoints(billet);
	}
	billets_.push_back(billet); //ajout billet
	modifierPoints(pts); //ajout de points
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


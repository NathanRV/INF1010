/********************************************
* Titre: Travail pratique #5 - membreRegulier.cpp
* Date: 30 octobre 2019
* Auteur: Allan BEDDOUK & Jeffrey LAVALLEE
* Modification : Nathan RAMSAY-VEJLENS
* Modifié le : 13 novembre 2019
*******************************************/

#include "membreRegulier.h"

MembreRegulier::MembreRegulier(const string& nom) : 
	Membre(nom), points_(0)
{
}

int MembreRegulier::getPoints() const
{
	return points_;
}

vector<Coupon*> MembreRegulier::getCoupons() const
{
	return coupons_;
}

void MembreRegulier::ajouterBillet(Billet* billet)
{
	Membre::ajouterBillet(billet);
	modifierPoints(calculerPoints(billets_.back()));
}

Membre& MembreRegulier::operator+=(Coupon* coupon)
{
	coupons_.push_back(coupon);

	return *this;
}

/****************************************************************************
* Fonction:		MembreRegulier::operator-=
* Description:	Permet d'enlever un coupon du vecteur de coupon
* Paramètres:	Coupon* coupon
* Retour:		Membre&
****************************************************************************/
Membre& MembreRegulier::operator-=(Coupon* coupon)
{
	auto it = find_if(coupons_.begin(), coupons_.end(), [coupon](Coupon* coup1) {return coup1 == coupon; });
	*it = coupons_[coupons_.size() - 1];
	coupons_.pop_back(); 
	return *this;
}

void MembreRegulier::modifierPoints(int points)
{
	points_ += points;
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

bool MembreRegulier::peutAcheterCoupon(Coupon* coupon) const
{
	return points_ >= coupon->getCout();
}

void MembreRegulier::acheterCoupon(Coupon* coupon)
{
	if (peutAcheterCoupon(coupon)) {
		*this += coupon;
		modifierPoints(-coupon->getCout());
	}
}



/****************************************************************************
* Fonction:		MembreRegulier::afficher
* Description:	Permet d'afficher les attributs d'un MembreRegulier
* Paramètres:	ostream& o
* Retour:		aucun
****************************************************************************/
void MembreRegulier::afficher(ostream& o) const
{
	Membre::afficher(o);
	o << "\t" << "- Points : " << points_ << endl;
	o << "\t" << "- Coupons :" << endl;	
	copy(coupons_.begin(), coupons_.end(), ostream_iterator<const Coupon*>(o, "\n"));
}

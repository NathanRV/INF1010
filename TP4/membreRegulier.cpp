/*
* Titre : membreRegulier.cpp - Travail Pratique #4
* Date : 5 Octobre 2019
* Auteur : Philippe C�T�-MORNEAULT
* Mise � jour : Nathan Ramsay-Vejlens
* Date mise � jour : 17 octobre 2019
*/

#include "membreRegulier.h"

/****************************************************************************
* Fonction:		MembreRegulier::MembreRegulier()
* Description:	Constructeur par param�tres
* Param�tres:	const string& nom
* Retour:		aucun
****************************************************************************/
MembreRegulier::MembreRegulier(const string& nom) : 
	Membre(nom), points_(0)
{
}

/****************************************************************************
* Fonction:		MembreRegulier::getPoints() const
* Description:	Retourne nombre de points
* Param�tres:	Aucun
* Retour:		int
****************************************************************************/
int MembreRegulier::getPoints() const
{
	return points_;
}

/****************************************************************************
* Fonction:		MembreRegulier::getCoupons() const
* Description:	Retourne vecteur de pointeur de coupons
* Param�tres:	Aucun
* Retour:		vector<Coupon*>
****************************************************************************/
vector<Coupon*> MembreRegulier::getCoupons() const
{
	return coupons_;
}

/****************************************************************************
* Fonction:		MembreRegulier::ajouterBillet()
* Description:	appel fonction ajouterBillet de Membre et modifier points
* Param�tres:	Billet* billet
* Retour:		aucun
****************************************************************************/
void MembreRegulier::ajouterBillet(Billet* billet)
{
	Membre::ajouterBillet(billet);
	modifierPoints(calculerPoints(billets_.back()));
}

/****************************************************************************
* Fonction:		MembreRegulier::operator+=()
* Description:	surcharge op�rateur += pour ajouter un coupon
* Param�tres:	Coupon* coupon
* Retour:		Membre&
****************************************************************************/
Membre& MembreRegulier::operator+=(Coupon* coupon)
{
	coupons_.push_back(coupon);

	return *this;
}

/****************************************************************************
* Fonction:		MembreRegulier::operator-=()
* Description:	surcharge op�rateur -= pour supprimer un coupon
* Param�tres:	Coupon* coupon
* Retour:		Membre&
****************************************************************************/
Membre& MembreRegulier::operator-=(Coupon* coupon)
{
	for (size_t i = 0; i < coupons_.size(); ++i) {
		if (coupons_[i] == coupon) {
			coupons_[i] = coupons_[coupons_.size() - 1];
			coupons_.pop_back();
			return *this;
		}
	}

	return *this;
}

/****************************************************************************
* Fonction:		MembreRegulier::modifierPoints()
* Description:	Modifier point en ajoutant la valeur de points
* Param�tres:	int points
* Retour:		aucun
****************************************************************************/
void MembreRegulier::modifierPoints(int points)
{
	points_ += points;
}

/****************************************************************************
* Fonction:		MembreRegulier::calculerPoints()
* Description:	Calcule le nombre de points que rapporte le billet
* Param�tres:	Billet* billet
* Retour:		double
****************************************************************************/
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

/****************************************************************************
* Fonction:		MembreRegulier::peutAcheterCoupon()
* Description:	Verifie si assez de points pour acheter le coupon
* Param�tres:	Coupon* coupon
* Retour:		bool
****************************************************************************/
bool MembreRegulier::peutAcheterCoupon(Coupon* coupon)
{
	if(points_>=coupon->getCout())
	{
		return true;
	}
	return false;
}

/****************************************************************************
* Fonction:		MembreRegulier::acheterCoupon()
* Description:	Achete le coupon
* Param�tres:	Coupon* coupon
* Retour:		aucun
****************************************************************************/
void MembreRegulier::acheterCoupon(Coupon* coupon)
{
	if (peutAcheterCoupon(coupon)) {
		*this += coupon;
		modifierPoints(-coupon->getCout());
	}
}

/****************************************************************************
* Fonction:	MembreRegulier::afficher()
* Description:Fonction affichage de la classe
* Param�tres:	ostream& o
* Retour:		aucun
****************************************************************************/
void MembreRegulier::afficher(ostream& os)
{
	dynamic_cast<Membre*>(this)->afficher(os);
	os << "\t" << "- Points : " << points_ << endl;
	os << "\t" << "- Coupons :" << endl;
	for (size_t i = 0; i < coupons_.size(); ++i) {
		coupons_[i]->afficher(os);
	}
}

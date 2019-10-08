/*
 * Date : 4 Octobre 2019
 * Auteur : Nathan RAMSAY-VEJLENS
 */

#include "membreRegulier.h"

/**
*	Constructeur par parametres
* \param[in]	const string& nom
* \param[in]	TypeMembre		typeMembre
*/
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

/**
*	Fonction qui achete un coupon à l'aide des points du membre
* \param[in]	Coupon* coupon
*/
void MembreRegulier::acheterCoupon(Coupon* coupon)
{
	if (points_ > coupon->getCout()) {
		*this += coupon;
		modifierPoints(-coupon->getCout());
	}
}

/**
*	Surcharge operateur += afin ajouter un coupon au vecteur de coupons du membre
*	\param [in] Coupon* coupon
*/
Membre& MembreRegulier::operator+=(Coupon* coupon)
{
	coupons_.push_back(coupon);

	return *this;
}

/**
*	Surcharge operateur -= afin d'enlever un coupon au vecteur de coupons du membre
*	\param [in] Coupon* coupon
*/
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

/**
*	Fonction qui ajoute un billet au vecteur de billets du membre
*	\param [in] const string&	pnr
*	\param [in] double			prix
*	\param [in] const string&	od
*	\param [in] TarifBillet		tarifBillet
*	\param [in] TypeBillet		typeBillet
*	\param [in] const string&	dateVol
*/
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

/**
*	Fonction qui calcule les points qu'un billet donne 
*	\param [in] Billet* billet
*/
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


/**
*	Surcharge operateur << afin d'afficher le membreRegulier
*/
ostream& operator<<(ostream& os, const MembreRegulier& membreRegulier)
{
	os << setfill(' ');
	os << "- Membre " << membreRegulier.nom_ << ":" << endl;
	os << "\t" << "- Billets :" << endl;
	for (unsigned int i = 0; i < membreRegulier.billets_.size(); i++) {
		if (membreRegulier.billets_[i]->getTypeBillet() == TypeBillet::Billet_Base) {
			os << *membreRegulier.billets_[i] << endl;
		}
		else if (membreRegulier.billets_[i]->getTypeBillet() == TypeBillet::Billet_Regulier) {
			BilletRegulier* billetTemp = static_cast<BilletRegulier*>(membreRegulier.billets_[i]);
			os << *billetTemp << endl;
		}
		else if (membreRegulier.billets_[i]->getTypeBillet() == TypeBillet::Flight_Pass) {
			FlightPass* billetTemp = static_cast<FlightPass*>(membreRegulier.billets_[i]);
			os << *billetTemp << endl;
		}
	}
	os << "\n\t" << left << setw(10) << "- Points" << ": " << membreRegulier.points_ << endl;
	os << "\t" << "- Coupons : \n" << endl;
	for (int i = 0; i < membreRegulier.coupons_.size(); i++) {
		os << *membreRegulier.coupons_[i];
	}

	return os << endl;
}

/*
 * Date : 4 Octobre 2019
 * Auteur : Nathan RAMSAY-VEJLENS
 */

#include "membrePremium.h"

 /**
 *	Constructeur par parametres
 * \param[in]	const string& nom
 */
MembrePremium::MembrePremium(const string& nom) 
	:	MembreRegulier(nom,TypeMembre::Membre_Premium),
	joursRestants_(JOUR_RESTANT_INITIALE),
	pointsCumules_(0)
{}

//Modificateurs

//jourRestants
void MembrePremium::setJourRestants(unsigned int joursRestants) {
	joursRestants_ = joursRestants;
}

//pointCumulee
void MembrePremium::modifierPointsCumules(unsigned int pointCumulee) {
	pointsCumules_ += pointCumulee;
}


//Accesseurs

//jourRestants
unsigned int MembrePremium::getJourRestants() const {
	return joursRestants_;
}

//pointsCumule
unsigned int MembrePremium::getpointsCumulee() const {
	return pointsCumules_;
}

//Autres methodes

/**
*	Fonction qui ajoute un billet au vecteur de billets du membre
*	\param [in] const string&	pnr
*	\param [in] double			prix
*	\param [in] const string&	od
*	\param [in] TarifBillet		tarifBillet
*	\param [in] TypeBillet		typeBillet
*	\param [in] const string&	dateVol
*/
void MembrePremium::ajouterBillet(const string& pnr, double prix, const string& od, TarifBillet tarifBillet, TypeBillet typeBillet, const string& dateVol) {
	Billet* billet = nullptr;
	if (typeBillet == TypeBillet::Billet_Base) {
		billet = new Billet(pnr, nom_, prix, od, tarifBillet, typeBillet);
	}
	else if (typeBillet == TypeBillet::Billet_Regulier) {
		billet = new BilletRegulier(pnr, nom_, prix, od, tarifBillet, dateVol, typeBillet);
	}
	else if (typeBillet == TypeBillet::Flight_Pass) {
		billet = new FlightPass(pnr, nom_, prix, od, tarifBillet, typeBillet);
	}
	billets_.push_back(billet);
	modifierPoints(calculerPoints(billet));
	modifierPointsCumules(calculerPoints(billet));
}

/**
*	Fonction qui achete un coupon
*	\param [in] Coupon* coupon
*/
void MembrePremium::acheterCoupon(Coupon* coupon) {
	//rabais premium
	double rabais = 0.01 * pointsCumules_/1000;
	//rabais max 20%
	if (rabais > 0.2) { rabais = 0.2; }
	//prix coupon
	double prix = coupon->getCout() - rabais * coupon->getCout();
	if (points_ > prix) {
		*this += coupon;
		modifierPoints(-prix);
	}
}

/**
*	Surcharge operateur << afin d'afficher le membrePremium et ses attributs
*/
ostream& operator<<(ostream& os, const MembrePremium& membrePremium) {
	os << setfill(' ');
	os << "- Membre " << membrePremium.nom_ << ":" << endl;
	os << "\t" << "- Billets :" << endl;
	for (unsigned int i = 0; i < membrePremium.billets_.size(); i++) {
		if (membrePremium.billets_[i]->getTypeBillet() == TypeBillet::Billet_Base) {
			os << *membrePremium.billets_[i] << endl;
		}
		else if (membrePremium.billets_[i]->getTypeBillet() == TypeBillet::Billet_Regulier) {
			BilletRegulier* billetTemp = static_cast<BilletRegulier*>(membrePremium.billets_[i]);
			os << *billetTemp << endl;
		}
		else if (membrePremium.billets_[i]->getTypeBillet() == TypeBillet::Flight_Pass) {
			FlightPass* billetTemp = static_cast<FlightPass*>(membrePremium.billets_[i]);
			os << *billetTemp << endl;
		}
	}
	os << "\t" << left << setw(10) << "- Points" << ": " << membrePremium.points_ << endl;
	os << "\t" << "- Coupons : \n" << endl;
	for (int i = 0; i < membrePremium.coupons_.size(); i++) {
		os << *membrePremium.coupons_[i];
	}
	os << "\t" << "- Points cumulees : " << membrePremium.pointsCumules_ << endl;
	os << "\t" << "- Jours premium restant : " << membrePremium.joursRestants_ << endl;

	return os;
}

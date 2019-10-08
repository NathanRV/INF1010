/*
 * Date : 12 Septembre 2019
 * Auteur : Philippe CÔTÉ-MORNEAULT
 * Mise à jour le : 4 Octobre 2019
 * Par : Nathan RAMSAY-VEJLENS
 */

#include "gestionnaire.h"

 /**
 *	Constructeur par defaut
 */
Gestionnaire::Gestionnaire()
{}

Gestionnaire::~Gestionnaire()
{
	for (unsigned int i = 0; i < membres_.size(); i++) {
		delete membres_[i];
	}

	for (unsigned int i = 0; i < coupons_.size(); i++) {
		delete coupons_[i];
	}
}

vector<Membre*> Gestionnaire::getMembres() const
{
	return membres_;
}

vector<Coupon*> Gestionnaire::getCoupons() const
{
	return coupons_;
}

/**
*	Fonction qui ajoute un membre au vecteur de membre du gestionnaire
*	\param [in]		const string&	nomMembre
*	\param [in]		TypeMembre		typeMembre
*/
void Gestionnaire::ajouterMembre(const string& nomMembre, TypeMembre typeMembre)
{
	if (typeMembre == TypeMembre::Membre_Regulier) {
		membres_.push_back(new MembreRegulier(nomMembre, typeMembre));
	}
	else if (typeMembre == TypeMembre::Membre_Premium){
		membres_.push_back(new MembrePremium(nomMembre));
	}
	else {
		membres_.push_back(new Membre(nomMembre, typeMembre));
	}
}

/**
*	Fonction qui ajoute un coupon
*	\param [in]		const string&	code
*	\param [in]		double			rabais
*	\param [in]		int				cout
*/
void Gestionnaire::ajouterCoupon(const string& code, double rabais, int cout)
{
	coupons_.push_back(new Coupon(code, rabais, cout));
}

Membre* Gestionnaire::trouverMembre(const string& nomMembre) const
{
	for (unsigned int i = 0; i < membres_.size(); i++) {
		if (*membres_[i] == nomMembre) {
			return membres_[i];
		}
	}
	cout << "Le membre " << nomMembre << " n'existe pas\n";

	return nullptr;
}

/**
*	Fonction qui assigne un billet à un membre
*	\param [in]		const string&	nomMembre
*	\param [in]		const string&	pnr
*	\param [in]		double			prixBase
*	\param [in]		const string&	od
*	\param [in]		TarifBillet		tarif
*	\param [in]		const string&	dateVol
*	\param [in]		bool			utiliserCoupon
*	\param [in]		TypeBillet		typeBillet
*/
void Gestionnaire::assignerBillet(const string& nomMembre, const string& pnr, double prixBase, const string& od, TarifBillet tarif, const string& dateVol, bool utiliserCoupon, TypeBillet typeBillet)
{
	double prixReel = prixBase;
	Membre* membre = trouverMembre(nomMembre);

	if (membre == nullptr) {
		return;
	}
	
	//flighPass prix multiplie
	if (typeBillet == TypeBillet::Flight_Pass) {
		prixReel = prixReel * 10;
	}

	//Membre premium rabais
	if (membre->getTypeMembre() == TypeMembre::Membre_Premium) {
		MembrePremium* membrePrem = static_cast<MembrePremium*>(membre);
		//rabais premium
		double rabais = 0.005*(membrePrem->getpointsCumulee()/1000);
		if (rabais > 0.1) { rabais = 0.1; }
		prixReel = prixReel - rabais * prixReel;
	}

	if (utiliserCoupon) {
		prixReel = prixReel - appliquerCoupon(membre, prixReel);
	}

	membre->ajouterBillet(pnr, prixReel, od, tarif, typeBillet, dateVol);
}

/**
*	Fonction qui applique un coupon à un prix selon le type de membre
*	\param [in]		Membre*		membre
*	\param [in]		double		prix
*/
double Gestionnaire::appliquerCoupon(Membre* membre, double prix)
{
	if (membre->getTypeMembre() == TypeMembre::Membre_Premium) {
		MembrePremium* membreTemp = static_cast<MembrePremium*>(membre);
		if (membreTemp->getCoupons().size() == 0) {
			cout << "Le membre n'a pas de coupon utilisable.\n";
			return 0;
		}

		Coupon* meilleurCoupon = membreTemp->getCoupons()[0];
		vector<Coupon*> coupons = membreTemp->getCoupons();
		for (unsigned int i = 1; i < coupons.size(); ++i) {
			if (*coupons[i] > * meilleurCoupon) {
				meilleurCoupon = coupons[i];
			}
		}

		*membreTemp -= meilleurCoupon;

		return prix * meilleurCoupon->getRabais();
	}
	else if (membre->getTypeMembre() == TypeMembre::Membre_Regulier) {
		MembreRegulier* membreTemp = static_cast<MembreRegulier*>(membre);
		if (membreTemp->getCoupons().size() == 0) {
			cout << "Le membre n'a pas de coupon utilisable.\n";
			return 0;
		}

		Coupon* meilleurCoupon = membreTemp->getCoupons()[0];
		vector<Coupon*> coupons = membreTemp->getCoupons();
		for (unsigned int i = 1; i < coupons.size(); ++i) {
			if (*coupons[i] > * meilleurCoupon) {
				meilleurCoupon = coupons[i];
			}
		}

		*membreTemp -= meilleurCoupon;

		return prix * meilleurCoupon->getRabais();
	}
	else { //membre occasionnel ne possedent pas de coupon
		cout << "Le type de membre ne permet pas de coupon.\n";
		return 0;
	}
}

/**
*	Fonction qui achete un coupon
*	\param [in]		const string&	nomMembre
*/
void Gestionnaire::acheterCoupon(const string& nomMembre)
{
	if (coupons_.size() == 0) {
		cout << "Le gestionnaire n'a pas de coupon!" << endl;
		return;
	}

	Membre* membre = trouverMembre(nomMembre);
	Coupon* meilleurCoupon = nullptr;

	if (membre == nullptr) {
		return;
	}
	else if (membre->getTypeMembre() == TypeMembre::Membre_Occasionnel) {
		cout << "Le type de membre ne permet pas l'achat de coupon!" << endl;
		return;
	}
	else if (membre->getTypeMembre() == TypeMembre::Membre_Regulier) {
		MembreRegulier* membreTemp=static_cast<MembreRegulier*>(membre);
		for (unsigned int i = 0; i < coupons_.size(); i++) {
			if (membreTemp->getPoints() >= coupons_[i]->getCout()) {
				// Si on avait pas encore trouve de meilleur coupon, on fait la premiere assignation
				if (meilleurCoupon == nullptr) {
					meilleurCoupon = coupons_[i];
				}
				// Sinon on compare si le coupon courant a un rabais superieur au meilleur coupon
				else if (*coupons_[i] > * meilleurCoupon) {
					meilleurCoupon = coupons_[i];
				}
			}
		}

		if (meilleurCoupon) {
			membreTemp->acheterCoupon(meilleurCoupon);
		}
		else {
			cout << "Le membre ne peut acheter de coupon\n";
		}
	}
	else if (membre->getTypeMembre() == TypeMembre::Membre_Premium) {
		MembrePremium* membreTemp = static_cast<MembrePremium*>(membre);
		for (unsigned int i = 0; i < coupons_.size(); i++) {
			if (membreTemp->getPoints() >= coupons_[i]->getCout()) {
				// Si on avait pas encore trouve de meilleur coupon, on fait la premiere assignation
				if (meilleurCoupon == nullptr) {
					meilleurCoupon = coupons_[i];
				}
				// Sinon on compare si le coupon courant a un rabais superieur au meilleur coupon
				else if (*coupons_[i] > * meilleurCoupon) {
					meilleurCoupon = coupons_[i];
				}
			}
		}

		if (meilleurCoupon) {
			membreTemp->acheterCoupon(meilleurCoupon);
		}
		else {
			cout << "Le membre ne peut acheter de coupon\n";
		}
	}
}

/**
*	Surcharge operateur <<
*/
ostream& operator<<(ostream& o, const Gestionnaire& gestionnaire)
{
	o << "=================== ETAT ACTUEL DU PROGRAMME ==================\n\n";
	for (unsigned int i = 0; i < gestionnaire.membres_.size(); i++) {
		if (gestionnaire.membres_[i]->getTypeMembre() == TypeMembre::Membre_Occasionnel) {
			o << *gestionnaire.membres_[i];
		}
		else if (gestionnaire.membres_[i]->getTypeMembre() == TypeMembre::Membre_Regulier) {
			MembreRegulier* membreTemp = static_cast<MembreRegulier*>(gestionnaire.membres_[i]);
			o << *membreTemp << endl;
		}
		else if (gestionnaire.membres_[i]->getTypeMembre() == TypeMembre::Membre_Premium) {
			MembrePremium* membreTemp = static_cast<MembrePremium*>(gestionnaire.membres_[i]);
			o << *membreTemp << endl;
		}
	}

	return o;
}

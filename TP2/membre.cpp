/****************************************************************************
 * Fichier: membre.cpp
 * Auteur: Nathan Ramsay-Vejlens,Freddy Some,Lorenzo Florenty
 * Date: 23 sept 2019
 * Mise a jour : 23 sept 2019
 * Description: Implémentation de la classe membre
 ****************************************************************************/
#include "membre.h"

 /****************************************************************************
  * Fonction:	Membre::Membre()
  * Description:Constructeur par défaut
  * Paramètres:	aucun
  * Retour:		aucun
  ****************************************************************************/
Membre::Membre() :
	nom_(""),
	points_(0),
	billets_(0),
	coupons_(0)
{
}

/****************************************************************************
 * Fonction:	Membre::Membre
 * Description: Constructeur par parametre
 * Paramètres:	(string) nom_
 * Retour:		aucun
 ****************************************************************************/
Membre::Membre(const string& nom) :
	nom_(nom),
	points_(0),
	billets_(0),
	coupons_(0)
{
}

/****************************************************************************
 * Fonction:	Membre::Membre
 * Description: Constructeur par copie
 * Paramètres:	(Membre) membre_
 * Retour:		aucun
 ****************************************************************************/
//Constructeur par copie
Membre::Membre(const Membre& membre) :
	nom_(membre.nom_),
	points_(membre.points_),
	billets_(0),
	coupons_(membre.coupons_)
{
	for (unsigned int i = 0; i < membre.billets_.size(); i++)
	{
		this->billets_.push_back(new Billet(membre.getBillets()[i]->getPnr(), membre.getBillets()[i]->getNomPassager(), membre.getBillets()[i]->getPrix(), membre.getBillets()[i]->getOd(), membre.getBillets()[i]->getTarif(), membre.getBillets()[i]->getDateVol()));
	}
}

/****************************************************************************
 * Fonction:	Membre::~Membre
 * Description: Destructeur
 * Paramètres:	aucun
 * Retour:		aucun
 ****************************************************************************/
Membre::~Membre() 
{
	while (!billets_.empty())
	{
		delete billets_.back();
		billets_.pop_back();
	}
}

/****************************************************************************
 * Fonction:	Membre::getNom
 * Description: Obtenir la variable nom_
 * Paramètres:	aucun
 * Retour:		string
 ****************************************************************************/
string Membre::getNom() const
{
	return nom_;
}

/****************************************************************************
 * Fonction:	Membre::getPoints
 * Description: Obtenir la variable points_
 * Paramètres:	aucun
 * Retour:		int
 ****************************************************************************/
int Membre::getPoints()const
{
	return points_;
}

/****************************************************************************
 * Fonction:	Membre::getBillets
 * Description: Obtenir la variable billets_
 * Paramètres:	aucun
 * Retour:		vector<Billet*>
 ****************************************************************************/
vector<Billet*> Membre::getBillets() const
{
	return billets_;
}

/****************************************************************************
 * Fonction:	Membre::getCoupons
 * Description: Obtenir la variable coupons_
 * Paramètres:	aucun
 * Retour:		vector<Coupon*> 
 ****************************************************************************/
vector<Coupon*> Membre::getCoupons() const
{
	return coupons_;
}

/****************************************************************************
 * Fonction:	Membre::setNom
 * Description: Modifier la variable nom_
 * Paramètres:	(string)nom
 * Retour:		aucun
 ****************************************************************************/
void Membre::setNom(const string& nom)
{
	nom_ = nom;
}

/****************************************************************************
 * Fonction:	Membre::modifierPoints
 * Description: Modifier la variable points_
 * Paramètres:	(int) points
 * Retour:		aucun
 ****************************************************************************/
void Membre::modifierPoints(int points)
{
	points_ += points;
}

/****************************************************************************
 * Fonction:	Membre::ajouterBillet
 * Description: Ajout d'un billet dans la liste de billet
 * Paramètres:	(string)pnr
                (double)prix
				(string)od
				(TarifBillet)tarif
				(string)dateVol
 * Retour:		aucun
 ****************************************************************************/
void Membre::ajouterBillet(const string& pnr, double prix, const string& od, TarifBillet tarif, const string& dateVol)
{
	Billet* billet = new Billet(pnr, nom_, prix, od, tarif, dateVol);
	billets_.push_back(billet);
	modifierPoints(calculerPoints(billet));
}

/****************************************************************************
 * Fonction:	Membre::acheterCoupon
 * Description: Permet de modifier les points en acquerissant un coupon passé en parametre
 * Paramètres:	(Coupon*)coupon
 * Retour:		aucun
 ****************************************************************************/
void Membre::acheterCoupon(Coupon* coupon)
{
	if (points_ > coupon->getCout()) {
		//Utilise la surcharge de l'operateur += de la classe Membre plutot qu'utiliser la methode ajouterCoupon
		*this += coupon;
		modifierPoints(-coupon->getCout());
	}
}

/****************************************************************************
 * Fonction:	Membre::calculerPoints
 * Description: Calcule les points obtenu par le billet passé en parametre
 * Paramètres:	(Billet *)billet
 * Retour:		double
 ****************************************************************************/
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

/****************************************************************************
 * Fonction:	Membre::operator+=
 * Description: Remplace methode(ajouterCoupon) par l'operateur += 
 * Paramètres:	(Coupon*)coupon 
 * Retour:		Membre
 ****************************************************************************/
Membre& Membre::operator+=(Coupon* coupon)
{
	this->coupons_.push_back(coupon) ;
	return *this;
}

/****************************************************************************
 * Fonction:	Membre::operator-=
 * Description: Remplace cette methode(retirerCoupon) par l'operateur -=
 * Paramètres:	(Coupon* coupon)
 * Retour:		Membre
 ****************************************************************************/
Membre& Membre::operator-=(Coupon* coupon)
{
	for (unsigned int i = 0; i < coupons_.size(); i++) {
		if (coupons_[i] == coupon) {
			coupons_[i] = coupons_[coupons_.size()-1];
			coupons_.pop_back();
			return *this;
		}
	}
	return *this;
}

/****************************************************************************
 * Fonction:	Membre::operator==
 * Description: Surcharge operateur == droite:string, gauche:membre
 * Paramètres:	(string)nom
 * Retour:		bool
 ****************************************************************************/
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

/****************************************************************************
 * Fonction:	 operator==
 * Description: Surcharge operateur == droite:membre, gauche:string
 * Paramètres:	(string)nom
                (Membre)membre
 * Retour:		bool
 ****************************************************************************/
bool operator==(const string nom, const Membre& membre)
{
	return membre == nom;
}

/****************************************************************************
 * Fonction:	Membre::operator=
 * Description: Surcharge operateur =
 * Paramètres:	(Membre)membre
 * Retour:		Membre
 ****************************************************************************/
Membre& Membre::operator=(const Membre& membre)
{
	if (membre.billets_ != getBillets())
	{
		this->nom_ = membre.nom_;
		this->points_ = membre.points_;
		this->coupons_ = membre.coupons_;
		for (unsigned int i = 0; i<billets_.size(); i++)
		{
			if (billets_[i] != nullptr)
			{
				delete billets_[i];
			}
		}
		billets_.clear();
		for (unsigned int i = 0; i < membre.billets_.size(); i++)
		{
			this->billets_.push_back(new Billet(membre.getBillets()[i]->getPnr(), membre.getBillets()[i]->getNomPassager(), membre.getBillets()[i]->getPrix(), membre.getBillets()[i]->getOd(), membre.getBillets()[i]->getTarif(), membre.getBillets()[i]->getDateVol()));
		}
	}
	return *this;
}

/****************************************************************************
 * Fonction:	operator<<
 * Description: Affichage d'un membre passé en parametre
 * Paramètres:	(Membre)membre
 * Retour:		ostream
 ****************************************************************************/
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
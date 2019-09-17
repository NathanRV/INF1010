/*
 * Date : 10 Septembre 2019
 * Auteur : Nathan Ramsay-Vejlens
 */

#include "membre.h"

//Constructeur par d�faut
Membre::Membre() : nom_("Inconnu"),points_(0),capaciteBillets_(CAPACITE_INITIALE),billets_(nullptr),
					nbBillets_(0),capaciteCoupons_(CAPACITE_INITIALE),coupons_(nullptr),nbCoupons_(0)
{
	billets_ = new Billet* [capaciteBillets_]; //cr�e tableau de pointeurs
	for (int i = 0; i < capaciteBillets_; i++)//initialise tous les pointeurs
		billets_[i] = nullptr;
	coupons_ = new Coupon* [capaciteCoupons_]; //cr�e tableau de pointeurs
	for (int i = 0; i < capaciteCoupons_; i++) //initialise tous les pointeurs
		coupons_[i] = nullptr;
}

//Constructeur avec param�tre
Membre::Membre(const string& nom_): nom_(nom_),points_(0), capaciteBillets_(CAPACITE_INITIALE),
									billets_(nullptr),nbBillets_(0), capaciteCoupons_(CAPACITE_INITIALE),
									coupons_(nullptr), nbCoupons_(0)
{
	billets_ = new Billet * [capaciteBillets_]; //cr�e tableau de pointeurs
	for (int i = 0; i < capaciteBillets_; i++)//initialise tous les pointeurs
		billets_[i] = nullptr;
	coupons_ = new Coupon * [capaciteCoupons_]; //cr�e tableau de pointeurs
	for (int i = 0; i < capaciteCoupons_; i++) //initialise tous les pointeurs
		coupons_[i] = nullptr;
}

//Destructeur
Membre::~Membre()
{
	//D�sallocation m�moire du tableau dynamique des Billets
	for (int i = 0; i < nbBillets_; i++)
	{
		if (billets_[i] != nullptr)
		{
			delete billets_[i];
		}
		billets_[i] = nullptr;
	}
	delete[] billets_;
	billets_ = nullptr;

	//D�sallocation m�moire du tableau dynamique des Coupons
	for (int i = 0;i<nbCoupons_; i++)
	{
		coupons_[i] = nullptr;
	}
	delete[] coupons_;
	coupons_ = nullptr;
}

//Accesseurs

//Acc�de au nom
string Membre::getNom() const
{
	return nom_;
}

//Acc�de au points
int Membre::getPoints() const
{
	return points_;
}

//Acc�de au billets
Billet** Membre::getBillets() const
{
	return billets_;
}

//Acc�de au nombre de billets
int Membre::getNbBillets() const
{
	return nbBillets_;
}

//Acc�de � la capacit� de billets
int Membre::getCapaciteBillets() const
{
	return capaciteBillets_;
}

//Acc�de aux coupons
Coupon** Membre::getCoupons() const
{
	return coupons_;
}

//Acc�de au nombre de coupons
int Membre::getNbCoupons() const
{
	return nbCoupons_;
}

//Acc�de � la capacit� de coupons
int Membre::getCapaciteCoupons() const
{
	return capaciteCoupons_;
}

//Modificateurs

//Modifie le nom
void Membre::setNom(const string& nom)
{
	nom_ = nom;
}

//Modifie les points
void Membre::modifierPoints(int points)
{
	points_ = points_ + points;
}

//Ajoute un billet
void Membre::ajouterBillet(const string& pnr, double prix, const string& od, TarifBillet tarif, const string& dateVol)
{
	//espace dans tableau
	if (capaciteBillets_ == nbBillets_)	//si plein
	{
		capaciteBillets_ *= 2;
		//Copier premier tableau vers tableau double et recopier
		Billet** doubleBillets = nullptr;
		doubleBillets = new Billet * [capaciteBillets_];
		for (int i = 0; i < capaciteBillets_ / 2; i++) //copie les donn�es du premier
			doubleBillets[i] = billets_[i];
		//effacer premier
		delete[] billets_;
		//copier deuxi�me
		billets_ = doubleBillets;
	}


	//cr�� et ajoute billet
	billets_[nbBillets_] = new Billet(pnr, getNom(), prix, od, tarif, dateVol);

	//modifie points
	int point = calculerPoints(billets_[nbBillets_]);
	modifierPoints(point);

	//incr�mente nombre de billet
	nbBillets_++;
}

//Ajoute coupon
void Membre::ajouterCoupon(Coupon* coupon)
{
	//espace dans tableau
	if (capaciteCoupons_ == nbCoupons_)
	{
		capaciteCoupons_ *= 2;
		//Copier premier tableau vers tableau double et recopier
		Coupon** doubleCoupons = nullptr;
		doubleCoupons = new Coupon * [capaciteCoupons_];
		for (int i = 0; i < nbCoupons_; i++) //copie les donn�es du premier
			doubleCoupons[i] = coupons_[i];
		//effacer premier
		delete[] coupons_;
		//copier deuxi�me
		coupons_ = doubleCoupons;
	}

	//ajoute coupon
	coupons_[nbCoupons_] = coupon;

	//incr�mente nb de coupons
	nbCoupons_++;
}

//retire coupon
void Membre::retirerCoupon(Coupon* coupon)
{
	//v�rifier tous les coupons
	for (int i = 0; i < nbCoupons_; i++)
	{
		if (coupon == coupons_[i]) //trouver coupon
		{
			for (int j = i; j < nbCoupons_ - 1; j++)
			{
				if(coupons_[j+1]==nullptr)
				{
					coupons_[j] = nullptr;
				}
				else
				{
					coupons_[j] = coupons_[j + 1]; //replace les coupons dans le tableau
				}
			}
			i = nbCoupons_;
		}
	}

	//baisse nombre coupon
	nbCoupons_--;
}

//Ach�te coupon
void Membre::acheterCoupon(Coupon* coupon)
{
	//ajoute coupon si assez de points
	if (getPoints() > coupon->getCout())
	{
		//ajout coupon
		ajouterCoupon(coupon);
		//modifie points (enl�ve)
		modifierPoints(-(coupon->getCout()));
	}
	else	//si pas assez de points
	{
		cout << "Erreur: le membre ne possede pas assez de points!\n"; //message d'erreur
	}
}

//Calcul point
double Membre::calculerPoints(Billet* billet) const
{
	//Cherche prix
	double prix = billet->getPrix();
	//10% du prix
	double points = 0.1 * prix;
	//Boni de tarif
	if (TarifBillet::PremiumEconomie == billet->getTarif())
	{
		points += 50;
	}
	else if (TarifBillet::Affaire == billet->getTarif())
	{
		points += 150;
	}
	else if(TarifBillet::Premiere == billet->getTarif())
	{
		points += 300;
	}
	return points;
}

//Affichage
void Membre::afficherMembre() const
{
	//nom
	cout << "- Membre " << getNom() << ":\n";
	//nombre de points
	cout << "	- Points  : " << getPoints() <<"\n";
	//Billets
	cout << "	- Billets :\n";
	Billet** billets = nullptr;
	billets = getBillets();
	for (int i = 0; i < getNbBillets(); i++)
	{
		billets[i]->afficherBillet();
	}
	//Coupons
	cout << "	- Coupons :\n";
	Coupon** coupons = nullptr;
	coupons = getCoupons();
	for (int i = 0; i < getNbCoupons(); i++)
	{
		coupons[i]->afficherCoupon();
	}
}

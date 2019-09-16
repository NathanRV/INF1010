/*
 * Date : 10 Septembre 2019
 * Auteur : Nathan Ramsay-Vejlens
 * Questions :
 *		1. Quel est le lien (agr�gation ou composition) entre les classes Membre et Coupon?
 *			C'est un lien d'agr�gation qu'il y a entre les classes Membre et Coupon puisque
 *			un membre peut �tre d�truit sans que les coupons ne le soient.De plus, il est
 *			possible de le voir dans la destructeur de membre qui ne d�truit que le tableau
 *			de pointeurs et non les pointeurs.
 *
 *		2. Quel effet aura une m�thode si elle a un const ?
 *			Elle rend impossible la modification par inadvertance de la variable pass�e
 *			dans l'appel de la m�thode.
 */

#include "gestionnaire.h"

//Constructeur par d�faut
Gestionnaire::Gestionnaire() : capaciteMembres_(CAPACITE_INITIALE), membres_(nullptr), nbMembres_(0),
		capaciteCoupons_(CAPACITE_INITIALE),coupons_(nullptr),nbCoupons_(0)
{
	membres_ = new Membre* [capaciteMembres_];//cr�e tableau de pointeur
	for (int i = 0; i < capaciteMembres_; i++)//initialise pointeurs
		membres_[i] = nullptr;
	coupons_ = new Coupon* [capaciteCoupons_];//cr�e tableau de pointeur
	for (int i = 0; i < capaciteCoupons_; i++) //initialise pointeurs
		coupons_[i] = nullptr;
}

//Destructeur
Gestionnaire::~Gestionnaire()
{
	//D�sallocation m�moire membre
	for (int i = 0; i < nbMembres_; i++)
	{
		if (membres_[i] != nullptr)
		{
			delete membres_[i];
		}
		membres_[i] = nullptr;
	}
	delete[] membres_;
	membres_ = nullptr;

	//D�sallocation m�moire coupons
	for (int i = 0; i < nbCoupons_; i++)
	{
		if (coupons_[i] != nullptr)
		{
			delete coupons_[i];
		}
		coupons_[i] = nullptr;
	}
	delete[] coupons_;
	coupons_ = nullptr;
}

//Accesseurs

//Acc�de aux membres
Membre** Gestionnaire::getMembres() const
{
	return membres_;
}

//Acc�de au nombre de membres
int Gestionnaire::getNbMembres() const
{
	return nbMembres_;
}

//Acc�de � la capacit� en membres
int Gestionnaire::getCapaciteMembres() const
{
	return capaciteMembres_;
}

//Acc�de aux coupons
Coupon** Gestionnaire::getCoupons() const
{
	return coupons_;
}

//Acc�de au nombre de coupons
int Gestionnaire::getNbCoupons() const
{
	return nbCoupons_;
}

//Acc�de � la capacit� en coupons
int Gestionnaire::getCapaciteCoupons() const
{
	return capaciteCoupons_;
}

//Trouve un membre
Membre* Gestionnaire::trouverMembre(const string& nomMembre) const
{
	Membre* temp = nullptr;
	for (int i = 0; i < nbMembres_; i++)
	{
		if (nomMembre == membres_[i]->getNom())
			temp = membres_[i];
	}
	if (temp == nullptr)
	{
		cout << "Le membre " << nomMembre << " n'existe pas!\n";
	}
	return temp;
}

//Modificateurs

//Ajoute membre
void Gestionnaire::ajouterMembre(const string& nomMembre)
{
	//v�rifier capacit� tableau et doubler si plein
	if (capaciteMembres_ == nbMembres_)
	{
		capaciteMembres_ *= 2;
		//Copier premier tableau vers tableau double et recopier
		Membre** doubleMembres = nullptr;
		doubleMembres = new Membre* [capaciteMembres_];
		for (int i = 0; i < nbMembres_; i++) //copie les donn�es du premier
			doubleMembres[i] = membres_[i];
		//effacer premier
		delete[] membres_;
		//copier deuxi�me
		membres_ = doubleMembres;
	}

	//cr�er un nouveau membre
	membres_[nbMembres_] = new Membre(nomMembre);

	//incr�menter le nombre de membre
	nbMembres_ = nbMembres_ + 1;
}

//Ajoute coupon
void Gestionnaire::ajouterCoupon(const string& code, double rabais, int cout)
{
	if (nbCoupons_ == capaciteCoupons_)
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

	coupons_[nbCoupons_]=new Coupon(code, rabais, cout);
	nbCoupons_++;
}

//Assigne un billet
void Gestionnaire::assignerBillet(const string& nomMembre, const string& pnr, double prixBase, const string& od, TarifBillet tarif, const string& dateVol, bool utiliserCoupon)
{
	//variable temporaires
	double prix = prixBase;
	Membre* temp = nullptr;
	//trouver membre
	temp = trouverMembre(nomMembre);
	//si on utilise un coupon
	if (utiliserCoupon)
	{
		prix = appliquerCoupon(temp, prixBase);
	}
	//ajoute le billet
	temp->ajouterBillet(pnr, prix, od, tarif, dateVol);
}

//Applique un coupon
double Gestionnaire::appliquerCoupon(Membre* membre, double prix)
{
	//variable temporaire
	double maxRabais = 0;
	Coupon* pos = nullptr;
	Coupon* coupon = nullptr;
	Coupon** coupons = nullptr;
	//Acc�de coupons
	coupons = membre->getCoupons();
	//Pour tous les coupons
	for (int i = 0; i < membre->getNbCoupons(); i++)
	{
		coupon = coupons[i];
		if (coupon->getRabais() > maxRabais) //v�rifie quel coupon a le plus grand rabais
		{
			maxRabais = coupon->getRabais();
			pos = coupon;
		}
	}
	if (maxRabais != 0)//s'il y a un rabais
	{
		membre->retirerCoupon(pos);	//effacer coupon

		//rabais sur le prix en dollar
		double rabais = maxRabais * prix;
		return prix - rabais;	//prix apr�s rabais
	}
	cout << "Erreur: le membre ne possede aucun coupon!\n" ;	//sinon message d'erreur
	return prix;
}

//Ach�te un coupon
void Gestionnaire::acheterCoupon(const string& nomMembre)
{
	//Trouver membre
	Membre* membre = nullptr;
	membre = trouverMembre(nomMembre);
	int point = membre->getPoints();

	//trouver coupon qui donne plus de rabais selon point membre
	double maxRabais = 0;
	Coupon* couponMax = nullptr;
	Coupon* couponAchete = nullptr;
	for (int i = 0; i < nbCoupons_; i++)
	{
		Coupon* pos = coupons_[i];
		if (pos->getRabais() > maxRabais)
		{
			maxRabais = pos->getRabais();
			couponMax = pos;
			if (pos->getCout() < point)
			{
				couponAchete = pos;
			}
		}
	}
	if (couponAchete == nullptr)
	{
		couponAchete = couponMax;
	}
	//achat du coupon
	membre->acheterCoupon(couponAchete);
}

//Affichage
void Gestionnaire::afficherInfos() const
{
	//Variables temporaires
	Membre** membres = getMembres();
	cout << "=========================Gestionnaire=========================\n";
	for (int i = 0; i < getNbMembres(); i++)
	{
		membres[i]->afficherMembre();
	}
}


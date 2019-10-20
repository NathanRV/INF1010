/*
* Titre : gestionnaire.cpp - Travail Pratique #4
* Date : 5 Octobre 2019
* Auteur : Philippe CÔTÉ-MORNEAULT
* Mise à jour : Nathan Ramsay-Vejlens
* Date mise à jour : 17 octobre 2019
*/

#include "gestionnaire.h"

/****************************************************************************
* Fonction:		Gestionnaire::Gestionnaire()
* Description:	Constructeur par défaut
* Paramètres:	aucun
* Retour:		aucun
****************************************************************************/
Gestionnaire::Gestionnaire()
{
}

/****************************************************************************
* Fonction:		Gestionnaire::~Gestionnaire()
* Description:	destructeur virtuel
* Paramètres:	aucun
* Retour:		aucun
****************************************************************************/
Gestionnaire::~Gestionnaire()
{
	for (size_t i = 0; i < membres_.size(); ++i) {
		delete membres_[i];
	}

	for (size_t i = 0; i < coupons_.size(); ++i) {
		delete coupons_[i];
	}
}

/****************************************************************************
* Fonction:		Gestionnaire::getMembres() const
* Description:	retourne vecteur de pointeurs de membres
* Paramètres:	aucun
* Retour:		vector<Membre*>
****************************************************************************/
vector<Membre*> Gestionnaire::getMembres() const
{
	return membres_;
}

/****************************************************************************
* Fonction:		Gestionnaire::getCoupons() const
* Description:	retourne vecteur de pointeurs de coupons
* Paramètres:	aucun
* Retour:		vector<Coupon*>
****************************************************************************/
vector<Coupon*> Gestionnaire::getCoupons() const
{
	return coupons_;
}

/****************************************************************************
* Fonction:		Gestionnaire::ajouterMembre()
* Description:	Ajoute un membre au vecteur de pointeur de membre
* Paramètres:	Membre* membre
* Retour:		aucun
****************************************************************************/
void Gestionnaire::ajouterMembre(Membre* membre)
{
	membres_.push_back(membre);
}

/****************************************************************************
* Fonction:		Gestionnaire::ajouterCoupon()
* Description:	Ajoute un coupon au vecteur de pointeur de coupon
* Paramètres:	Coupon* coupon
* Retour:		aucun
****************************************************************************/
void Gestionnaire::ajouterCoupon(Coupon* coupon)
{
	coupons_.push_back(coupon);
}

/****************************************************************************
* Fonction:		Gestionnaire::trouverMembre() const
* Description:	Cherche membre dans le veceteur de pointeur de membre avec son nom
* Paramètres:	const string& nomMembre
* Retour:		Membre*
****************************************************************************/
Membre* Gestionnaire::trouverMembre(const string& nomMembre) const
{
	for (size_t i = 0; i < membres_.size(); ++i) {
		if (*membres_[i] == nomMembre) {
			return membres_[i];
		}
	}
	cout << "Le membre " << nomMembre << " n'existe pas\n";

	return nullptr;
}

/****************************************************************************
* Fonction:		Gestionnaire::assignerBillet()
* Description:	Assigne un billet à un membre en utilisant(ou pas) un coupon
* Paramètres:	Billet* billet, const string& nomMembre, bool utiliserCoupon
* Retour:		aucun
****************************************************************************/
void Gestionnaire::assignerBillet(Billet* billet, const string& nomMembre, bool utiliserCoupon)
	{
	Membre* membre = trouverMembre(nomMembre);

	if (membre == nullptr) {
		delete billet;
		return;
	}

	double prix = 0;
	//Verifie si billets deja en solde
	if (dynamic_cast<Solde*>(billet))
	{
		Solde* solde = dynamic_cast<Solde*>(billet);
		prix = solde->getPrixBase();
	}
	else
	{
		prix = billet->getPrix();
	}

	if (utiliserCoupon) {
		prix -= appliquerCoupon(membre, prix);
	}

	if (dynamic_cast<MembrePremium*>(membre)) {
		double rabais = 0.005 * dynamic_cast<MembrePremium*>(membre)->getpointsCumulee() / 1000;
		if (rabais > 0.1)
			rabais = 0.1;

		prix *= (1 - rabais);
		billet->setPrix(prix);
		dynamic_cast<MembrePremium*>(membre)->ajouterBillet(billet);
	}
	else if(dynamic_cast<MembreRegulier*>(membre))
	{
		billet->setPrix(prix);
		dynamic_cast<MembreRegulier*>(membre)->ajouterBillet(billet);
	}
	else
	{
		billet->setPrix(prix);
		membre->ajouterBillet(billet);
	}
	
}


/****************************************************************************
* Fonction:		Gestionnaire::appliquerCoupon()
* Description:	Applique un coupon du membre à un prix passé en valeur
* Paramètres:	Membre* membre, double prix
* Retour:		double
****************************************************************************/
double Gestionnaire::appliquerCoupon(Membre* membre, double prix)
{
	MembreRegulier* membreReg = dynamic_cast<MembreRegulier*>(membre);

	if (!membreReg || membreReg->getCoupons().size() == 0) {
		cout << "Le membre n'a pas de coupon utilisable\n";
		return 0;
	}

	Coupon* meilleurCoupon = membreReg->getCoupons()[0];
	vector<Coupon*> coupons = membreReg->getCoupons();
	for (size_t i = 1; i < coupons.size(); ++i) {
		if (*coupons[i] > *meilleurCoupon) {
			meilleurCoupon = coupons[i];
		}
	}

	*membreReg -= meilleurCoupon;

	return prix * meilleurCoupon->getRabais();
}


/****************************************************************************
* Fonction:		Gestionnaire::acheterCoupon()
* Description:	Achete un coupon pour le membre
* Paramètres:	const string& nomMembre
* Retour:		aucun
****************************************************************************/
void Gestionnaire::acheterCoupon(const string& nomMembre)
{
	if (coupons_.size() == 0) {
		cout << "Le gestionnaire n'a pas de coupon!" << endl;
		return;
	}

	Membre* membre = trouverMembre(nomMembre);

	if (membre == nullptr) {
		return;
	}

	Coupon* meilleurCoupon = nullptr;

	if (auto membreRegulier = dynamic_cast<MembreRegulier*>(membre)) {
		for (size_t i = 0; i < coupons_.size(); ++i) {
			if (membreRegulier->peutAcheterCoupon(coupons_[i])) {
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
			membreRegulier->acheterCoupon(meilleurCoupon);
		}
		else {
			cout << "Le membre ne peut acheter de coupon\n";
		}
	}
	else {
		cout << "Le membre ne peut acheter de coupon\n";
	}
}

/****************************************************************************
* Fonction:		Gestionnaire::calculerRevenu()
* Description:	Calcule le revenu fait sur les billets achetés en tenant compte solde
* Paramètres:	aucun
* Retour:		double
****************************************************************************/
double Gestionnaire::calculerRevenu()
{
	double rev=0;
	for(unsigned int i=0;i<membres_.size();i++)
	{
		for (unsigned int j = 0; j < membres_[i]->getBillets().size(); j++)
		{
			rev += membres_[i]->getBillets()[j]->getPrix();
		}
	}
	return rev;
}

/****************************************************************************
* Fonction:		Gestionnaire::calculerNombreBilletsEnSolde()
* Description:	Calcule nombre de billets en solde
* Paramètres:	aucun
* Retour:		int
****************************************************************************/
int Gestionnaire::calculerNombreBilletsEnSolde()
{
	int Nb=0;
	for (unsigned int i = 0; i < membres_.size(); i++)
	{
		for(unsigned int j=0;j<membres_[i]->getBillets().size();j++)
		{
			if (dynamic_cast<Solde*>(membres_[i]->getBillets()[j]))
			{

				Nb++;
			}
		}
	}
	return Nb;
}
	
/****************************************************************************
* Fonction:		Gestionnaire::afficher()
* Description:	Fonction affichage de la classe
* Paramètres:	ostream& o
* Retour:		aucun
****************************************************************************/
void Gestionnaire::afficher(ostream& o)
{
	o << "=================== ETAT ACTUEL DU PROGRAMME ==================\n\n";

	for (int i = 0; i < membres_.size(); ++i) {
		if (MembrePremium* membrePremium = dynamic_cast<MembrePremium*>(membres_[i]))
		{
			membrePremium->afficher(o);
		}
		else if (MembreRegulier* membreRegulier = dynamic_cast<MembreRegulier*>(membres_[i]))
		{
			membreRegulier->afficher(o);
		}
		else
		{
			membres_[i]->afficher(o);
		}
	}
}
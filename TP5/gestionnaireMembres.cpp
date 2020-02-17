/********************************************
* Titre: Travail pratique #5 - gestionnaireMembres.cpp
* Date: 30 octobre 2019
* Auteur: Allan BEDDOUK & Jeffrey LAVALLEE
* Modification : Nathan RAMSAY-VEJLENS
* Modifié le : 12 novembre 2019
*******************************************/

#include "gestionnaireMembres.h"

/****************************************************************************
* Fonction:		GestionnaireMembres::~GestionnaireMembres()
* Description:	Destructeur
* Paramètres:	aucun
* Retour:		aucun
****************************************************************************/
GestionnaireMembres::~GestionnaireMembres()
{
	for(auto it=conteneur_.begin();it!=conteneur_.end();it++)
	{
		delete it->second;
	}
}

/****************************************************************************
* Fonction:		GestionnaireCoupons::assignerBillet()
* Description:	assigne un billet à un membre en appliquant un coupon
* Paramètres:	Billet8 billet, const string& nomMembre, int rabaisCoupon
* Retour:		aucun
****************************************************************************/
void GestionnaireMembres::assignerBillet(Billet* billet, const string& nomMembre, int rabaisCoupon)
{
	Membre* membre = conteneur_[nomMembre];

	if (membre == nullptr) {
		delete billet;
		return;
	}

	double prix = billet->getPrix();

	if (auto solde = dynamic_cast<Solde*>(billet)) {
		prix = solde->getPrixBase();
	}

	
	prix -= rabaisCoupon;
	

	if (auto membrePremium = dynamic_cast<MembrePremium*>(membre)) {
		double rabais = 0.005 * membrePremium->getpointsCumulee() / 1000;
		if (rabais > 0.1)
			rabais = 0.1;

		prix *= (1 - rabais);
	}

	billet->setPrix(prix);
	membre->ajouterBillet(billet);
}


/****************************************************************************
* Fonction:		GestionnaireMembres::calculerRevenu() const
* Description:	calcule la somme de tous les prix de billets achetés
* Paramètres:	aucun
* Retour:		double
****************************************************************************/
double GestionnaireMembres::calculerRevenu() const
{
	double revenu = 0;
	for (auto it = conteneur_.begin(); it != conteneur_.end(); it++)
	{
		vector<Billet*> billets=it->second->getBillets();
		for (auto it2 = billets.begin(); it2 != billets.end(); it2++)
		{
			revenu += (*it2)->getPrix();
		}
	}
	return revenu;
}

/****************************************************************************
* Fonction:		GestionnaireMembres::calculerNombreBilletsEnSolde() const
* Description:	calcule le nombre de billets en solde
* Paramètres:	aucun
* Retour:		int
****************************************************************************/
int GestionnaireMembres::calculerNombreBilletsEnSolde() const
{
	int nbBilletsSolde = 0;
	for (pair<string, Membre*> pair : conteneur_)
	{
		auto billets = pair.second->getBillets();
		nbBilletsSolde += count_if(billets.begin(), billets.end(), [](Billet* billet) {return dynamic_cast<Solde*>(billet); });
	}
	return nbBilletsSolde;
}

/****************************************************************************
* Fonction:		GestionnaireMembres::getBilletMin() const
* Description:	Retourne pointeur sur billet le moins cher
* Paramètres:	string nomMembre
* Retour:		Billet*
****************************************************************************/
Billet* GestionnaireMembres::getBilletMin(string nomMembre) const
{
	//accède à pair avec nom du membre
	auto it = conteneur_.find(nomMembre);
	//vecteur de billet
	auto billets=it->second->getBillets();
	//trouve element minimum
	auto it1 = min_element(billets.begin(), 
		billets.end(), 
		[](const Billet* billet, const Billet* billet2 ) {return billet->getPrix()<billet2->getPrix(); });
	return *it1;
}

/****************************************************************************
* Fonction:		GestionnaireMembres::getBilletMax() const
* Description:	Retourne pointeur sur billet le plus cher
* Paramètres:	string nomMembre
* Retour:		Billet*
****************************************************************************/
Billet* GestionnaireMembres::getBilletMax(string nomMembre) const
{
	//accède à pair avec nom du membre
	auto it = conteneur_.find(nomMembre);
	//vecteur de billet
	auto billets = it->second->getBillets();
	//trouve element minimum
	auto it1 = max_element(billets.begin(),
		billets.end(),
		[](const Billet* billet, const Billet* billet2) {return billet->getPrix() < billet2->getPrix(); });
	return *it1;
}

/****************************************************************************
* Fonction:		GestionnaireMembres::trouverBilletParIntervalle() const
* Description:	Retourne les billets dans l'intervalle
* Paramètres:	Membre* membre, double prixInf, double prixSup
* Retour:		vector<Billet*>
****************************************************************************/
vector<Billet*> GestionnaireMembres::trouverBilletParIntervallle(Membre* membre, double prixInf, double prixSup) const
{
	//accède à pair avec nom du membre
	auto it = conteneur_.find(membre->getNom());
	//vecteur de billet
	auto billets = it->second->getBillets();
	//initialiser intervalle
	auto intervalle = IntervallePrixBillet(prixInf, prixSup);
	//trouve element intervalle
	vector<Billet*> vec;
	copy_if(billets.begin(), billets.end(), back_inserter(vec),
		bind([](Billet* billet,auto intervalle) {return intervalle(billet); },std::placeholders::_1,intervalle));
	return vec;
}

/****************************************************************************
* Fonction:		GestionnaireMembres::afficher() const
* Description:	Affiche les membres et leurs attributs
* Paramètres:	ostream& o
* Retour:		aucun
****************************************************************************/
void GestionnaireMembres::afficher(ostream& o) const
{
	o << "=================== ETAT ACTUEL DU PROGRAMME ==================\n\n";
	
	for (pair<string, Membre*> pair : conteneur_)
	{
		pair.second->afficher(o);
	}
}

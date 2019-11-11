/********************************************
* Titre: Travail pratique #5 - gestionnaireMembres.cpp
* Date: 30 octobre 2019
* Auteur: Allan BEDDOUK & Jeffrey LAVALLEE
*******************************************/

#include "gestionnaireMembres.h"
#include <numeric>

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



double GestionnaireMembres::calculerRevenu() const
{
	double revenu = 0;
	for (pair<string, Membre*> pair : conteneur_)
	{
		for (Billet* billet : pair.second->getBillets())
		{
			revenu += billet->getPrix();
		}
	}
	return revenu;
}

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

void GestionnaireMembres::afficher(ostream& o) const
{
	//TODO
	o << "=================== ETAT ACTUEL DU PROGRAMME ==================\n\n";
	
	for (pair<string, Membre*> pair : conteneur_)
	{
		pair.second->afficher(o);
	}
}

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
		nbBilletsSolde += count_if(pair.second->getBillets().begin(), pair.second->getBillets().end(), [](Billet* billet) {return dynamic_cast<Solde*>(billet); });
	}
	return nbBilletsSolde;
}

Billet* GestionnaireMembres::getBilletMin(string nomMembre) const
{
	/////////////////////////////////////////////////////////////
	//accède à pair avec nom du membre
	/*auto it = conteneur_.find(nomMembre);
	conteneur_(it).begin()
	billets_=getBillets()
	min_element()*/
	return nullptr;
}

Billet* GestionnaireMembres::getBilletMax(string nomMembre) const
{
	return nullptr;
}

vector<Billet*> GestionnaireMembres::trouverBilletParIntervallle(Membre* membre, double prixInf, double prixSup) const
{
	return vector<Billet*>();
}

void GestionnaireMembres::afficher(ostream& o) const
{
	/*//TODO
	o << "=================== ETAT ACTUEL DU PROGRAMME ==================\n\n";

	for (size_t i =0 ; i<membres_.size() ; ++i) {
		membres[i]->afficher(o);
	}*/
}

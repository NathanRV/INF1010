/********************************************
* Titre: Travail pratique #5 - membre.cpp
* Date: 30 octobre 2019
* Auteur: Allan BEDDOUK & Jeffrey LAVALLEE
* Modification : Nathan RAMSAY-VEJLENS
* Modifié le : 12 novembre 2019
*******************************************/

#include "membre.h"

Membre::Membre() :
	nom_("")
{
}

Membre::Membre(const string& nom) :
	nom_(nom)
{
}


/****************************************************************************
* Fonction:		Membre::Membre()
* Description:	Constructeur par copie d'un membre
* Paramètres:	const Membre& membre
* Retour:		Membre
****************************************************************************/
Membre::Membre(const Membre& membre) :
	nom_(membre.nom_)
{
	copy(membre.billets_.begin(), membre.billets_.end(), billets_.begin());
}

/****************************************************************************
* Fonction:		Membre::~Membre()
* Description:	Destructeur virtuel
* Paramètres:	aucun
* Retour:		aucun
****************************************************************************/
Membre::~Membre()
{
	for (auto it=billets_.begin(); it!=billets_.end(); it++) {
		delete *it;
	}
}

string Membre::getNom() const
{
	return nom_;
}

vector<Billet*> Membre::getBillets() const
{
	return billets_;
}

void Membre::setNom(const string& nom)
{
	nom_ = nom;
}

/****************************************************************************
* Fonction:		Membre::trouverBillet
* Description:	retourne iterateur sur billet cherché si disponible
* Paramètres:	const string& pnr
* Retour:		vector<Billet*>::iterator
****************************************************************************/
vector<Billet*>::iterator Membre::trouverBillet(const string& pnr)
{
	return find_if(billets_.begin(), billets_.end(), [pnr](Billet* billet) {return billet->getPnr() == pnr; });
}


/****************************************************************************
* Fonction:		Membre::utiliserBillet
* Description:	Deep copy d'un membre
* Paramètres:	const string& pnr
* Retour:		aucun
****************************************************************************/
void Membre::utiliserBillet(const string& pnr)
{
	auto it = trouverBillet(pnr);
	
	if (it == billets_.end()) {
		cout << "Le billet n'est pas trouve" << endl;
		return;
	}
	
	if (auto flightPass = dynamic_cast<FlightPass*>(*it)) {
		flightPass->decrementeNbUtilisations();
		if (flightPass->getNbUtilisationsRestante() > 0) {
			return;
		}
	}

	delete *it;
	*it = billets_[billets_.size() - 1];
	billets_.pop_back();
}

void Membre::ajouterBillet(Billet* billet)
{
	billet->setNomPassager(nom_);
	billets_.push_back(billet);
}

bool Membre::operator==(const string& nomMembre) const
{
	return nom_ == nomMembre;
}

bool operator==(const string& nomMembre, const Membre& membre)
{
	return nomMembre == membre.nom_;
}


/****************************************************************************
* Fonction:		Membre::operator=
* Description:	Deep copy d'un membre
* Paramètres:	const Membre& membre
* Retour:		Membre&
****************************************************************************/
Membre& Membre::operator=(const Membre& membre)
{
	if (this != &membre) {
		nom_ = membre.nom_;

		for (auto it = billets_.begin(); it != billets_.end();it++) {
			delete *it;
		}

		billets_.clear();
		
		copy(membre.billets_.begin(), membre.billets_.end(), back_inserter(billets_));
	}

	return *this;
}


/****************************************************************************
* Fonction:		Membre::afficher
* Description:	Affiche les attributs du Membre
* Paramètres:	ostream& o
* Retour:		aucun
****************************************************************************/
void Membre::afficher(ostream& o) const
{
	o << setfill(' ');
	o << "- Membre " << nom_ << ":" << endl;
	o << "\t" << "- Billets :" << endl;
	copy(billets_.begin(), billets_.end(), ostream_iterator<const Billet* >(o, "\n"));
}
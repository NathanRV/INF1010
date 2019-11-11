/********************************************
* Titre: Travail pratique #5 - membre.cpp
* Date: 30 octobre 2019
* Auteur: Allan BEDDOUK & Jeffrey LAVALLEE
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

//todo
Membre::Membre(const Membre& membre) :
	nom_(membre.nom_)
{
	for (size_t i = 0; i < membre.billets_.size(); ++i) {
		billets_.push_back(membre.billets_[i]->clone());
	}
}

//todo
Membre::~Membre()
{
	for (size_t i = 0; i < billets_.size(); ++i) {
		delete billets_[i];
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

//à revoir
vector<Billet*>::iterator Membre::trouverBillet(const string& pnr)
{
	return find_if(billets_.begin(), billets_.end(), [pnr](Billet* billet) {return billet->getPnr() == pnr; });
}

//todo
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


//fait
Membre& Membre::operator=(const Membre& membre)
{
	if (this != &membre) {
		nom_ = membre.nom_;

		for (Billet* billet : billets_) {
			delete billet;
		}

		billets_.clear();

		for (Billet* billet : membre.billets_) {
			billets_.push_back(billet);
			copy(membre.billets_.begin(), membre.billets_.end(), back_inserter(billets_));
		}
	}

	return *this;
}


//todo
void Membre::afficher(ostream& o) const
{
	o << setfill(' ');
	o << "- Membre " << nom_ << ":" << endl;
	o << "\t" << "- Billets :" << endl;
	copy(billets_.begin(), billets_.end(), ostream_iterator<const Billet* >(o, "\n"));
}
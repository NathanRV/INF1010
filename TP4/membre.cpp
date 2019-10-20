/*
* Titre : membre.cpp - Travail Pratique #4
* Date : 5 Octobre 2019
* Auteur : Philippe CÔTÉ-MORNEAULT
* Mise à jour : Nathan Ramsay-Vejlens
* Date mise à jour : 17 octobre 2019
*/

#include "membre.h"
/****************************************************************************
* Fonction:		Membre::Membre()
* Description:	Constructeur par défaut
* Paramètres:	aucun
* Retour:		aucun
****************************************************************************/
Membre::Membre() :
	nom_("")
{
}

/****************************************************************************
* Fonction:		Membre::Membre()
* Description:	Constructeur par paramèetres
* Paramètres:	const string& nom
* Retour:		aucun
****************************************************************************/
Membre::Membre(const string& nom) :
	nom_(nom)
{
}

/****************************************************************************
* Fonction:		Membre::Membre()
* Description:	Constructeur par copie
* Paramètres:	const Membre& membre
* Retour:		aucun
****************************************************************************/
Membre::Membre(const Membre& membre) :
	nom_(membre.nom_)
{
	for (size_t i = 0; i < membre.billets_.size(); ++i) {
		if (FlightPassSolde* flightPassSolde = dynamic_cast<FlightPassSolde*>(membre.billets_[i]))
		{
			billets_.push_back(new FlightPassSolde(*flightPassSolde));
		}
		else if (FlightPass* flightPass = dynamic_cast<FlightPass*>(membre.billets_[i]))
		{
			billets_.push_back(new FlightPass(*flightPass));
		}
		else if (BilletRegulierSolde* billetRegSolde = dynamic_cast<BilletRegulierSolde*>(membre.billets_[i]))
		{
			billets_.push_back(new BilletRegulierSolde(*billetRegSolde));
		}
		else if (BilletRegulier* billetReg = dynamic_cast<BilletRegulier*>(membre.billets_[i]))
		{
			billets_.push_back(new BilletRegulier(*billetReg));
		}
	}
}

/****************************************************************************
* Fonction:		Membre::~Membre()
* Description:	Destructeur virtuel
* Paramètres:	aucun
* Retour:		aucun
****************************************************************************/
Membre::~Membre()
{
	for (size_t i = 0; i < billets_.size(); ++i) {
		delete billets_[i];
	}
}

/****************************************************************************
* Fonction:		Membre::getNom()
* Description:	Retourne nom
* Paramètres:	Aucun
* Retour:		string
****************************************************************************/
string Membre::getNom() const
{
	return nom_;
}

/****************************************************************************
* Fonction:		Membre::getBillets() const
* Description:	Retourne vecteur de pointeurs de billets
* Paramètres:	Aucun
* Retour:		vector<Billet*>
****************************************************************************/
vector<Billet*> Membre::getBillets() const
{
	return billets_;
}

/****************************************************************************
* Fonction:		Membre::setNom()
* Description:	modifie le nom
* Paramètres:	const string& nom
* Retour:		aucun
****************************************************************************/
void Membre::setNom(const string& nom)
{
	nom_ = nom;
}

/****************************************************************************
* Fonction:		Membre::utiliserBillet()
* Description:	Efface le billet
* Paramètres:	const string& pnr
* Retour:		aucun
****************************************************************************/
void Membre::utiliserBillet(const string& pnr)
{
	int indexTrouve = -1;
	for (size_t i = 0; i < billets_.size(); ++i) {
		if (billets_[i]->getPnr() == pnr) {
			indexTrouve = i;
			break;
		}
	}

	if (indexTrouve == -1) {
		cout << "Le billet n'est pas trouve" << endl;
		return;
	}

	
	if (dynamic_cast<FlightPass*>(billets_[indexTrouve]))
	{
		FlightPass* flightPass = dynamic_cast<FlightPass*>(billets_[indexTrouve]);
		flightPass->decrementeNbUtilisations();
		if (flightPass->getNbUtilisationsRestante() > 0) {
			return;
		}
	}

	delete billets_[indexTrouve];
	billets_[indexTrouve] = billets_[billets_.size() - 1];
	billets_.pop_back();
}

/****************************************************************************
* Fonction:		Membre::ajouterBillet()
* Description:	ajoute un billet
* Paramètres:	Billet* billet
* Retour:		aucun
****************************************************************************/
void Membre::ajouterBillet(Billet* billet)
{
	billet->setNomPassager(nom_);
	billets_.push_back(billet);
}

/****************************************************************************
* Fonction:		Membre::operator==() const
* Description:	opérateur ==
* Paramètres:	const string& nomMembre
* Retour:		bool
****************************************************************************/
bool Membre::operator==(const string& nomMembre) const
{
	return nom_ == nomMembre;
}

/****************************************************************************
* Fonction:		friend operator==() 
* Description:	opérateur ==
* Paramètres:	const string& nomMembre, const Membre& membre
* Retour:		bool
****************************************************************************/
bool operator==(const string& nomMembre, const Membre& membre)
{
	return nomMembre == membre.nom_;
}

/****************************************************************************
* Fonction:		Membre::operator=()
* Description:	opérateur =
* Paramètres:	const Membre& Membre
* Retour:		Membre&
****************************************************************************/
Membre& Membre::operator=(const Membre& membre)
{
	if (this != &membre) {
		nom_ = membre.nom_;

		for (size_t i = 0; i < billets_.size(); ++i) {
			delete billets_[i];
		}

		billets_.clear();

		for (size_t i = 0; i < membre.billets_.size(); ++i) {
			if (FlightPassSolde* flightPassSolde = dynamic_cast<FlightPassSolde*>(membre.billets_[i]))
			{
				billets_.push_back(new FlightPassSolde(*flightPassSolde));
			}
			else if (FlightPass* flightPass=dynamic_cast<FlightPass*>(membre.billets_[i]))
			{
				billets_.push_back(new FlightPass(*flightPass));
			}
			else if (BilletRegulierSolde* billetRegSolde = dynamic_cast<BilletRegulierSolde*>(membre.billets_[i]))
			{
				billets_.push_back(new BilletRegulierSolde(*billetRegSolde));
			}
			else if (BilletRegulier* billetReg = dynamic_cast<BilletRegulier*>(membre.billets_[i]))
			{
				billets_.push_back(new BilletRegulier(*billetReg));
			}
		}
	}

	return *this;
}

/****************************************************************************
  * Fonction:	Membre::afficher()
  * Description:Fonction affichage de la classe
  * Paramètres:	ostream& o
  * Retour:		aucun
  ****************************************************************************/
void Membre::afficher(ostream& o)
{
	o << setfill(' ');
	o << "- Membre " << nom_ << ":" << endl;
	o << "\t" << "- Billets :" << endl;
	for (size_t i = 0; i < billets_.size(); i++) {
		if (BilletRegulierSolde* billetRegulierSolde = dynamic_cast<BilletRegulierSolde*>(billets_[i]))
		{
			billetRegulierSolde->afficher(o);
		}
		else if (BilletRegulier* billetRegulier = dynamic_cast<BilletRegulier*>(billets_[i]))
		{
			billetRegulier->afficher(o);
		}
		else if (FlightPassSolde* flightPassSolde = dynamic_cast<FlightPassSolde*>(billets_[i]))
		{
			flightPassSolde->afficher(o);
		}
		else if (FlightPass* flightPass = dynamic_cast<FlightPass*>(billets_[i]))
		{
			flightPass->afficher(o);
		}
		else
		{
			billets_[i]->afficher(o);
		}
	}
}
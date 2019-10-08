/*
 * Date : 12 Septembre 2019
 * Auteur : Philippe CÔTÉ-MORNEAULT
 * Mise à jour le : 4 Octobre 2019
 * Par : Nathan RAMSAY-VEJLENS
 */

#include "membre.h"

//Constructeur de base
Membre::Membre() :
	nom_(""),
	typeMembre_(Membre_Regulier)
{
}

/**
*	Constructeurs par parametres
*	\param [in] const string&	nom
*	\param [in] TypeMembre		typeMembre
*/
Membre::Membre(const string& nom, TypeMembre typeMembre) :
	nom_(nom),
	typeMembre_(typeMembre)
{
}

/**
*	Constructeurs par copie
*	\param [in] const Membre& membre
*/
Membre::Membre(const Membre& membre) :
	nom_(membre.nom_),
	typeMembre_(membre.typeMembre_)
{
	for (unsigned int i = 0; i < membre.billets_.size(); ++i) {
		if (membre.billets_[i]->getTypeBillet() == TypeBillet::Billet_Base) {
			billets_.push_back(new Billet(*membre.billets_[i]));
		}
		else if(membre.billets_[i]->getTypeBillet() == TypeBillet::Billet_Regulier) {
			billets_.push_back(static_cast<BilletRegulier*>(membre.billets_[i]));
		}
		else if (membre.billets_[i]->getTypeBillet() == TypeBillet::Flight_Pass) {
			billets_.push_back(static_cast<FlightPass*>(membre.billets_[i]));
		}
	}
}

Membre::~Membre()
{
	for (unsigned int i = 0; i < billets_.size(); i++) {
		delete billets_[i];
	}
}

string Membre::getNom() const
{
	return nom_;
}

//Accesseur de typeMembre_
TypeMembre Membre::getTypeMembre() const{
	return typeMembre_;
}

vector<Billet*> Membre::getBillets() const
{
	return billets_;
}


void Membre::setNom(const string& nom)
{
	nom_ = nom;
}

/**
*	Fonction qui utilise un billet
*	\param [in] const string&	pnr
*/
void Membre::utiliserBillet(const string& pnr) {
	for (unsigned int i = 0; i < billets_.size(); i++) {
		if (billets_[i]->getPnr() == pnr) {
			if (billets_[i]->getTypeBillet() == TypeBillet::Flight_Pass) {
				//conversion en pointeur de type flightpass
				FlightPass* flightpass = static_cast<FlightPass*>(billets_[i]);
				if (flightpass->getNbUtilisationsRestante() <= 1) { //si derniere utilisation flightpass
					//efface flightpass
					delete flightpass;
					billets_[i]=billets_[billets_.size()-1];
					billets_.pop_back();
				}
				else {//sinon simplement decerementeNbUtilisations
					flightpass->decrementeNbUtilisations();
				}
			}
			else { //pas un flightpass
				//supprime billet 
				delete billets_[i];
				billets_[i] = billets_[billets_.size() - 1];
				billets_.pop_back();
			}
		}
	}
}

/**
*	Fonction qui ajoute un billet au vecteur de billets du membre
*	\param [in] const string&	pnr
*	\param [in] double			prix
*	\param [in] const string&	od
*	\param [in] TarifBillet		tarifBillet
*	\param [in] TypeBillet		typeBillet
*	\param [in] const string&	dateVol
*/
void Membre::ajouterBillet(const string& pnr, double prix, const string& od, TarifBillet tarif, TypeBillet typeBillet, const string& dateVol)
{
	Billet* billet = nullptr;
	if (typeBillet == TypeBillet::Billet_Base) {
		billet = new Billet(pnr, nom_, prix, od, tarif, typeBillet);
		}
	else if (typeBillet == TypeBillet::Billet_Regulier) {
		billet = new BilletRegulier(pnr, nom_, prix, od, tarif, dateVol, typeBillet);
	}
	else if (typeBillet == TypeBillet::Flight_Pass) {
		billet = new FlightPass(pnr, nom_, prix, od, tarif, typeBillet);
	}
	billets_.push_back(billet);

}


/**
*	Surcharge operateur == opérandes de gauche Membre
*/
bool Membre::operator==(const string& nomMembre) const
{
	return nom_ == nomMembre;
}

/**
*	Surcharge operateur == opérandes de gauche string
*/
bool operator==(const string& nomMembre, const Membre& membre)
{
	return nomMembre == membre.nom_;
}

/**
*	Surcharge operateur d'affectation
*	\param [in]	const Membre& membre
*/
Membre& Membre::operator=(const Membre& membre)
{
	if (this != &membre) {
		nom_ = membre.nom_;
		typeMembre_ = membre.typeMembre_;


		for (unsigned int i = 0; i < billets_.size(); ++i) {
			delete billets_[i];
		}

		billets_.clear();

		for (unsigned int i = 0; i < membre.billets_.size(); i++) {
			billets_.push_back(new Billet(*membre.billets_[i]));
		}
	}

	return *this;
}

//Surcharge operateur <<
ostream& operator<<(ostream& o, const Membre& membre)
{
	o << setfill(' ');
	o << "- Membre " << membre.nom_ << ":" << endl;
	o << "\t" << "- Billets :" << endl;
	for (unsigned int i = 0; i < membre.billets_.size(); i++) {
		if (membre.billets_[i]->getTypeBillet() == TypeBillet::Billet_Base) {
			o << *membre.billets_[i] << endl;
		}
		else if (membre.billets_[i]->getTypeBillet() == TypeBillet::Billet_Regulier) {
			BilletRegulier* billetTemp = static_cast<BilletRegulier*>(membre.billets_[i]);
			o << *billetTemp << endl;
		}
		else if (membre.billets_[i]->getTypeBillet() == TypeBillet::Flight_Pass) {
			FlightPass* billetTemp = static_cast<FlightPass*>(membre.billets_[i]);
			o << *billetTemp << endl;
		}
	}

	return o << endl;
}

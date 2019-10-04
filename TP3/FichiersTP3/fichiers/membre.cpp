/*
 * Date : 12 Septembre 2019
 * Auteur : Philippe CÔTÉ-MORNEAULT
 * Mise à jour le : 4 Octobre 2019
 * Par : Nathan RAMSAY-VEJLENS
 */

#include "membre.h"

//Changé
Membre::Membre() :
	nom_(""),
	typeMembre_(Membre_Regulier)
{
}

//Changé
Membre::Membre(const string& nom, TypeMembre typeMembre) :
	nom_(nom),
	typeMembre_(typeMembre)
{
}

//a changer
Membre::Membre(const Membre& membre) :
	nom_(membre.nom_)
{
	for (int i = 0; i < membre.billets_.size(); ++i) {
		billets_.push_back(new Billet(*membre.billets_[i]));
	}
}

Membre::~Membre()
{
	for (int i = 0; i < billets_.size(); i++) {
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

//Utilise billet (à finaliser)
void Membre::utiliserBillet(const string& pnr) {
	for (unsigned int i = 0, i < billets_.size(), i++) {
		if (billets_[i]->getPnr() == pnr) {
			if (billets_[i]->getTypeBillet() == TypeBillet::Flight_Pass) {
				if (billets_[i]->getNbUtilisationsRestante() == 0) { //si plus de flightpass
					//efface flightpass

				}
				else {
					billets_[i]->decrementeNbUtilisations();
				}
			}
			else { //pas un flightpass
				//supprime billet (À FAIRE)
			}
		}
	}
}

//Fait (à vérifier)
void Membre::ajouterBillet(const string& pnr, double prix, const string& od, TarifBillet tarif, TypeBillet typeBillet, const string& dateVol)
{
	if (typeBillet == TypeBillet::Billet_Base) {
		Billet* billet = new Billet(pnr, nom_, prix, od, tarif, typeBillet);
		}
	else if (typeBillet == TypeBillet::Billet_Regulier) {
		Billet* billet = new BilletRegulier(pnr, nom_, prix, od, tarif, dateVol, typeBillet);
	}
	else if (typeBillet == TypeBillet::Flight_Pass) {
		Billet* billet = new FlightPass(pnr, nom_, prix, od, tarif, typeBillet);
	}
	billets_.push_back(billet);

	//inutile, cette classe ne fait pas partie du programme de fidèlité.
	//modifierPoints(calculerPoints(billet));
}



bool Membre::operator==(const string& nomMembre) const
{
	return nom_ == nomMembre;
}

bool operator==(const string& nomMembre, const Membre& membre)
{
	return nomMembre == membre.nom_;
}

Membre& Membre::operator=(const Membre& membre)
{
	if (this != &membre) {
		nom_ = membre.nom_;
		typeMembre_ = membre.typeMembre_;


		for (int i = 0; i < billets_.size(); ++i) {
			delete billets_[i];
		}

		billets_.clear();

		for (int i = 0; i < membre.billets_.size(); i++) {
			billets_.push_back(new Billet(*membre.billets_[i]));
		}
	}

	return *this;
}

// a changer
ostream& operator<<(ostream& o, const Membre& membre)
{
	o << setfill(' ');
	o << "- Membre " << membre.nom_ << ":" << endl;
	o << "\t" << left << setw(10) << "- Points" << ": " << membre.points_ << endl;
	o << "\t" << "- Billets :" << endl;
	for (int i = 0; i < membre.billets_.size(); i++) {
		o << *membre.billets_[i];
	}
	o << "\t" << "- Coupons :" << endl;
	for (int i = 0; i < membre.coupons_.size(); i++) {
		o << *membre.coupons_[i];
	}

	return o << endl;
}

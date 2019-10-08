/*
* Titre : membre.h - Travail Pratique #3
* Date : 20 Septembre 2019
* Auteur : Jeffrey Lavallee
 * Mise à jour le : 4 Octobre 2019
 * Par : Nathan RAMSAY-VEJLENS
*/


#ifndef MEMBRE_H
#define MEMBRE_H

#include <string>
#include <vector>

#include "flightPass.h"
#include "billetRegulier.h"
#include "coupon.h"

using namespace std;

enum TypeMembre { Membre_Regulier, Membre_Premium, Membre_Occasionnel};

class Membre {
public:
	// Constructeurs

	//constructeur par defaut
	Membre();
	//constructeur par parametres
	Membre(const string& nom, TypeMembre typeMembre);
	//constructeur par copie
	Membre(const Membre& membre);

	virtual ~Membre(); //virtual permet de bien delete les object derivé 

	// accesseurs
	string getNom() const;
	TypeMembre getTypeMembre() const;

	vector<Billet*> getBillets() const;


	// modificateurs
	void setNom(const string& nom);

	//utilise billet
	void utiliserBillet(const string& pnr);

	//ajoutebillet
	virtual void ajouterBillet(const string& pnr, double prix, const string& od, TarifBillet tarif, TypeBillet typeBillet , const string& dateVol);

	bool operator==(const string& nomMembre) const;
	friend bool operator==(const string& nomMembre, const Membre& membre);

	Membre& operator=(const Membre& membre);

	//surcharge operateur <<
	friend ostream& operator<<(ostream& o, const Membre& membre);
protected:
	string nom_;
	TypeMembre typeMembre_;
	vector<Billet*> billets_;
};


#endif

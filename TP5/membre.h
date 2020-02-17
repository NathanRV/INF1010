/********************************************
* Titre: Travail pratique #5 - membre.h
* Date: 30 octobre 2019
* Auteur: Allan BEDDOUK & Jeffrey LAVALLEE
* Modification : Nathan RAMSAY-VEJLENS
* Modifi� le : 12 novembre 2019
*******************************************/

#ifndef MEMBRE_H
#define MEMBRE_H

#include <string>
#include <vector>
#include <iterator> 
#include <iomanip>
#include <algorithm>

#include "flightPass.h"
#include "billetRegulier.h"
#include "coupon.h"

using namespace std;

class Membre {
public:
	// Constructeurs
	Membre();
	Membre(const string& nom);

	/****************************************************************************
	* Fonction:		Membre::Membre()
	* Description:	Constructeur par copie d'un membre
	* Param�tres:	const Membre& membre
	* Retour:		Membre
	****************************************************************************/
	Membre(const Membre& membre);

	/****************************************************************************
	* Fonction:		Membre::~Membre()
	* Description:	Destructeur virtuel
	* Param�tres:	aucun
	* Retour:		aucun
	****************************************************************************/
	virtual ~Membre();

	// Getters
	string getNom() const;

	vector<Billet*> getBillets() const;

	// Setters
	void setNom(const string& nom);
	


	/****************************************************************************
	* Fonction:		Membre::trouverBillet
	* Description:	Retourne un it�rateur sur le billet cherch� si le Membre le poss�de
	* Param�tres:	const string& pnr
	* Retour:		vector<Billet*>::iterator
	****************************************************************************/
	vector<Billet*>::iterator trouverBillet(const string& pnr);
	   
	/****************************************************************************
	* Fonction:		Membre::utiliserBillet
	* Description:	Deep copy d'un membre
	* Param�tres:	const string& pnr
	* Retour:		aucun
	****************************************************************************/
	void utiliserBillet(const string& pnr);
	virtual void ajouterBillet(Billet* billet);

	bool operator==(const string& nomMembre) const;
	friend bool operator==(const string& nomMembre, const Membre& membre);

	/****************************************************************************
	* Fonction:		Membre::operator=
	* Description:	Deep copy d'un membre
	* Param�tres:	const Membre& membre
	* Retour:		Membre&
	****************************************************************************/
	Membre& operator=(const Membre& membre);

	/****************************************************************************
	* Fonction:		Membre::afficher
	* Description:	Affiche les attributs du Membre
	* Param�tres:	ostream& o
	* Retour:		aucun
	****************************************************************************/
	virtual void afficher(ostream& o) const;
protected:
	string nom_;
	vector<Billet*> billets_;
};
#endif // !MEMBRE_H

/*
* Titre : membre.h - Travail Pratique #4
* Date : 5 Octobre 2019
* Auteur : Philippe CÔTÉ-MORNEAULT
* Mise à jour : Nathan Ramsay-Vejlens
* Date mise à jour : 17 octobre 2019
*/

#ifndef MEMBRE_H
#define MEMBRE_H

#include <string>
#include <vector>
#include <iomanip>

#include "flightPass.h"
#include "flightPassSolde.h"
#include "billetRegulier.h"
#include "billetRegulierSolde.h"
#include "coupon.h"

using namespace std;

class Membre {
public:
	/****************************************************************************
	* Fonction:		Membre::Membre()
	* Description:	Constructeur par défaut
	* Paramètres:	aucun
	* Retour:		aucun
	****************************************************************************/
	Membre();
	/****************************************************************************
* Fonction:		Membre::Membre()
* Description:	Constructeur par paramètres
* Paramètres:	const string& nom
* Retour:		aucun
****************************************************************************/
	Membre(const string& nom);

	/****************************************************************************
	* Fonction:		Membre::Membre()
	* Description:	Constructeur par copie
	* Paramètres:	const Membre& membre
	* Retour:		aucun
	****************************************************************************/
	Membre(const Membre& membre);

	/****************************************************************************
* Fonction:		Membre::~Membre()
* Description:	Destructeur virtuel
* Paramètres:	aucun
* Retour:		aucun
****************************************************************************/
	virtual ~Membre();

	// Getters
/****************************************************************************
* Fonction:		Membre::getNom()
* Description:	Retourne nom
* Paramètres:	Aucun
* Retour:		string
****************************************************************************/
	string getNom() const;

/****************************************************************************
* Fonction:		Membre::getBillets() const
* Description:	Retourne vecteur de pointeurs de billets
* Paramètres:	Aucun
* Retour:		vector<Billet*>
****************************************************************************/
	vector<Billet*> getBillets() const;

	// Setters
	/****************************************************************************
* Fonction:		Membre::setNom() 
* Description:	modifie le nom
* Paramètres:	const string& nom
* Retour:		aucun
****************************************************************************/
	void setNom(const string& nom);
	
	/****************************************************************************
* Fonction:		Membre::utiliserBillet()
* Description:	Efface le billet 
* Paramètres:	const string& pnr
* Retour:		aucun
****************************************************************************/
	void utiliserBillet(const string& pnr);

	/****************************************************************************
* Fonction:		Membre::ajouterBillet()
* Description:	ajoute un billet
* Paramètres:	Billet* billet
* Retour:		aucun
****************************************************************************/
	virtual void ajouterBillet(Billet* billet);

	/****************************************************************************
* Fonction:		Membre::operator==() const
* Description:	opérateur ==
* Paramètres:	const string& nomMembre
* Retour:		bool
****************************************************************************/
	bool operator==(const string& nomMembre) const;

	/****************************************************************************
* Fonction:		friend operator==()
* Description:	opérateur ==
* Paramètres:	const string& nomMembre, const Membre& membre
* Retour:		bool
****************************************************************************/
	friend bool operator==(const string& nomMembre, const Membre& membre);

	/****************************************************************************
* Fonction:		Membre::operator=()
* Description:	opérateur =
* Paramètres:	const Membre& Membre
* Retour:		Membre&
****************************************************************************/
	Membre& operator=(const Membre& membre);

	/****************************************************************************
	  * Fonction:	Membre::afficher()
	  * Description:Fonction affichage de la classe
	  * Paramètres:	ostream& o
	  * Retour:		aucun
	  ****************************************************************************/
	void afficher(ostream& o);
protected:
	string nom_;
	vector<Billet*> billets_;
};
#endif // !MEMBRE_H

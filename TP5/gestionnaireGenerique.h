/********************************************
* Titre: Travail pratique #5 - GestionnaireGenerique.h
* Date: 30 octobre 2019
* Auteur: Allan BEDDOUK & Jeffrey LAVALLEE
*******************************************/

#pragma once

#include <algorithm>
#include "foncteur.h"
#include "T.h"
#include "C.h"

using namespace  std;

/*
    class GestionnaireGenerique

    Méthodes :
    C getConteneur() const;
    void ajouter(const T& t);
    int getNombreElements() const;
 
    Attributs :
    C conteneur_;
*/

/*              
	* typename T   = pair<string, Membre*> ou Coupon*; 
	* Conteneur   = map<string, Membre*> ou vector<Coupon*>; 
	* FoncteurAjouter = AjouterMembre ou AjouterCoupon
*/

#ifndef _GESTIONNAIREGEN_H_
#define _GESTIONNAIREGEN_H_

template<typename T,typename C>
class GestionnaireGenerique
{
public:
	C getConteneur() const;
	void ajouter(const T& t);
	int getNombreElements() const;
protected:
	C conteneur_;
};


#endif // !_GESTIONNAIREGEN_H_


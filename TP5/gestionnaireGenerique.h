/********************************************
* Titre: Travail pratique #5 - GestionnaireGenerique.h
* Date: 30 octobre 2019
* Auteur: Allan BEDDOUK & Jeffrey LAVALLEE
* Modification : Nathan RAMSAY-VEJLENS
* Modifié le : 12 novembre 2019
*******************************************/

#pragma once

#include <algorithm>
#include "foncteur.h"
using namespace  std;

#ifndef _GESTIONNAIREGEN_H_
#define _GESTIONNAIREGEN_H_

template<typename T,typename C,typename FoncteurAjouter>
class GestionnaireGenerique
{
public:
	C getConteneur() const { return conteneur_; };

  /****************************************************************************
  * Fonction:	GestionnaireGenerique::ajouter
  * Description: Permet d'ajouter un element au conteneur à l'aide d'un foncteur
  * Paramètres:	const T& t
  * Retour:		aucun
  ****************************************************************************/
	void ajouter(const T& t) 
	{ 
		FoncteurAjouter fct = FoncteurAjouter(conteneur_);
		fct(t);
	};
	int getNombreElements() const { return conteneur_.size(); };
protected:
	C conteneur_;
};


#endif // !_GESTIONNAIREGEN_H_


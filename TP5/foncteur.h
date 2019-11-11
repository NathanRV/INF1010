/********************************************
* Titre: Travail pratique #5 - foncteur.h
* Date: 30 octobre 2019
* Auteur: Allan BEDDOUK & Jeffrey LAVALLEE
*******************************************/
#pragma once

#include <string>
#include <vector>
#include <map>
#include <functional>
#include <iterator>


#include "coupon.h"
#include "membrePremium.h"


class AjouterCoupon
{
public:
	AjouterCoupon(vector<Coupon*>& conteneur) 
		:conteneur_(conteneur)
	{}
	vector<Coupon*> operator()(Coupon* coupon)
	{
		//algo verifie présence et ajoute par après
		for (Coupon* coup : conteneur_)
		{
			if (coupon == coup)
			{
				return conteneur_;
			}
		}
		conteneur_.push_back(coupon);
		return conteneur_; //retourne vecteur
	}
private:
	vector<Coupon*>& conteneur_;
};


class AjouterMembre
{
public:
	AjouterMembre(map<string, Membre*>& conteneur)
		:conteneur_(conteneur)
	{}
	void operator()(pair<string,Membre*> membre) 
	{
		conteneur_.insert(membre);
	}
private:
	map<string, Membre*>& conteneur_;
};

class IntervallePrixBillet
{
public:
	IntervallePrixBillet(double borneInf,double borneSup)
		:borneInf_(borneInf),
		borneSup_(borneSup)
	{}

	bool operator()(Billet* billet)
	{
		if (billet->getPrix() >= borneInf_&& billet->getPrix() <= borneSup_)
			return true;
		return false;
	}

private:
	double borneInf_;
	double borneSup_;
};
#pragma once
/********************************************
* Titre: Travail pratique #5 - gestionnaireCoupons.h
* Date: 30 octobre 2019
* Auteur: Allan BEDDOUK & Jeffrey LAVALLEE
*******************************************/

#include "gestionnaireGenerique.h"

#ifndef GESTIONNAIRECOUPONS_H
#define	GESTIONNAIRECOUPONS_H	

#include <vector>

#include "membrePremium.h"
#include "solde.h"
#include "gestionnaireGenerique.h"


class GestionnaireCoupons: public GestionnaireGenerique<Coupon T, C>
{
public:
	double appliquerCoupon(Membre* membre, double prix);
	void acheterCoupon(Membre* membre);
};
#endif // !GESTIONNAIRECOUPONS_H




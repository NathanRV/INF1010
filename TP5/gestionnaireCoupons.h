#pragma once
/********************************************
* Titre: Travail pratique #5 - gestionnaireCoupons.h
* Date: 30 octobre 2019
* Auteur: Allan BEDDOUK & Jeffrey LAVALLEE
* Modification : Nathan RAMSAY-VEJLENS
* Modifi� le : 12 novembre 2019
*******************************************/


#ifndef GESTIONNAIRECOUPONS_H
#define	GESTIONNAIRECOUPONS_H	

#include <vector>
#include <string>
#include "membrePremium.h"
#include "solde.h"
#include "gestionnaireGenerique.h"
#include "coupon.h"

class GestionnaireCoupons: public GestionnaireGenerique<Coupon*, vector<Coupon*>, AjouterCoupon>
{
public:
	/****************************************************************************
	* Fonction:		GestionnaireCoupons::~GestionnaireCoupons()
	* Description:	Destructeur
	* Param�tres:	aucun
	* Retour:		aucun
	****************************************************************************/
	~GestionnaireCoupons();
	/****************************************************************************
	* Fonction:		GestionnaireCoupons::appliquerCoupon()
	* Description:	Utilise un coupon de rabais
	* Param�tres:	Membre* membre, double prix	
	* Retour:		double
	****************************************************************************/
	double appliquerCoupon(Membre* membre, double prix);
	/****************************************************************************
	* Fonction:		GestionnaireCoupons::acheterCoupon()
	* Description:	Achete un coupon
	* Param�tres:	Membre* membre
	* Retour:		aucun
	****************************************************************************/
	void acheterCoupon(Membre* membre);
};
#endif // !GESTIONNAIRECOUPONS_H




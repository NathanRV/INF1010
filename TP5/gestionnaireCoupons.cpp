/********************************************
* Titre: Travail pratique #5 - gestionnaireCoupons.cpp
* Date: 30 octobre 2019
* Auteur: Allan BEDDOUK & Jeffrey LAVALLEE
* Modification : Nathan RAMSAY-VEJLENS
* Modifié le : 12 novembre 2019
*******************************************/

#include "gestionnaireCoupons.h"

/****************************************************************************
* Fonction:		GestionnaireCoupons::~GestionnaireCoupons()
* Description:	Destructeur
* Paramètres:	aucun
* Retour:		aucun
****************************************************************************/
GestionnaireCoupons::~GestionnaireCoupons()
{
	for (auto it=conteneur_.begin();it!=conteneur_.end();it++)
	{
		delete *it;
	}
}

/****************************************************************************
* Fonction:		GestionnaireCoupons::appliquerCoupon()
* Description:	Utilise un coupon de rabais
* Paramètres:	Membre* membre, double prix
* Retour:		double
****************************************************************************/
double GestionnaireCoupons::appliquerCoupon(Membre* membre, double prix)
{
	MembreRegulier* membreReg = dynamic_cast<MembreRegulier*>(membre);
	if(membreReg!=nullptr)
	{
		if (!membreReg || membreReg->getCoupons().size() == 0) {
			cout << "Le membre n'a pas de coupon utilisable\n";
			return 0;
		}

		Coupon* meilleurCoupon = membreReg->getCoupons()[0];
		vector<Coupon*> coupons = membreReg->getCoupons();
		for (auto it=coupons.begin(); it != coupons.end();it++) {
			if (*(*it) > * meilleurCoupon) {
				meilleurCoupon = *it;
			}
		}

		*membreReg -= meilleurCoupon;

		return prix * meilleurCoupon->getRabais();
	}
	return prix;
}

/****************************************************************************
* Fonction:		GestionnaireCoupons::acheterCoupon()
* Description:	Achete un coupon
* Paramètres:	Membre* membre
* Retour:		aucun
****************************************************************************/
void GestionnaireCoupons::acheterCoupon(Membre* membre)
{
	if (conteneur_.size() == 0) {
		cout << "Le GestionnaireCoupons n'a pas de coupon!" << endl;
		return;
	}

	Coupon* meilleurCoupon = nullptr;

	if (auto membreRegulier = dynamic_cast<MembreRegulier*>(membre)) {
		for (auto it = conteneur_.begin(); it != conteneur_.end();it++) {
			if (membreRegulier->peutAcheterCoupon(*it)) {
				// Si on avait pas encore trouve de meilleur coupon, on fait la premiere assignation
				if (meilleurCoupon == nullptr) {
					meilleurCoupon = *it;
				}
				// Sinon on compare si le coupon courant a un rabais superieur au meilleur coupon
				else if (*(*it) > * meilleurCoupon) {
					meilleurCoupon = *it;
				}
			}
		}
		if (meilleurCoupon) {
			membreRegulier->acheterCoupon(meilleurCoupon);
		}
		else {
			cout << "Le membre ne peut acheter de coupon\n";
		}
	}
	else {
		cout << "Le membre ne peut acheter de coupon\n";
	}
}
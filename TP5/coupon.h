/********************************************
* Titre: Travail pratique #5 - coupon.h
* Date: 30 octobre 2019
* Auteur: Allan BEDDOUK & Jeffrey LAVALLEE
* Modification : Nathan RAMSAY-VEJLENS
* Modifié le : 12 novembre 2019
*******************************************/

#ifndef COUPON_H
#define COUPON_H

#include <string>
#include <iostream>

using namespace std;

class Coupon {
public:
	// Constructeurs
	Coupon();
	Coupon(const string& code, double rabais, int cout);
	
	~Coupon();

	// Getters
	string getCode() const;
	double getRabais() const;
	int getCout() const;

	// Setters
	void setCode(const string& code);
	void setRabais(double rabais);
	void setCout(int cout);

	bool operator>(const Coupon& coupon) const;
	bool operator<(const Coupon& coupon) const;

	void afficher(ostream& o) const;


/****************************************************************************
* Fonction:		Coupon::operator<<
* Description:	Apelle la fonction afficher de coupon
* Paramètres:	ostream& o,const Coupon* c
* Retour:		ostream&
****************************************************************************/
	friend ostream& operator<<(ostream& o, const Coupon* c);
private:
	string code_;
	double rabais_;
	int cout_;
};
#endif // !COUPON_H
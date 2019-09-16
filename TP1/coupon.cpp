/*
 * Date : 10 Septembre 2019
 * Auteur : Nathan Ramsay-Vejlens
 */

#include "coupon.h"

//Constructeur par d�faut
Coupon::Coupon() :code_("code"), rabais_(0.2), cout_(2)
{
}

//constructeur par param�tres
Coupon::Coupon(const string& code, double rabais, int cout):code_(code),rabais_(rabais),cout_(cout)
{
}

//Destructeur
Coupon::~Coupon()
{}

// Getters

//Acc�de au code
string Coupon::getCode() const
{
	return code_;
}

//Acc�de au rabais
double Coupon::getRabais() const
{
	return rabais_;
}

//Acc�de au co�t
int Coupon::getCout() const
{
	return cout_;
}

//Modificateurs

//Modifie le code
void Coupon::setCode(const string& code)
{
	code_ = code;
}

//Modifie le rabais
void Coupon::setRabais(double rabais)
{
	rabais_ = rabais;
}

//Modifie le co�t
void Coupon::setCout(int cout) 
{
	cout_ = cout;
}

//Affichage
void Coupon::afficherCoupon() const
{
	cout << "		- Coupon " << this->getCode() << ". Rabais : " << this->getRabais() << "." << endl;
}
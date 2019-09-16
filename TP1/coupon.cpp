/*
 * Date : 10 Septembre 2019
 * Auteur : Nathan Ramsay-Vejlens
 */

#include "coupon.h"

//Constructeur par défaut
Coupon::Coupon() :code_("code"), rabais_(0.2), cout_(2)
{
}

//constructeur par paramètres
Coupon::Coupon(const string& code, double rabais, int cout):code_(code),rabais_(rabais),cout_(cout)
{
}

//Destructeur
Coupon::~Coupon()
{}

// Getters

//Accède au code
string Coupon::getCode() const
{
	return code_;
}

//Accède au rabais
double Coupon::getRabais() const
{
	return rabais_;
}

//Accède au coût
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

//Modifie le coût
void Coupon::setCout(int cout) 
{
	cout_ = cout;
}

//Affichage
void Coupon::afficherCoupon() const
{
	cout << "		- Coupon " << this->getCode() << ". Rabais : " << this->getRabais() << "." << endl;
}
/****************************************************************************
 * Fichier: coupon.cpp
 * Auteur: Nathan Ramsay-Vejlens,Freddy Some,Lorenzo Florenty
 * Date: 23 sept 2019
 * Mise a jour : 23 sept 2019
 * Description: Implémentation de la classe coupon
 ****************************************************************************/

#include "coupon.h"
 /****************************************************************************
  * Fonction:	Coupon::Coupon
  * Description: Constructeur par défaut
  * Paramètres:	aucun
  * Retour:		aucun
  ****************************************************************************/
Coupon::Coupon() : 
	code_(""),
	rabais_(0),
	cout_(0)
{
}
/****************************************************************************
 * Fonction:	Coupon::Coupon
 * Description: Constructeur par parametre
 * Paramètres:	(string)code
                (double)rabais
				(int)cout
 * Retour:		aucun
 ****************************************************************************/
Coupon::Coupon(const string& code, double rabais, int cout) :
	code_(code),
	rabais_(rabais),
	cout_(cout)
{
}
/****************************************************************************
 * Fonction:	Coupon::~Coupon()
 * Description: Destructeur
 * Paramètres:	aucun
 * Retour:		aucun
 ****************************************************************************/
Coupon::~Coupon()
{
}
/****************************************************************************
 * Fonction:	Coupon::getCode
 * Description: Retourne code_
 * Paramètres:	aucun
 * Retour:		string
 ****************************************************************************/
string Coupon::getCode() const
{
	return code_;
}
/****************************************************************************
 * Fonction:	Coupon::getRabais
 * Description: Retourne rabais_
 * Paramètres:	aucun
 * Retour:		double
 ****************************************************************************/
double Coupon::getRabais() const
{
	return rabais_;
}
/****************************************************************************
 * Fonction:	Coupon::getCout
 * Description: Retourne cout_
 * Paramètres:	aucun
 * Retour:		int
 ****************************************************************************/
int Coupon::getCout() const
{
	return cout_;
}
/****************************************************************************
 * Fonction:	Coupon::setCode
 * Description: modifie code_
 * Paramètres:	(string)code
 * Retour:		aucun
 ****************************************************************************/
void Coupon::setCode(const string& code)
{
	code_ = code;
}
/****************************************************************************
 * Fonction:	Coupon::setRabais
 * Description: Modifie rabais_
 * Paramètres:	(double)code
 * Retour:		aucun
 ****************************************************************************/
void Coupon::setRabais(double rabais)
{
	rabais_ = rabais;
}
/****************************************************************************
 * Fonction:	Coupon::setCout
 * Description: Modifie cout_
 * Paramètres:	(int)cout
 * Retour:		aucun
 ****************************************************************************/
void Coupon::setCout(int cout)
{
	cout_ = cout;
}
/****************************************************************************
 * Fonction:	operator>
 * Description: Retourne vrai si le Rabais du coupon 1 est superieur a celui du 2
 * Paramètres:	- (Coupon) coupon1
 *				- (Coupon) coupon2
 * Retour:		bool
 ****************************************************************************/
//Surcharge opérateur >
bool operator>(const Coupon& coupon1, const Coupon& coupon2)
{
	if (coupon1.getRabais() > coupon2.getRabais())
	{
		return true;
	}
	else
	{
		return false;
	}
}
/****************************************************************************
 * Fonction:	operator<
 * Description: Operateur inferieur qui retourne vrai si coupon1 >coupon2
 * Paramètres:	- (Coupon) coupon1
 *				- (Coupon) coupon2
 * Retour:		bool
 ****************************************************************************/
//Surcharge opérateur < (friend)
bool operator<(const Coupon& coupon2, const Coupon& coupon1)
{
	return coupon1 > coupon2;
}
/****************************************************************************
 * Fonction:	 operator<<
 * Description: Operateur qui retourne un coupon en string
 * Paramètres:	- (Coupon) coupon
 * Retour:		ostream
 ****************************************************************************/
ostream& operator<<(ostream& o, const Coupon& coupon)
{
	return o << "\t\t- Coupon " << coupon.code_ << ". Rabais : " << coupon.rabais_ << "." << endl;
}

 
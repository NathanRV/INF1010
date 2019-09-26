/****************************************************************************
 * Fichier: coupon.cpp
 * Auteur: Nathan Ramsay-Vejlens,Freddy Some,Lorenzo Florenty
 * Date: 23 sept 2019
 * Mise a jour : 23 sept 2019
 * Description: Impl�mentation de la classe coupon
 ****************************************************************************/

#include "coupon.h"
 /****************************************************************************
  * Fonction:	Coupon::Coupon
  * Description: Constructeur par d�faut
  * Param�tres:	aucun
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
 * Param�tres:	(string)code
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
 * Param�tres:	aucun
 * Retour:		aucun
 ****************************************************************************/
Coupon::~Coupon()
{
}
/****************************************************************************
 * Fonction:	Coupon::getCode
 * Description: Retourne code_
 * Param�tres:	aucun
 * Retour:		string
 ****************************************************************************/
string Coupon::getCode() const
{
	return code_;
}
/****************************************************************************
 * Fonction:	Coupon::getRabais
 * Description: Retourne rabais_
 * Param�tres:	aucun
 * Retour:		double
 ****************************************************************************/
double Coupon::getRabais() const
{
	return rabais_;
}
/****************************************************************************
 * Fonction:	Coupon::getCout
 * Description: Retourne cout_
 * Param�tres:	aucun
 * Retour:		int
 ****************************************************************************/
int Coupon::getCout() const
{
	return cout_;
}
/****************************************************************************
 * Fonction:	Coupon::setCode
 * Description: modifie code_
 * Param�tres:	(string)code
 * Retour:		aucun
 ****************************************************************************/
void Coupon::setCode(const string& code)
{
	code_ = code;
}
/****************************************************************************
 * Fonction:	Coupon::setRabais
 * Description: Modifie rabais_
 * Param�tres:	(double)code
 * Retour:		aucun
 ****************************************************************************/
void Coupon::setRabais(double rabais)
{
	rabais_ = rabais;
}
/****************************************************************************
 * Fonction:	Coupon::setCout
 * Description: Modifie cout_
 * Param�tres:	(int)cout
 * Retour:		aucun
 ****************************************************************************/
void Coupon::setCout(int cout)
{
	cout_ = cout;
}
/****************************************************************************
 * Fonction:	operator>
 * Description: Retourne vrai si le Rabais du coupon 1 est superieur a celui du 2
 * Param�tres:	- (Coupon) coupon1
 *				- (Coupon) coupon2
 * Retour:		bool
 ****************************************************************************/
//Surcharge op�rateur >
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
 * Param�tres:	- (Coupon) coupon1
 *				- (Coupon) coupon2
 * Retour:		bool
 ****************************************************************************/
//Surcharge op�rateur < (friend)
bool operator<(const Coupon& coupon2, const Coupon& coupon1)
{
	return coupon1 > coupon2;
}
/****************************************************************************
 * Fonction:	 operator<<
 * Description: Operateur qui retourne un coupon en string
 * Param�tres:	- (Coupon) coupon
 * Retour:		ostream
 ****************************************************************************/
ostream& operator<<(ostream& o, const Coupon& coupon)
{
	return o << "\t\t- Coupon " << coupon.code_ << ". Rabais : " << coupon.rabais_ << "." << endl;
}

 
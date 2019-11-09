/********************************************
* Titre: Travail pratique #5 - C.h
* Date: 4 novembre 2019
* Auteur: Nathan RAMSAY-VEJLENS & 
*******************************************/

#include"coupon.h"
#include"membre.h"
#include<map>
#include<string>

/*
	* Conteneur   = map<string, Membre*> ou vector<Coupon*>;
*/
#ifndef _C_H_
#define _C_H_


class C
{
public:
	C(string type);
private:
	map<string, Membre*> conteneur_;
};


#endif // !_C_H_


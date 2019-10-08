/*
 * Date : 12 Septembre 2019
 * Auteur : Philippe CÔTÉ-MORNEAULT
 * Mise à jour le : 4 Octobre 2019
 * Par : Nathan RAMSAY-VEJLENS
 */

#ifndef BILLET_H
#define BILLET_H

#include <string>
#include <iostream>
#include <iomanip>

#include "def.h"

using namespace std;

enum TypeBillet {Billet_Base, Billet_Regulier, Flight_Pass};

class Billet {
public:
	// Constructeurs
	//constructeur par defaut
	Billet();
	//constructeur par parametres
	Billet(const string& pnr, const string& nomPassager, double prix, const string& od, TarifBillet tarif, TypeBillet typeBillet);

	virtual ~Billet(); //virtual permet de bien delete les object derivé 

	// Getters
	string getPnr() const;
	string getNomPassager() const;
	double getPrix() const;
	string getOd() const;
	TarifBillet getTarif() const;

	//accesseur de typeBillet
	TypeBillet getTypeBillet() const;

	// Setters
	void setPnr(const string& pnr);
	void setNomPassager(const string& nomPassager);
	void setPrix(double prix);
	void setOd(const string& od);
	void setTarif(TarifBillet tarif);
	//Modificateur de typeBillet
	void setTypeBillet(TypeBillet typeBillet);

	string formatTarif(TarifBillet tarif) const;

	//surcharge operateur <<
	friend ostream& operator<<(ostream& o, const Billet& billet);
private:
	string pnr_;
	string nomPassager_;
	double prix_;
	string od_;
	TarifBillet tarif_;
	TypeBillet typeBillet_;
};
#endif // !BILLET_H


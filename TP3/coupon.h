/*
 * Date : 12 Septembre 2019
 * Auteur : Philippe C�T�-MORNEAULT
 */

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

	friend ostream& operator<<(ostream& o, const Coupon& coupon);
private:
	string code_;
	double rabais_;
	int cout_;
};

#endif // !COUPON_H


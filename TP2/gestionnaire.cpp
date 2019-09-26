/****************************************************************************
 * Fichier: gestionnaire.cpp
 * Auteur: Nathan Ramsay-Vejlens,Freddy Some,Lorenzo Florenty
 * Date: 23 sept 2019
 * Mise a jour : 23 sept 2019
 * Description: Implémentation de la classe gestionnaire
 ****************************************************************************/
#include "gestionnaire.h"

 /****************************************************************************
  * Fonction:	Gestionnaire::Gestionnaire
  * Description: Constructeur par défaut
  * Paramètres:	aucun
  * Retour:		aucun
  ****************************************************************************/
Gestionnaire::Gestionnaire() :
	membres_(0),
	coupons_(0)
{
}

/****************************************************************************
 * Fonction:	Gestionnaire::~Gestionnaire
 * Description: Destructeur
 * Paramètres:	aucun
 * Retour:		aucun
 ****************************************************************************/
Gestionnaire::~Gestionnaire()
{
	while (!membres_.empty())
	{
		delete membres_.back();
		membres_.pop_back();
	}
	while (!coupons_.empty())
	{
		delete coupons_.back();
		coupons_.pop_back();
	}
}

/****************************************************************************
 * Fonction:	Gestionnaire::getMembres
 * Description: Obtenir la variable membres_
 * Paramètres:	aucun
 * Retour:		vector<Membre*> 
 ****************************************************************************/
vector<Membre*> Gestionnaire::getMembres() const
{
	return membres_;
}

/****************************************************************************
 * Fonction:	Gestionnaire::getMembres
 * Description: Obtenir la variable coupons_
 * Paramètres:	aucun
 * Retour:		vector<Coupon*>
 ****************************************************************************/
vector<Coupon*> Gestionnaire::getCoupons() const
{
	return coupons_;
}

/****************************************************************************
 * Fonction:	Gestionnaire::ajouterMembre
 * Description: trouve le membre dont le nom est passé en parametre et le met dans la liste
 * Paramètres:	(string)nomMembre
 * Retour:		aucun
 ****************************************************************************/
void Gestionnaire::ajouterMembre(const string& nomMembre)
{
	Membre* membre = new Membre(nomMembre);
	membres_.push_back(membre);
}

/****************************************************************************
 * Fonction:	Gestionnaire::ajouterCoupon
 * Description: Creer un coupon avec les infos passé en parametre et le met dans la liste
 * Paramètres:	(string)code
                (double)rabais
				(int)cout
 * Retour:		aucun
 ****************************************************************************/
void Gestionnaire::ajouterCoupon(const string& code, double rabais, int cout)
{
	Coupon* coupon = new Coupon(code, rabais, cout);
	coupons_.push_back(coupon);
}

/****************************************************************************
 * Fonction:	Gestionnaire::trouverMembre
 * Description: Trouve le membre dont le nom est passé en parametre
 * Paramètres:	(string)nomMembre
 * Retour:		Membre*
 ****************************************************************************/
Membre* Gestionnaire::trouverMembre(const string& nomMembre) const
{
	for (unsigned int i = 0; i < membres_.size(); i++) {
		// Fait cette comparaison avec la surcharge de l'operateur == de la classe Membre
		if (*membres_[i] == nomMembre) {
			return membres_[i];
		}
	}
	cout << "Le membre " << nomMembre << " n'existe pas\n";

	return nullptr;
}

/****************************************************************************
 * Fonction:	Gestionnaire::assignerBillet
 * Description: creer un billet avec les infos passé en parametre et l'atribut au membre dont le nom est passé en parametre
 * Paramètres:	(string)nomMembre
                (string)pnr
                (double)prixBase
				(string)od
				(TarifBillet)tarif
				(string)dateVol
				(bool)utiliserCoupon
 * Retour:		aucun
 ****************************************************************************/
void Gestionnaire::assignerBillet(const string& nomMembre, const string& pnr, double prixBase, const string& od, TarifBillet tarif, const string& dateVol, bool utiliserCoupon)
{
	double prixReel;
	Membre* membre = trouverMembre(nomMembre);

	if (membre == nullptr) {
		return;
	}

	if (utiliserCoupon) {
		prixReel = prixBase - appliquerCoupon(membre, prixBase);
	}
	else {
		prixReel = prixBase;
	}
	membre->ajouterBillet(pnr, prixReel, od, tarif, dateVol);
}

/****************************************************************************
 * Fonction:	Gestionnaire::appliquerCoupon
 * Description: Le membre passer en parametre applique un coupon pour baisser le prix passé en parametre
 * Paramètres:	(Membre*)membre
 * Retour:		(double)prix
 ****************************************************************************/
double Gestionnaire::appliquerCoupon(Membre* membre, double prix)
{
	if (membre->getCoupons().size() == 0) {
		cout << "Le membre n'a pas de coupon utilisable\n";
		return 0;
	}

	Coupon* meilleurCoupon = membre->getCoupons()[0];
	vector<Coupon*> coupons = membre->getCoupons();
	for (unsigned int i = 1; i < coupons.size(); i++) {
		// TODO: Faites cette comparaison par la surcharge de l'operateur > de la classe Coupon
		if (coupons[i] > meilleurCoupon) {
			meilleurCoupon = coupons[i];
		}
	}

	// TODO: Utiliser la surcharge de l'operateur -= de la classe Membre plutot qu'utiliser la methode retirerCoupon
	*membre-=meilleurCoupon;

	return prix * meilleurCoupon->getRabais();
}

/****************************************************************************
 * Fonction:	Gestionnaire::acheterCoupon
 * Description: Permet d'acheter le meilleur coupon pour le membre dont le nom est passé en parametre
 * Paramètres:	(string)nomMembre
 * Retour:		aucun
 ****************************************************************************/
void Gestionnaire::acheterCoupon(const string& nomMembre)
{
	if (coupons_.size() == 0) {
		cout << "Le gestionnaire n'a pas de coupon!" << endl;
		return;
	}

	Membre* membre = trouverMembre(nomMembre);

	if (membre == nullptr) {
		return;
	}

	Coupon* meilleurCoupon = nullptr;

	for (unsigned int i = 0; i < coupons_.size(); i++) {
		if (membre->getPoints() >= coupons_[i]->getCout()) {
			// Si on avait pas encore trouve de meilleur coupon, on fait la premiere assignation
			if (meilleurCoupon == nullptr) {
				meilleurCoupon = coupons_[i];
			}
			// Sinon on compare si le coupon courant a un rabais superieur au meilleur coupon
			// TODO: Faites cette comparaison avec la surcharge de l'operateur > de la classe Coupon
			else if (coupons_[i] > meilleurCoupon) {
				meilleurCoupon = coupons_[i];
			}
		}
	}

	if (meilleurCoupon) {
		membre->acheterCoupon(meilleurCoupon);
	}
	else {
		cout << "Le membre ne peut acheter de coupon\n";
	}
}

/****************************************************************************
 * Fonction:	operator<<
 * Description: Remplacer cette methode(afficherInfos()) par l'operateur << 
 * Paramètres:	aucun
 * Retour:		aucun
 ****************************************************************************/

ostream& operator<<(ostream& os, const Gestionnaire& g)
{
	os << "=================== ETAT ACTUEL DU PROGRAMME ==================\n\n";
	for (unsigned int i = 0; i < g.membres_.size(); i++) {
		os << *g.membres_[i];
	}
	return os;
}


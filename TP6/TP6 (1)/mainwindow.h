/********************************************
* Titre: Travail pratique #6 - mainwindow.h
* Date: 21 novembre 2019
* Auteur: Allan BEDDOUK
* Modification: Nathan RAMSAY-VEJLENS
* Modifié le : 28 novembre 2019
*******************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QLineEdit>
#include <QRadioButton>
#include <QPushButton>
#include <QComboBox>
#include <string>
#include <vector>

#include "billetRegulierSolde.h"
#include "coupon.h"
#include "membrePremium.h"
#include "flightPassSolde.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(vector<Coupon*> coupons, vector<Membre*> membres, QWidget *parent = nullptr);
    ~MainWindow();

public slots :

    void selectionnerBillet(QListWidgetItem* item);
    void selectionnerCoupon(QListWidgetItem* item);
    void selectionnerMembre(QListWidgetItem* item);
    void ajouterBillet();
    void ajouterCoupon();
    void filtrerListe(int index);
    void nettoyerVue();

    //Petite liberte (ajout fonction)
    void enableUtilisation(bool b);
    void disableDate(bool b);
    void disableSolde(bool b);
private:

    //Attributs
    Ui::MainWindow *ui;

    vector<Coupon*> coupons_;
    vector<Membre*> membres_;


    QListWidget* listeBillets_;
    QListWidget* listeCoupons_;
    QListWidget* listeMembres_;


    // Billet
    vector<QRadioButton*> boutonsRadioTypeBillets_;
    QComboBox* choixMembreBillet_;
    QLineEdit* editeurPNR_;
    QLineEdit* editeurPrixBillet_;
    QLineEdit* editeurOD_;
    QComboBox* choixTarifBillet_;
    QLineEdit* editeurDateVol_;
    QLineEdit* editeurPourcentageSoldeBillet_;
    QLineEdit* editeurUtilisationsRestantesFlightPass_;

    //Bouton "ajouter Billet"
    QPushButton* ajouterBillet_;

    // Coupon
    QLineEdit* editeurCodeCoupon_;
    QLineEdit* editeurRabaisCoupon_;
    QLineEdit* editeurCoutCoupon_;

    //Bouton "ajouter Coupon"
    QPushButton* ajouterCoupon_;


    // Membres
    QLineEdit* editeurPoints_;
    QLineEdit* editeurPointsCumules_;
    QLineEdit* editeurJoursRestants_;

    // Methodes
    void setup();
    void setMenu();
    void setUI();
    void afficherMessage(QString msg);

    void chargerMembres();
    void chargerCoupons();
    void chargerBillets();
    bool filtrerMasque(Membre* membre, int index);

    void nettoyerVueBillets();
    void nettoyerVueCoupons();
    void nettoyerVueMembres();

    TarifBillet getTarifBillet();
    void ajouterMembresDansComboBox(QComboBox* list);
    Membre* trouverMembreParNom(const string& nom);


};
#endif // MAINWINDOW_H

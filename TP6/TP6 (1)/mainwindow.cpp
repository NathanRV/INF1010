/********************************************
* Titre: Travail pratique #6 - mainwindow.cpp
* Date: 21 novembre 2019
* Auteur: Allan BEDDOUK
* Modification : Nathan RAMSAY-VEJLENS & al.
* Modifié le : 28 novembre 2019
*******************************************/
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ExceptionArgumentInvalide.h"


#include <QComboBox>
#include <QLabel>
#include <QHBoxLayout>
#include <QMessageBox>
#include <algorithm>


Q_DECLARE_METATYPE(Membre*)
Q_DECLARE_METATYPE(Billet*)
Q_DECLARE_METATYPE(Coupon*)

using namespace std;

MainWindow::MainWindow(vector<Coupon*> coupons, vector<Membre*> membres, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), coupons_(coupons), membres_(membres)
{
    ui->setupUi(this);
    setup();
}


MainWindow::~MainWindow()
{
    for(auto membre : membres_)
        delete membre;

    for (auto coupon: coupons_)
         delete coupon;

    delete ui;
}

void MainWindow::setup(){
   setMenu();
   setUI();
   chargerCoupons();
   chargerBillets();
   chargerMembres();
   nettoyerVue();
}

void MainWindow::afficherMessage(QString msg) {
    // fait message box
    QMessageBox msgBox;
    msgBox.setText(msg);
    msgBox.exec();
}


//Petite liberte prise (BONUS)
void MainWindow::enableUtilisation(bool b){
    (*editeurUtilisationsRestantesFlightPass_).setDisabled(!b);
    (*editeurUtilisationsRestantesFlightPass_).clear();
}
void MainWindow::disableDate(bool b){
    (*editeurDateVol_).setDisabled(b);
    (*editeurDateVol_).clear();
}
void MainWindow::disableSolde(bool b){
    (*editeurPourcentageSoldeBillet_).setDisabled(b);
    (*editeurPourcentageSoldeBillet_).clear();
}



void MainWindow::setMenu() {
    //Crée action de quitter et connecte le signal
    QAction* quitter_=new QAction(tr("Quitter"),this);
    connect(quitter_,SIGNAL(triggered()),
            this, SLOT(close()));

    //Crée action de nettoyerVue et connecte le signal
    QAction* nettoyerVue_=new QAction(tr("Nettoyer vue"),this);
    connect(nettoyerVue_,SIGNAL(triggered(bool)),
            this, SLOT(nettoyerVue()));

    //Cree menu et ajouter les actions au menu
    QMenu* fileMenu=menuBar()->addMenu(tr("Fichier"));
    fileMenu->addAction(quitter_);
    fileMenu->addAction(nettoyerVue_);
}


void MainWindow::setUI(){
    /* Petite liberte prise pour effacer et disable champ
     * voir ligne 126
     * suffit de commenter 131 à 140 sinon
     * afin de voir fonctionnement de try/catch sur champ
     * */

    //liste des billets
    QLabel* billetsLabel = new QLabel();
    billetsLabel->setText("Billets : ");
    listeBillets_ = new QListWidget(this);
    listeBillets_->setSortingEnabled(true);


    //Connect signal de selection billet
    connect(listeBillets_,SIGNAL(itemClicked(QListWidgetItem*)),
            this, SLOT(selectionnerBillet(QListWidgetItem*)));


    // Boutons radios Type de billets
    boutonsRadioTypeBillets_.push_back(new QRadioButton("Regulier", this));
    boutonsRadioTypeBillets_.push_back(new QRadioButton("Regulier Solde", this));
    boutonsRadioTypeBillets_.push_back(new QRadioButton("FlightPass", this));
    boutonsRadioTypeBillets_.push_back(new QRadioButton("FlightPass Solde", this));

    QHBoxLayout* boutonsRadioBilletsLayout = new QHBoxLayout();
    for(QRadioButton* bouton : boutonsRadioTypeBillets_)
        boutonsRadioBilletsLayout->addWidget(bouton);

    //Utilisations restantes enabled ou pas selon type de billet
    connect(boutonsRadioTypeBillets_[2],SIGNAL(toggled(bool)),
            this,SLOT(enableUtilisation(bool)));
    connect(boutonsRadioTypeBillets_[3],SIGNAL(toggled(bool)),
            this,SLOT(enableUtilisation(bool)));
    //Date disabled ou pas selon type de billet
    connect(boutonsRadioTypeBillets_[2],SIGNAL(toggled(bool)),
            this,SLOT(disableDate(bool)));
    connect(boutonsRadioTypeBillets_[3],SIGNAL(toggled(bool)),
            this,SLOT(disableDate(bool)));
    //Solde disabled ou pas selon type de billet
    connect(boutonsRadioTypeBillets_[0],SIGNAL(toggled(bool)),
            this,SLOT(disableSolde(bool)));
    connect(boutonsRadioTypeBillets_[2],SIGNAL(toggled(bool)),
            this,SLOT(disableSolde(bool)));


    // Liste deroulante pour choisir le Membre
    choixMembreBillet_ = new QComboBox(this);
    choixMembreBillet_->addItem("Membres");
    ajouterMembresDansComboBox(choixMembreBillet_);

    //Champ pour le PNR
    editeurPNR_ = new QLineEdit();

    QHBoxLayout* pnrLayout = new QHBoxLayout();
    pnrLayout->addWidget(new QLabel("PNR : "));
    pnrLayout->addWidget(editeurPNR_);


    //Champ pour le prix
    editeurPrixBillet_ = new QLineEdit();
    editeurPrixBillet_->setValidator(new QDoubleValidator(0, 10000, 2, this));

    QHBoxLayout* prixBilletLayout = new QHBoxLayout();
    prixBilletLayout->addWidget(new QLabel("Prix : "));
    prixBilletLayout->addWidget(editeurPrixBillet_);


    //Champ pour l'Od
    editeurOD_ = new QLineEdit();

    QHBoxLayout* odBilletLayout = new QHBoxLayout();
    odBilletLayout->addWidget(new QLabel("Od : "));
    odBilletLayout->addWidget(editeurOD_);


    //Champ pour le Tarif du Billet
    choixTarifBillet_ = new QComboBox(this);
    choixTarifBillet_->addItem("Tarif Billet");
    choixTarifBillet_->addItem("Economie");
    choixTarifBillet_->addItem("Premium economie");
    choixTarifBillet_->addItem("Affaire");
    choixTarifBillet_->addItem("Premiere");

    //Champ pour la date de vol
    editeurDateVol_ = new QLineEdit();

    QHBoxLayout* dateVolLayout = new QHBoxLayout();
    dateVolLayout->addWidget(new QLabel("Date de Vol : "));
    dateVolLayout->addWidget(editeurDateVol_);


    //Champ pour le pourcentage solde du billet
    editeurPourcentageSoldeBillet_ = new QLineEdit();
    editeurPourcentageSoldeBillet_->setValidator(new QDoubleValidator(0, 10000, 2, this));

    QHBoxLayout* pourcentageSoldeBilletLayout = new QHBoxLayout();
    pourcentageSoldeBilletLayout->addWidget(new QLabel("Pourcentage Solde Billet : "));
    pourcentageSoldeBilletLayout->addWidget(editeurPourcentageSoldeBillet_);

    //Champ pour les jours restants
    editeurUtilisationsRestantesFlightPass_ = new QLineEdit();
    editeurUtilisationsRestantesFlightPass_->setValidator(new QDoubleValidator(0, 10000, 2, this));
    editeurUtilisationsRestantesFlightPass_->setDisabled(true);

    QHBoxLayout* utilisationsRestantesLayout = new QHBoxLayout();
    utilisationsRestantesLayout->addWidget(new QLabel("Utilisations Restantes : "));
    utilisationsRestantesLayout->addWidget(editeurUtilisationsRestantesFlightPass_);


    //Bouton ajouter billet
    ajouterBillet_=new QPushButton(this);
    (*ajouterBillet_).setText("Ajouter Billet");
    //Connecte le signal d'ajout de billet
    connect(ajouterBillet_,SIGNAL(clicked()),
            this, SLOT(ajouterBillet()));


    //ligne separant les ajouts de billets
    //et les ajouts de coupons
    QFrame* horizontaleFrameLine = new QFrame();
    horizontaleFrameLine->setFrameShape(QFrame::HLine);

    //liste des coupons
    QLabel* couponsLabel = new QLabel();
    couponsLabel->setText("Coupons : ");
    listeCoupons_ = new QListWidget(this);
    listeCoupons_->setSortingEnabled(true);




    //Connecte signal selection de coupon
    connect(listeCoupons_,SIGNAL(itemClicked(QListWidgetItem*)),
            this, SLOT(selectionnerCoupon(QListWidgetItem*)));
    //Bouton Ajouter Coupon
    ajouterCoupon_=new QPushButton(this);
    (*ajouterCoupon_).setText("Ajouter Coupon");
    //Connecte signal clic sur ajouter coupon
    connect(ajouterCoupon_,SIGNAL(clicked()),
            this, SLOT(ajouterCoupon()));




    //Champ pour le code du coupon
    editeurCodeCoupon_ = new QLineEdit();

    QHBoxLayout* codeCouponLayout = new QHBoxLayout();
    codeCouponLayout->addWidget(new QLabel("Code : "));
    codeCouponLayout->addWidget(editeurCodeCoupon_);

    //Champ pour le rabais du coupon
    editeurRabaisCoupon_ = new QLineEdit();
    editeurRabaisCoupon_->setValidator(new QDoubleValidator(0, 10000, 2, this));

    QHBoxLayout* rabaisCouponLayout = new QHBoxLayout();
    rabaisCouponLayout->addWidget(new QLabel("Rabais : "));
    rabaisCouponLayout->addWidget(editeurRabaisCoupon_);

    //Champ pour le cout du coupon
    editeurCoutCoupon_ = new QLineEdit();
    editeurCoutCoupon_->setValidator(new QDoubleValidator(0, 10000, 2, this));

    QHBoxLayout* coutCouponLayout = new QHBoxLayout();
    coutCouponLayout->addWidget(new QLabel("Cout : "));
    coutCouponLayout->addWidget(editeurCoutCoupon_);


    //ligne seprant les ajouts de coupons
    //et les informations des membres
    QFrame* horizontaleFrameLine2 = new QFrame();
    horizontaleFrameLine2->setFrameShape(QFrame::HLine);


    //selecteur pour les membres
    QComboBox* choixMembre = new QComboBox(this);
    choixMembre->addItem("Tout Afficher"); // Index 0
    choixMembre->addItem("Afficher Membres Reguliers"); // Index 1
    choixMembre->addItem("Afficher Membres Premium"); // Index 2



    // Connecte signal de choix de liste
    connect(choixMembre,SIGNAL(currentIndexChanged(int)),
            this,SLOT(filtrerListe(int)));



    //liste des membres
    QLabel* membresLabel = new QLabel();
    membresLabel->setText("Membres : ");
    listeMembres_ = new QListWidget(this);
    listeMembres_->setSortingEnabled(true);




    //Connecte signal de selection membre
    connect(listeMembres_,SIGNAL(itemClicked(QListWidgetItem*)),
            this, SLOT(selectionnerMembre(QListWidgetItem*)));



    //Champ pour les points du Membres Regulier
    editeurPoints_ = new QLineEdit();
    editeurPoints_->setValidator(new QDoubleValidator(0, 10000, 2, this));

    QHBoxLayout* pointsMembreLayout = new QHBoxLayout();
    pointsMembreLayout->addWidget(new QLabel("Points : "));
    pointsMembreLayout->addWidget(editeurPoints_);


    //Champ pour les points cumules du Membres Regulier
    editeurPointsCumules_ = new QLineEdit();
    editeurPointsCumules_->setValidator(new QDoubleValidator(0, 10000, 2, this));
    QHBoxLayout* pointsCumMembreLayout = new QHBoxLayout();
    pointsCumMembreLayout->addWidget(new QLabel("Points Cumules : "));
    pointsCumMembreLayout->addWidget(editeurPointsCumules_);

    //Champ pour les points cumules du Membres Regulier
    editeurJoursRestants_ = new QLineEdit();
    editeurJoursRestants_->setValidator(new QDoubleValidator(0, 10000, 2, this));
    QHBoxLayout* joursRestantsLayout = new QHBoxLayout();
    joursRestantsLayout->addWidget(new QLabel("Jours Restants : "));
    joursRestantsLayout->addWidget(editeurJoursRestants_);



    //Layout de gauche
    QVBoxLayout* layoutHautGauche = new QVBoxLayout;

    layoutHautGauche->addWidget(billetsLabel);
    layoutHautGauche->addWidget(listeBillets_);

    layoutHautGauche->addWidget(couponsLabel);
    layoutHautGauche->addWidget(listeCoupons_);

    layoutHautGauche->addWidget(choixMembre);

    layoutHautGauche->addWidget(membresLabel);
    layoutHautGauche->addWidget(listeMembres_);

    //layout de droite
     QVBoxLayout* layoutHautDroite = new QVBoxLayout;
     layoutHautDroite->addWidget(choixMembreBillet_);
     layoutHautDroite->addLayout(boutonsRadioBilletsLayout);
     layoutHautDroite->addLayout(pnrLayout);
     layoutHautDroite->addLayout(prixBilletLayout);
     layoutHautDroite->addLayout(odBilletLayout);
     layoutHautDroite->addWidget(choixTarifBillet_);
     layoutHautDroite->addLayout(dateVolLayout);
     layoutHautDroite->addLayout(pourcentageSoldeBilletLayout);
     layoutHautDroite->addLayout(utilisationsRestantesLayout);
    //Placer bouton ajouterBillet
     layoutHautDroite->addWidget(ajouterBillet_);


     layoutHautDroite->addWidget(horizontaleFrameLine);

     layoutHautDroite->addLayout(codeCouponLayout);
     layoutHautDroite->addLayout(rabaisCouponLayout);
     layoutHautDroite->addLayout(coutCouponLayout);
    //Placer bouton Ajoutercoupon
     layoutHautDroite->addWidget(ajouterCoupon_);

     layoutHautDroite->addWidget(horizontaleFrameLine2);

     layoutHautDroite->addLayout(pointsMembreLayout);
     layoutHautDroite->addLayout(pointsCumMembreLayout);
     layoutHautDroite->addLayout(joursRestantsLayout);


    //ligne verticale
    QFrame* verticalFrameLine = new QFrame;
    verticalFrameLine->setFrameShape(QFrame::VLine);

    //Layout du haut
    QHBoxLayout* layoutHaut = new QHBoxLayout;
    layoutHaut->addLayout(layoutHautGauche);
    layoutHaut->addWidget(verticalFrameLine);
    layoutHaut->addLayout(layoutHautDroite);

    //Main layout
    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addLayout(layoutHaut);

    QWidget* widget = new QWidget;
    widget->setLayout(mainLayout);

    setCentralWidget(widget);

    string title = "Bienvenue sur PolyAir !" ;
    setWindowTitle(title.c_str());
}


void MainWindow::chargerBillets(){
    listeBillets_->clear();

    for(Membre* membre: membres_){
        for(Billet* billet: membre->getBillets())
        {
            QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(billet->getPnr()), listeBillets_);
            item->setData(Qt::UserRole, QVariant::fromValue<Billet*>(billet));
        }
    }

}

void MainWindow::chargerCoupons(){
    listeCoupons_->clear();
    for (auto coupon: coupons_){

        QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(coupon->getCode()), listeCoupons_);
        item->setData(Qt::UserRole, QVariant::fromValue<Coupon*>(coupon));
    }

}

void MainWindow::chargerMembres(){
    listeMembres_->clear();
    for (auto membre: membres_){

        QListWidgetItem* item = new QListWidgetItem(
            QString::fromStdString(membre->getNom()) , listeMembres_);
        item->setData(Qt::UserRole, QVariant::fromValue<Membre*>(membre));
    }
}

void MainWindow::ajouterMembresDansComboBox(QComboBox* list){
    for(Membre* membre : membres_){
        list->addItem(QString::fromStdString(membre->getNom()));
    }
}

void MainWindow::nettoyerVue() {

    nettoyerVueBillets();
    nettoyerVueCoupons();
    nettoyerVueMembres();

    // Listes
    listeBillets_->clearSelection();
    listeCoupons_->clearSelection();
    listeMembres_->clearSelection();
    chargerBillets();
    chargerCoupons();
    chargerMembres();
}

void MainWindow::nettoyerVueBillets(){
    //Vide les champs et possible de les remplir
    //PNR
    (*editeurPNR_).clear();
    (*editeurPNR_).setDisabled(false);

    //Prix billet
    (*editeurPrixBillet_).clear();
    (*editeurPrixBillet_).setDisabled(false);

    //Origine-destination
    (*editeurOD_).clear();
    (*editeurOD_).setDisabled(false);

    //Date de vol
    (*editeurDateVol_).clear();
    (*editeurDateVol_).setDisabled(false);

    //Pourcentage solde
    (*editeurPourcentageSoldeBillet_).clear();
    (*editeurPourcentageSoldeBillet_).setDisabled(false);

    //Utilisations restantes (voir bonus pour le disable)
    (*editeurUtilisationsRestantesFlightPass_).clear();

    //Choix de tarif
    (*choixTarifBillet_).setCurrentIndex(0);
    (*choixTarifBillet_).setDisabled(false);

    //Bouton ajouter Billet
    (*ajouterBillet_).setDisabled(false);

    //Choix de membre
    (*choixMembreBillet_).setCurrentIndex(0);
    (*choixMembreBillet_).setDisabled(false);

    //Boutons radio des types de billets
    for(auto bouton:boutonsRadioTypeBillets_){
        (*bouton).setAutoExclusive(false);
        (*bouton).setDisabled(false);
        (*bouton).setChecked(false);
        (*bouton).setAutoExclusive(true);
    }
}

void MainWindow::nettoyerVueCoupons(){
    //Champ vide et possible de les remplir
    //Code coupon
    (*editeurCodeCoupon_).clear();
    (*editeurCodeCoupon_).setDisabled(false);

    //Rabais coupon
    (*editeurRabaisCoupon_).clear();
    (*editeurRabaisCoupon_).setDisabled(false);

    //Cout coupon
    (*editeurCoutCoupon_).clear();
    (*editeurCoutCoupon_).setDisabled(false);

    //Bouton ajouter coupon
    (*ajouterCoupon_).setDisabled(false);
}

void MainWindow::nettoyerVueMembres(){
    //champ vide et possible de les remplir
    //Jours restants
    (*editeurJoursRestants_).setText("N/A");
    (*editeurJoursRestants_).setDisabled(true);

    //Points cumules
    (*editeurPointsCumules_).setText("N/A");
    (*editeurPointsCumules_).setDisabled(true);

    //Points
    (*editeurPoints_).setText("N/A");
    (*editeurPoints_).setDisabled(true);
}

//Affiche les informations du billet selectionne
void MainWindow::selectionnerBillet(QListWidgetItem* item){
    //Chercher billet
    Billet* billet=(*item).data(Qt::UserRole).value<Billet*>();

    //Nom du propriétaire du billet
    (*choixMembreBillet_).setCurrentText(QString::fromStdString((*billet).getNomPassager()));
    (*choixMembreBillet_).setDisabled(true);

    //Bouton radio du type de billet ainsi que les attributs associes

    //Billet Regulier
    if(BilletRegulier* billetReg=dynamic_cast<BilletRegulier*>(billet))
    {
        if(BilletRegulierSolde* solde=dynamic_cast<BilletRegulierSolde*>(billet)){
            (*boutonsRadioTypeBillets_[1]).toggle();
            (*editeurPourcentageSoldeBillet_).setText(QString::number((*solde).getPourcentageSolde()));
        }
        else{
            (*boutonsRadioTypeBillets_[0]).toggle();
            (*editeurPourcentageSoldeBillet_).setText("N/A");
        }
        (*editeurDateVol_).setText(QString::fromStdString((*billetReg).getDateVol()));
    }
    else{
        (*editeurDateVol_).setText("N/A");
    }
    (*editeurDateVol_).setDisabled(true);

    //FlightPass
    if(FlightPass* fp=dynamic_cast<FlightPass*>(billet)){
        if(FlightPassSolde* solde=dynamic_cast<FlightPassSolde*>(billet)){
            (*boutonsRadioTypeBillets_[3]).toggle();
            (*editeurPourcentageSoldeBillet_).setText(QString::number((*solde).getPourcentageSolde()));
        }
        else{
            (*boutonsRadioTypeBillets_[2]).toggle();
            (*editeurPourcentageSoldeBillet_).setText("N/A");
        }
        (*editeurUtilisationsRestantesFlightPass_).setText(QString::number((*fp).getNbUtilisationsRestante()));
        (*editeurDateVol_).setText("N/A");
    }
    else{
        (*editeurUtilisationsRestantesFlightPass_).setText("N/A");
    }
    (*editeurUtilisationsRestantesFlightPass_).setDisabled(true);
    (*editeurPourcentageSoldeBillet_).setDisabled(true);

    //Tarif
    if(billet->getTarif()==TarifBillet::Economie){
        (*choixTarifBillet_).setCurrentIndex(1);
    }
    else if(billet->getTarif()==TarifBillet::PremiumEconomie){
        (*choixTarifBillet_).setCurrentIndex(2);
    }
    else if(billet->getTarif()==TarifBillet::Affaire){
        (*choixTarifBillet_).setCurrentIndex(3);
    }
    else if(billet->getTarif()==TarifBillet::Premiere){
        (*choixTarifBillet_).setCurrentIndex(4);
    }
    else{
        (*choixTarifBillet_).setCurrentIndex(0);
    }
    (*choixTarifBillet_).setDisabled(true);

    //PNR
    (*editeurPNR_).setText((*item).text());
    (*editeurPNR_).setDisabled(true);

    //Prix billet
    (*editeurPrixBillet_).setText(QString::number( (*billet).getPrix()));
    (*editeurPrixBillet_).setDisabled(true);

    //Origine-destination
    (*editeurOD_).setText(QString::fromStdString( (*billet).getOd()));
    (*editeurOD_).setDisabled(true);

    //Bouton ajouter billet
    (*ajouterBillet_).setDisabled(true);

    //Boutons radio desactive
    for(auto bouton:boutonsRadioTypeBillets_)
        (*bouton).setDisabled(true);

}

//Affiche les informations du coupon selectionne
void MainWindow::selectionnerCoupon(QListWidgetItem* item ){
    //Valeur de coupon
    Coupon* coupon=(*item).data(Qt::UserRole).value<Coupon*>();

    //Code coupon
    (*editeurCodeCoupon_).setText(QString::fromStdString(coupon->getCode()));
    (*editeurCodeCoupon_).setDisabled(true);

    //Rabais coupon
    (*editeurRabaisCoupon_).setText(QString::number(coupon->getRabais()));
    (*editeurRabaisCoupon_).setDisabled(true);

    //Cout coupon
    (*editeurCoutCoupon_).setText(QString::number(coupon->getCout()));
    (*editeurCoutCoupon_).setDisabled(true);

    //Bouton coupon
    (*ajouterCoupon_).setDisabled(true);
}
void MainWindow::selectionnerMembre(QListWidgetItem* item){
    //Valeur membre
    Membre* membre=(*item).data(Qt::UserRole).value<Membre*>();

    //Attribut de membre regulier
    if(MembreRegulier* membreReg=dynamic_cast<MembreRegulier*>(membre))
    {
        (*editeurPoints_).setText(QString::number((*membreReg).getPoints()));
    }
    else{
        (*editeurPoints_).setText("N/A");
    }

    //Attributs de membre premium
    if(MembrePremium* membrePre=dynamic_cast<MembrePremium*>(membre))
    {
        (*editeurPointsCumules_).setText(QString::number(membrePre->getpointsCumulee()));
        (*editeurJoursRestants_).setText(QString::number(membrePre->getJourRestants()));
    }
    else{
        (*editeurPointsCumules_).setText("N/A");
        (*editeurJoursRestants_).setText("N/A");
    }

    //Desactiver case
    (*editeurPoints_).setDisabled(true);
    (*editeurPointsCumules_).setDisabled(true);
    (*editeurJoursRestants_).setDisabled(true);

}
void MainWindow::ajouterBillet(){

    //Try different entree
   try {
        //Trouver membre
        Membre* membre=trouverMembreParNom((*choixMembreBillet_).currentText().toStdString());
        if(membre==nullptr){
            throw ExceptionArgumentInvalide("Erreur: Membre invalide!");
        }
        string type;
        for(auto bouton:boutonsRadioTypeBillets_){
            if((*bouton).isChecked()){
                type=(*bouton).text().toStdString();
            }
        }
        if(type.empty()){
            throw ExceptionArgumentInvalide("Erreur: Type de billet invalide!");
        }
        else if((*editeurPNR_).text().isEmpty()){ //No validator yet
            throw ExceptionArgumentInvalide("Erreur: PNR invalide!");
        }
        else if(!(*editeurPrixBillet_).hasAcceptableInput()){
            throw ExceptionArgumentInvalide("Erreur: Prix invalide!");
        }
        else if((*editeurOD_).text().isEmpty()){ // No Validator yet
            throw ExceptionArgumentInvalide("Erreur: Origine-Destination invalide!");
        }
        else if((*choixTarifBillet_).currentIndex()==0){
            throw ExceptionArgumentInvalide("Erreur: Tarif invalide!");
        }
        //Valeur valide jusqu'à date et partagé par tout les types
        string pnr=(*editeurPNR_).text().toStdString();
        double prix= (*editeurPrixBillet_).text().toDouble();
        string od=(*editeurOD_).text().toStdString();
        TarifBillet tarif=getTarifBillet();

        //Valeur selon type billet
        if(type=="Regulier"){
            if((*editeurDateVol_).text().isEmpty()){
                throw ExceptionArgumentInvalide("Erreur: Date invalide!");
            }
            else if((*editeurPourcentageSoldeBillet_).hasAcceptableInput()){
                throw ExceptionArgumentInvalide("Erreur: Solde non applicable à ce type de billet!");
            }
            else if((*editeurUtilisationsRestantesFlightPass_).hasAcceptableInput()){
                throw ExceptionArgumentInvalide("Erreur: Utilisations restantes non applicable à ce type de billet!");
            }
            string date=(*editeurDateVol_).text().toStdString();
            Billet* billet=new BilletRegulier(pnr,prix,od,tarif,date);
            (*membre).ajouterBillet(billet);
        }
        else if (type=="Regulier Solde") {
            if((*editeurDateVol_).text().isEmpty()){
                throw ExceptionArgumentInvalide("Erreur: Date invalide!");
            }
            else if(!(*editeurPourcentageSoldeBillet_).hasAcceptableInput()){
                throw ExceptionArgumentInvalide("Erreur: Pourcentage solde invalide!");
            }
            else if((*editeurUtilisationsRestantesFlightPass_).hasAcceptableInput()){
                throw ExceptionArgumentInvalide("Erreur: Utilisations restantes non applicable à ce type de billet!");
            }
            string date=(*editeurDateVol_).text().toStdString();
            double pourcentageSolde=(*editeurPourcentageSoldeBillet_).text().toDouble();
            Billet* billet=new BilletRegulierSolde(pnr,prix,od,tarif,date,pourcentageSolde);
            (*membre).ajouterBillet(billet);
        }
        else if(type=="FlightPass"){
            if(!(*editeurDateVol_).text().isEmpty()){
                throw ExceptionArgumentInvalide("Erreur: Date non applicable à ce type de billet!");
            }
            else if((*editeurPourcentageSoldeBillet_).hasAcceptableInput()){
                throw ExceptionArgumentInvalide("Erreur: Solde non applicable à ce type de billet!");
            }
            else if(!(*editeurUtilisationsRestantesFlightPass_).hasAcceptableInput()){
                throw ExceptionArgumentInvalide("Erreur: Utilisations restantes invalide!");
            }
            Billet* billet=new FlightPass(pnr,prix,od,tarif);
            (*membre).ajouterBillet(billet);
        }
        else{
            if(!(*editeurDateVol_).text().isEmpty()){
                throw ExceptionArgumentInvalide("Erreur: Date non applicable à ce type de billet!");
            }
            else if(!(*editeurPourcentageSoldeBillet_).hasAcceptableInput()){
                throw ExceptionArgumentInvalide("Erreur: Pourcentage solde invalide!");
            }
            else if(!(*editeurUtilisationsRestantesFlightPass_).hasAcceptableInput()){
                throw ExceptionArgumentInvalide("Erreur: Utilisations restantes invalide!");
            }
            double pourcentageSolde=(*editeurPourcentageSoldeBillet_).text().toDouble();
            Billet* billet=new FlightPassSolde(pnr,prix,od,tarif,pourcentageSolde);
            (*membre).ajouterBillet(billet);
        }

    } catch (ExceptionArgumentInvalide& e){
        afficherMessage(e.what());
    }

    //Recharger afin que billet apparaisse dans liste
    chargerBillets();
}

void MainWindow::ajouterCoupon(){

    //Try differentes entrees
    try {
        if((*editeurCodeCoupon_).text().isEmpty()){
            throw ExceptionArgumentInvalide("Erreur: Code coupon invalide!");
        }
        else if(!(*editeurRabaisCoupon_).hasAcceptableInput()){
            throw ExceptionArgumentInvalide("Erreur: Rabais coupon invalide!");
        }
        else if(!(*editeurCoutCoupon_).hasAcceptableInput()){
            throw ExceptionArgumentInvalide("Erreur: Cout coupon invalide!");
        }

        //Entrees valides
        string code=(*editeurCodeCoupon_).text().toStdString();
        double rabais=(*editeurRabaisCoupon_).text().toDouble();
        int cout=(*editeurCoutCoupon_).text().toInt();

        //Creation et ajout coupon
        Coupon* coupon=new Coupon(code,rabais,cout);
        coupons_.push_back(coupon);

    } catch (ExceptionArgumentInvalide& e) {
        afficherMessage(e.what());
    }

    //Recharger afin de voir coupon dans liste
    chargerCoupons();
}


void MainWindow::filtrerListe(int index){
    //Filtre tous les membres selon ofnction filtrerMasque
    for(unsigned int i=0;i<membres_.size();i++)
    {
        QListWidgetItem* membre=(*listeMembres_).item(int(i));
        (*membre).setHidden(filtrerMasque((*membre).data(Qt::UserRole).value<Membre*>(),index));
    }
}

bool MainWindow::filtrerMasque(Membre* membre, int index) {
    //Selon index, retourne vrai faux pour afficher le membre sinon cache
    if(index==0)
    {
        return false;
    }
    else if(index==1)
    {
        if(dynamic_cast<MembreRegulier*>(membre))
        {
            if(!dynamic_cast<MembrePremium*>(membre)) //NON membrePremium
            {
                return false;    //affiche
            }
        }
    }
    else if(index==2) //afficher membrePremium seulement
    {
        if(dynamic_cast<MembrePremium*>(membre))
        {
            return false;    //affiche membrePremium
        }
    }
    return true;
}

TarifBillet MainWindow::getTarifBillet(){
    //Selon index actuel, retourner tarif
    auto index=(*choixTarifBillet_).currentIndex();
    if(index==2){
        return TarifBillet::PremiumEconomie;
    }
    else if(index==3){
        return TarifBillet::Affaire;
    }
    else if(index==4){
        return TarifBillet::Premiere;
    }
    else{
        return TarifBillet::Economie;
    }
}


//Trouve membre par son nom
Membre* MainWindow::trouverMembreParNom(const string& nom){
   for(unsigned int i=0;i<membres_.size();i++)
   {
       if((*membres_[i]).getNom()==nom)
       {
           return membres_[i];
       }
   }
   return nullptr;
}

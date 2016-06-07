

#ifndef INTERFACE_H
#define INTERFACE_H

#include <QApplication>
#include<QWidget>
#include<QPushButton>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QGridLayout>
#include<QLineEdit>
#include<QObject>
#include"computer.h"
#include <QTableWidget>
#include <QTabWidget>
#include <QtWidgets>
//#include <QSound>



//Widget de type QLineEdit pour utilier des slots persos pour utiliser avec les QPushButton



class variableWindow : public QWidget {
    Q_OBJECT
    friend class Fenetre;

};

class programWindow : public QWidget {
    Q_OBJECT
    friend class Fenetre;
};

class settingWindow : public QWidget {
// parametrer l'affichage du clavier cliquable
// -> Regrouper le pavé numérique et les opérateurs
// -> Placer tout seul le truc des messages en attendant de faire un QDialog pour le remplacer avec un bip sonore et parametrer ensuite ce bip sonore
// parametrer le bip sonore quand le QDialog sera créé
// parametrer le nb d'éléments de la pile qu'on affiche
    Q_OBJECT
private :
     QVBoxLayout* layout;
     QLabel* label_clavier;
     QLabel* label_son;
     QLabel* label_nbEl;
     QPushButton* button_clavier;
     QPushButton* button_son;
     QLineEdit* nb_ele;

public :
     settingWindow();
     friend class Fenetre;
     friend class mainWindow;
public slots :

     //void activer_son;
     //void para_nbEl;
};

class mainWindow : public QWidget
{
    Q_OBJECT

public slots:
    //SLOTS 1 A 15 POUR LES QPUSHBUTTONS
    void slot0 ();
    void slot1 ();
    void slot2 ();
    void slot3 ();
    void slot4 ();
    void slot5 ();
    void slot6 ();
    void slot7 ();
    void slot8 ();
    void slot9 ();
    void slot10 ();
    void slot11 ();
    void slot12 ();
    void slot13 ();
    void slot14 ();
    void slot15 ();
    //SLOT POUR LE PASSAGE DU QLINEEDIT AU CONTROLEUR
    void slot16 ();
    void slot17 (); //refresh
    void slot18 ();
    void slot19 ();
    void slot20 ();
    void slot21 ();
    void slot22 ();


public:
    mainWindow();
    friend class Fenetre;
    friend class settingWindow;

private:
    //Vue principale : clavier cliquable (pavé numérique + opérateurs) + état du calculateur
    QPushButton* bouton0;
    QPushButton* bouton1;
    QPushButton* bouton2;
    QPushButton* bouton3;
    QPushButton* bouton4;
    QPushButton* bouton5;
    QPushButton* bouton6;
    QPushButton* bouton7;
    QPushButton* bouton8;
    QPushButton* bouton9;
    QPushButton* addition;
    QPushButton* soustraction;
    QPushButton* multiplication;
    QPushButton* division;
    QPushButton* complexe;
    QPushButton* swap;
    QPushButton* drop;
    QPushButton* clear;
    QPushButton* dup;

    QHBoxLayout* valid_button;
    QPushButton* enter;
    QPushButton* correction;

    QHBoxLayout* clavier_cliquable;
    QGridLayout* pave_ope;
    QGridLayout* pave_num;
    QLineEdit* box;

    QDialog* message;
    QLineEdit* ligne_message;
    QPushButton* valider_message;
    QVBoxLayout* total;
 //   QSound* bip;

    QTableWidget* resultBox;
    QGridLayout* global;


    //partie du code ou on gère les données récupérées
    Pile* pile;
    litteraleManager* lManager;
    Controleur* controleur;

signals :


};

class Fenetre : public QWidget {
    Q_OBJECT
private :
    QTabWidget* onglets;
    mainWindow* page1;
    variableWindow* page2;
    programWindow* page3;
    settingWindow* page4;
public :
    Fenetre();
public slots :
    void desactiver_clavier();
    void changer_nb_el();

};


#endif // INTERFACE_H

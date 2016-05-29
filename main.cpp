#include"interface.h"


#include <QApplication>
#include<QWidget>
#include<QPushButton>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QGridLayout>
#include<QLineEdit>
#include<QObject>
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget conteneur;


    QTabWidget* onglets = new QTabWidget(&conteneur);
    onglets->setGeometry(40,20,600, 250);
    // Création des pages
    mainWindow* page1 = new mainWindow;
    variableWindow* page2 = new variableWindow;
    programWindow* page3 = new programWindow;
    settingWindow* page4 = new settingWindow;
    // Ajout des onglets au QTabWidget
    onglets->addTab(page1, "Calculatrice");
    onglets->addTab(page2, "Gestion et édition des variables");
    onglets->addTab(page3, "Gestion et édition des programmes");
    onglets->addTab(page4, "Gestion des paramètres");

    conteneur.show();
    return app.exec();
}

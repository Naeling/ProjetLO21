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

    Fenetre conteneur;
    conteneur.show();



    return app.exec();
}

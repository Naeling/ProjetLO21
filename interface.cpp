#include"interface.h"

settingWindow::settingWindow()
{
    // Création des boutons et zones d'affichage
    label_clavier= new QLabel("Affichage du clavier cliquable");
    button_clavier= new QPushButton("Désactiver");
    label_son= new QLabel("Activation du bip sonore accompagnant un message");
    button_son= new QPushButton("Désactiver");
    label_nbEl= new QLabel("Parametrer le nombre de derniers éléments de la pile affichés");
    nb_ele= new QLineEdit;

    // Mise en place
    layout= new QVBoxLayout;
    layout->addWidget(label_clavier);
    layout->addWidget(button_clavier);
    layout->addWidget(label_son);
    layout->addWidget(button_son);
    layout->addWidget(label_nbEl);
    layout->addWidget(nb_ele);
    setLayout(layout);

    // Connexion entre les boutons et les para
    QObject::connect(button_clavier, SIGNAL(clicked()), this, SLOT(desactiver_clavier()));



}



// constructeur de la classe champTexte
mainWindow::mainWindow()
{
    //Initialisation des la pile et du manager via les methodes sur singleton
    pile=&(Pile::getInstance());
    lManager=&(litteraleManager::getInstance());
    controleur=&(Controleur::getInstance());

    bouton0= new QPushButton("0");
    bouton1= new QPushButton("1");
    bouton2= new QPushButton("2");
    bouton3= new QPushButton("3");
    bouton4= new QPushButton("4");
    bouton5= new QPushButton("5");
    bouton6= new QPushButton("6");
    bouton7= new QPushButton("7");
    bouton8= new QPushButton("8");
    bouton9= new QPushButton("9");

    addition = new QPushButton("+");
    soustraction = new QPushButton("-");
    multiplication = new QPushButton("*");
    division= new QPushButton("/");
    complexe = new QPushButton("$");

    enter= new QPushButton("Valider");
    correction= new QPushButton("Corriger");


    box= new QLineEdit; //c'est la ligne d'affichage du resultat


    message= new QDialog; // A modifier en QDialog dans le reste du code
    boitier= new QTabWidget;
    resultBox= new QTableWidget(pile->getNbLitteralesToAffiche(),1);
    for(unsigned int i=pile->getNbLitteralesToAffiche();i>0;i--){

           resultBox->setItem(i-1,0,new QTableWidgetItem(""));
       }

    //pave->addWidget(enter,3,0);
    //pave->addWidget(correction,0,0);


    // pavé opérateur
    pave_ope = new QGridLayout;
    pave_ope->addWidget(addition,1,0);
    pave_ope->addWidget(soustraction,1,1);
    pave_ope->addWidget(multiplication, 2,0);
    pave_ope->addWidget(division,2,1);
    pave_ope->addWidget(complexe,3,1);

    // pavé numérique
    pave_num= new QGridLayout; //ancien numberbox
    pave_num->addWidget(bouton9,1,0);
    pave_num->addWidget(bouton8,1,1);
    pave_num->addWidget(bouton7,1,2);
    pave_num->addWidget(bouton6,2,0);
    pave_num->addWidget(bouton5,2,1);
    pave_num->addWidget(bouton4,2,2);
    pave_num->addWidget(bouton3,3,0);
    pave_num->addWidget(bouton2,3,1);
    pave_num->addWidget(bouton1,3,2);
    pave_num->addWidget(bouton0,4,0);


    // clavier cliquable que l'on peut faire sauter
    clavier_cliquable= new QHBoxLayout;
    clavier_cliquable->addLayout(pave_num);
    clavier_cliquable->addLayout(pave_ope);

    // à finir : mettre en ligne le resultat, 
    global= new QHBoxLayout;
    global-> addLayout(numberBox,0,0, 2,1);
    global-> addWidget(resultBox,0,1);
    global-> addLayout(pave,0,2);
    //boitier->addTab(resultBox);
    setLayout(global);



    // Connection entre les boutons et le champ de texte
    QObject::connect(bouton0, SIGNAL(clicked()), this, SLOT(slot0()));
    QObject::connect(bouton1, SIGNAL(clicked()), this, SLOT(slot1()));
    QObject::connect(bouton2, SIGNAL(clicked()), this, SLOT(slot2()));
    QObject::connect(bouton3, SIGNAL(clicked()), this, SLOT(slot3()));
    QObject::connect(bouton4, SIGNAL(clicked()), this, SLOT(slot4()));
    QObject::connect(bouton5, SIGNAL(clicked()), this, SLOT(slot5()));
    QObject::connect(bouton6, SIGNAL(clicked()), this, SLOT(slot6()));
    QObject::connect(bouton7, SIGNAL(clicked()), this, SLOT(slot7()));
    QObject::connect(bouton8, SIGNAL(clicked()), this, SLOT(slot8()));
    QObject::connect(bouton9, SIGNAL(clicked()), this, SLOT(slot9()));
    QObject::connect(addition, SIGNAL(clicked()), this, SLOT(slot10()));
    QObject::connect(soustraction, SIGNAL(clicked()), this, SLOT(slot11()));
    QObject::connect(division, SIGNAL(clicked()), this, SLOT(slot12()));
    QObject::connect(multiplication, SIGNAL(clicked()), this, SLOT(slot13()));
    QObject::connect(complexe, SIGNAL(clicked()), this, SLOT(slot14()));
    QObject::connect(correction, SIGNAL(clicked()), this, SLOT(slot15()));
    QObject::connect(enter, SIGNAL(clicked()), this, SLOT(slot16()));
    QObject::connect(box, SIGNAL(returnPressed()),this,SLOT(slot16()));
    QObject::connect(pile,SIGNAL(modificationEtat()),this,SLOT(slot17()));






}


//SLOTS 0 A 9 INCLUS: LINKAGE DES BOUTONS QLINEEDIT
void mainWindow::slot0()
{
    QString temp= box->text()+'0';
    box->setText(temp);
}


void mainWindow::slot1()
{
    QString temp= box->text()+'1';
    box->setText(temp);
}
void mainWindow::slot2()
{
    QString temp= box->text()+'2';
    box->setText(temp);
}
void mainWindow::slot3()
{
    QString temp= box->text()+'3';
    box->setText(temp);
}
void mainWindow::slot4()
{
    QString temp= box->text()+'4';
    box->setText(temp);
}
void mainWindow::slot5()
{
    QString temp= box->text()+'5';
    box->setText(temp);
}
void mainWindow::slot6()
{
    QString temp= box->text()+'6';
    box->setText(temp);
}
void mainWindow::slot7()
{
    QString temp= box->text()+'7';
    box->setText(temp);
}
void mainWindow::slot8()
{
    QString temp= box->text()+'8';
    box->setText(temp);
}
void mainWindow::slot9()
{
    QString temp= box->text()+'9';
    box->setText(temp);
}
//SLOTS 10 A 14 INCLUS CONNEXION DES BOUTONS D'OPERATEURS
void mainWindow::slot10()
{
    controleur->commande(QString('+'));

}
void mainWindow::slot11()
{
    controleur->commande(QString('-'));
}
void mainWindow::slot12()
{
    controleur->commande(QString('/'));
}
void mainWindow::slot13()
{
    controleur->commande(QString('*'));
}
void mainWindow::slot14()
{
    controleur->commande(QString('$'));
}
void mainWindow::slot15()
{
    box->backspace();
}
//quand on appuie sur valider le champ de texte est effacé et le texte est passé quelque part.
void mainWindow::slot16()
{
    // commande prend en parametre un QString
    controleur->commande(box->displayText());
    box->setText("");

}


void mainWindow::slot17(){ //refresh

    //Le message
    message->setText((pile->getMessage()));
    //0 à getNbLitteralToAffiche

    for(unsigned int i=0;i<pile->getNbLitteralesToAffiche();i++) //on parcourt toute la vue en effaçant le contenu pour le remplacer avec la boucle suivante
       resultBox->item(i,0)->setText("");
    //Mettre a jour
    unsigned int nb=0;
    //on commence l'affichage à partir du haut de la pile  Pile::iterator it=pile->begin()
    //on s'arrette à la fin de la pile
    //ou
    for(Pile::iterator it=pile->begin() ; it!=pile->end() && nb<pile->getNbLitteralesToAffiche( ); ++it,++nb) {
         //gérer la différence d'affichage d'un type de littérale à l'autre
        if((*it)->getType()==1)
            //*it renvoie un pointeur sur litterale
            resultBox->item(pile->getNbLitteralesToAffiche()-1-nb,0)->setText(QString::number((dynamic_cast<lEntiere*>(*it))->getValeur()));
        if((*it)->getType()==2)  //result = abc + def;
            resultBox->item(pile->getNbLitteralesToAffiche()-1-nb,0)->setText(QString::number((dynamic_cast<lRationnelle*>(*it))->getNumerateur())+'/'+QString::number((dynamic_cast<lRationnelle*>(*it))->getDenominateur()));
        if((*it)->getType()==3)  //result = abc + def;
            resultBox->item(pile->getNbLitteralesToAffiche()-1-nb,0)->setText(QString::number((dynamic_cast<lReelle*>(*it))->getValeur()));
        if((*it)->getType()==4){
            litterale* reelle=&dynamic_cast<lComplexe*>(*it)->getReelle();
            litterale* imaginaire=&dynamic_cast<lComplexe*>(*it)->getIm();
            if(reelle->getType()==1)
                resultBox->item(pile->getNbLitteralesToAffiche()-1-nb,0)->setText(QString::number((dynamic_cast<lEntiere*>(reelle))->getValeur()));
            if(reelle->getType()==2)
                resultBox->item(pile->getNbLitteralesToAffiche()-1-nb,0)->setText(QString::number((dynamic_cast<lRationnelle*>(reelle))->getNumerateur())+'/'+QString::number((dynamic_cast<lRationnelle*>(reelle))->getDenominateur()));
            if(reelle->getType()==3)
                resultBox->item(pile->getNbLitteralesToAffiche()-1-nb,0)->setText(QString::number((dynamic_cast<lReelle*>(reelle))->getValeur()));
            if(imaginaire->getType()==1)
                resultBox->item(pile->getNbLitteralesToAffiche()-1-nb,0)->setText(resultBox->item(pile->getNbLitteralesToAffiche()-1-nb,0)->text()+'$'+QString::number((dynamic_cast<lEntiere*>(imaginaire))->getValeur()));
            if(imaginaire->getType()==2)
                resultBox->item(pile->getNbLitteralesToAffiche()-1-nb,0)->setText(resultBox->item(pile->getNbLitteralesToAffiche()-1-nb,0)->text()+'$'+QString::number((dynamic_cast<lRationnelle*>(imaginaire))->getNumerateur())+'/'+QString::number((dynamic_cast<lRationnelle*>(imaginaire))->getDenominateur()));
            if(imaginaire->getType()==3)
                resultBox->item(pile->getNbLitteralesToAffiche()-1-nb,0)->setText(resultBox->item(pile->getNbLitteralesToAffiche()-1-nb,0)->text()+'$'+QString::number((dynamic_cast<lReelle*>(imaginaire))->getValeur()));
        }
    }
}


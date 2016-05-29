#ifndef COMPUTER_H_INCLUDED
#define COMPUTER_H_INCLUDED
//tyftuftyfjy
#include <iostream>
#include <sstream>
#include <QApplication>
#include<QWidget>
#include<QPushButton>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QGridLayout>
#include<QLineEdit>
#include<QObject>
#include <QString>
#include <QTextStream>
#include <QObject>
#include <QDebug>

using namespace std;

class ComputerException {
    string info;
public:
    ComputerException(const string& str):info(str){}
    string getInfo() const { return info; }
};

// on doit avoir une virtuelle pure dans litterale
// on a donc un getType qui va retourner un entier correspondant au type réel de la littérale

//PENSER A SURCHARCHER LES DESTRUCTEURS EN VIRTUEL
class litterale
{
public:

   virtual unsigned int getType() const =0;
   virtual  ~litterale();
protected:
    unsigned int type;
};



class lEntiere: public litterale   //type=1
{
public:

    unsigned int getType () const {return type;}
    lEntiere(int val): valeur(val) {type=1;}
    int getValeur() const {return valeur;}
    ~lEntiere();
private:
    int valeur;
};

//concernant la place du signe - sur le numerateur ou le denominateur ou les deux:
//dans cette classe ça ne pose pas de problème au niveau des opérations je crois
//mais reste à vérifier
class lRationnelle: public litterale   //type=2
{
public:

    unsigned int getType () const {return type;}
    int getNumerateur() const {return numerateur;}
    int getDenominateur() const {return denominateur;}
    lRationnelle (int num, int den): numerateur(num), denominateur(den)  {type=2;}
    ~lRationnelle();
private:

    int numerateur;
    int denominateur;
};


//apres reflexion un seul attribut de type float fera bien le café
class lReelle: public litterale  //type =3
{
public:
    unsigned int getType() const {return type;}
    float getValeur() const {return valeur;}
    lReelle(float val): valeur(val)   {   type=3;    }
    ~lReelle();
private:
    float valeur;
};



class lComplexe: public litterale // type=4
{
public:

    unsigned int getType() const {return type;}
    lComplexe (litterale* ree, litterale* im)
    {
        reelle=ree;
        imaginaire=im;
        type=4;
    }
     lComplexe (litterale& ree, litterale& im)
    {
        reelle=&ree;
        imaginaire=&im;
        type=4;
    }
    litterale& getReelle() const {return *reelle;}
    litterale& getIm () const {return *imaginaire;}
    ~lComplexe();

private:

    litterale* reelle;
    litterale* imaginaire;
    //unsigned int typeReelle;
    //unsigned int typeImaginaire;
};



class lAtome: public litterale
{
public:

    unsigned int getType() const {return type;}
    //le constructeur verifie la valeur de la chaine passée en argument et vérifie que le formalisme correspond à celui d'un atome
    lAtome (string& exp): expression (exp)
    {
        type=5;
        if(exp[0]>'Z'  || exp[0]<'A') throw "erreur le premier caractère doit être une lettre majuscule";
        unsigned int i=1;
        while(exp[i]!= '\0')
        {
            // si c'est pas une lettre maj et pas un chiffre
            if((exp[i]<'A' || exp[i]>'Z')&& (exp[i]<0  ||  exp[i] >9))
                throw "erreur la litterale atome saisie ne respecte pas le formalime imposé: 1 maj puis 1 chiffre ou une maj";
            i++;
        }
    }
    ~lAtome();
private:

    string expression;
};


//constructeur pour cette classe à implémenter par la suite en étudiant un peu plus le fonctionnement du truc

class lExpression: public litterale
{
public:

    unsigned int getType() const { return type;}
    ~lExpression();
private:


    // tableau pour stocker les litterales de l'expression
    //nil pour signifier qu'on a un opérateur à la position concernée
    litterale** tab1;
    unsigned int nbr_tab1;
    unsigned int taille_tab1;

    //tableau pour stocker les operateurs et parenthèses
    char** tab2;
    unsigned int nbr_tab2;
    unsigned int taille_tab2;
};

//Implémenter un Design Pattern Singleton
class Pile: public QObject
{
Q_OBJECT
private:

    litterale** tab;
    unsigned int nb;
    unsigned int nbMax;
    QString message;
    void agrandissementCapacite();
    unsigned int nbAffiche; //nombre de litterale à afficher dans la vue de la pile, par défaut 4
    Pile():tab(0),nb(0),nbMax(0),message(""),nbAffiche(4){}

    struct Handler{
        Pile* instance;
        Handler():instance(0){}
        // destructeur appelé à la fin du programme
        ~Handler(){ delete instance; }
    };
    static Handler handler;


public:

    ~Pile(){delete [] tab; }
    void push(litterale& l);
    void pop();
    bool estVide() const { return nb==0; }
    unsigned int taille() const { return nb; }
    litterale& top() const;
    static Pile& getInstance();
    static void libererInstance();

    unsigned int getNbLitteralesToAffiche()const { return nbAffiche; }
    void setNbItemsToAffiche(unsigned int n) { nb=n; }
    void setMessage(const QString& m) { message=m; }
    QString getMessage() const { return message; }

    class iterator {
            litterale** current;
            iterator(litterale** u):current(u){} //seul le litteraleManager a acces à ce constructeur
            friend class Pile;
        public:
            iterator():current(0){}
            litterale* operator*() const { return *current; } //renvoie la valeur actuellement pointée
            bool operator!=(iterator it) const { return *current!=*it.current; } //permet de comparer deux iterateurs
            //pourrait tout autant retourner void
            iterator& operator++(){ --current; return *this; } //permet de descendre les valeurs de la pile
        };
        //donne un iterateur sur le haut de la pile
        iterator begin() { return iterator(tab+nb-1); }
        //donne un iterateur sur le bas de la pile
        iterator end() { return iterator(tab-1); }


signals:
    void modificationEtat();


};


class litteraleManager: public QObject {
    litterale** litt;
    unsigned int nb;
    unsigned int nbMax;
    void agrandissementCapacite();
    litteraleManager():litt(0),nb(0),nbMax(0){}
    ~litteraleManager();
    litteraleManager(const litteraleManager& m);
    litteraleManager& operator=(const litteraleManager& m);

    struct Handler{
        litteraleManager* instance;
        Handler():instance(0){}
        // destructeur appelé à la fin du programme
        ~Handler(){ delete instance; }
    };

    static Handler handler;



public:

    //Methodes factory
    litterale& addLitterale(int v);
    litterale& addLitterale(int num, int den);
    litterale& addLitterale(float v);
    litterale& addLitterale(litterale& target);
    litterale& addLitterale(litterale& re,litterale& l);

    void removeLitterale(litterale& e);
    static litteraleManager& getInstance();
    static void libererInstance();

    // Les opérateurs
    litterale& addition(litterale& op1,litterale& op2);
    litterale& soustraction(litterale& op1,litterale& op2);
    litterale& multiplication(litterale& op1,litterale& op2);
    litterale& division(litterale& op1,litterale& op2);

    //fonctionnement de l'iterateur
    //il part de la fin comme on va souvent devoir utiliser des litterales qui se trouvent
    //à la fin de la pile
    class iterator {
            litterale** current;
            iterator(litterale** u):current(u){} //seul le litteraleManager a acces à ce constructeur
            friend class litteraleManager;
        public:
            iterator():current(0){}
            litterale* operator*() const { return *current; } //renvoie la valeur actuellement pointée
            bool operator!=(iterator it) const { return *current!=*it.current; } //permet de comparer deux iterateurs
            //pourrait tout autant retourner void
            iterator& operator++(){ --current; return *this; } //permet de descendre les valeurs de la pile
        };
        //donne un iterateur sur le haut de la pile
        iterator begin() { return iterator(litt+nb-1); }
        //donne un iterateur sur le bas de la pile
        iterator end() { return iterator(litt-1); }

};


//probablement 1 controleur unique relié à la fenetre globale
//singleton ?
class Historique :public QObject {
private:
    Pile** historique;
    unsigned int nb;
    unsigned int nbMax;
public:
    //initialiser pour accueillir 10 piles
    Historique(unsigned int max=10): historique(new Pile* [max]), nb(0), nbMax(max) {}
    unsigned int taille() const {return nb;}
    bool estVide() const {return nb>0;}
    void agrandissementCapacite();
    void push(Pile& nouveau){
        if(nb==nbMax) agrandissementCapacite();
        historique[nb++]=&nouveau;
    }
    Pile* current() const {


    }
    struct Handler{
        Historique* instance;
        Handler():instance(0){}
        // destructeur appelé à la fin du programme
        ~Handler(){ delete instance; }
    };

    static Handler handler;
    static Historique& getInstance();
    static void libererInstance();
};

//le controleur est utilisé à la fois pour l'affichage
//et le traitement des expressions passés par le QLineEdit
class Controleur : public QObject {
Q_OBJECT
private:

    litteraleManager* littMng;
    Pile* littAff;
    Historique* log;
    struct Handler{
        Controleur* instance;
        Handler():instance(0){}
        // destructeur appelé à la fin du programme
        ~Handler(){ delete instance; }
    };
    static Handler handler;

public:
    Controleur()
    // le constructeur utilise le singleton implémenté dans les classes Pile et litteraleManager
    {
        littMng= &(litteraleManager::getInstance());
        littAff= &(Pile::getInstance());
        log= &(Historique::getInstance());
    }

    static Controleur& getInstance();
    static void libererInstance();
    void commande(const QString& c);

signals:
    void modificationEtat();
};



#endif // COMPUTER_H_INCLUDED

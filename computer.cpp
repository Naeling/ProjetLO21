#include"computer.h"

//DESTRUCTEURS VIRTUELS
litterale::~litterale() {}
lEntiere::~lEntiere() {}
lRationnelle::~lRationnelle() {}
lReelle::~lReelle() {}
lComplexe::~lComplexe() {
    delete reelle;
    delete imaginaire;
}
litterale& Addition::addition(litterale& op1, litterale& op2) {
    //addition avec op1 ENTIER
    if(op1.getType()>4) {
        if(op2.getType()>4) { // les deux membres sont composites
            return addition(op1.evaluer(),op2.evaluer());
        }   return addition(op1.evaluer(),op2); //seul op1 est composite
    } else if(op2.getType()>4) {
            return addition(op1,op2.evaluer()); //seul op2 est composite
    }      //sinon on est dans un cas classique d'operation entre deux feuilles comme ci dessous
    if(op1.getType()==1) {
        if(op2.getType()==1)
        {
            return *(new lEntiere(dynamic_cast<const lEntiere&>(op2).getValeur()+dynamic_cast<const lEntiere&>(op1).getValeur()));
        }

        if(op2.getType()==2)
        {
            int num=dynamic_cast<const lRationnelle&> (op2).getNumerateur()+dynamic_cast<const lRationnelle&> (op2).getDenominateur()*dynamic_cast<const lEntiere&>(op1).getValeur();
            int den=dynamic_cast<const lRationnelle&>(op2).getDenominateur();
            return *(new lRationnelle(num, den));
        }
        if(op2.getType()==3)
        {
            return *(new lReelle((float)(dynamic_cast<const lEntiere&>(op1).getValeur()+dynamic_cast<const lReelle&>(op2).getValeur())));
        }
        if(op2.getType()==4)
        {
            return *(new lComplexe(&(addition(dynamic_cast<const lComplexe&>(op2).getReelle(),op1)),&(dynamic_cast<const lComplexe&>(op2).getIm())));
        }
        else
        {
            //si un argument est composite on appelle evaluer pour determiner sa valeur avant de faire le calcul
            return addition(op1, op2.evaluer());
        }
    }
    //addition avec op1 RATIONNELLE
    if(op1.getType()==2) {
        if(op2.getType()==1)
        {
            return addition(op2,op1);
        }
        if(op2.getType()==2)
        {
            return *(new lRationnelle(dynamic_cast<const lRationnelle&>(op2).getDenominateur()*dynamic_cast<const lRationnelle&>(op1).getNumerateur()+
                                      dynamic_cast<const lRationnelle&>(op1).getDenominateur()*dynamic_cast<const lRationnelle&>(op2).getNumerateur(),
                                      dynamic_cast<const lRationnelle&>(op2).getDenominateur()*dynamic_cast<const lRationnelle&>(op1).getDenominateur()));
        }
        if(op2.getType()==3)
        {
            return *(new lReelle(dynamic_cast<const lReelle&>(op2).getValeur()+((float)dynamic_cast<const lRationnelle&>(op1).getNumerateur()/
                                                                                (float)dynamic_cast<const lRationnelle&>(op1).getDenominateur())));
        }
        if(op2.getType()==4)
        {
            return *(new lComplexe(&(addition(op1,dynamic_cast<const lComplexe&>(op2).getReelle())), &(dynamic_cast<const lComplexe&>(op2).getIm())));
        }
        else
        {
            return addition(op1, op2.evaluer());
        }
    }
   //addition avec Reelle
   if(op1.getType()==3)   {
        if(op2.getType()==1)
        {
            return addition(op2,op1);
        }
        if(op2.getType()==2)
        {
            float num=dynamic_cast<const lRationnelle&> (op2).getNumerateur()+dynamic_cast<const lRationnelle&> (op2).getDenominateur()*dynamic_cast<const lReelle&>(op1).getValeur();
            float den=dynamic_cast<const lRationnelle&>(op2).getDenominateur();
            return *(new lRationnelle(num, den));
        }
        if(op2.getType()==3)
        {
            return *(new lReelle(dynamic_cast<const lReelle&>(op1).getValeur()+dynamic_cast<const lReelle&>(op2).getValeur()));
        }
        if(op2.getType()==4)
        {
            return *(new lComplexe(&addition(dynamic_cast<const lComplexe&>(op2).getReelle(),op1),&(dynamic_cast<const lComplexe&>(op2).getIm())));
        }
        else
        {
            throw ComputerException("Erreur l'opérations entre les littérales demandées est inexistante, merci de saisir une opération valide");
        }
    }
    if(op1.getType()==4)
       if(op2.getType()==1)
       {
           return *(new lComplexe(&addition(op2,dynamic_cast<const lComplexe&>(op1).getReelle()),&(dynamic_cast<const lComplexe&>(op1).getIm())));
       }
       if(op2.getType()==2)
       {
           return *(new lComplexe(&addition(op2,dynamic_cast<const lComplexe&>(op1).getReelle()),&(dynamic_cast<const lComplexe&>(op1).getIm())));
       }
       if(op2.getType()==3)
       {
           return *(new lComplexe(&addition(dynamic_cast<const lComplexe&>(op1).getReelle(),op2),
                                  &(dynamic_cast<const lComplexe&>(op1).getIm())));
       }
       if(op2.getType()==4)
       {
           return *(new lComplexe(&addition(dynamic_cast<const lComplexe&>(op1).getReelle(),dynamic_cast<const lComplexe&>(op2).getReelle()),
                                  &addition(dynamic_cast<const lComplexe&>(op1).getIm(),dynamic_cast<const lComplexe&>(op2).getIm())));
       }
       else
       {
           throw ComputerException("Erreur l'opérations entre les littérales demandées est inexistante, merci de saisir une opération valide");
       }

}


litterale& Soustraction::soustraction(litterale& op1, litterale&op2)  {
    //soustraction avec op1 ENTIER
    if(op1.getType()>4) {
        if(op2.getType()>4) { // les deux membres sont composites
            return soustraction(op1.evaluer(),op2.evaluer());
        }   return soustraction(op1.evaluer(),op2); //seul op1 est composite
    } else if(op2.getType()>4) {
            return soustraction(op1,op2.evaluer()); //seul op2 est composite
    }      //sinon on est dans un cas classique d'operation entre deux feuilles comme ci dessous
    if(op1.getType()==1) {
        if(op2.getType()==1)
        {
            return *(new lEntiere(dynamic_cast<const lEntiere&>(op1).getValeur()-dynamic_cast<const lEntiere&>(op2).getValeur()));
        }

        if(op2.getType()==2)
        {
            int num=dynamic_cast<const lRationnelle&> (op2).getDenominateur()*dynamic_cast<const lEntiere&>(op1).getValeur()-dynamic_cast<const lRationnelle&> (op2).getNumerateur();
            int den=dynamic_cast<const lRationnelle&>(op2).getDenominateur();
            return *(new lRationnelle(num, den));
        }
        if(op2.getType()==3)
        {
            return *(new lReelle((float)(dynamic_cast<const lEntiere&>(op1).getValeur()-dynamic_cast<const lReelle&>(op2).getValeur())));
        }
        if(op2.getType()==4)
        {
            return *(new lComplexe(&(soustraction(dynamic_cast<const lComplexe&>(op2).getReelle(),op1)),&(dynamic_cast<const lComplexe&>(op2).getIm())));
        }
        else
        {
            throw ComputerException("Erreur l'opérations entre les littérales demandées est inexistante, merci de saisir une opération valide");
        }
    }
    //soustraction avec op1 RATIONNELLE
    if(op1.getType()==2) {
        if(op2.getType()==1)
        {
            int num=dynamic_cast<const lRationnelle&> (op1).getNumerateur()-dynamic_cast<const lRationnelle&> (op1).getDenominateur()*dynamic_cast<const lEntiere&>(op2).getValeur();
            int den=dynamic_cast<const lRationnelle&>(op1).getDenominateur();
            return *(new lRationnelle(num, den));
        }
        if(op2.getType()==2)
        {
            return *(new lRationnelle(dynamic_cast<const lRationnelle&>(op2).getDenominateur()*dynamic_cast<const lRationnelle&>(op1).getNumerateur()-
                                      dynamic_cast<const lRationnelle&>(op1).getDenominateur()*dynamic_cast<const lRationnelle&>(op2).getNumerateur(),
                                      dynamic_cast<const lRationnelle&>(op2).getDenominateur()*dynamic_cast<const lRationnelle&>(op1).getDenominateur()));
        }
        if(op2.getType()==3)
        {
            return *(new lReelle((float)dynamic_cast<const lRationnelle&>(op1).getNumerateur()/
                                 (float)dynamic_cast<const lRationnelle&>(op1).getDenominateur()-dynamic_cast<const lReelle&>(op2).getValeur()));
        }
        if(op2.getType()==4)
        {
            return *(new lComplexe(&(soustraction(op1,dynamic_cast<const lComplexe&>(op2).getReelle())), &(dynamic_cast<const lComplexe&>(op2).getIm())));
        }
        else
        {
            throw ComputerException("Erreur l'opérations entre les littérales demandées est inexistante, merci de saisir une opération valide");
        }
    }
   //soustraction avec Reelle
   if(op1.getType()==3)   {
        if(op2.getType()==1)
        {
            return soustraction(op2,op1);
        }
        if(op2.getType()==2)
        {
            float num=dynamic_cast<const lRationnelle&> (op2).getDenominateur()*dynamic_cast<const lReelle&>(op1).getValeur()-dynamic_cast<const lRationnelle&> (op2).getNumerateur();
            float den=dynamic_cast<const lRationnelle&>(op2).getDenominateur();
            return *(new lRationnelle(num, den));
        }
        if(op2.getType()==3)
        {
            return *(new lReelle(dynamic_cast<const lReelle&>(op1).getValeur()-dynamic_cast<const lReelle&>(op2).getValeur()));
        }
        if(op2.getType()==4)
        {
            return *(new lComplexe(&soustraction(op1,dynamic_cast<const lComplexe&>(op2).getReelle()),&(dynamic_cast<const lComplexe&>(op2).getIm())));
        }
        else
        {
            throw ComputerException("Erreur l'opérations entre les littérales demandées est inexistante, merci de saisir une opération valide");
        }
    }
    //soustraction avec complexe
    if(op1.getType()==4)
       if(op2.getType()==1)
       {
           return *(new lComplexe(&soustraction(dynamic_cast<const lComplexe&>(op1).getReelle(),op2),&(dynamic_cast<const lComplexe&>(op1).getIm())));
       }
       if(op2.getType()==2)
       {
           return *(new lComplexe(&soustraction(dynamic_cast<const lComplexe&>(op1).getReelle(),op2),&(dynamic_cast<const lComplexe&>(op1).getIm())));
       }
       if(op2.getType()==3)
       {
           return *(new lComplexe(&soustraction(dynamic_cast<const lComplexe&>(op1).getReelle(),op2),
                                  &(dynamic_cast<const lComplexe&>(op1).getIm())));
       }
       if(op2.getType()==4)
       {
           return *(new lComplexe(&soustraction(dynamic_cast<const lComplexe&>(op1).getReelle(),dynamic_cast<const lComplexe&>(op2).getReelle()),
                                  &soustraction(dynamic_cast<const lComplexe&>(op1).getIm(),dynamic_cast<const lComplexe&>(op2).getIm())));
       }
        else
       {
           throw ComputerException("Erreur l'opérations entre les littérales demandées est inexistante, merci de saisir une opération valide");
       }
}
litterale& Multiplication::multiplication(litterale& op1, litterale&op2) {
    if(op1.getType()==1) {
        if(op2.getType()==1)
        {
            return *(new lEntiere(dynamic_cast<const lEntiere&>(op1).getValeur()*dynamic_cast<const lEntiere&>(op2).getValeur()));
        }

        if(op2.getType()==2)
        {
            int num=dynamic_cast<const lEntiere&>(op1).getValeur()*dynamic_cast<const lRationnelle&> (op2).getNumerateur();
            int den=dynamic_cast<const lRationnelle&>(op2).getDenominateur();
            return *(new lRationnelle(num, den));
        }
        if(op2.getType()==3)
        {
            return *(new lReelle((float)(dynamic_cast<const lEntiere&>(op1).getValeur()*dynamic_cast<const lReelle&>(op2).getValeur())));
        }
        if(op2.getType()==4)
        {
            return *(new lComplexe(&(multiplication(dynamic_cast<const lComplexe&>(op2).getReelle(),op1)),&(dynamic_cast<const lComplexe&>(op2).getIm())));
        }
        else
        {
            throw ComputerException("Erreur l'opérations entre les littérales demandées est inexistante, merci de saisir une opération valide");
        }

    }
    if(op1.getType()==2) {
        if(op2.getType()==1)
        {
            return multiplication(op2,op1);
        }
        if(op2.getType()==2)
        {
            return *(new lRationnelle(dynamic_cast<const lRationnelle&>(op1).getNumerateur()*dynamic_cast<const lRationnelle&>(op2).getNumerateur(),
                                      dynamic_cast<const lRationnelle&>(op1).getDenominateur()*dynamic_cast<const lRationnelle&>(op2).getDenominateur()));
        }
        if(op2.getType()==3)
        {
            return *(new lReelle((((float)dynamic_cast<const lRationnelle&>(op1).getNumerateur()/(float)dynamic_cast<const lRationnelle&>(op1).getDenominateur()))
                                 *dynamic_cast<const lReelle&>(op2).getValeur()));
        }
        if(op2.getType()==4)
        {
            return *(new lComplexe(&multiplication(op1,dynamic_cast<const lComplexe&>(op2).getReelle()),&multiplication(op1,dynamic_cast<const lComplexe&>(op2).getIm())));
        }
        else
        {
            throw ComputerException("Erreur l'opérations entre les littérales demandées est inexistante, merci de saisir une opération valide");
        }
    }

    if(op1.getType()==3) {
        //multiplication avec ENTIER
        if(op2.getType()==1)
        {
            return multiplication(op2,op1);
        }
        //multiplication avec RATIONNEL
        if(op2.getType()==2)
        {
            return multiplication(op2,op1);
        }
        if(op2.getType()==3)
        {
            return *(new lReelle(dynamic_cast<const lReelle&>(op1).getValeur()*dynamic_cast<const lReelle&>(op2).getValeur()));
        }
        if(op2.getType()==4)
        {
            return *(new lComplexe(&multiplication(op1,dynamic_cast<const lComplexe&>(op2).getReelle()),&multiplication(op1,dynamic_cast<const lComplexe&> (op2).getIm())));
        }
         else
        {
            throw ComputerException("Erreur l'opérations entre les littérales demandées est inexistante, merci de saisir une opération valide");
        }
    }
    if(op1.getType()==4)  {
        if(op2.getType()==1)
        {
            return multiplication(op2,op1);
        }
        if(op2.getType()==2)
        {
            return multiplication(op2,op1);
        }
        if(op2.getType()==3)
        {
            return multiplication(op2,op1);
        }
        //OPERATION ICI FAUSSE, LA MULTIPLICATION DE DEUX COMPLEXES EST PLUS COMPLIQUEE QUE CA
        //(a+ib)(c+id)=(ac-bd)+i(ad+bc)
        if(op2.getType()==4)
        {
            return *(new lComplexe(&Soustraction::soustraction
                                   (multiplication(dynamic_cast<const lComplexe&>(op1).getReelle(),dynamic_cast<const lComplexe&>(op2).getReelle()),
                                    multiplication(dynamic_cast<const lComplexe&>(op1).getIm(),dynamic_cast<const lComplexe&>(op2).getIm())),
                                   &Addition::addition
                                   (multiplication(dynamic_cast<const lComplexe&>(op1).getReelle(),dynamic_cast<const lComplexe&>(op2).getIm()),
                                    multiplication(dynamic_cast<const lComplexe&>(op1).getIm(),dynamic_cast<const lComplexe&>(op2).getReelle()))));
        }
         else
        {
            throw ComputerException("Erreur l'opérations entre les littérales demandées est inexistante, merci de saisir une opération valide");
        }
    }
}
litterale& Division::division(litterale& op1, litterale&op2) {
    if(op1.getType()==1) {
        if(op2.getType()==1)
        {
            if(dynamic_cast<const lEntiere&>(op1).getValeur()%dynamic_cast<const lEntiere&>(op2).getValeur()==0)
                return *(new lEntiere(dynamic_cast<const lEntiere&>(op1).getValeur()/dynamic_cast<const lEntiere&>(op2).getValeur()));
            else return *(new lRationnelle(dynamic_cast<const lEntiere&>(op1).getValeur(), dynamic_cast<const lEntiere&>(op2).getValeur()));

        }
        if(op2.getType()==2)
        {   //diviser c'est multiplier par l'inverse

            return *(new lRationnelle(dynamic_cast<const lRationnelle&>(Multiplication::multiplication(op1,
                   *(new lRationnelle(dynamic_cast<const lRationnelle&>(op2).getDenominateur(),dynamic_cast<const lRationnelle&>(op2).getNumerateur()))))));
        }
        if(op2.getType()==3)
        {
            return *(new lReelle((float)dynamic_cast<const lEntiere&>(op1).getValeur()/dynamic_cast<const lReelle&>(op2).getValeur()));
        }
        if(op2.getType()==4)
        {
            return *(new lComplexe(&division(op1,dynamic_cast<const lComplexe&>(op2).getReelle()),&division(op1,dynamic_cast<const lComplexe&>(op2).getIm())));
        }
        else
        {
            throw ComputerException("Erreur l'opérations entre les littérales demandées est inexistante, merci de saisir une opération valide");
        }
    }
    if(op1.getType()==2) {
        if(op2.getType()==1)
        {
             return *(new lRationnelle(dynamic_cast<const lRationnelle&>(op1).getNumerateur(),dynamic_cast<const lEntiere&>(op2).getValeur()*dynamic_cast<const lRationnelle&>(op1).getDenominateur()));
        }
        if(op2.getType()==2)
        {   //diviser c'est multiplier par l''inverse #j'aimelesmaths
            return *(new lRationnelle(dynamic_cast<const lRationnelle&>(Multiplication::multiplication(op1,*new lRationnelle(dynamic_cast<const lRationnelle&>(op2).getDenominateur(),dynamic_cast<const lRationnelle&>(op2).getNumerateur())))));
        }
        if(op2.getType()==3)
        {
            return *(new lReelle(((float)dynamic_cast<const lRationnelle&>(op1).getNumerateur()/(float)dynamic_cast<const lRationnelle&>(op1).getDenominateur())/
                                                            dynamic_cast<const lReelle&>(op2).getValeur()));
        }
        if(op2.getType()==4)
        {
            return *(new lComplexe(&division(op1,dynamic_cast<const lComplexe&>(op2).getReelle()),&division(op1,dynamic_cast<const lComplexe&>(op2).getIm())));
        }
        else
        {
            throw ComputerException("Erreur l'opérations entre les littérales demandées est inexistante, merci de saisir une opération valide");
        }
    }
    if(op1.getType()==3) {
        if(op2.getType()==1)
        {
            return *(new lReelle(dynamic_cast<const lReelle&>(op1).getValeur()*(float)dynamic_cast<const lEntiere&>(op2).getValeur()));
        }
        if(op2.getType()==2)
        {
            return *(new lReelle(dynamic_cast<const lReelle&>(Multiplication::multiplication(op1, *new lRationnelle(dynamic_cast<const lRationnelle&>(op2).getDenominateur(),dynamic_cast<const lRationnelle&>(op2).getNumerateur())))));
        }
        if(op2.getType()==3)
        {
            return *(new lReelle(dynamic_cast<const lReelle&>(op1).getValeur()*dynamic_cast<const lReelle&>(op2).getValeur()));
        }
        if(op2.getType()==4)
        {
            return *(new lComplexe(&division(op1,dynamic_cast<const lComplexe&>(op2).getReelle()),&division(op1,dynamic_cast<const lComplexe&>(op2).getIm())));
        }
         else
        {
            throw ComputerException("Erreur l'opérations entre les littérales demandées est inexistante, merci de saisir une opération valide");
        }
    }
    if(op1.getType()==4) {
        if(op2.getType()==1)
        {
            return *(new lComplexe(division(dynamic_cast<const lComplexe&>(op1).getReelle(),op2),division(dynamic_cast<const lComplexe&>(op1).getIm(),op2)));
        }
         if(op2.getType()==2)
        {
            return *(new lComplexe(division(dynamic_cast<const lComplexe&>(op1).getReelle(),op2),division(dynamic_cast<const lComplexe&>(op1).getIm(),op2)));
        }
        if(op2.getType()==3)
        {
            return *(new lComplexe(division(dynamic_cast<const lComplexe&>(op1).getReelle(),op2),division(dynamic_cast<const lComplexe&>(op1).getIm(),op2)));
        }
        //OPERATION ICI FAUSSE, LA DIVISION DE DEUX COMPLEXES EST PLUS COMPLIQUEE QUE CA
        //
        if(op2.getType()==4)
        {
            return *(new lComplexe(division(dynamic_cast<const lComplexe&>(op1).getReelle(),dynamic_cast<const lComplexe&>(op2).getReelle()),division(dynamic_cast<const lComplexe&>(op1).getIm(),dynamic_cast<const lComplexe&>(op2).getIm())));
        }
         else
        {
            throw ComputerException("Erreur l'opérations entre les littérales demandées est inexistante, merci de saisir une opération valide");
        }
    }
}







void Pile::agrandissementCapacite() {
    litterale** newtab=new litterale* [(nbMax+1)*2];
    for(unsigned int i=0; i<nb; i++) newtab[i]=tab[i];
    litterale**  old=tab;
    tab=newtab;
    nbMax=(nbMax+1)*2;
    //delete old;
    //delete[] old;
}

//methode pour empiler une litterale
void Pile::push(litterale& l)
{
    if(nb==nbMax)
        agrandissementCapacite();
    tab[nb]=&l;
    nb++;
    modificationEtat();
}

//methode pour depiler une litterale de la pile
void Pile::pop()
{
    if(estVide()){
        throw ComputerException("erreur aucune litterale à dépiler la pile est vide");
    }
    else tab[nb--]=nullptr;
    //modificationEtat();
}
litterale& Pile::top() const
{
    if (estVide()) throw ComputerException("aucune expression sur la pile");
    return *tab[nb-1];
}


void Historique::agrandissementCapacite() {
    Pile** newtab=new Pile * [(nbMax+1)*2];
    for(unsigned int i=0; i<nb; i++) newtab[i]=historique[i];
    Pile**  old=historique;
    historique=newtab;
    nbMax=(nbMax+1)*2;
    delete [] old;

}

litteraleManager::Handler litteraleManager::handler=litteraleManager::Handler();
Pile::Handler Pile::handler=Pile::Handler();
Controleur::Handler Controleur::handler=Controleur::Handler();
Historique::Handler Historique::handler=Historique::Handler();

Historique& Historique::getInstance() {
    if(handler.instance==0)
        handler.instance=new Historique;
    return *handler.instance;
}

void Historique::libererInstance() {
    delete handler.instance;
    handler.instance=0;
}

Controleur& Controleur::getInstance(){
    if(handler.instance==0)
        handler.instance=new Controleur;
    return *handler.instance;
}
void Controleur::libererInstance(){
    delete handler.instance;
    handler.instance=0;
}


Pile& Pile::getInstance(){
    if(handler.instance==0)
        handler.instance=new Pile;
    return  *handler.instance;
}

void Pile::libererInstance(){
    delete handler.instance;
    handler.instance=0;
}


litteraleManager& litteraleManager::getInstance(){
    if (handler.instance==0) handler.instance=new litteraleManager;
    return *handler.instance;
}

void litteraleManager::libererInstance(){
    delete handler.instance;
    handler.instance=0;
}

/*
QString  litterale::toString() const {
    return QString::number(value);
}
*/
void litteraleManager::agrandissementCapacite() {
    litterale** newtab=new litterale*[(nbMax+1)*2];
    for(unsigned int i=0; i<nb; i++) newtab[i]=litt[i];
    litterale**  old=litt;
    litt=newtab;
    nbMax=(nbMax+1)*2;
    delete old;
}

litterale& litteraleManager::addLitterale(int v){
    if (nb==nbMax) agrandissementCapacite();
    litt[nb++]=new lEntiere(v);
    return *litt[nb-1];
}

litterale& litteraleManager::addLitterale(int num, int den){
    if (nb==nbMax) agrandissementCapacite();
    litt[nb++]=new lRationnelle(num,den);
    return *litt[nb-1];
}

litterale& litteraleManager::addLitterale(float v){
    if (nb==nbMax) agrandissementCapacite();
    litt[nb++]=new lReelle(v);
    return *litt[nb-1];
}

litterale& litteraleManager::addLitterale(litterale& re,litterale& im){
    if (nb==nbMax) agrandissementCapacite();
    litt[nb++]=new lComplexe(&re,&im);
    return *litt[nb-1];
}

litterale& litteraleManager::addLitterale(litterale& target) {
    if (nb==nbMax) agrandissementCapacite();
    litt[nb++]=&target;
    return target;
}


void litteraleManager::removeLitterale(litterale& e){
    //i nombre de valeurs restant à parcourir
    unsigned int i=nb;
    iterator it=begin();
    //comparaison entre la valeur itérée et la valeur à supprimer
    while(*it!=&e) {
        i--;
        ++it;
    }
    //pas de test de sortie à faire, si on a pas la bonne valeur on ne sort pas
    if((*it)->getType()==4){ //si c'est un complexe on doit d'abord supprimer les parties Reelle et imaginaire
        delete &dynamic_cast<const lComplexe*>(*it)->getReelle();
        delete &dynamic_cast<const lComplexe*>(*it)->getIm();
    }
    delete *it;
    nb--;
    //on a supprimé le ieme-1 élément
    while(i<=nb){
        litt[i-1]=litt[i]; //on décale tous les termes empilés au dessus
        i++;
    }

}


litteraleManager::~litteraleManager(){
    for(unsigned int i=0; i<nb; i++) delete litt[i];
    delete[] litt;
}

//renvoie vrai si la chaine passée est un nombre
bool estUnNombre(const QString s){
   bool ok=false;
   s.toInt(&ok);
   s.toFloat(&ok);
   return ok;
}
// Il faut utiliser les regex pour reconnaitre les autres types de littérale -> a voir !
// Non enfait le design interpreter peut faire le job

//renvoie vrai si la chaine passée est un opérateur
bool estUnOperateur(const QString s){
    if (s=="+") return true;
    if (s=="-") return true;
    if (s=="*") return true;
    if (s=="/") return true;
    if (s=="$") return true;
    if(s=="DROP") return true;
    if(s=="SWAP") return true;
    if(s=="CLEAR") return true;
    if(s=="DUP") return true;
    if(s=="UNDO") return true;
    return false;
}

//fonction dont le role est de traiter
//les expressions passées par le QLineEdit


void Controleur::commande(const QString& c){

    //on suppose qu'on récupère un entier et qu'on l'empile
    //créé et empile la nouvelle littérale sur la pile
    if(estUnNombre(c))   {
        log->push(*littAff); //empilement de la pile dans l'historique
        if(c.toInt()) littAff->push(littMng->addLitterale(c.toInt()));
        else littAff->push(littMng->addLitterale(c.toFloat()));
    }
    //si on a saisit un opérateur alors on depile deux littérales, on fait le calcul et on empile le résultat
    if(estUnOperateur(c))
    {

        log->push(*littAff); //empilement de la pile dans l'historique en vue d'un changement d'état
        if(c.toStdString()=="UNDO" && !log->estVide()) {

        }
        if(littAff->taille()>=1)
        {
            // Fonctionne pas chez moi
            if(c.toStdString()=="DROP") {
                litterale& detruire=littAff->top();
                littAff->pop();
                littMng->removeLitterale(detruire);
                littAff->setMessage("La dernière littérale entrée a été supprimée.");
                modifMessage();
            }
            //Fonctionne pas chez moi
            if(c.toStdString()=="CLEAR") {
                while(!littAff->estVide()) {
                   litterale& detruire=littAff->top();
                   littAff->pop();
                   littMng->removeLitterale(detruire);
                }
                littAff->setMessage("La pile a été vidée. ");
                modifMessage();
            }
            if(c.toStdString()=="DUP") { //NOTE: on ne duplique pas la litterale dans l'expressionManager
                litterale& copie=littAff->top();
                littAff->push(copie);
                littAff->setMessage("La dernière littérale entrée a été dupliquée. ");
                modifMessage();
            }
        }

        //on teste si on a au moins deux opérateurs
        if(littAff->taille()>=2)
        {
            if(c.toStdString()=="+")
            {

                litterale& op1=littAff->top();
                littAff->pop();
                litterale& op2=littAff->top();
                littAff->pop();
                littAff->push(littMng->addLitterale(Addition::addition(op2,op1)));
                if(littAff->top().getType()!=4){
                  littMng->removeLitterale(op1);
                  littMng->removeLitterale(op2);
                }
                littAff->setMessage("Addition effectuée");
                modifMessage();

            }
            if(c.toStdString()=="-")
            {
                litterale& op1=littAff->top();
                littAff->pop();
                litterale& op2=littAff->top();
                littAff->pop();
                littAff->push(littMng->addLitterale(Soustraction::soustraction(op2,op1)));
                if(littAff->top().getType()!=4){
                  littMng->removeLitterale(op1);
                  littMng->removeLitterale(op2);
                }
                littAff->setMessage("Soustraction effectuée");
                modifMessage();

            }
            if(c.toStdString()=="*")
            {

                litterale& op1=littAff->top();
                littAff->pop();
                litterale& op2=littAff->top();
                littAff->pop();
                littAff->push(littMng->addLitterale(Multiplication::multiplication(op2,op1)));
                if(littAff->top().getType()!=4){
                  littMng->removeLitterale(op1);
                  littMng->removeLitterale(op2);
                }
                littAff->setMessage("Multiplication effectuée");
                modifMessage();

            }
            if(c.toStdString()=="/")
            {
                litterale& op1=littAff->top();
                littAff->pop();
                litterale& op2=littAff->top();
                littAff->pop();
                littAff->push(littMng->addLitterale(Division::division(op2,op1)));
                if(littAff->top().getType()!=4){
                   littMng->removeLitterale(op1);
                   littMng->removeLitterale(op2);
                }
                littAff->setMessage("Division effectuée");
                modifMessage();


            }
            if(c.toStdString()=="$")
            {
                littAff->setMessage("");
                litterale& op1=littAff->top();
                littAff->pop();
                litterale& op2=littAff->top();
                littAff->pop();
                littAff->push(littMng->addLitterale(op2,op1));
                //on ne detruit pas les litterales qui font partie de la nouvelle littérale complexe
                //car la littérale complexe pointe sur ces littérales
                //littMng->removeLitterale(op1);
                //littMng->removeLitterale(op2);
                littAff->setMessage("Un complexe vient d'être créée.");
                modifMessage();
            }
            if(c.toStdString()=="SWAP") {
                litterale& op1=littAff->top();
                littAff->pop();
                litterale& op2=littAff->top();
                littAff->pop();
                littAff->push(littMng->addLitterale(op1));
                littAff->push(littMng->addLitterale(op2));
                littAff->setMessage("Les deux derniers éléments ont été inversés.");
                modifMessage();
            }
            //littAff->setMessage("operation réalisée avec succès");
            //modificationEtat();

        } else {
            littAff->setMessage("Pas assez d'opérandes");
            modifMessage();
        }
}
}




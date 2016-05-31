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
            cout<<"valeur de l'entier créé" <<dynamic_cast<const lEntiere&>(op2).getValeur()+dynamic_cast<const lEntiere&>(op1).getValeur();
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
    if(op1.getType()>4) {
        if(op2.getType()>4) { // les deux membres sont composites
            return multiplication(op1.evaluer(),op2.evaluer());
        }   return multiplication(op1.evaluer(),op2); //seul op1 est composite
    } else if(op2.getType()>4) {
            return multiplication(op1,op2.evaluer()); //seul op2 est composite
    }      //sinon on est dans un cas classique d'operation entre deux feuilles comme ci dessous
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
    if(op1.getType()>4) {
        if(op2.getType()>4) { // les deux membres sont composites
            return division(op1.evaluer(),op2.evaluer());
        }   return division(op1.evaluer(),op2); //seul op1 est composite
    } else if(op2.getType()>4) {
            return division(op1,op2.evaluer()); //seul op2 est composite
    }      //sinon on est dans un cas classique d'operation entre deux feuilles comme ci dessous
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



unsigned int traitement(string expression) {

    bool operateur= false; //teste si on a bien un operateur dans la chaine
    unsigned int i=0;
    unsigned int compteur=0;
    unsigned int compteurParenthese=0; //plus cette valeur est élevée, plus on est susceptible de tomber sur un opérateur hautement prioritaire
    unsigned int prioriteOperateur=2000; //plus cette valeur est eleve plus l'operateur est prioritaire, le premier operateur trouvé etant forcemment le moins proritaire au debut

    //boucle de recherche de l'operateur le moins prioritaire dans la chaine
    while(compteur<expression.size()){
        if(expression[compteur]=='(')
            compteurParenthese++;
        if(expression[compteur]==')')
            compteurParenthese--;
        //premier cas, l'operateur trouvé est quelconque et la priorite dans le parenthesage est strictement superieure
        if(((expression[compteur]=='+' || expression[compteur]=='-' || expression[compteur]=='*' || expression[compteur]=='/' || expression[compteur]=='$') && prioriteOperateur>compteurParenthese)
           //deuxieme cas l'operateur a le meme niveau de parenthesage mais est plus prioritaire en terme mathematique
           //en cas d'egalité les operateurs les plus à doite sont les plus prioritaires
            ||  ((expression[compteur]=='+' || expression[compteur]=='-' || expression[compteur]=='$') && prioriteOperateur>= compteurParenthese)) {
                prioriteOperateur=compteurParenthese;
                i=compteur;
                operateur=true;

        }
        compteur++;
    }
    cout<< "valeur retournée i="<< i<< "\n";
    cout<< "operateur correspondant=" <<expression[i]<< "\n";
    if (operateur==true) return i; else  return  0;
}
void test(int afficher){
    cout<<afficher;
}

Addition::Addition(string expression) {
    type=5;
    unsigned int test=traitement(expression); //pour connaitre l'endroit où on doit faire la coupure
    unsigned int taille= expression.size();

    char* copie= (char*)expression.c_str();
    char* dest1= new char[test-1];
    //copie des test-1 premier caracteres dans la chaine op1.

    char* str1=strncpy(dest1,copie, (test)*sizeof(char));
    string sOp1(str1); //il existe un constructeur de string qui prend en parametre un char * et qui fait la conversion automatique

    string sOp2=expression.substr(test+1,taille-test);
    //reste à tester si op1 et op2 sont des composites ou des litterales

    unsigned int test1= traitement(sOp1);
    unsigned int test2= traitement(sOp2);

    if(test1==0) { // alors on est sur une feuille
        if(estUnEntier(sOp1))
                op1= new lEntiere(stoi(sOp1));
            else
                op1= new lReelle(stof(sOp1));// throw "erreur";}

    }
    if(sOp1[0]=='(')  {sOp1=sOp1.substr(1,sOp1.size()-2);
                        test1--;}
    if(sOp1[test1]=='+')  op1= new Addition(sOp1);
    if(sOp1[test1]=='-')  op1= new Soustraction(sOp1);
    if(sOp1[test1]=='*')  op1= new Multiplication(sOp1);
    if(sOp1[test1]=='/')  op1= new Division(sOp1);
    if(sOp1[test1]=='$')  op1= new lComplexe(sOp1);

    if(test2==0) { // alors on est sur une feuille
        if(estUnEntier(sOp2))
                op2= new lEntiere(stoi(sOp2));
            else
                op2= new lReelle(stof(sOp2));// throw "erreur";} 
    }
    if(sOp2[0]=='(') { sOp2=sOp2.substr(1,sOp2.size()-2);
                        test2--;}
    if(sOp2[test2]=='+') op2= new Addition(sOp2);
    if(sOp2[test2]=='-') op2= new Soustraction(sOp2);
    if(sOp2[test2]=='*') op2= new Multiplication(sOp2);
    if(sOp2[test2]=='/') op2= new Division(sOp2);
    if(sOp2[test2]=='$') op2= new lComplexe(sOp2);
}

Soustraction::Soustraction(string expression) {
    type=6;
    unsigned int test=traitement(expression); //pour connaitre l'endroit où on doit faire la coupure
    unsigned int taille= expression.size();

    char* copie= (char*)expression.c_str();
    char* dest1= new char[test-1];
    //copie des test-1 premier caracteres dans la chaine op1.

    char* str1=strncpy(dest1,copie, (test)*sizeof(char));
    string sOp1(str1); //il existe un constructeur de string qui prend en parametre un char * et qui fait la conversion automatique

    string sOp2=expression.substr(test+1,taille-test);
    //reste à tester si op1 et op2 sont des composites ou des litterales

    unsigned int test1= traitement(sOp1);
    unsigned int test2= traitement(sOp2);

    if(test1==0) { // alors on est sur une feuille
        if(estUnEntier(sOp1))
                op1= new lEntiere(stoi(sOp1));
            else
                op1= new lReelle(stof(sOp1));// throw "erreur";}

    }
    if(sOp1[0]=='(')  {sOp1=sOp1.substr(1,sOp1.size()-2);
                        test1--;}
    if(sOp1[test1]=='+')  op1= new Addition(sOp1);
    if(sOp1[test1]=='-')  op1= new Soustraction(sOp1);
    if(sOp1[test1]=='*')  op1= new Multiplication(sOp1);
    if(sOp1[test1]=='/')  op1= new Division(sOp1);
    if(sOp1[test1]=='$')  op1= new lComplexe(sOp1);

    if(test2==0) { // alors on est sur une feuille
        if(estUnEntier(sOp2))
                op2= new lEntiere(stoi(sOp2));
            else
                op2= new lReelle(stof(sOp2));// throw "erreur";}
    }if(sOp2[0]=='(') { sOp2=sOp2.substr(1,sOp2.size()-2);
        test2--;}
    if(sOp2[test2]=='+') op2= new Addition(sOp2);
    if(sOp2[test2]=='-') op2= new Soustraction(sOp2);
    if(sOp2[test2]=='*') op2= new Multiplication(sOp2);
    if(sOp2[test2]=='/') op2= new Division(sOp2);
    if(sOp2[test2]=='$') op2= new lComplexe(sOp2);
}


Multiplication::Multiplication(string expression) {
    type=7;
    unsigned int test=traitement(expression); //pour connaitre l'endroit où on doit faire la coupure
    unsigned int taille= expression.size();

    char* copie= (char*)expression.c_str();
    char* dest1= new char[test-1];
    //copie des test-1 premier caracteres dans la chaine op1.

    char* str1=strncpy(dest1,copie, (test)*sizeof(char));
    string sOp1(str1); //il existe un constructeur de string qui prend en parametre un char * et qui fait la conversion automatique

    string sOp2=expression.substr(test+1,taille-test);
    //reste à tester si op1 et op2 sont des composites ou des litterales

    unsigned int test1= traitement(sOp1);
    unsigned int test2= traitement(sOp2);

    if(test1==0) { // alors on est sur une feuille
        if(estUnEntier(sOp1))
                op1= new lEntiere(stoi(sOp1));
            else
                op1= new lReelle(stof(sOp1));// throw "erreur";}

    } if(sOp1[0]=='(')  {sOp1=sOp1.substr(1,sOp1.size()-2);
        test1--;}
    if(sOp1[test1]=='+')  op1= new Addition(sOp1);
    if(sOp1[test1]=='-')  op1= new Soustraction(sOp1);
    if(sOp1[test1]=='*')  op1= new Multiplication(sOp1);
    if(sOp1[test1]=='/')  op1= new Division(sOp1);
    if(sOp1[test1]=='$')  op1= new lComplexe(sOp1);

    if(test2==0) { // alors on est sur une feuille
        if(estUnEntier(sOp2))
                op2= new lEntiere(stoi(sOp2));
            else
                op2= new lReelle(stof(sOp2));// throw "erreur";}
    }if(sOp2[0]=='(') { sOp2=sOp2.substr(1,sOp2.size()-2);
        test2--;}
    if(sOp2[test2]=='+') op2= new Addition(sOp2);
    if(sOp2[test2]=='-') op2= new Soustraction(sOp2);
    if(sOp2[test2]=='*') op2= new Multiplication(sOp2);
    if(sOp2[test2]=='/') op2= new Division(sOp2);
    if(sOp2[test2]=='$') op2= new lComplexe(sOp2);
}
Division::Division(string expression) {
    type=8;
    unsigned int test=traitement(expression); //pour connaitre l'endroit où on doit faire la coupure
    unsigned int taille= expression.size();

    char* copie= (char*)expression.c_str();
    char* dest1= new char[test-1];
    //copie des test-1 premier caracteres dans la chaine op1.

    char* str1=strncpy(dest1,copie, (test)*sizeof(char));
    string sOp1(str1); //il existe un constructeur de string qui prend en parametre un char * et qui fait la conversion automatique

    string sOp2=expression.substr(test+1,taille-test);
    //reste à tester si op1 et op2 sont des composites ou des litterales

    unsigned int test1= traitement(sOp1);
    unsigned int test2= traitement(sOp2);

    if(test1==0) { // alors on est sur une feuille
        if(estUnEntier(sOp1))
                op1= new lEntiere(stoi(sOp1));
            else
                op1= new lReelle(stof(sOp1));// throw "erreur";}

    }
    if(sOp1[0]=='(')  {sOp1=sOp1.substr(1,sOp1.size()-2);
                        test1--;}// si on a une parenthese en debut on tronque le premier caractere et on recupere test-2 caracteres pour ne pas recuperer la parenthese de fin
    if(sOp1[test1]=='+')  op1= new Addition(sOp1);
    if(sOp1[test1]=='-')  op1= new Soustraction(sOp1);
    if(sOp1[test1]=='*')  op1= new Multiplication(sOp1);
    if(sOp1[test1]=='/')  op1= new Division(sOp1);
    if(sOp1[test1]=='$')  op1= new lComplexe(sOp1);

    if(test2==0) { // alors on est sur une feuille
        if(estUnEntier(sOp2))
                op2= new lEntiere(stoi(sOp2));
            else
                op2= new lReelle(stof(sOp2));// throw "erreur";}
    }
    if(sOp2[0]=='(') { sOp2=sOp2.substr(1,sOp2.size()-2);
                        test2--;}
    if(sOp2[test2]=='+') op2= new Addition(sOp2);
    if(sOp2[test2]=='-') op2= new Soustraction(sOp2);
    if(sOp2[test2]=='*') op2= new Multiplication(sOp2);
    if(sOp2[test2]=='/') op2= new Division(sOp2);
    if(sOp2[test2]=='$') op2= new lComplexe(sOp2);
}

lComplexe::lComplexe(string expression) {
    type=4;
    unsigned int test=traitement(expression); //pour connaitre l'endroit où on doit faire la coupure
    unsigned int taille= expression.size();

    char* copie= (char*)expression.c_str();
    char* dest1= new char[test-1];
    //copie des test-1 premier caracteres dans la chaine op1.

    char* str1=strncpy(dest1,copie, (test)*sizeof(char));
    string sOp1(str1); //il existe un constructeur de string qui prend en parametre un char * et qui fait la conversion automatique

    string sOp2=expression.substr(test+1,taille-test);
    //reste à tester si op1 et op2 sont des composites ou des litterales

    unsigned int test1= traitement(sOp1);
    unsigned int test2= traitement(sOp2);

    if(test1==0) { // alors on est sur une feuille
        if(estUnEntier(sOp1))
                reelle= new lEntiere(stoi(sOp1));
            else
                reelle= new lReelle(stof(sOp1));// throw "erreur";}

    }
    if(sOp1[0]=='(')  {sOp1=sOp1.substr(1,sOp1.size()-2);
                        test1--;}
    if(sOp1[test1]=='+')  reelle= new Addition(sOp1);
    if(sOp1[test1]=='-')  reelle= new Soustraction(sOp1);
    if(sOp1[test1]=='*')  reelle= new Multiplication(sOp1);
    if(sOp1[test1]=='/')  reelle= new Division(sOp1);
    if(sOp1[test1]=='$')  reelle= new lComplexe(sOp1);

    if(test2==0) { // alors on est sur une feuille
        if(estUnEntier(sOp2))
                imaginaire= new lEntiere(stoi(sOp2));
            else
                imaginaire= new lReelle(stof(sOp2));// throw "erreur";}
    }if(sOp2[0]=='(') { sOp2=sOp2.substr(1,sOp2.size()-2);
        test2--;}
    if(sOp2[test2]=='+') imaginaire= new Addition(sOp2);
    if(sOp2[test2]=='-') imaginaire= new Soustraction(sOp2);
    if(sOp2[test2]=='*') imaginaire= new Multiplication(sOp2);
    if(sOp2[test2]=='/') imaginaire= new Division(sOp2);
    if(sOp2[test2]=='$') imaginaire= new lComplexe(sOp2);
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
    if(estVide())
        throw ComputerException("erreur aucune litterale à dépiler la pile est vide");
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
bool estUnEntier(string expression){
    QString qCopie = QString::fromStdString(expression);
    bool ok=false;
    qCopie.toInt(&ok);
    return ok;
}
bool estUnReel(string expression){
    QString qCopie= QString::fromStdString(expression);
    bool ok=false;
    qCopie.toFloat(&ok);
    return ok;
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
    if(estUnNombre(c)||estUnOperateur(c)){
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
                if(c.toStdString()=="DROP") {
                    litterale& detruire=littAff->top();
                    littAff->pop();
                    littMng->removeLitterale(detruire);
                }
                if(c.toStdString()=="CLEAR") {
                    while(!littAff->estVide()) {
                       litterale& detruire=littAff->top();
                       littAff->pop();
                       littMng->removeLitterale(detruire);
                    }
                }
                if(c.toStdString()=="DUP") { //NOTE: on ne duplique pas la litterale dans l'expressionManager
                    litterale& copie=littAff->top();
                    littAff->push(copie);
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

                }
                if(c.toStdString()=="$")
                {
                    littAff->setMessage("tentative de complexe");
                    modifMessage();
                    litterale& op1=littAff->top();
                    littAff->pop();
                    litterale& op2=littAff->top();
                    littAff->pop();
                    littAff->push(littMng->addLitterale(op2,op1));
                    //on ne detruit pas les litterales qui font partie de la nouvelle littérale complexe
                    //car la littérale complexe pointe sur ces littérales
                    //littMng->removeLitterale(op1);
                    //littMng->removeLitterale(op2);
                }
                if(c.toStdString()=="SWAP") {
                    litterale& op1=littAff->top();
                    littAff->pop();
                    litterale& op2=littAff->top();
                    littAff->pop();
                    littAff->push(op1);
                    littAff->push(op2);
                }
                //littAff->setMessage("operation réalisée avec succès");
                //modificationEtat();

            } else {

                littAff->setMessage("Le nombre d'opérandes stockées dans la pile n'est pas suffisant pour réaliser l'operation");
                modifMessage();
            }
        }
    } else {
    //la deuxieme partie traite les litterales expressions:
    //on suppose à ce stade que ce qui a été passé à la commande est une expression
    string test=c.toStdString();
    unsigned int testTraitement= traitement(test);
    if (c[testTraitement]=='+'){
            Addition resultat(test);
            littAff->push(littMng->addLitterale(resultat.evaluer()));            
        }
    if(c[testTraitement]=='-') {

            Soustraction resultat(c.toStdString());
            littAff->push(littMng->addLitterale(resultat.evaluer()));

        }
    if(c[testTraitement]=='*') {
            Multiplication resultat(c.toStdString());
            littAff->push(littMng->addLitterale(resultat.evaluer()));

        }
    if(c[testTraitement]=='/') {
            Division resultat(c.toStdString());
            littAff->push(littMng->addLitterale(resultat.evaluer()));
        }
    if(c[testTraitement]=='$') {
            lComplexe resultat(c.toStdString());
            littAff->push(littMng->addLitterale(resultat.evaluer()));
    }

}
}







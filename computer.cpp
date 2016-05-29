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
// OPERERATEURS DE CLASSE LITTERALE : INUTILISABLE
//Cause des avertissements à ne pas prendre en compte à la compilation
litterale& litterale::operator+(const litterale& op) const { throw ComputerException("erreur l'operations entre deux objets de la classe littérale de base est impossible");}
litterale& litterale::operator-(const litterale& op) const {throw ComputerException("erreur l'operations entre deux objets de la classe littérale de base est impossible");}
litterale& litterale::operator*(const litterale& op) const {throw ComputerException("erreur l'operations entre deux objets de la classe littérale de base est impossible");}
litterale& litterale::operator/(const litterale& op) const {throw ComputerException("erreur l'operations entre deux objets de la classe littérale de base est impossible");}

/*
// OPERATEURS DE LA CLASSE ENTIERE
litterale& lEntiere::operator+(const litterale& op) const
{
    if(op.getType()==1)
    {
        return *(new lEntiere(dynamic_cast<const lEntiere&> (op).valeur+valeur));
    }

    if(op.getType()==2)
    {
        int num=dynamic_cast<const lRationnelle&> (op).getNumerateur()+dynamic_cast<const lRationnelle&> (op).getDenominateur()*valeur;
        int den=dynamic_cast<const lRationnelle&>(op).getDenominateur();
        return *(new lRationnelle(num, den));
    }
    if(op.getType()==3)
    {
        return *(new lReelle((float)(valeur+dynamic_cast<const lReelle&>(op).getValeur())));
    }
    if(op.getType()==4)
    {
        return *(new lComplexe(&(dynamic_cast<const lComplexe&>(op).getReelle()+*this),&(dynamic_cast<const lComplexe&>(op).getIm())));
    }
    else
    {
        throw ComputerException("Erreur l'opérations entre les littérales demandées est inexistante, merci de saisir une opération valide");
    }
}
litterale& lEntiere::operator-(const litterale& op) const
{
    if(op.getType()==1)
    {
        return *(new lEntiere(valeur-dynamic_cast<const lEntiere&> (op).valeur));

    }
    if(op.getType()==2)
    {
        int num=dynamic_cast<const lRationnelle&> (op).getDenominateur()*valeur-dynamic_cast<const lRationnelle&> (op).getNumerateur();
        int den=dynamic_cast<const lRationnelle&>(op).getDenominateur();
        return *(new lRationnelle(num, den));
    }
    if(op.getType()==3)
    {
        return *(new lReelle((float)(valeur-dynamic_cast<const lReelle&>(op).getValeur())));
    }
    if(op.getType()==4)
    {
        return *(new lComplexe(&(*this-dynamic_cast<const lComplexe&>(op).getReelle()),&(dynamic_cast<const lComplexe&>(op).getIm())));
    }
     else
    {
        throw ComputerException("Erreur l'opérations entre les littérales demandées est inexistante, merci de saisir une opération valide");
    }
}

litterale& lEntiere::operator* (const litterale& op) const
{
    if(op.getType()==1)
    {
        return *(new lEntiere(dynamic_cast<const lEntiere&> (op).valeur*valeur));
    }
    if(op.getType()==2)
    {
        int num=valeur*dynamic_cast<const lRationnelle&> (op).getNumerateur();
        int den=dynamic_cast<const lRationnelle&>(op).getDenominateur();
        if (den==1) return *(new lEntiere(num));
                else  return *(new lRationnelle(num, den));
    }
    // test a faire sur le signe de la litterale pour savoir quel traitement appliquer
    if(op.getType()==3)
    {
       return *(new lReelle((float)((float)valeur*dynamic_cast<const lReelle&>(op).getValeur())));
    }
    if(op.getType()==4)
    {
        return *(new lComplexe(&(*this*dynamic_cast<const lComplexe&>(op).getReelle()),&(*this*dynamic_cast<const lComplexe&>(op).getIm())));
    }
    else
    {
        throw ComputerException("Erreur l'opérations entre les littérales demandées est inexistante, merci de saisir une opération valide");
    }
}


litterale& lEntiere::operator/(const litterale& op) const
{
    if(op.getType()==1)
    {
        if(valeur%dynamic_cast<const lEntiere&>(op).valeur==0)
            return *(new lEntiere(valeur/dynamic_cast<const lEntiere&>(op).valeur));
        else return *(new lRationnelle(valeur, dynamic_cast<const lEntiere&>(op).valeur));
    }
    if(op.getType()==2)
    {
        return *(new lRationnelle(dynamic_cast<const lRationnelle&>(*this*lRationnelle(dynamic_cast<const lRationnelle&>(op).getDenominateur(),dynamic_cast<const lRationnelle&>(op).getNumerateur()))));
    }
    if(op.getType()==3)
    {
        return *(new lReelle(dynamic_cast<const lReelle&>(op).getValeur()*(float)valeur));
    }
    if(op.getType()==4)
    {
        return *(new lComplexe(&(*this/dynamic_cast<const lComplexe&>(op).getReelle()),&(*this/dynamic_cast<const lComplexe&>(op).getIm())));
    }
    else
    {
        throw ComputerException("Erreur l'opérations entre les littérales demandées est inexistante, merci de saisir une opération valide");
    }
}
//OPERATEURS DE LA CLASSE RATIONNELLE
litterale& lRationnelle::operator+(const litterale& op) const
{
    if(op.getType()==1)
    {
        return dynamic_cast<const lEntiere&>(op)+*this;
    }
    if(op.getType()==2)
    {
        return *(new lRationnelle(dynamic_cast<const lRationnelle&>(op).getDenominateur()*numerateur+denominateur*dynamic_cast<const lRationnelle&>(op).getNumerateur(),dynamic_cast<const lRationnelle&>(op).getDenominateur()*denominateur));
    }
    if(op.getType()==3)
    {
        return *(new lReelle(dynamic_cast<const lReelle&>(op).getValeur()+((float)numerateur/(float)denominateur)));
    }
    if(op.getType()==4)
    {
        return *(new lComplexe(&(*this+dynamic_cast<const lComplexe&>(op).getReelle()), &(dynamic_cast<const lComplexe&>(op).getIm())));
    }
    else
    {
        throw ComputerException("Erreur l'opérations entre les littérales demandées est inexistante, merci de saisir une opération valide");
    }
}
 litterale& lRationnelle::operator-(const litterale& op) const
 {
     if(op.getType()==1)
     {
        int num=numerateur-dynamic_cast<const lEntiere&> (op).getValeur()*denominateur;
        return *(new lRationnelle(num, denominateur));
     }
     if(op.getType()==2)
    {
         return *(new lRationnelle(dynamic_cast<const lRationnelle&>(op).getDenominateur()*numerateur-denominateur*dynamic_cast<const lRationnelle&>(op).getNumerateur(),dynamic_cast<const lRationnelle&>(op).getDenominateur()*denominateur));
    }
    if(op.getType()==3)
    {
        return *(new lReelle((((float)numerateur/(float)denominateur))-dynamic_cast<const lReelle&>(op).getValeur()));
    }
    if(op.getType()==4)
    {
        return *(new lComplexe(&(*this-dynamic_cast<const lComplexe&>(op).getReelle()), &(dynamic_cast<const lComplexe&>(op).getIm())));
    }
    else
    {
        throw ComputerException("Erreur l'opérations entre les littérales demandées est inexistante, merci de saisir une opération valide");
    }
 }
 litterale& lRationnelle::operator*(const litterale& op) const
{
    if(op.getType()==1)
    {   //grosse reserve sur **this qui est censé faire la multiplication mais j'ai peur qu'il voit ça comme déréférencement même si il compile
        return dynamic_cast<const lEntiere&>(op)**this;
    }
    if(op.getType()==2)
    {
        return *(new lRationnelle(dynamic_cast<const lRationnelle&>(op).getNumerateur()*numerateur,dynamic_cast<const lRationnelle&>(op).getDenominateur()*denominateur));
    }
    if(op.getType()==3)
    {
        return *(new lReelle((((float)numerateur/(float)denominateur))*dynamic_cast<const lReelle&>(op).getValeur()));
    }
    if(op.getType()==4)
    {
        return *(new lComplexe(&(*this*dynamic_cast<const lComplexe&>(op).getReelle()),&(*this*dynamic_cast<const lComplexe&>(op).getIm())));
    }
    else
    {
        throw ComputerException("Erreur l'opérations entre les littérales demandées est inexistante, merci de saisir une opération valide");
    }
}
litterale& lRationnelle::operator/(const litterale& op) const
{
    if(op.getType()==1)
    {
         return *(new lRationnelle(numerateur,dynamic_cast<const lEntiere&>(op).getValeur()*denominateur));
    }
    if(op.getType()==2)
    {
        return *(new lRationnelle(dynamic_cast<const lRationnelle&>(*this*lRationnelle(dynamic_cast<const lRationnelle&>(op).getDenominateur(),dynamic_cast<const lRationnelle&>(op).getNumerateur()))));
    }
    if(op.getType()==3)
    {
        return *(new lReelle((float)numerateur/(float)denominateur/dynamic_cast<const lReelle&>(op).getValeur()));
    }
    if(op.getType()==4)
    {
        return *(new lComplexe(&(*this/dynamic_cast<const lComplexe&>(op).getReelle()),&(*this/dynamic_cast<const lComplexe&>(op).getIm())));
    }
    else
    {
        throw ComputerException("Erreur l'opérations entre les littérales demandées est inexistante, merci de saisir une opération valide");
    }
}
//OPERATEURS DE LA CLASSE REELLE
litterale& lReelle::operator+(const litterale& op) const
{
    if(op.getType()==1)
    {
        return dynamic_cast<const lEntiere&>(op)+*this;
    }
    if(op.getType()==2)
    {
        return dynamic_cast<const lRationnelle&> (op)+*this;
    }
    if(op.getType()==3)
    {
        return *(new lReelle(valeur+dynamic_cast<const lReelle&>(op).getValeur()));
    }
    if(op.getType()==4)
    {
        return *(new lComplexe(&(dynamic_cast<const lComplexe&>(op).getReelle()+*this),&(dynamic_cast<const lComplexe&>(op).getIm())));
    }
    else
    {
        throw ComputerException("Erreur l'opérations entre les littérales demandées est inexistante, merci de saisir une opération valide");
    }
}
litterale& lReelle::operator-(const litterale& op) const
{
    if(op.getType()==1)
    {
         return *(new lReelle(valeur-(float)(dynamic_cast<const lRationnelle&>(op).getNumerateur())/(float)(dynamic_cast<const lRationnelle&>(op).getDenominateur())));
    }
    if(op.getType()==2)
    {
        return *(new lReelle(valeur-(float)(dynamic_cast<const lRationnelle&>(op).getNumerateur())/(float)(dynamic_cast<const lRationnelle&>(op).getDenominateur())));
    }
   if(op.getType()==3)
    {
        return *(new lReelle(valeur-dynamic_cast<const lReelle&>(op).getValeur()));
    }
    if(op.getType()==4)
    {
        return *(new lComplexe(&(*this-dynamic_cast<const lComplexe&>(op).getReelle()),&(dynamic_cast<const lComplexe&> (op).getIm())));
    }
     else
    {
        throw ComputerException("Erreur l'opérations entre les littérales demandées est inexistante, merci de saisir une opération valide");
    }
}
litterale& lReelle::operator*(const litterale& op) const
{
    if(op.getType()==1)
    {
        return dynamic_cast<const lEntiere&>(op)**this;
    }
    if(op.getType()==2)
    {
        return dynamic_cast<const lRationnelle&>(op)**this;
    }
    if(op.getType()==3)
    {
        return *(new lReelle(valeur*dynamic_cast<const lReelle&>(op).getValeur()));
    }
    if(op.getType()==4)
    {
        return *(new lComplexe(&(*this*dynamic_cast<const lComplexe&>(op).getReelle()),&(*this*dynamic_cast<const lComplexe&> (op).getIm())));
    }
     else
    {
        throw ComputerException("Erreur l'opérations entre les littérales demandées est inexistante, merci de saisir une opération valide");
    }
}
litterale& lReelle::operator/(const litterale& op) const
{
    if(op.getType()==1)
    {
        return *(new lReelle(valeur*(float)dynamic_cast<const lEntiere&>(op).getValeur()));
    }
    if(op.getType()==2)
    {
        return *(new lReelle(dynamic_cast<const lReelle&>(*this*lRationnelle(dynamic_cast<const lRationnelle&>(op).getDenominateur(),dynamic_cast<const lRationnelle&>(op).getNumerateur()))));
    }
    if(op.getType()==3)
    {
        return *(new lReelle(valeur*dynamic_cast<const lReelle&>(op).getValeur()));
    }
    if(op.getType()==4)
    {
        return *(new lComplexe(&(*this/dynamic_cast<const lComplexe&>(op).getReelle()),&(*this/dynamic_cast<const lComplexe&> (op).getIm())));
    }
     else
    {
        throw ComputerException("Erreur l'opérations entre les littérales demandées est inexistante, merci de saisir une opération valide");
    }
}
//OPERATEURS DE LA CLASSE COMPLEXE
litterale& lComplexe::operator+(const litterale& op) const
{
    if(op.getType()==1)
    {
        return *(new lComplexe(dynamic_cast<const lEntiere&>(op)+*reelle,*imaginaire));
    }
    if(op.getType()==2)
    {
        return *(new lComplexe(dynamic_cast<const lRationnelle&>(op)+*reelle, *imaginaire));
    }
    if(op.getType()==3)
    {
        return *(new lComplexe(*reelle+dynamic_cast<const lReelle&>(op), *imaginaire));
    }
    if(op.getType()==4)
    {
        return *(new lComplexe(*reelle+dynamic_cast<const lComplexe&>(op).getReelle(), *imaginaire+dynamic_cast<const lComplexe&>(op).getIm()));
    }
     else
    {
        throw ComputerException("Erreur l'opérations entre les littérales demandées est inexistante, merci de saisir une opération valide");
    }
}
litterale& lComplexe::operator-(const litterale& op) const
{
    if(op.getType()==1)
    {
        return *(new lComplexe(*reelle-dynamic_cast<const lEntiere&>(op),*imaginaire));
    }
    if(op.getType()==2)
    {
        return *(new lComplexe(*reelle-dynamic_cast<const lRationnelle&>(op),*imaginaire));
    }
    if(op.getType()==3)
    {
        return *(new lComplexe(*reelle-dynamic_cast<const lReelle&>(op), *imaginaire));
    }
    if(op.getType()==4)
    {
        return *(new lComplexe(*reelle-dynamic_cast<const lComplexe&>(op).getReelle(),*imaginaire-dynamic_cast<const lComplexe&>(op).getIm()));
    }
     else
    {
        throw ComputerException("Erreur l'opérations entre les littérales demandées est inexistante, merci de saisir une opération valide");
    }
}
litterale& lComplexe::operator*(const litterale& op) const
{
    if(op.getType()==1)
    {
        return *(new lComplexe(*reelle*dynamic_cast<const lEntiere&>(op),*imaginaire*dynamic_cast<const lEntiere&>(op)));
    }
    if(op.getType()==2)
    {
        return *(new lComplexe(*reelle*dynamic_cast<const lRationnelle&>(op),*imaginaire*dynamic_cast<const lRationnelle&>(op)));
    }
    if(op.getType()==3)
    {
        return *(new lComplexe(*reelle*dynamic_cast<const lReelle&>(op),*imaginaire*dynamic_cast<const lReelle&>(op)));
    }
    //OPERATION ICI FAUSSE, LA MULTIPLICATION DE DEUX COMPLEXES EST PLUS COMPLIQUEE QUE CA
    if(op.getType()==4)
    {
        return *(new lComplexe(*reelle*dynamic_cast<const lComplexe&>(op).getReelle(),*imaginaire*dynamic_cast<const lComplexe&>(op).getIm()));
    }
     else
    {
        throw ComputerException("Erreur l'opérations entre les littérales demandées est inexistante, merci de saisir une opération valide");
    }
}
litterale& lComplexe::operator/(const litterale& op) const
{
    if(op.getType()==1)
    {
        return *(new lComplexe(*reelle/dynamic_cast<const lEntiere&>(op),*imaginaire/dynamic_cast<const lEntiere&>(op)));
    }
     if(op.getType()==2)
    {
        return *(new lComplexe(*reelle/dynamic_cast<const lRationnelle&>(op),*imaginaire/dynamic_cast<const lRationnelle&>(op)));
    }
    if(op.getType()==3)
    {
        return *(new lComplexe(*reelle/dynamic_cast<const lReelle&>(op),*imaginaire/dynamic_cast<const lReelle&>(op)));
    }
    //OPERATION ICI FAUSSE, LA DIVISION DE DEUX COMPLEXES EST PLUS COMPLIQUEE QUE CA
    if(op.getType()==4)
    {
        return *(new lComplexe(*reelle*dynamic_cast<const lComplexe&>(op).getReelle(),*imaginaire*dynamic_cast<const lComplexe&>(op).getIm()));
    }
     else
    {
        throw ComputerException("Erreur l'opérations entre les littérales demandées est inexistante, merci de saisir une opération valide");
    }
}
*/
litterale& litteraleManager::addition(litterale& op1, litterale& op2) {
    //addition avec op1 ENTIER
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
            throw ComputerException("Erreur l'opérations entre les littérales demandées est inexistante, merci de saisir une opération valide");
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
            throw ComputerException("Erreur l'opérations entre les littérales demandées est inexistante, merci de saisir une opération valide");
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
litterale& litteraleManager::soustraction(litterale& op1, litterale&op2) {
    //soustraction avec op1 ENTIER
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
            return addition(op2,op1);
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
litterale& litteraleManager::multiplication(litterale& op1, litterale&op2) {
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
            return *(new lComplexe(&soustraction
                                   (multiplication(dynamic_cast<const lComplexe&>(op1).getReelle(),dynamic_cast<const lComplexe&>(op2).getReelle()),
                                    multiplication(dynamic_cast<const lComplexe&>(op1).getIm(),dynamic_cast<const lComplexe&>(op2).getIm())),
                                   &addition
                                   (multiplication(dynamic_cast<const lComplexe&>(op1).getReelle(),dynamic_cast<const lComplexe&>(op2).getIm()),
                                    multiplication(dynamic_cast<const lComplexe&>(op1).getIm(),dynamic_cast<const lComplexe&>(op2).getReelle()))));
        }
         else
        {
            throw ComputerException("Erreur l'opérations entre les littérales demandées est inexistante, merci de saisir une opération valide");
        }
    }
}
litterale& litteraleManager::division(litterale& op1, litterale&op2) {
    if(op1.getType()==1) {
        if(op2.getType()==1)
        {
            if(dynamic_cast<const lEntiere&>(op1).getValeur()%dynamic_cast<const lEntiere&>(op2).getValeur()==0)
                return *(new lEntiere(dynamic_cast<const lEntiere&>(op1).getValeur()/dynamic_cast<const lEntiere&>(op2).getValeur()));
            else return *(new lRationnelle(dynamic_cast<const lEntiere&>(op1).getValeur(), dynamic_cast<const lEntiere&>(op2).getValeur()));
        }
        if(op2.getType()==2)
        {   //diviser c'est multiplier par l'inverse

            return *(new lRationnelle(dynamic_cast<const lRationnelle&>(multiplication(op1,
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
            return *(new lRationnelle(dynamic_cast<const lRationnelle&>(multiplication(op1,*new lRationnelle(dynamic_cast<const lRationnelle&>(op2).getDenominateur(),dynamic_cast<const lRationnelle&>(op2).getNumerateur())))));
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
            return *(new lReelle(dynamic_cast<const lReelle&>(multiplication(op1, *new lRationnelle(dynamic_cast<const lRationnelle&>(op2).getDenominateur(),dynamic_cast<const lRationnelle&>(op2).getNumerateur())))));
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




litteraleManager::Handler litteraleManager::handler=litteraleManager::Handler();
Pile::Handler Pile::handler=Pile::Handler();
Controleur::Handler Controleur::handler=Controleur::Handler();

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
    return false;
}

//fonction dont le role est de traiter
//les expressions passées par le QLineEdit
void Controleur::commande(const QString& c){

    //on suppose qu'on récupère un entier et qu'on l'empile
    //créé et empile la nouvelle littérale sur la pile
    if(estUnNombre(c))   {
        if(c.toInt()) littAff->push(littMng->addLitterale(c.toInt()));
        else littAff->push(littMng->addLitterale(c.toFloat()));
    }
    //si on a saisit un opérateur alors on depile deux littérales, on fait le calcul et on empile le résultat
    if(estUnOperateur(c))
    {
        //on teste si on a au moins deux opérateurs
        if(littAff->taille()>=2)
        {
            if(c.toStdString()=="+")
            {

                litterale& op1=littAff->top();
                littAff->pop();
                litterale& op2=littAff->top();
                littAff->pop();
                littAff->push(littMng->addLitterale(op2+op1));
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
                littAff->push(littMng->addLitterale(op2-op1));
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
                littAff->push(littMng->addLitterale(op2*op1));
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
                littAff->push(littMng->addLitterale(op2/op1));
                if(littAff->top().getType()!=4){
                   littMng->removeLitterale(op1);
                   littMng->removeLitterale(op2);
                }
            }
            if(c.toStdString()=="$")
            {
                littAff->setMessage("tentative de complexe");
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
            //littAff->setMessage("operation réalisée avec succès");
            //modificationEtat();

        } else littAff->setMessage("Le nombre d'opérandes stockées dans la pile n'est pas suffisant pour réaliser l'operation");
    }
}






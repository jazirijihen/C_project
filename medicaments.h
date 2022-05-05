struct date 
{
    int jour ;
    int mois  ;
    int annee ;
};
typedef struct date DATE  ; 
struct medicaments 
{
    int reference ;
    char nom[10];
    int prix;
    DATE delai ;
    int  stock ;

} ;
typedef struct medicaments MEDICAMENTS ;

struct commande   // structure commande contient une autre stucture date 
{
    int reference ;
    DATE delai  ;
    int nb_med ;
    int *commandes ;    // tableau dynamique contient les nombres de medicaments de chaque commande
    int prix;
};
typedef struct commande COMMANDE ;
struct laboratoire 
{
    char nom_laboratoire[50] ;
    int nb_medicaments ;
    MEDICAMENTS *achats ;
};
typedef struct laboratoire LABORATOIRE ;


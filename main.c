#include<stdio.h>
#include<conio.h>
#include"medicaments.h" 
#include<stdlib.h>
struct date saisir_date() {
    struct date d ;
    printf("donner le jour actuel :");
    scanf("%d",&d.jour);
    printf("donner le mois actuel:");
    scanf("%d",&d.mois);
    printf("donner l annee actuelle:");
    scanf("%d",&d.annee);
    return(d);

}
void suppression_medicaments_hors_delai (MEDICAMENTS *med , int n) 
{
int i , j ,m,x; 
DATE date_actuelle;
date_actuelle=saisir_date();
    for (int i=0;i<n;i++){
        if ((med+i)->delai.annee < date_actuelle.annee)
               x=i;
        else if ((med+i)->delai.annee = date_actuelle.annee){
            if((med+i)->delai.mois< date_actuelle.mois)
                 x=i;
            else if((med+i)->delai.mois =date_actuelle.mois) {
                if ((med+i)->delai.jour<date_actuelle.jour)
                     x=i;
            }               
        }      
    }
    m=n;
    for (i=0;i<m;i++){
       if (i== x){
           m=m-1;
           j=0;
           while( j<m){
               med[i+j]=med[i+j+1];
               j++;} }
       else j++;
} 
} 

int saisir () 
{
    int x  ;
    printf("saisir le nombre des medicaments : ");
    scanf("%d",&x) ;
    return x ;
}

MEDICAMENTS saisir_medicament()
{   
    MEDICAMENTS med ;
    {
        printf("donner la reference :");
        scanf("%d",&med.reference);
        printf("donner le nom de medicament(max de 25) :") ;
        scanf("%s",&med.nom );
        printf("donner son prix: ") ;
        scanf("%d", &med.prix) ;
        printf("donner la date limite ");
        scanf("%d%d%d" ,&med.delai.jour, &med.delai.mois , &med.delai.annee);
        printf("donner la quantite en stock disponible :") ;
        scanf("%d" , &med.stock) ;
        printf("\n ************** \n") ;
    }
    return med ;   
}
COMMANDE saisir_commande()
{
    COMMANDE com ;
    {
        int i ;
        printf("donner la reference :");
        scanf("%d" , &com.reference) ;
        printf("donner la date limite ");
        scanf("%d%d%d" ,&com.delai.jour, &com.delai.mois , &com.delai.annee);
        printf("donner le nombre des medicaments demandes : ");
        scanf("%d ", &com.nb_med);
        com.commandes=(int* ) malloc (com.nb_med*sizeof(int));
        if(!com.commandes) exit(-3);
        for (i=0 ; i < com.nb_med ; i++) 
            {
                printf("donner le reference de medicament");
                scanf("%d", &com.commandes[i]) ;
            }
        printf("donner le prix : \n ");
        scanf("%d" , &com.prix) ;
        printf("\n ************** \n") ;
    }
    return com ;
}

void afficher_medicament(MEDICAMENTS med ) 
{    
            printf("\n la reference est %d \n " , med.reference);
            printf("\n le nom de medicament est %s \n ", med.nom) ;
            printf("\n son prix est %d  \n ", med.prix) ;
            printf("\n la date limite est %d \t %d \t %d \n " , med.delai);
            printf("\n la quantite dispoible est %d \n ",med.stock);
            printf("\n ----------------\n") ;   
}
void afficher_commande(COMMANDE com) 
    {
        int i ;
        printf("\n la reference de la commande est: %d \n  ", com.commandes) ;
        printf("\n la date limite est %d%d%d \n " ,com.delai.jour, com.delai.mois, com.delai.annee);
        for (i=0; i<com.nb_med ; i++) 
            printf("%d  \t ", com.commandes[i]) ;
        printf("\n le prix est : %d \n " , com.prix);
        printf("\n ----------------\n") ;
    }

void allocation (MEDICAMENTS** t , int n)
   { 
    *t=(MEDICAMENTS* )malloc(n*sizeof(MEDICAMENTS)); 
    if(!*t) exit(-1) ; 
   }
void remplir_medicaments(MEDICAMENTS*t , int n)
    {
    printf("\n rempissage du tableau \n ") ;
    for (int i=0 ;i<n; i++)
        *(t+i)=saisir_medicament() ;   // saisir_medicament2(t+i)
    }
void afficher_medicaments(MEDICAMENTS*t , int n )
{   
    int i ;
    printf("affichage du tableau \n ") ;
    for(int i=0 ; i<n ; i++)
        afficher_medicament(*(t+i)) ;  

}
void rechercher_medicament(MEDICAMENTS * med , int n )
    {
    int indice , i ; 
    printf(" \n donner l'indice de med recherche \n ");
    scanf("%d", &indice);
    for(i=0;i<n;i++)   //parcours du tableau
        {
            if((med+indice)==(med+i)) // si je trouve l elemnt rechercher
            {
                if ((med+indice)->stock != 0)  // je verifie le stock n est pas vide
                    { 
                    printf(" \n le medicament est encore disponible \n ");
                    printf("\n voici son nom %s \n ", (med+indice)->nom) ;   
                    }
                else 
                    printf("\n repture de stock !! \n") ;
            }
            else 
                {
                printf("\n le medicaments n existe pas !\n ");
                }
        }
    }

void reallocation (MEDICAMENTS ** med , int n)
{
    *med = (MEDICAMENTS * ) realloc (*med , n * sizeof (MEDICAMENTS)) ;   // reallocation de l espace ( la taille augmente)
    if (!med) exit(-2) ;
}
int ajouter_medicament(MEDICAMENTS*med , int n )
    {
    int i ; 
    int n1 ;
    printf("donner le nombre de medicaments qui tu va ajouter ? ") ;
    scanf("%d", &n1) ;
    reallocation(&med , n+n1) ;
    for( i=n; i<n1+n ; i++)
    {
        printf("donner la reference de mediacament : ") ;
        scanf("%d", &(med+i)->reference );
        printf("donner le nom de medicament:") ;
        scanf("%s",&(med+i)->nom );
        printf("donner son prix : ") ;
        scanf("%d", &(med+i)->prix) ;
        printf("donner la quantite en stock disponible :" ) ;
        scanf("%d" , &(med+i)->stock );
    }
    n=n+n1; 
    return n ;

    }

int supprimer_medicament_repturedustock(MEDICAMENTS * med , int n) 
{
    int i , j ; 

    for(i=0; i<n;i++)   // parcours du tableau
        {
            if ((med+i)->stock==0)   // si je trouve un medicaments qui a le stock vide 
                {   
                    j=i ;   
                    for (j= i; j<n ;j++)
                    {
                        med[i]=med[i+1]  ;
                        n-- ;
                        printf("medicament supprimer ! \n ");
                    }
                }   
            
        }
        
    return n ;
}
int supprimer_medicament (MEDICAMENTS * med , int n) 
{
    int position , i;
    printf(" Entrez l'emplacement où vous souhaitez supprimer l'élément: ");
    scanf("%d", &position);
 
    if (position >= n +1)
          printf("Suppression impossible.\n");
    else
     {
      for (i = position; i < n; i++)
        {
            med[i] = med[i+1];
            n-- ;
            printf("medicament supprimer ! \n ");
        }
     }
    return n ;
} 
void modifier_medicaments_prix(MEDICAMENTS * med , int n )

{
    int indice , i ; 
    printf("donner l indice de medicaments:") ;
    scanf("%d", &indice);
    for(i=0;i<n;i++)
        if((med+indice)==(med+i))
            {
                printf("donner le nouveau prix :");
                scanf("%d", &(med+indice)->prix);
            }
        else 
        printf("le medicaments n existe pas \n ") ;

}
void modifier_medicaments_stock(MEDICAMENTS * med , int n )

{
    int indice , i ; 
    printf("donner l indice de medicaments:") ;
    scanf("%d", &indice);
    for(i=0;i<n;i++)
        if((med+indice)==(med+i))
            {
                printf("donner le nouveau stock disponible :");
                scanf("%d", &(med+indice)->stock);
            }
        else 
        printf("le medicaments n existe pas \n ") ;

}

void main () 
{
    int mot_de_pass ;
    int n , x , nb_lab ;
    struct medicaments med ;
    struct medicaments * q ;
    struct medicaments **t ;
    struct commande com ;
    q=&med ;
    t=&q ;
    printf("REMPLISSAGE DE TOUTES LES MEDICAMENTS \n ");
    n=saisir () ;
    allocation (t, n) ;
    remplir_medicaments(q , n) ;
    afficher_medicaments(q , n );
    do 
    {
        printf("bonjour , donner le mot de passe : \n");
        scanf("%d",&mot_de_pass) ;
    } 
    while(mot_de_pass!=1999) ;
    do 
    {
        etiquette :
        printf(" 1 si vous voulez ajouter un medicament \n ");
        printf(" 2 si vous voulez supprimer un medicament \n " );
        printf(" 3 si vous voulez modifier le prix d un medicament \n " );
        printf(" 4 si vous voulez modifier le stock d un medicament \n ");
        printf(" 5 si vous voulez rechercher un medicament \n ") ;
        printf(" 6 si vous voulez ajouter une commende \n ") ;
        printf(" 7 si vous voulez supprimer un medicament \n ");
        printf(" 8 si vous vouler afficher le tableau \n ") ;
        printf(" 9 si vous voulez supprimer un medicament hots delai \n ") ;
        printf(" 0 si vous voulez sortir du programme ") ;
        printf("\n tapez le numero choisir \n ");
        scanf("%d",&x) ;
        if(x==1)
        {
            n=ajouter_medicament(q, n) ;   // verifiée
        }
        if (x==2)
        {
            n=supprimer_medicament_repturedustock(q,n); 
        }   
        if(x==3)
        {
            modifier_medicaments_prix(q, n );   // verifiée
        }
        if(x==4)
        {
            modifier_medicaments_stock(q,n) ;   // verifiée
        }
        if(x==5) 
        {
            rechercher_medicament(q,n ) ;   // oui
        } 
        if(x==6) 
        {   
            com=saisir_commande() ;   // presque
            afficher_commande(com)  ;

        }
        if(x==7)
        {
            n= supprimer_medicament(q,n) ;
        }        
        if(x==8)
        {
            afficher_medicaments(q, n );
        }
        if(x==9) 
            suppression_medicaments_hors_delai (q , n);
        if(x==0) 
        {
            printf("merci pour l utlisation :) ") ;
            break ; 
        }
    
        goto etiquette ;
    
    
    }
    while(mot_de_pass==1999 || x!=0) ;
        
    getch();
}

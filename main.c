#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"election.h"

int main()
{
        election e1={1,12,07,2019,"g",5000,5} , e2={2,12,07,2019,"c",3000,3} ;
        election e3={2,12,07,2019,"h",3000,3} ;

    int x ;
    //ajout
    x=ajouter_election("election.txt",e1) ;
    if (x==1)
        printf("\n ajout election avec succes");
    else printf("\n echec ajout");
    x=ajouter_election("election.txt",e2) ;
    if (x==1)
        printf("\n ajout election avec succes");
    else printf("\n echec ajout");
    //modification
    x=modifier_election("election.txt",e2,2);
    if(x==1)
        printf("\n Modification election avec succes");
    else printf("\n echec Modification");
    //suppression
 x=supprimer("election.txt",1) ;
    if(x==1)
        printf("\n Suppression election avec succes");
    else printf("\n echec Suppression");
    e3 = chercher("election.txt",2);
    if(e3.ID==-1)
        printf("introuvable");
	else 
		printf("\n Recherche réussie : %d %d/%d/%d %s %d %d \n ", e3.ID, e3.date.jour, e3.date.mois, e3.date.annee,e3.Munic, e3.NbreH, e3.NbreC);

    return 0;
}


#ifndef ELECTION_H_INCLUDED
#define ELECTION_H_INCLUDED


typedef struct
{
    int jour;
    int mois;
    int annee;
}DATE;


typedef struct
{
    int ID ;
    DATE date;
    char Munic[30];
    int NbreH;
    int NbreC ;


}election;

int ajouter_election(char *filename, election e );
int modifier_election(char *filename, election e,int id);
int supprimer(char * filename, int id);
election chercher(char * filename, int id);


#endif // ELECTION_H_INCLUDED

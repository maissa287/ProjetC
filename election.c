#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"election.h"



int ajouter_election(char *filename, election e )
{
    FILE *f;
    f=fopen (filename, "a");
    if (f != NULL )
    {
        fprintf(f,"%d %d %d %d %s %d %d \n" , e.ID, e.date.jour, e.date.mois , e.date.annee , e.Munic, e.NbreH , e.NbreC);
        fclose(f);
        return 1 ;
    }
    else return 0 ;
}

int modifier_election(char *filename, election e,int id)
{
    FILE *f;
    FILE *t;
    election s;
    int tr=0; 

  f=fopen(filename,"r");
    t=fopen("electionadmintemp.txt","w");

    if (f != NULL && t != NULL )
    {   while ( fscanf(f,"%d %d %d %d %s %d %d \n", &s.ID, &s.date.jour, &s.date.mois, &s.date.annee, s.Munic, &s.NbreH, &s.NbreC )!= EOF)
    {
        if (id ==s.ID)
            {fprintf(t,"%d %d %d %d %s %d %d \n",e.ID, e.date.jour, e.date.mois, e.date.annee, e.Munic, e.NbreH, e.NbreC);
                tr = 1; }
        else
            fprintf(t,"%d %d/%d/%d %s %d %d \n",s.ID, s.date.jour, s.date.mois, s.date.annee, s.Munic, s.NbreH, s.NbreC);
    }
    }
    fclose(f);
    fclose(t);
    remove(filename);
    rename("electionadmintemp.txt",filename);
    return tr ;
}

int supprimer(char * filename, int id)
{
    int tr=0;
    election e;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");

    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %d/%d/%d %s %d %d \n",&e.ID, &e.date.jour, &e.date.mois, &e.date.annee, e.Munic, &e.NbreH, &e.NbreC)!=EOF)
        {
            if(e.ID== id)
                tr=1;
            else
                fprintf(f2,"%d %d/%d/%d %s %d %d \n",e.ID, e.date.jour, e.date.mois, e.date.annee, e.Munic, e.NbreH, e.NbreC);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}


election chercher(char * filename, int id)
{
    election e;
    int tr;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while( (tr==0) && (fscanf(f,"%d %d %d %d %s %d %d \n",&e.ID, &e.date.jour, &e.date.mois, &e.date.annee, e.Munic, &e.NbreH, &e.NbreC)!=EOF) )
        {
            if(e.ID== id)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        e.ID = -1;
    return e;

}

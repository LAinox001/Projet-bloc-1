//
// Created by lanto on 15/11/2018.
//

#include "donnees.h"
#include <stdlib.h>
#include <stdio.h>


int compterNblignes(FILE* fichier)
{
    int c;
    int nLignes = 0;
    int c2 = '\0';

    while((c=fgetc(fichier)) != EOF)
    {
        if(c=='\n')
            nLignes++;
        c2 = c;
    }

    /* Ici, c2 est égal au caractère juste avant le EOF. */
    if(c2 != '\n')
    {
        nLignes++; /* Dernière ligne non finie */
    }

    return nLignes;
}

void lirefichier(FILE* fichier, ligne *p_tab)
{
    for(long i = 0; i <NLIGNES; i++)
    {
        fscanf(fichier, "%d;%d", &p_tab[i].pouls, &p_tab[i].temps);   //lit le fichier et rentre les valeurs lues dans les variables de la structure ligne
    }
}

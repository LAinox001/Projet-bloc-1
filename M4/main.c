#include <stdio.h>
#include <stdlib.h>
#include "donnees.h"
#include "action.h"
#include "menu.h"

void main(){

    ligne* info = NULL; //création tableau info

    info = (ligne*)malloc(NLIGNES* sizeof(ligne));  //pour chaque valeur de type ligne, on alloue de la mémoire pour la taille de ligne et multiplie par le nb de lignes

    FILE* fichier = NULL;
    fichier = fopen("C:\\Users\\lanto\\Documents\\Cours\\Projets\\Projet bloc 1\\processing_vers_csv\\Battements.csv", "r");

    if(fichier != NULL)
    {
        lirefichier(fichier, info);
        afficherMenu(fichier, info);
    }

    else
    {
        printf("Le fichier n'a pas pu être ouvert");
        exit(0);
    }
    fclose(fichier);
    free(info); //libere la mémoire allouée
}

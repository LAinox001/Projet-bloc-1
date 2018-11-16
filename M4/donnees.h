//
// Created by lanto on 15/11/2018.
//

#ifndef MODULE_4_DONNEES_H
#define MODULE_4_DONNEES_H

#include <stdlib.h>
#include <stdio.h>

typedef struct ligne
{
    int pouls;
    int temps;
}ligne;

#define NLIGNES compterNblignes(fopen("C:\\Users\\lanto\\Documents\\Cours\\Projets\\Projet bloc 1\\processing_vers_csv\\Battements.csv", "r"))
int compterNblignes(FILE* fichier);
void lirefichier(FILE* fichier, ligne *p_tab);

#endif //MODULE_4_DONNEES_H

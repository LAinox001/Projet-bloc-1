//
// Created by lanto on 14/11/2018.
//

#include <stdio.h>
#include <stdlib.h>
#include "generationCode.h"

void ecrire(int choixMenu)
{
    int choixLed;

    FILE * fichier = NULL;

    fichier = fopen("C:\\Users\\lanto\\Documents\\Arduino\\libraries\\param\\param.h", "w+");              //création du fichier dans le dossier voulue

    if (fichier != NULL)
    {
        fprintf(fichier, "#ifndef PARAM_H\n");
        fprintf(fichier, "#define PARAM_H\n");
        fprintf(fichier, "#define CHOIX %d \n", choixMenu);
        if(choixMenu == 7){
            printf("Selectionnez la LED que vous voulez allumer (entre 2 et 11) : \n");                   //si l'utilisateur souhaite allumer une seule LED au choix on lui demande laquelle et on l'écrit dans le fichier
            scanf("%d", &choixLed);
            fprintf(fichier, "#define CHOIX_LED %d \n", choixLed);
        }
        else {
            fprintf(fichier, "#define CHOIX_LED 2 \n");                                                   //sinon on la set de base à deux (il faut la set, même si on ne l'utilise pas
        }
        fprintf(fichier, "#endif //PARAM_H");
    }

}

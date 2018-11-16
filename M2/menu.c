//
// Created by lanto on 14/11/2018.
//

#include <stdlib.h>
#include <stdio.h>
#include "menu.h"

int choixMenu;

//on affiche les différents modes possibles et l'utilisateur rentre le mode qu'il souhaite

int afficherchoix()
{

    printf("Choisisez le mode de fonctionnement du coeur en LED\n\n");
    printf("1. Toutes les LEDS en même temps\n");
    printf("2. Une LED sur deux\n");
    printf("3. Une LED sur trois\n");
    printf("4. Une lED sur quatre\n");
    printf("5. Une LED sur cinq\n");
    printf("6. Mode chenille\n");
    printf("7. Une LED au choix\n");
    scanf("%d", &choixMenu);

    //la valeur return ici sera prise en compte dans le fichier generationCode

    return choixMenu;
}

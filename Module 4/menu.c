//
// Created by lanto on 15/11/2018.
//

#include "menu.h"
#include "action.h"
#include "donnees.h"

#include <stdio.h>
#include <stdlib.h>


void afficherMenu(FILE *fichier, ligne *p_tab)
{
    int choix;
    int choix2;
    int choix3;
    int tps;
    int tps1;
    int tps2;
    int nombreLignes;

    //affichage du menu

    printf("Choisissez une fonctionnalité:\n");
    printf("1. Afficher les données dans l'ordre\n");
    printf("2. Afficher les données dans l'ordre croissant\n");
    printf("3. Afficher les données dans l'ordre décroissant\n");
    printf("4. Afficher les données pour un temps precis\n");
    printf("5. Afficher la moyenne de pouls dans un intervalle de temps\n");
    printf("6. Afficher le nombre de lignes de données actuellement en mémoire\n");
    printf("7. Afficher le pouls minimum\n");
    printf("8. Afficher le pouls maximum\n");
    printf("0. Quitter le programme\n");
    scanf("%d", &choix);

    //appelle des différentes fonctions en fonction de ce qu'a choisi l'utilisateur

    switch(choix)
    {

        case 0:
            printf("Vous allez quitter le programme\n");
            exit(EXIT_SUCCESS);
            break;

        case 1:
            lirefichier(fichier, p_tab);
            break;

        case 2:
            printf("Voulez vous afficher le temps ou le pouls ?\n");
            printf("1. En fonciton du temps \n");
            printf("2. En fonction du pouls \n");
            scanf("%d", &choix2);
            switch(choix2)
            {
                case 1 :
                    tempsCroissant(p_tab, NLIGNES);
                    break;

                case 2:
                    poulsCroissant(p_tab, NLIGNES);
                    break;
            }
            break;

        case 3:
            printf("Voulez vous afficher le temps ou le pouls ?\n");
            printf("1. En fonciton du temps \n");
            printf("2. En fonction du pouls \n");
            scanf("%d", &choix3);

            switch(choix3)
            {
                case 1 :
                    tempsDecroissant(p_tab, NLIGNES);
                    break;

                case 2:
                    poulsDecroissant(p_tab, NLIGNES);
                    break;
            }
            break;

        case 4:
            printf("entrez quel temps vous voulez : ");
            scanf("%d", &tps);
            tempsDonne(tps, p_tab);
            break;

        case 5:
            printf("entrez le premier temps : ");
            scanf("%d", &tps1);
            printf("entrez le deuxième temps : ");
            scanf("%d", &tps2);
            moyenneTempsDonnes(tps1, tps2, p_tab);
            break;

        case 6:
            nombreLignes = compterNblignes(fichier);
            printf("%d", nombreLignes);
            break;

        case 7:
            poulsMin(p_tab, NLIGNES);
            break;

        case 8:
            poulsMax(p_tab, NLIGNES);
            break;
    }
}

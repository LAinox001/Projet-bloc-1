#include <stdio.h>
#include <stdlib.h>
#include "action.h"
#include "donnees.h"


//tri par insertion qui tri le pouls par ordre croissant
void poulsCroissant(ligne *p_tab, int n){
    int i;
    int j;
    int tempoPouls;
    int tempoTemps;
    for(i=0; i<n; i++){
        j = i;
        while(j>0 && p_tab[j-1].pouls > p_tab[j].pouls){  //tant que la case j-1 est supérieur à la case j et qu'on a pas fait tout le tableau on interverti les deux valeurs
            tempoPouls = p_tab[j].pouls;
            tempoTemps = p_tab[j].temps;
            p_tab[j].pouls = p_tab[j-1].pouls;
            p_tab[j].temps = p_tab[j-1].temps;
            p_tab[j-1].pouls = tempoPouls;
            p_tab[j-1].temps = tempoTemps;
            j = j-1;
        }
    }
    printf("Pouls dans l'ordre croissant : \n");
    for(i=0; i<n; i++){
        printf("%d ; %d \n", p_tab[i].pouls, p_tab[i].temps);
    }
}

//tri par insertion qui tri le pouls par ordre decroissant
void poulsDecroissant(ligne *p_tab, int n){
    int i;
    int j;
    int tempoPouls;
    int tempoTemps;
    for(i=0; i<n; i++){
        j = i;
        while(j>0 && p_tab[j-1].pouls < p_tab[j].pouls){
            tempoPouls = p_tab[j].pouls;
            tempoTemps = p_tab[j].temps;
            p_tab[j].pouls = p_tab[j-1].pouls;
            p_tab[j].temps = p_tab[j-1].temps;
            p_tab[j-1].pouls = tempoPouls;
            p_tab[j-1].temps = tempoTemps;
            j = j-1;
        }
    }
    printf("Pouls dans l'ordre croissant : \n");
    for(i=0; i<n; i++){
        printf("%d ; %d \n", p_tab[i].pouls, p_tab[i].temps);
    }
}

//tri par insertion qui tri le temps par ordre croissant
void tempsCroissant(ligne *p_tab, int n){
    int i;
    int j;
    int tempoTemps;
    int tempoPouls;
    for(i=0; i<n; i++){
        j = i;
        while(j>0 && p_tab[j-1].temps > p_tab[j].temps){
            tempoTemps = p_tab[j].temps;
            tempoPouls = p_tab[j].pouls;
            p_tab[j].temps = p_tab[j-1].temps;
            p_tab[j].pouls = p_tab[j-1].pouls;
            p_tab[j-1].temps = tempoTemps;
            p_tab[j-1].pouls = tempoPouls;
            j = j-1;
        }
    }
    printf("Temps dans l'ordre croissant : \n");
    for(i=0; i<n; i++){
        printf("%d ; %d \n", p_tab[i].temps, p_tab[i].pouls);
    }
}

//tri par insertion qui tri le pouls par ordre decroissant
void tempsDecroissant(ligne *p_tab, int n){
    int i;
    int j;
    int tempoTemps;
    int tempoPouls;
    for(i=0; i<n; i++){
        j = i;
        while(j>0 && p_tab[j-1].temps < p_tab[j].temps){
            tempoTemps = p_tab[j].temps;
            tempoPouls = p_tab[j].pouls;
            p_tab[j].temps = p_tab[j-1].temps;
            p_tab[j].pouls = p_tab[j-1].pouls;
            p_tab[j-1].temps = tempoTemps;
            p_tab[j-1].pouls = tempoPouls;
            j = j-1;
        }
    }
    printf("Temps dans l'ordre croissant : \n");
    for(i=0; i<n; i++){
        printf("%d ; %d \n", p_tab[i].temps, p_tab[i].pouls);
    }
}

//recherche du maximum du pouls
void poulsMax(ligne *p_tab, int n){
    int i;
    int max = p_tab[0].pouls;
    int tempsAssocie = p_tab[0].temps;
    for(i=0; i<n; i++){
        if(p_tab[i+1].pouls > p_tab[i].pouls){                //on fait tout le tableau et si on trouve que la valeur du pouls de la case i est > au max précédent
            max = p_tab[i+1].pouls;                           //le maximum prend cette valeur (et on y associe le pouls)
            tempsAssocie = p_tab[i+1].temps;
        }
    }
    printf("pouls avec le temps associe : \n");
    printf("%d ; %d", max, tempsAssocie);
}

//recherche du minimum du pouls
void poulsMin(ligne *p_tab, int n){
    int i;
    int min = p_tab[0].pouls;
    int tempsAssocie = p_tab[0].temps;
    for(i=0; i<n; i++){
        if(p_tab[i+1].pouls < p_tab[i].pouls){
            min = p_tab[i+1].pouls;
            tempsAssocie = p_tab[i+1].temps;
        }
    }
    printf("pouls avec le temps associe : \n");
    printf("%d ; %d", min, tempsAssocie);
}

//on recherche la valeur du pouls pour un temps donné
void tempsDonne(int tps, ligne *p_tab){
    int i;
    int j = 0;

    for(i=0; i<NLIGNES; i++){  //on fait tout le tableau
        if(p_tab[i].temps == tps){       //si on le trouve d'office on le print
            printf("A %d millisecondes, le pouls était de %d", tps, p_tab[i].pouls);
            return;
        }
    }
    if(p_tab[NLIGNES-1].temps != tps){   //sinon
        while(p_tab[j].temps < tps){     //tant que la valeur de la case j est inférieure au temps recherché on fait j+1
            if(p_tab[j+1].temps > tps){  //si la case j+1 est > au temps, on affiche la case (en gros, on prend la valeur précédente
                printf("A %d millisecondes, le pouls était de %d", p_tab[j].temps, p_tab[j].pouls);
                return;
            }
            j = j+1;
        }
    }
}

//moyenne du pouls pour une plage donnée
void moyenneTempsDonnes(int tps1, int tps2, ligne *p_tab){
    int i;
    int j = 0;
    int somme = 0;
    int compteur = 0;
    float resultat;

    int temps1;
    int temps2;

    for(i=0; i<NLIGNES; i++){ //si on trouve le temps 1 d'office
        if(p_tab[i].temps == tps1){
            temps1 = i;
        }
        else if(p_tab[NLIGNES-1].temps != tps1){   //sinon
            while(p_tab[j].temps < tps1){     //tant que la valeur de la case j est inférieure au temps recherché on fait j+1
                if(p_tab[j+1].temps > tps1){  //si la case j+1 est > au temps, on affiche la case (en gros, on prend la valeur précédente)
                    temps1 = j;
                    printf("temps 1 %d \n", temps1);
                }
                j = j+1;
            }
        }
    }

    for(i=temps1; i<NLIGNES; i++){  //si on trouve le temps 2 d'office
        if(p_tab[i].temps == tps2){
            temps2 = i;
        }
        else if(p_tab[NLIGNES-1].temps != tps2){   //sinon
            while(p_tab[j].temps < tps2){     //tant que la valeur de la case j est inférieure au temps recherché on fait j+1
                if(p_tab[j+1].temps > tps2){  //si la case j+1 est > au temps, on affiche la case (en gros, on prend la valeur précédente
                    temps2 = j;
                    printf("temps 2 %d \n", temps2);
                }
                j = j+1;
            }
        }
    }

    for(i=temps1; i<=temps2; i++){    //pour i allant de temps 1 à temps 2
        somme = somme + p_tab[i].pouls; //on fait la somme des pouls
        compteur = compteur+1;  //on compte le nombre de pouls
    }
    resultat = somme/compteur; //on divise la somme par le pouls
    printf("La moyenne entre %d millisecondes et %d millisecondes est de : %f", tps1, tps2, resultat);
}

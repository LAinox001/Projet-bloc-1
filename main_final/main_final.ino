#include <param.h>                        //défini le choix d'affichage

#include <coeur.h>
#include <cardio.h>

cardio cardio;
coeur coeur;

int i;
int choixLed = 8;                       //défini quelle LED on veut allumer pour la LED au choix
int ledChenille = 2;                    //définit la LED de départ pour le mode chenille

int valeurPrecedente = 0;
long tempsPrecedent = 0;

void setup() {                          //on set tous les PINs et on démarre le moniteur
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  int valeurActuelle, valeurSeuil;
  long tempsDebutPulsation;

  valeurActuelle = analogRead(0);                                                                                   //on read le port A0
  valeurSeuil = 300;                                                                                                //on définit la valeur de seuil à 300 qui correspond à une valeur moyenne entre le moment où le coeur ne bat pas et ou il est au maximum de son impulsion

  if (valeurActuelle > valeurSeuil) {                                                                               // si on est dans la zone max
    if (valeurPrecedente <= valeurSeuil) {                                                                          // et si on vient d'y entrer
      tempsDebutPulsation = millis();
      if (tempsDebutPulsation > (tempsPrecedent + 200)){                                                            //et si le temps au dessus du seuil est asssez long pour correspondre (si ce n'est pas du bruit)
          tempsPrecedent = cardio.calculPouls(tempsDebutPulsation, tempsPrecedent);                                 //on appelle la fonction qui calcul le pouls
          if (CHOIX == 1){                                                                                          //et en fonction du pouls on appelle la fonction d'affichage du coeur correspondant
             coeur.toutesLesLeds();
          }
  
          if (CHOIX == 2){
            coeur.uneLedSurDeux();
          }

          if(CHOIX == 3){
            coeur.uneLedSurTrois();
          }

          if(CHOIX == 4){
            coeur.uneLedSurQuatre();
          }

          if(CHOIX == 5){
            coeur.uneLedSurCinq();
          }

          if(CHOIX == 6){
            ledChenille = coeur.chenille(ledChenille);
          }

          if(CHOIX == 7){
            coeur.ledAuChoix(CHOIX_LED);
          }
        }
      }
    }
    delay(100);                                                                                                     //on laisse un petit délai et ensuite on éteint toutes les LEDs
    for(i=2; i<=11; i++){
      digitalWrite(i, LOW);
    }
    valeurPrecedente = valeurActuelle;
}

/* Programme :
   - Genère un rythme cardiaque aléatoire (entre 60 et 80 bpm) toutes les secondes (soit 1000ms).
   - Donne une moyenne glissante des valeurs aléatoires du rythme cardiaque sur 5 éléments.
   - Le résultat final est composé de deux éléments : Rythme cardiaque (bpm) et à quel moment il a été prélevé, en ms (tempsMS).

   Programme édité par Julien LORENZO / Gabriel RICARD / Corentin PAUGAM
 */
 
#include "coeur.h"
#include "param.h"

//Déclaration des Variables :
double bps;   // Nombre décimal : battements par seconde
unsigned int bpm;   // Entier : battement par minute
unsigned int tempsMS;   // Variable indiquant le temps en Milliseconde
float Moy[5];   // Tableau de nombres décimaux stockant les cinq éléement pour calculer une moyenne glissante
float Moye;   // Résultante de la moyenne glissante
int j = 3;    // Compteur pour les chenilles
int i;    // Permet d'intialiser les boucles for
int test = 1;   // Permet de stopper la boucle while une fois les 10 valeurs testées

void setup() {
  pinMode(2, INPUT);
  for(i=3; i<13; i++){
    pinMode(i, OUTPUT);   // On initialise les pins sur lesquels sont branchs les LEDs comme sorties.
  }
  Serial.begin(9600);   // On initialise la comunication à 9600 bauds
  for(int i = 0; i<5; i++){
    Moy[i]=random(60,80);   // On atribue une valeur aléatoire aux 5 cases du tableau
  }
}

void loop() {
  if(analogRead(0) > 500){
    bps = random(1000,1333);    // On génère une valeur aléatoire correspondant aux battements par seconde *1000
    bpm = (bps / 1000)*60;    // On convertit en battements par minute
    tempsMS = tempsMS + 1000;   // On incrémente de 1 seconde tempsMS
    
    fmode(mode, x, &j, bps);
      
    if(test<11){   // On récupère les 10 premières valeurs
      test++;   // On incrémente test
      for(int i =0; i<4;i++){
        Moy[i]=Moy[i+1];    // On décale le tableau
      }
      Moy[4]=bpm;
      Moye = (Moy[0]+Moy[1]+Moy[2]+Moy[3]+Moy[4])/5;    // On fait la moyenne
      Serial.print(tempsMS);
      Serial.print(" ; ");    // On affiche la moyenne des bpm
      Serial.println(Moye);
    }
  }
}

void fmode(int mode, int x, int *j, int bps){
  switch(mode){ // On regarde la valeur de mode, et on choisi la fonction correspondante.
    case 1:{
      all();
      delay((1000000/bps)-150);   // On supprime le délai induit par le mode des LEDs
      break;
    }
    case 2:{
      allBlink();
      delay((1000000/bps)-270);
      break;
    }
    case 3:{ 
      oneOuttaX(x);
      delay((1000000/bps)-150);
      break;
    }
    case 4:{
      caterpillar(*j);
      (*j)++; 
      if(*j>12){ //(1) Ces 4 lignes permettent de boucler la chenille des LEDs 
        *j = 3;
      }
      Serial.println(*j);
      delay((1000000/bps)-150);
      break;
    }
    case 5:{
      caterpillarBlink(*j);
      (*j)++;
      if(*j>12){ // Same as (1)
        *j = 3;
      }
      delay((1000000/bps)-280);
      break;
    }
    case 6:{
      alone(x);
      delay((1000000/bps)-150);
      break;
    }
  }
}

void all(){   // Fonction pour faire briller toutes les LEDs
  int i;
  for(i=3; i<13; i++){
    digitalWrite(i, HIGH);
  }
  delay(150);
  for(i=3; i<13; i++){
    digitalWrite(i, LOW);
  }
}

void allBlink(){    // Fonction pour faire clignoter toutes les LEDs
  int i;
  for(i=3; i<13; i++){
    digitalWrite(i, HIGH);
  }
  delay(90);
  for(i=3; i<13; i++){
    digitalWrite(i, LOW);  
  }
  delay(90);
  for(i=3; i<13; i++){
    digitalWrite(i, HIGH);
  }
  delay(90);
  for(i=3; i<13; i++){
    digitalWrite(i, LOW);
  }
}

void oneOuttaX(int x){    // Fonction pour faire briller une LED sur X
  int i;
  for(i=3; i<13; i=i+x){
    digitalWrite(i, HIGH);
  }
  delay(150);
  for(i=3; i<13; i=i+x){
    digitalWrite(i, LOW);
  }
}

void caterpillar(int j){    // Fonction pour faire briller une LED après l'autre
    digitalWrite(j, HIGH);
    delay(150);
    digitalWrite(j, LOW);
}

void caterpillarBlink(int j){   // Fonction pour faire clignoter une LED après l'autre
    digitalWrite(j, HIGH);
    delay(90);
    digitalWrite(j, LOW);
    delay(90);
    digitalWrite(j, HIGH);
    delay(90);
    digitalWrite(j, LOW);
}

void alone(int x){    // Fonction pour faire briller une seule LED
  digitalWrite(x+2, HIGH);
  delay(150);
  digitalWrite(x+2, LOW);
}

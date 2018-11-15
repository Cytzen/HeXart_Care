/* Programme :
   - genère un rythme cardiaque aléatoire (entre 60 et 80 bpm) toutes les secondes (soit 1000ms).
   - Donne une moyenne glissante des valeurs aléatoires du rythme cardiaque sur 5 éléments.
   - Le résultat final est composé de deux éléments : Rythme cardiaque (bpm) et à quel moment il a été prélevé, en ms (tempsMS).

   Programme édité par Julien LORENZO / Gabriel RICARD / Corentin PAUGAM
 */
 
#include "coeur.h"
#include "param.h"

//Déclaration des Variables :
double bps;  // nombre décimal : battements par seconde
unsigned int bpm;  // entier : battement par minute
unsigned int time;  // variable compteur temporel (de base en ms)
unsigned int tempsS;  // variable indiquant le temps en Seconde
unsigned int tempsMS;   // variable indiquant le temps en Milliseconde
float Moy[5];   // Tableau de nombres décimaux stockant les cinq éléement pour calculer une moyenne glissante
float Moye;   // Résultante de la moyenne glissante
int j = 3;
int i;
int val = 0;
int test = 1;

void setup() {
  for(i=3; i<13; i++){
    pinMode(i, OUTPUT); // On initialise les pins sur lesquels sont branchs les LEDs comme sorties.
  }
  Serial.begin(9600);
  for(int i = 0; i<5; i++){
    Moy[i]=random(60,80);
  }
  randomSeed(analogRead(5));
}

void loop() {
  while(test == 1){
    for(int i = 0; i<10 ; i++) {
      Moy[0]=0;
      for(int i =0; i<4;i++){
        Moy[i]=Moy[i+1];
      }
      
      
      bps = random(1000,1333);
      bpm = (bps / 1000)*60;
      time = millis();
      tempsS = tempsS + 1 ;
      tempsMS = tempsS * 1000;
      
      Moy[4]=bpm;
      Moye = (Moy[0]+Moy[1]+Moy[2]+Moy[3]+Moy[4])/5;
    
      switch(mode){ //...on regarde la valeur de mode, et on choisi la fonction correspondante.
        case 1:{
          all();
          delay((1000000/bps)-150);
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
          caterpillar(j);
          j++; 
          if(j>12){ //(1) Ces 4 lignes permettent de boucler la chenille des LEDs 
            j = 3;
          }
          delay((1000000/bps)-150);
          break;
        }
        case 5:{
          caterpillarBlink(j);
          j++;
          if(j>12){ // Same as (1)
            j = 3;
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
    
      Serial.print(tempsMS);
      Serial.print(" ; ");
      Serial.println(Moye);
    }
    test = 0;
  }
}


void all(){
  int i;
  for(i=3; i<13; i++){
    digitalWrite(i, HIGH);
  }
  delay(150);
  for(i=3; i<13; i++){
    digitalWrite(i, LOW);
  }
}

void allBlink(){
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

void oneOuttaX(int x){ 
  int i;
  for(i=3; i<13; i=i+x){
    digitalWrite(i, HIGH);
  }
  delay(150);
  for(i=3; i<13; i=i+x){
    digitalWrite(i, LOW);
  }
}

void caterpillar(int j){
    digitalWrite(j, HIGH);
    delay(150);
    digitalWrite(j, LOW);
}

void caterpillarBlink(int j){
    digitalWrite(j, HIGH);
    delay(90);
    digitalWrite(j, LOW);
    delay(90);
    digitalWrite(j, HIGH);
    delay(90);
    digitalWrite(j, LOW);
}

void alone(int x){
  digitalWrite(x+2, HIGH);
  delay(150);
  digitalWrite(x+2, LOW);
}

/*
case 7:{
  for(i=3; i<8; i++){
    digitalWrite(i, HIGH);
    digitalWrite(i+5, HIGH);
    delay(40); 
  }
  for(i=3; i<8; i++){
    digitalWrite(i, LOW);
    digitalWrite(i+5, LOW);
    delay(40);
  }
  delay(200);
  break;
}*/

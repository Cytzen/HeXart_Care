#include "coeur.h"
#include "param.h"

int i = 3;
int val = 0;

void setup() {
  for(i=3; i<13; i++){
    pinMode(i, OUTPUT); // On initialise les pins sur lesquels sont branchs les LEDs comme sorties.
  }
  pinMode(2, INPUT); // On initialise le pin 2 comme entrée.
}

void loop() {
  val = digitalRead(2); // On attribue l'état (HIGH ou LOW) du pin 2 à la variable val.
  if (val == 1){ // Si val(le pin 2) est à l'état haut...
    switch(mode){ //...on regarde la valeur de mode, et on choisi la fonction correspondante.
      case 1:{
        all();
        break;
      }
      case 2:{
        allBlink();
        break;
      }
      case 3:{ 
        oneOuttaX(x);
        break;
      }
      case 4:{
        caterpillar(i);
        i++; 
        if(i>12){ //v(1) Ces 4 lignes permettent de boucler la chenille des LEDs 
          i = 3;
        }
        break;
      }
      case 5:{
        caterpillarBlink(i);
        i++;
        if(i>12){ // Same as (1)
          i = 3;
        }
        break;
      }
      case 6:{
        alone(x);
        break;
      }
    }
    delay(100);
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

void caterpillar(int i){
    digitalWrite(i, HIGH);
    delay(200);
    digitalWrite(i, LOW);
}

void caterpillarBlink(int i){
    digitalWrite(i, HIGH);
    delay(100);
    digitalWrite(i, LOW);
    delay(100);
    digitalWrite(i, HIGH);
    delay(100);
    digitalWrite(i, LOW);
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

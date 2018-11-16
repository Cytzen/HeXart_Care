/* Programme :
   - genère un rythme cardiaque aléatoire (entre 60 et 80 bpm) toutes les secondes (soit 1000ms).
   - Donne une moyenne glissante des valeurs aléatoires du rythme cardiaque sur 5 éléments.
   - Le résultat final est composé de deux éléments : Rythme cardiaque (bpm) et à quel moment il a été prélevé, en ms (tempsMS).

   Programme édité par Julien LORENZO / Gabriel RICARD
 */




//Déclaration des Variables :
double bps;  // nombre décimal : battements par seconde
unsigned int bpm;  // entier : battement par minute
unsigned int time;  // variable compteur temporel (de base en ms)
unsigned int tempsS;  // variable indiquant le temps en Seconde
unsigned int tempsMS;   // variable indiquant le temps en Milliseconde
float Moy[5];   // Tableau de nombres décimaux stockant les cinq éléement pour calculer une moyenne glissante
float Moye;   // Résultante de la moyenne glissante



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
 /* pinMode(3, OUTPUT);*/ 

 for(int i = 0; i<5; i++){
    Moy[i]=random(60,80);
  }
}



void loop() {
  // put your main code here, to run repeatedly:

  for(int i = 0; i<10 ; i++) {
    Moy[0]=0;
   for(int i =0; i<4;i++){
      Moy[i]=Moy[i+1];
   }


    bps = random (1000,1333);
    bpm = (bps / 1000)*60;
    time = millis();
    tempsS = time /1000 ;
    tempsMS = tempsS * 1000;

  
    Moy[4]=bpm;
    Moye = (Moy[0]+Moy[1]+Moy[2]+Moy[3]+Moy[4])/5;

  

  
  



/*{  
digitalWrite(3,HIGH); 
delay(bps); 
digitalWrite(3,LOW); 
delay(abs(1000-bps));/*ajouter valeur absolu
}*/


  Serial.print(bpm);
  Serial.print(";");
  Serial.println(tempsMS); 

  delay(1000);
 }
  exit(0);
   /* ancienne formule
  bps = random (700,750);
  bpm = (1000/bps)*60;
  time = millis();
  tempsS = time /1000 ;
  */
}

double bps;
unsigned int bpm;
unsigned int time;
unsigned int tempsS;
unsigned int tempsMS;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
 /* pinMode(3, OUTPUT);*/ 
}

void loop() {
  // put your main code here, to run repeatedly:
  bps = random (800,1160);
  bpm = (bps * 60)/1000;
  time = millis();
  tempsS = time /1000 ;
  tempsMS = tempsS * 1000;

/*{  
digitalWrite(3,HIGH); 
delay(bps); 
digitalWrite(3,LOW); 
delay(abs(1000-bps));/*ajouter valeur absolu
}*/

 Serial.print(bpm);
 Serial.print(";");
 Serial.println( tempsMS ); 

 delay(1000);
 
   /* ancienne formule
  bps = random (700,750);
  bpm = (1000/bps)*60;
  time = millis();
  tempsS = time /1000 ;
  */
}

/*programme genenrant les pulsations du coeur 
Format .ino*/
double bps;
unsigned int bpm;
unsigned int time;
unsigned int tempsS;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  bps = random (850,1160);
  bpm = (bps * 60)/1000;
  time = millis();
  tempsS = time /1000 ;
  
/*{  
digitalWrite(3,HIGH); 
delay(bps); 
digitalWrite(3,LOW); 
delay(abs(1000-bps));/*ajouter valeur absolu
}*/

 Serial.print(bpm);
 Serial.print(";");
 Serial.println(tempsS); 

 delay(1000);
 
}

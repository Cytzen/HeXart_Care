//From Arduino to Processing to Txt or cvs etc.
//import
import processing.serial.*;
//declare
PrintWriter output;
Serial udSerial;

void setup() {

  udSerial = new Serial(this, Serial.list()[0], 9600);
  output = createWriter ("Battements.csv");
}

  void draw() {
    if (udSerial.available() > 0) {
      String SenVal = udSerial.readString();
      /* int Heure = hour();
      int Minute = minute();
      int Seconde = second();
      int Jour = day();
      int Mois = month();
      int Annee = year();*/
      if (SenVal != null) {
        output.println(SenVal/*+"     "+Jour+"/"+Mois+"/"+Annee+"  "+Heure+":"+Minute+" "+Seconde+"s"*/);
      }
    }
  }

  void keyPressed(){
    output.flush();
    output.close();
    exit(); 
  }

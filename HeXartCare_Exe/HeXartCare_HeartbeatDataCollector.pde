//From Arduino to Processing to Txt or cvs etc.
//import
import processing.serial.*;   // importation de la bibliothèque Serial
//declare
PrintWriter output;      // variable output du type PrintWriter, qui désigne un fichier éditable
Serial udSerial;         // variable du type serial qui désigne un port série

void setup() {

  udSerial = new Serial(this, Serial.list()[0], 9600);   // définition du port USB correspondant à la carte Arduino
  output = createWriter ("HeartbeatData.csv");              // association du fixhier tableur excel pour notre variable output
}

  void draw() {                                       // procédure qui execute toutes les instruction puis une fois terminé recommence
    if (udSerial.available() > 0) {                   // vérifie si le port USB est disponible/accessible
      String SenVal = udSerial.readString();          // SenVal est une variable de type chaîne de caractère, et prend la valeur que la carte Arduino envoie sur le Port USB
      println(SenVal);
      /* int Heure = hour();       //entier désignant l'heure système
      int Minute = minute();       //entier désignant la minute système
      int Seconde = second();      //entier désignant les secondes système
      int Jour = day();            
      int Mois = month();            //entiers désignant la date système (Jour/Mois/Année)
      int Annee = year();*/
      if (SenVal != null) {            // ecrit SenVal dans battements.csv si SenVal n'est pas nul
        output.println(SenVal/*+"     "+Jour+"/"+Mois+"/"+Annee+"  "+Heure+":"+Minute+" "+Seconde+"s"*/);
      }
    }
  }

  void keyPressed(){           // procédure qui s'execute si une touche du clavier est activée
    output.flush();            // ecrit les dernières valeurs dans le tableur
    output.close();            // ferme le fichier tableur
    exit();                    // arrête le programme
  }

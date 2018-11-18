
float A = 1;                    
bool MoinSeuil = false;        // variable booléenne désignant si ou non le seuil est atteint
int battements = 0;            // variable comptant le nombre de battement
int C = 0;                     // variable compteur
int S = 0;                     // variable comptant les secondes écoulées
float Moy[50];                 // tableau stockant les éléments dont on veut faire la moyenne
float Moye;                    // moyenne glissante sur 50 éléments


void setup() {
  for(int i = 0; i<50; i++){      //initialisation des élément du tableau
    Moy[i]=0;
    pinMode(13, OUTPUT);          // désigne le pin N°13 comme étant une sortie
  }
  Serial.begin(9600);             // définition du baudrate à 9600
}

void loop() {
  C=C+1;
  A = analogRead(0);           // A prend la valeur du pin Analogique (A0)
  Moy[49]= A;                  // Le dernier élément du tableau prend la valeur de A et le premier 0
  Moy[0]=0;
  for(int i =0; it<49;i++){    // Permet de faire glisser le élément du tableau
    Moy[i]=Moy[i+1];
  }
  Moye = (Moy[0]+Moy[1]+Moy[2]+Moy[3]+Moy[4]+Moy[5]+Moy[6]+Moy[7]+Moy[8]+Moy[9]+Moy[10]+Moy[11]+Moy[12]+Moy[13]+Moy[14]+Moy[15]+Moy[16]+Moy[17]+Moy[18]+Moy[19]+Moy[20]+Moy[21]+Moy[22]+Moy[23]+Moy[24]+Moy[25]+Moy[26]+Moy[27]+Moy[28]+Moy[29]+Moy[30]+Moy[31]+Moy[32]+Moy[33]+Moy[34]+Moy[35]+Moy[36]+Moy[37]+Moy[38]+Moy[39]+Moy[40]+Moy[41]+Moy[42]+Moy[43]+Moy[44]+Moy[55]+Moy[46]+Moy[47]+Moy[48]+Moy[49])/50;
       // Moye prend la valeur moyenne de tout les éléments du tableau

  
  if(MoinSeuil == false){                 // si le seuil n'est pas atteint
    if(Moye > 170){                       // on vérifie si Moye(la moyenne glisssante) dépasse 170
      battements = battements + 1;        // si elle dépasse on considère que c'est +1 battement 
       digitalWrite(13, HIGH);            // on active la sortie digitale 13 pendant 5ms
       delay(5);
       digitalWrite(13, LOW);
      MoinSeuil = true;                   // et on cosidère qu'on est au dessus du seuil
    }
  }
  if(Moye < 170){                         // puis quand la moyenne descend en dessous de 170
    MoinSeuil = false;                    // on considère qu'on est en dessous du seuil
  }
  if(C == 750){                           // quand C est égal à 750 cela veut dire qu'il s'est écoulé 3 secondes
    C = 0;                                // on remet le compteur à 0
    S = S + 3;                            // on ajoute trois secondes au compteur S
    battements = battements * 20;         // on détermine le BPM d'une mesure sur trois secondes
    Serial.print(S);             
    Serial.print(";");                    // on envoie les données au port USB
    Serial.print(battements);
    battements = 0;                       // on remet le compteur de battement à 0
  }
  delay(4);                               // on applique un delais de 4 ms sur toute la procédure loop
}

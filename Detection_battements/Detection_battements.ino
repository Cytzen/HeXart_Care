
float A = 1;
bool MoinSeuil = false;
int battements = 0;
int C = 0;
int S = 0;
float Moy[50];
float Moye;
void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i<50; i++){
    Moy[i]=0;
  }
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  C=C+1;
  A = analogRead(0);
  Moy[49]= A;
  Moy[0]=0;
  for(int i =0; i<49;i++){
    Moy[i]=Moy[i+1];
  }
  Moye = (Moy[0]+Moy[1]+Moy[2]+Moy[3]+Moy[4]+Moy[5]+Moy[6]+Moy[7]+Moy[8]+Moy[9]+Moy[10]+Moy[11]+Moy[12]+Moy[13]+Moy[14]+Moy[15]+Moy[16]+Moy[17]+Moy[18]+Moy[19]+Moy[20]+Moy[21]+Moy[22]+Moy[23]+Moy[24]+Moy[25]+Moy[26]+Moy[27]+Moy[28]+Moy[29]+Moy[30]+Moy[31]+Moy[32]+Moy[33]+Moy[34]+Moy[35]+Moy[36]+Moy[37]+Moy[38]+Moy[39]+Moy[40]+Moy[41]+Moy[42]+Moy[43]+Moy[44]+Moy[55]+Moy[46]+Moy[47]+Moy[48]+Moy[49])/50;
  
  if(MoinSeuil == false){
    if(Moye > 170){
      battements = battements + 1;
      MoinSeuil = true;
    }
  }
  if(Moye < 170){
    MoinSeuil = false;
  }
  if(C == 750){
    C = 0;
    S = S + 3;
    battements = battements * 20;
    Serial.print(battements);
    Serial.print(";");
    Serial.println(S);
    battements = 0;
  }
  delay(4);
}

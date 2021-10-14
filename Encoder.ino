int SW=13;
int outputCLK=11;
int outputDT=10;
int most=1;
int ezelott=1;
int szamlalo=50;
int LED=3;
byte fenyEro=0;

void setup() {
  Serial.begin(9600);
  Serial.println("Encoder kezelő program!");
  for(int i=10;i<=13;i++) pinMode(i, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  //digitalWrite(LED, 1);

}

void loop() {
  if(digitalRead(SW)==0) {szamlalo=50;}
  
  most=digitalRead(outputCLK);
  if (most != ezelott)
  {
    if(digitalRead(outputDT) != most) { szamlalo=szamlalo-10;}
      else { szamlalo=szamlalo+10;}
     szamlalo=constrain(szamlalo, 0,100);
     Serial.print("A fényerő: ");
    Serial.println(szamlalo);
    Serial.print("%");
    
  }
   ezelott=most;
   fenyEro=map(szamlalo,0,100,0,255);
   analogWrite(LED, fenyEro);
  
   
   }

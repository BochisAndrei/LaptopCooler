//include biblioteca dht.h pentru a putea utiliza sensorul de umiditate si temperatura
#include <dht.h>
//creeam o variabila de tip DHT
dht DHT; 
//folosim un define pt pin-ul la care e legat sensorul de temperatura
#define DHT11_PIN 11

//declaram un int pt a salva valoarea rezultata din intensitatea luminii
unsigned int AnalogValue;
//pastram un contor care va avea valori intre 0 si 255
unsigned int Luminiozitate = 0;

const int greenLed1 = 12;
const int redLed2 = 10;
const int greenLed2 = 9 ;
const int redLed3 = 8;
const int redLed4 = 7;
const int redLed5 = 6;
const int redLed1 = 5;


void setup() {
  // put your setup code here, to run once:
     Serial.begin(9600);
     pinMode(redLed1,OUTPUT);
     pinMode(redLed2,OUTPUT);
     pinMode(redLed3,OUTPUT);
     pinMode(redLed4,OUTPUT);
     pinMode(redLed5,OUTPUT);
     
     pinMode(greenLed1,OUTPUT);
     pinMode(greenLed2,OUTPUT);
     //pinMode(buttonPin, INPUT);
     
}

void loop() {
  //buttonState = digitalRead(buttonPin);
 
  //initializam biblioteca DHT
  int canalSenzor = DHT.read11(DHT11_PIN);
  Serial.print("Temperatura: ");
  Serial.print(DHT.temperature);//afisam temperatura
  Serial.print("°C        ");
  Serial.print("Umiditate: ");//afisam umiditatea
  Serial.print(DHT.humidity);
  Serial.print("%");
  Serial.println("");

  //In functie de luminiozitatea de afara vom 
  //regla nivelul de iluminare a beculetelor
  AnalogValue = intensitateLumina();
  Luminiozitate = AnalogValue/4;

  if((AnalogValue/4)>255)
      Luminiozitate = 255;
      
   if(Luminiozitate > 50){
    if(Luminiozitate < 150 ){
      analogWrite(redLed1,125);
      analogWrite(redLed2,125);
      analogWrite(redLed3,125);
      analogWrite(redLed4,125);
      analogWrite(redLed5,125);
      analogWrite(greenLed1,125);
      analogWrite(greenLed2,125);
    }
    else if(Luminiozitate < 200){
      analogWrite(redLed1,175);
      analogWrite(redLed2,175);
      analogWrite(redLed3,175);
      analogWrite(redLed4,175);
      analogWrite(redLed5,175);
      analogWrite(greenLed1,175);
      analogWrite(greenLed2,175);
    }
    else if(Luminiozitate < 255)
      analogWrite(redLed1,255);
      analogWrite(redLed2,255);
      analogWrite(redLed3,255);
      analogWrite(redLed4,255);
      analogWrite(redLed5,255);
      analogWrite(greenLed1,255);
      analogWrite(greenLed2,255);
   }
   else{
     analogWrite(redLed1,LOW);
     analogWrite(redLed2,LOW);
     analogWrite(redLed3,LOW);
     analogWrite(redLed4,LOW);
     analogWrite(redLed5,LOW);
     analogWrite(greenLed1,LOW);
     analogWrite(greenLed2,LOW);
   }
   
   
  //Serial.print("    Lumina:"); //afisam intensitatea luminii
  //Serial.print(numarLuminiozitate);
  //Serial.println("");  
     
  delay(3000);
  
}

//functie care returneaza valoarea luminii
int intensitateLumina(){
  unsigned int AnalogValue;
  AnalogValue = analogRead(A0);//citim valoarea primita prin portul A0
  return AnalogValue;
  
}

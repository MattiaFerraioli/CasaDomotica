#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 7
OneWire ourWire(ONE_WIRE_BUS);
DallasTemperature sensors(&ourWire);
    
long unsigned int lowIn;        

long unsigned int pause = 5000;  
 
boolean lockLow = true;
boolean takeLowTime;  
 
int pirPin = 3;    
int ledPin = 13;
int lucePir = 11;
const int sensorPin= 0;
bool all=false,fumo=false;
int intruso = 0;

int smoke_level;
int calibrationTime = 5;  
void setup() {
  
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  digitalWrite(pirPin, LOW);
  pinMode(sensorPin, INPUT); //fumo
  pinMode(ledPin, OUTPUT);
  pinMode(lucePir, OUTPUT);

  //give the sensor some time to calibrate
  Serial.print("CALIBRAZIONE SENSORE PIR ");
    for(int i = 0; i < calibrationTime; i++){
      Serial.print(".");
      delay(1000);
      }
    Serial.println("fatto");
    Serial.println("SENSORE ATTIVO");
    delay(50);
}


void loop() {
  if(digitalRead(pirPin) == HIGH && intruso==0 && all==true){
        digitalWrite(lucePir, HIGH);   
        intruso = 1;
        Serial.println("1");
        exit;
    }
 
   else if(digitalRead(pirPin) == LOW){      
       digitalWrite(lucePir, LOW);
       intruso =0;
       exit;
       }

     smoke_level= analogRead(sensorPin);
     if(smoke_level > 150 && fumo==true){ 
      //  digitalWrite(ledPin, HIGH);
        Serial.println("2");
      }
      
  String val=Serial.readString();
  if(val=="3") //spegni allarme
  {
    all=false;
  }
  else if(val=="4") //accendi allarme
  {
    all=true;
  }
  else if(val=="5") //spegni fumo
  {
    fumo=false;
  }
  else if(val=="6") //accendi fumo
  {
    fumo=true;
  }
  
  if(val=="7") //accendi luce
  {
    digitalWrite(ledPin, HIGH);
    Serial.println("LedAccesso");
    exit;
  }
  else if(val=="8") //spegni luce
  {
    digitalWrite(ledPin, LOW);
    Serial.println("LedSpento");
    exit;
  }
  else if(val=="9") //temperatura
  {
    delay(1000);
    sensors.requestTemperatures();
    Serial.println(sensors.getTempCByIndex(0));
    exit;
  }

val="";
  
}

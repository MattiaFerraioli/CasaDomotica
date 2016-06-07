#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 7
OneWire ourWire(ONE_WIRE_BUS);
DallasTemperature sensors(&ourWire);
      
//the time when the sensor outputs a low impulse
long unsigned int lowIn;        
 
//the amount of milliseconds the sensor has to be low
//before we assume all motion has stopped
long unsigned int pause = 5000;  
 
boolean lockLow = true;
boolean takeLowTime;  
 
int pirPin = 3;    //the digital pin connected to the PIR sensor's output
int ledPin = 13;
int lucePin = 11;
const int sensorPin= 0;
bool all=false,fumo=false;
int intruso = 0;

int smoke_level;
int calibrationTime = 5;  
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  digitalWrite(pirPin, LOW);
  pinMode(sensorPin, INPUT); //fumo
  pinMode(13, OUTPUT);

  //give the sensor some time to calibrate
  Serial.print("CALIBRAZIONE SENSORE ");
    for(int i = 0; i < calibrationTime; i++){
      Serial.print(".");
      delay(1000);
      }
    Serial.println("fatto");
    Serial.println("SENSORE ATTIVO");
    delay(50);
}

// the loop routine runs over and over again forever:
void loop() {
  if(digitalRead(pirPin) == HIGH && intruso==0 && all==true){
        digitalWrite(11, HIGH);   
        intruso = 1;
        Serial.println("allarme");
        exit;
    }
 
   else if(digitalRead(pirPin) == LOW){      
       digitalWrite(11, LOW);
       intruso =0;
       exit;
       }

     smoke_level= analogRead(sensorPin);
     if(smoke_level > 200 && fumo==true){ 
      //  digitalWrite(ledPin, HIGH);
        Serial.println("fumo");
      }
      
  String val=Serial.readString();
  if(val=="SpegniAllarme")
  {
    all=false;
  }
  else if(val=="AccendiAllarme")
  {
    all=true;
  }
  else if(val=="SpegniFumo")
  {
    fumo=false;
  }
  else if(val=="AccendiFumo")
  {
    fumo=true;
  }
  
  if(val=="ALED")
  {
    digitalWrite(ledPin, HIGH);
    Serial.println("LedAccesso");
    exit;
  }
  else if(val=="SLED")
  {
    digitalWrite(ledPin, LOW);
    Serial.println("LedSpento");
    exit;
  }
  else if(val=="TEMP")
  {
    sensors.requestTemperatures();
    Serial.println(sensors.getTempCByIndex(0));
    exit;
  }

val="";
//Serial.println("nullo");
  
}

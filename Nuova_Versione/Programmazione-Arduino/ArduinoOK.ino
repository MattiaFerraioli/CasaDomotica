#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 7
OneWire ourWire(ONE_WIRE_BUS);
DallasTemperature sensors(&ourWire);

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(13, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  String val=Serial.readString();

  if(val=="ALED")
  {
    digitalWrite(13, HIGH);
    Serial.println("LedAccesso");
    
  }
  else if(val=="SLED")
  {
    digitalWrite(13, LOW);
    Serial.println("LedSpento");
  }
  else if(val=="TEMP")
  {
    sensors.requestTemperatures();
    Serial.println(sensors.getTempCByIndex(0));
    exit;
  }

val="";

  
}

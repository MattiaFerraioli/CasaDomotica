int calibrationTime = 5;        
int i=0;
//the time when the sensor outputs a low impulse
long unsigned int lowIn;        
 
//the amount of milliseconds the sensor has to be low
//before we assume all motion has stopped
long unsigned int pause = 5000;  
 
boolean lockLow = true;
boolean takeLowTime;  
 
int pirPin = 3;    //the digital pin connected to the PIR sensor's output
int ledPin = 13;
 
 
/////////////////////////////
//SETUP
void setup(){
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(pirPin, LOW);
 
  //give the sensor some time to calibrate
  Serial.print("CALIBRAZIONE SENSORE ");
    for(int i = 0; i < calibrationTime; i++){
      Serial.print(".");
      delay(1000);
      }
    Serial.println(" fatto");
    Serial.println("SENSORE ATTIVO");
    delay(50);
  }
 
////////////////////////////
//LOOP
void loop(){
 i=0;
     if(digitalRead(pirPin) == HIGH){
       digitalWrite(ledPin, HIGH);   //the led visualizes the sensors output pin state
       
         //makes sure we wait for a transition to LOW before any further output is made:
         //lockLow = false;            
         //Serial.println("---");
         Serial.print(i);
         Serial.println("movimento rilevato");
         //Serial.print(millis()/1000);
        // Serial.println(" sec");
         //delay(50);
         
       }
 
    if(digitalRead(pirPin) == LOW){      
       digitalWrite(ledPin, LOW);
       }
}
  


void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(13, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  String val= "SLED";
  

  if(val=="ALED")
  {
    digitalWrite(13, HIGH);
    Serial.println("LedAccesso");
    val= "SLED";
    
  }
  else if(val=="SLED")
  {
    digitalWrite(13, HIGH);
    Serial.println("LedSpento");
  }
  else if(val=="TEMP")
  {
    exit;
  }


  
}




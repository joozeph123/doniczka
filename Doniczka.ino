/*
  AnalogReadSerial
  Reads an analog input on pin 0, prints the result to the serial monitor.
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.
 
 This example code is in the public domain.
 */

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
  pinMode(2, OUTPUT); 
  pinMode(17, OUTPUT); 
  digitalWrite(17, LOW);    // turn the LED off by making the voltage LOW
}

int poziom = 400;

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // print out the value you read:
  Serial.print("wartosc = ");
  Serial.println(sensorValue);
  
  if (sensorValue < poziom) {
    // HALASUJEMY
    digitalWrite(2, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(100);               // wait for a second
    digitalWrite(2, LOW);    // turn the LED off by making the voltage LOW
  }
  
  delay(1000);        // delay in between reads for stability
}

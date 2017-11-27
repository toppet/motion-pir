int ledPin = 13;                // choose the pin for the LED
int inputPin = 2;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0; // variable for reading the pin status
int photoSensorPin = A0;
int photoSensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(inputPin, INPUT);     // declare sensor as input
}
 
void loop(){
  photoSensorValue = analogRead(photoSensorPin);
  if(photoSensorValue <= 5) {
    val = digitalRead(inputPin);  
    if (val == HIGH) {
      digitalWrite(ledPin, HIGH);
      if (pirState == LOW) {
        pirState = HIGH;
      }
      delay(5000);
    } else {
      digitalWrite(ledPin, LOW);
      if (pirState == HIGH){
        Serial.println("Motion ended!");
        pirState = LOW;
      }
    }
  } else {
    if (val == HIGH) {
      digitalWrite(ledPin, LOW);
    }
  }
}

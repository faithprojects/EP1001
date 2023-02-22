// Read data from the serial and turn ON or OFF a light depending on the value
// led #PA2 (3)
// led #PA6 (0)
// led #PA7 (1)
//

char val;                          // Data received from the serial port
int ledPin = 1;                    // Set the pin to digital I/O 7

void setup() {
  pinMode(ledPin, OUTPUT);         // Set pin as OUTPUT
  Serial.swap(1);                  //alt tx/rx used
  Serial.begin(9600);              // Start serial communication at 9600 bps
}

void loop() {
  if (Serial.available()) {        // If data is available to read,
    val = Serial.read();           // read it and store it in val
  if (val == 'H') {                // If H was received
    digitalWrite(ledPin, HIGH);    // turn the LED on
  } else if (val == 'L') {
    digitalWrite(ledPin, LOW);     // Otherwise turn it OFF
    }
  }
  delay(100);                      // Wait 100 milliseconds for next reading
}

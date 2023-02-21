//WORKING CODE
//Press Button to on and off LED to display on serial monitor if the led is on or off

//LED @PA7 (1)
//TX @PA1 (0)
//RX @PA2 (1)
//Button @PA6 (0)
const int BUTTON = 0;
const int led = 1;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(BUTTON, INPUT);
  Serial.swap(1);   //Swap the RX and TX to allow data to be read for the serial monitor
  Serial.begin(9600);

}

void loop() {
  if (digitalRead(BUTTON) == HIGH){
    digitalWrite(led,HIGH);
    Serial.println("LED is ON");
  }
  else
  {
    digitalWrite(led,LOW);
    Serial.println("LED is OFF");
  }


}

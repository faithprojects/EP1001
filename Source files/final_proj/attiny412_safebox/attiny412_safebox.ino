//#include <Servo_megaTinyCore.h>

#include <tinyNeoPixel.h>

//Servo myServo;

#define NUMLEDS 10  //Number of Leds on the neopixel strip

#define ledPin PIN_PA6 //Neopixel pin
#define BUTTON PIN_PA2 //Push button pin
#define RPin PIN_PA7   //Reed switch 1 pin
#define RPin2 PIN_PA1  //Reed switch 2 pin
#define ServoPin PIN_PA3  //Servo motor pin

tinyNeoPixel leds = tinyNeoPixel(NUMLEDS, ledPin, NEO_GRB);

int timer;


void setup() {
  //myServo.attach(ServoPin);
  leds.begin();    // initialize the strip
  leds.clear();    //clear the strip
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(RPin, INPUT_PULLUP);
  pinMode(RPin2, INPUT_PULLUP);
}

void loop() {
  //When the button is pressed, game starts
  if (digitalRead(BUTTON) == LOW){
    delay(15);
    //myServo.write(90);    //Locks the safe door
    //delay(15);
    while (digitalRead(BUTTON) == LOW);
    //Light Sequence when the game starts
    for (int i = 0; i < NUMLEDS; ++i)
    {
      leds.setPixelColor(i, 22, 255, 0);       // LIGHT GREEN
      leds.show();
      delay(200);
      leds.setPixelColor(i, 55, 146, 55);       // GREEN
      leds.show();
    }
    leds.clear();

    //Countdown light sequence
    for (timer =0; timer <= 10; timer++) {
      leds.setPixelColor(timer, 220, 0, 0);       // RED
      leds.show();
      
      int proximity = digitalRead(RPin); // Read the state of the switch
      int proximity2 = digitalRead(RPin2); // Read the state of the switch
      delay(1000);
      
      //If reed switches are on, you win the game
      if (proximity == LOW && proximity2 == LOW) {
        //myServo.write(180);       //Unlocks the safe door
        //delay(15);
        //Light Sequence when you win the game
        for (int i = 0; i < NUMLEDS; ++i)
        {
          leds.setPixelColor(i, 91, 46, 126);       // WHITE
          leds.show();
          delay(200);
          leds.setPixelColor(i, 0, 0, 32);       // BLUE
          leds.show();
        }
        break;
      
      }
      
      else {
        leds.clear();
        leds.show();

        //if timer is already 10 secs, time's up!
        if (timer == 10) {
          //Light Sequence when you failed the game
          for (int i = 0; i < NUMLEDS; ++i)
          {
            leds.setPixelColor(i, 255, 139, 19);       // RED
            leds.show();
            delay(200);
            leds.setPixelColor(i, 250, 171, 120);       // BLUE
            leds.show();
          }
        }
      }
      
      delay(1000);
      
    }
  }
  else {
    delay(1000);
  }
  
  
}

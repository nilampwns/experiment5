/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo1;
Servo myservo2;

int pos1;
int pos2;

unsigned long previousMillis = 0;
unsigned long previousMillis2 = 0;

void setup() {
  myservo1.attach(9);
  myservo2.attach(10);
}

void loop() {
//myservo1.write(180);
//myservo2.write(180);


unsigned long currentMillis = millis();
unsigned long currentMillis2 = millis();


  if (currentMillis2 - previousMillis2 >= 10) {
      previousMillis2 = currentMillis2;
      for (pos2 = 100; pos2 <= random(150,180); pos2 += 5) {
        myservo2.write(pos2);
        //delay(100);
        if (currentMillis - previousMillis >= 10) {
            previousMillis = currentMillis;
            for (pos1 = random(60,80); pos1 <= 150; pos1 += 1) {
            myservo1.write(pos1); 
            //delay(100);
          }
        }
      }
  }

  if (currentMillis - previousMillis >= 10) {
      previousMillis = currentMillis;
      for (pos1 = 150; pos1 >= random(60,80); pos1 -= 1) {
        myservo1.write(pos1);
        //delay(100);
      }
  }
  if (currentMillis2 - previousMillis2 >= 10) {
      previousMillis2 = currentMillis2;
      for (pos2 = random(130,160); pos2 >= 100; pos2 -= 5) {
        myservo2.write(pos2);
        //delay(100);
      }
  }
  //delay(100);
}

#include <Servo.h>
/* Nb notches for 360 degrees */
#define NOTCHES 154 
#define HALF_TONE_RATIO 1.0595

float NOTCHES_PER_DEGREE = NOTCHES / 360.0;

int freq_to_delay(float freq) {
  return (NOTCHES_PER_DEGREE / freq);
}

Servo myservo;  // create servo object to control a servo
int pos = 0;    // variable to store the servo position
void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}


void loop() {

  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees

    // in steps of 1 degree

    myservo.write(pos);              // tell servo to go to position in variable 'pos'

    delay(1);            // waits 15ms for the servo to reach the position

  }

  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees

    myservo.write(pos);              // tell servo to go to position in variable 'pos'

    delay(1);                       // waits 15ms for the servo to reach the position

  }

}

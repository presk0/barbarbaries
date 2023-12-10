#include <Servo.h>
/* Nb notches for 360 degrees */
#define NOTCHES 154
#define REF_TONE 60
#define HALF_TONE_RATIO 1.0595
#define TONE_RATIO 1.1225 // half_tone^2

float NOTCHES_PER_DEGREE = NOTCHES / 360.0;
Servo myservo;  // create servo object to control a servo
int freq_to_delay(float freq) {
  return ((float)NOTCHES_PER_DEGREE / freq) * 1000;
}

void  play_push(float freq) {
  for (int pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(freq_to_delay(freq));            // waits 15ms for the servo to reach the position
  }
}

void  play_pull(float freq) {
  for (int pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(freq_to_delay(freq));            // waits 15ms for the servo to reach the position
  }
}



//int pos = 0;    // variable to store the servo position
float DO = REF_TONE;
float RE = REF_TONE * TONE_RATIO;
float MI = RE * TONE_RATIO;
float FA = MI * HALF_TONE_RATIO;
float SOL = FA * TONE_RATIO;
float LA = SOL * TONE_RATIO;
void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
}

void loop() {
  Serial.print(freq_to_delay(DO));
  Serial.print(freq_to_delay(RE));
  Serial.print(freq_to_delay(MI));
  Serial.print(freq_to_delay(FA));
  Serial.print(freq_to_delay(SOL));
  play_pull(DO);
  play_push(RE);
  play_pull(MI);
  play_push(FA);
  play_pull(SOL);
  play_push(LA);
}

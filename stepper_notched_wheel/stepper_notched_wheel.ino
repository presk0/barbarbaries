#define in1 8
#define in2 9
#define in3 10
#define in4 11
#define NOTCHES 154
#define REF_TONE 60
#define HALF_TONE_RATIO 1.0595
#define TONE_RATIO 1.1225 // half_tone^2

float NOTCHES_PER_STEP = NOTCHES / 360.0 * 64;


//int pos = 0;    // variable to store the servo position
float DO = REF_TONE;
float RE = REF_TONE * TONE_RATIO;
float MI = RE * TONE_RATIO;
float FA = MI * HALF_TONE_RATIO;
float SOL = FA * TONE_RATIO;
float LA = SOL * TONE_RATIO;

int freq_to_delay(float freq) {
  return ((float)NOTCHES_PER_STEP / freq) * 1000000 / 4; //4 steps in 1 play
}

// limite de delayMicroseconde = 1560
void    play(float freq, int pins[4]) {
    digitalWrite(pins[0], HIGH); 
    digitalWrite(pins[1], LOW); 
    digitalWrite(pins[2], LOW); 
    digitalWrite(pins[3], HIGH);
    delayMicroseconds(freq_to_delay(freq));

    digitalWrite(pins[0], HIGH); 
    digitalWrite(pins[1], HIGH); 
    digitalWrite(pins[2], LOW); 
    digitalWrite(pins[3], LOW);
    delayMicroseconds(freq_to_delay(freq));

    digitalWrite(pins[0], LOW); 
    digitalWrite(pins[1], HIGH); 
    digitalWrite(pins[2], HIGH); 
    digitalWrite(pins[3], LOW);
    delayMicroseconds(freq_to_delay(freq));

    digitalWrite(pins[0], LOW); 
    digitalWrite(pins[1], LOW); 
    digitalWrite(pins[2], HIGH); 
    digitalWrite(pins[3], HIGH);
    delayMicroseconds(freq_to_delay(freq));
}

void setup() {
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
}

void loop() {
    int pins[] = {in1, in2, in3, in4};
    for (int i = 0; i < 1000; i++)
        play(DO, pins);
    for (int i = 0; i < 1000; i++)
        play(RE, pins);
}

// Fade an LED in and out like on
// a sleeping computer

const int LED = 13;  // the pin for the standard LED
int i = 0;           // We'll use this to count up and down
int flex_sensor_pin = A0;      // analog input pin for flex sensor input
int begin_loop = 0;
int flex_value = 0;
int left_eye[3] = {9, 10, 11}; // arrays control our led rgb pins
int right_eye[3] = {3, 5, 6};  // to keep the code a little simpler
// green: pin 9
// red:   pin 10
// blue:  pin 11

void setup() {
    attachInterrupt(flex_sensor_pin, detect_flex, RISING);
    pinMode(left_eye[0], OUTPUT);
    pinMode(left_eye[1], OUTPUT);
    pinMode(left_eye[2], OUTPUT);
    pinMode(right_eye[0], OUTPUT);
    pinMode(right_eye[1], OUTPUT);
    pinMode(right_eye[2], OUTPUT);
    pinMode(LED, OUTPUT);
    Serial.begin(9600);
}

void loop() {
  sleepy_eyes();
  detect_flex();
  delay(500);
  // begin_loop = micros();
  // detect_flex();
  // delay(1000);
  // wait for flex sensor input to call these functions
  // nukular_eyes_on();
  // delay(1000);
  // nukular_eyes_off();
  // delay(1000);
  // rainbow_eyes();
  // delay(1000);
  // sleepy_eyes();
  // delay(1000);
}
// end of main loop                                     

void detect_flex() {
  // this function will handle our flex sensor input.
  // Base unflexed value is ~800.
  flex_value = analogRead(flex_sensor_pin);
  if (flex_value > 820 && flex_value < 900) {
    red_eyes_on();
  }
  else {
    red_eyes_off();
  }
  // if (flex_value < 900) {
  //   nukular_eyes_on();
  // }
  // else {
  //   nukular_eyes_off();
  // }
  Serial.println(flex_value);
}

void nukular_eyes_on() {
  // this function turns on all three colors in our 
  // rgb led, for super white bright eyes!
  for (i = 0; i < 3; i++) {
    digitalWrite(left_eye[i], HIGH);
    digitalWrite(right_eye[i], HIGH);
  }
}

void nukular_eyes_off() {
  // this function turns off all three colors
  // in our rgb led
  for (i = 0; i < 3; i++) {
    digitalWrite(left_eye[i], LOW);
    digitalWrite(right_eye[i], LOW);
  }
}

void red_eyes_on() {
  digitalWrite(left_eye[1], HIGH);
}

void red_eyes_off() {
  digitalWrite(right_eye[1], LOW);
}

void rainbow_eyes() {
  // cycle through all three colors in our 
  // rgb led
  for (i = 0; i < 3; i++) {
    digitalWrite(left_eye[i], HIGH);
    digitalWrite(right_eye[i], HIGH);
    delay(1000);
    digitalWrite(left_eye[i], LOW);
    digitalWrite(right_eye[i], LOW);
    delay(1000);
  } 
}
void sleepy_eyes() {
  for (i = 0; i <= 255; i++) {    // loop from 0 to 254 (fade in)
    analogWrite(left_eye[2], i);  // set the LED brightness
    analogWrite(right_eye[2], i);
    delay(5);   // Wait (n)ms because analogWrite
                // is instantaneous and we would
                // not see any change
  }
  for (i = 255; i >= 0; i--) {  // loop from 255 to 1 (fade out)
    analogWrite(left_eye[2], i);  // set the LED brightness
    analogWrite(right_eye[2], i);
    delay(5);            // Wait 10ms
    }
}                   
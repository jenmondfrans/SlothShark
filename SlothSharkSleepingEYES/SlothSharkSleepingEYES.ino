// Fade an LED in and out like on
// a sleeping computer

const int LED = 13;  // the pin for the standard LED
int i = 0;          // We'll use this to count up and down
int left_eye[3] = {9, 10, 11}; // arrays control our led rgb pins
int right_eye[3] = {3, 5, 6};  // to keep the code a little simpler
// green: pin 9
// red:   pin 10
// blue:  pin 11

void setup() {
    pinMode(left_eye[0], OUTPUT);
    pinMode(left_eye[1], OUTPUT);
    pinMode(left_eye[2], OUTPUT);
    pinMode(right_eye[0], OUTPUT);
    pinMode(right_eye[1], OUTPUT);
    pinMode(right_eye[2], OUTPUT);
  // for (i = 0; i < 4; i++) {
    // pinMode(left_eye[i], OUTPUT); // tell Arduino left eye is an output
    // pinMode(right_eye[i], OUTPUT); // tell Arduino right eye is an output
  // }
}

void loop() {
  nukular_eyes_on();
  delay(1000);
  nukular_eyes_off();
  delay(1000);
  rainbow_eyes();
  delay(1000);
  sleepy_eyes();
  delay(1000);
}
// end of main loop                                     

void detect_flex() {
  // this function will handle our flex sensor input
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
  for (i = 0; i <= 255; i++) {  // loop from 0 to 254 (fade in)
    analogWrite(left_eye[2], i);       // set the LED brightness
    analogWrite(right_eye[2], i);
    delay(5);  // Wait 10ms because analogWrite
                // is instantaneous and we would
                // not see any change
  }
  for (i = 255; i >= 0; i--) {  // loop from 255 to 1 (fade out)
    analogWrite(left_eye[2], i);  // set the LED brightness
    analogWrite(right_eye[2], i);
    delay(5);            // Wait 10ms
    }
}                   
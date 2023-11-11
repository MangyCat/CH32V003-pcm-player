const int sampleRate = 16000;
const int bufferSize = 256; //Its in bytes
unsigned char audioBuffer[bufferSize];
const unsigned char audioData[] PROGMEM = {};
const int outputPin = D5; // Use any PWM-capable digital pin

void setup() {
  pinMode(outputPin, OUTPUT); // Set the output pin
}

void loop() {
  // Play audio from PROGMEM
  for (unsigned int i = 0; i < sizeof(audioData); i++) { //Had to use pwm since analogwrite wasnt supported on the arduino core of the microcontroller
    if (pgm_read_byte_near(audioData + i) > 128) {
      // Simulate HIGH output
      digitalWrite(outputPin, HIGH);
    } else {
      // Simulate LOW output
      digitalWrite(outputPin, LOW);
    }
    delayMicroseconds(62); // Adjust delay for sample rate 62=16000 sample rate, 125=8000 sample rate, vice versa
  }
  delay(2000);
}

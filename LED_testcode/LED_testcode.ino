const int ledPins[] = {14, 15, 16, 17, 18};
const int Sled = 19; // Start LED pin
int const numberOfButtons = 5;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  for (int pin = 0; pin < numberOfButtons; pin++) {
    pinMode(ledPins[pin], OUTPUT);
  }
  pinMode(Sled, OUTPUT);
  Serial.begin(115200);
  Serial.println("Ready to start...");
}

// the loop function runs over and over again forever
void loop() {
  Serial.println("Turning game start LED on");
  digitalWrite(Sled, HIGH);
  for (int pin = 0; pin < numberOfButtons; pin++) {
    digitalWrite(ledPins[pin], HIGH);
    Serial.print("LED ");
    Serial.print(pin);
    Serial.println(" is on");
    delay(100);
    digitalWrite(ledPins[pin], LOW);
    Serial.println("LED off");
    delay(100);
  }
  Serial.println("Turning game start LED off");
  digitalWrite(Sled, LOW);
  delay(1000);
}

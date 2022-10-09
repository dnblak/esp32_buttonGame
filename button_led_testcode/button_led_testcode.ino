const int ledPins[] = {14, 15, 16, 17, 18};
const int Sled = 19; // Start LED pin
const int buttonPins[] = {32, 33, 34, 35, 36};
const int SB = 39; // Start Button
int const numberOfButtons = 5;

int buttonStates[] = {0,0,0,0,0,0};
int buttonsPushed = 0;

void setup() {
  Serial.begin(115200);
  Serial.println("Set each LED pin as output...");
  for (int pin = 0; pin < numberOfButtons; pin++) {
    pinMode(ledPins[pin], OUTPUT);
    Serial.print(pin);
    Serial.println(" pin is set for output");
  }
  pinMode(Sled, OUTPUT);
  Serial.println("Start LED is set for output.");
  Serial.println("Set each button pin as input...");
  for (int pin = 0; pin < numberOfButtons; pin++) {
    pinMode(buttonPins[pin], INPUT);
    Serial.print(pin);
    Serial.println(" pin is set for input");
  }
  pinMode(SB, INPUT);
  Serial.println("Start button is set for input");
  Serial.println("Ready to start...");
}

void loop() {
  for (int pin = 0; pin < numberOfButtons; pin++) {
    buttonStates[pin] = digitalRead(buttonPins[pin]);
    if (buttonStates[pin] == 1) {
      digitalWrite(ledPins[pin], HIGH);
      Serial.print("Button pushed: ");
      Serial.println(pin);
    } else {
      digitalWrite(ledPins[pin], LOW);
    }
  }
  memset(buttonStates, 0, sizeof(buttonStates));
  if (digitalRead(SB) == 1) {
    digitalWrite(Sled, HIGH);
    Serial.println("Start button is pressed!");
  } else {
    digitalWrite(Sled, LOW);
  }
  delay(100);
}

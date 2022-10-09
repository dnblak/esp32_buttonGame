const int buttonPins[] = {32, 33, 34, 35, 36};
const int SB = 39; // Start Button
int const numberOfButtons = 5;

int buttonStates[] = {0,0,0,0,0,0};
int buttonsPushed = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(115200);
  Serial.println("Set each button pin as input...");
  for (int pin = 0; pin < numberOfButtons; pin++) {
    pinMode(buttonPins[pin], INPUT);
    Serial.print(pin);
    Serial.println(" pin is set for input");
  }
  Serial.println("Set start button as input...");
  pinMode(SB, INPUT);
  Serial.println("Start button is set for input");
  Serial.println("Ready to start...");
}

// the loop function runs over and over again forever
void loop() {
  for (int pin = 0; pin < numberOfButtons; pin++) {
    buttonStates[pin] = digitalRead(buttonPins[pin]);
    if (buttonStates[pin] == 1) {
      Serial.print("Button pushed: ");
      Serial.println(pin);
    }
  }
  memset(buttonStates, 0, sizeof(buttonStates));
  if (digitalRead(SB) == 1) {
    Serial.println("Start button is pressed!");
  }
  delay(100);
}

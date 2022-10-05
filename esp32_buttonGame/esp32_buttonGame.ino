int const numberOfButtons = 5;
const int buttonPins[] = {32, 33, 34, 35, 36};
const int But1 = 32;
const int But2 = 33;
const int But3 = 34;
const int But4 = 35;
const int But5 = 36;
const int SB = 39;
const int ledPins[] = {14, 15, 16, 17, 18};
const int led1 = 14;
const int led2 = 15;
const int led3 = 16;
const int led4 = 17;
const int led5 = 18;
const int Sled = 19;

// variables will change:
//int B1State = 0;
//int B2State = 0;
//int B3State = 0;
//int B4State = 0;
//int B5State = 0;
int SBState = 0;
int buttonStates[] = {0,0,0,0,0,0};
int buttonsPushed = 0;

void setup() {
  // initialize the LED pin as an output:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(Sled, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(But1, INPUT);
  pinMode(But2, INPUT);
  pinMode(But3, INPUT);
  pinMode(But4, INPUT);
  pinMode(But5, INPUT);
  pinMode(SB, INPUT);
  Serial.begin(9600);
  Serial.println("Printing diagnostics....");
}

void resetLeds() {
  for (int pin = 0; pin < numberOfButtons; pin++) {
    digitalWrite(ledPins[pin], LOW);
  }
}

void fastButton(int buttonNumber[]) {
  for (int button = 0; button < numberOfButtons; button++) {
    Serial.print(buttonNumber[button]);
    Serial.print(", ");
  }
  while (SBState == HIGH) {
    for (int button = 0; button < numberOfButtons; button++) {
      if (buttonNumber[button] == 1) {
        digitalWrite(ledPins[button], HIGH);
      }
    }
    delay(100);
    SBState = digitalRead(SB);
  }
  memset(buttonStates, 0, sizeof(buttonStates));
  resetLeds();
}

void startGame() {
  while (SBState == HIGH) {
    Serial.println("HIGH");
    digitalWrite(Sled, HIGH);
    for (int pin = 0; pin < numberOfButtons; pin++) {
      buttonStates[pin] = digitalRead(buttonPins[pin]);
      if (buttonStates[pin] == 1) {
        fastButton(buttonStates);
      }
    }
    SBState = digitalRead(SB);
    delay(50);
  }  
}

void loop() {
  buttonsPushed = 0;
  SBState = digitalRead(SB);
  for (int pin = 0; pin < numberOfButtons; pin++) {
    buttonStates[pin] = digitalRead(buttonPins[pin]);
    buttonsPushed += buttonStates[pin];
  }
  if (buttonsPushed == 0) {
    startGame();
  }

  digitalWrite(Sled, LOW);
  buttonStates[0] = digitalRead(But1);
  buttonStates[1] = digitalRead(But2);
  buttonStates[2] = digitalRead(But3);
  buttonStates[3] = digitalRead(But4);
  buttonStates[4] = digitalRead(But5);
  for (int buttonNumber = 0; buttonNumber <5; buttonNumber++){
    Serial.print(buttonStates[buttonNumber]);
    Serial.print(", ");
  }
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
//  if (buttonState == LOW) {
//    // turn LED Off:
//    // Serial.println("Button LOW, led LOW");
//    digitalWrite(ledPin, LOW);
//  } else {
//    // turn LED on:
//    // Serial.println("Button HIGH, led HIGH");
//    digitalWrite(ledPin, HIGH);
//  }
  Serial.println("Waiting to start...");
  Serial.println("------");
  
  delay(3000);
}

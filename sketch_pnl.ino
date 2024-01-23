const int buttonPin = 2; 
const int ledPin = 13;  

int ledState = LOW; 
int lastbuttonState;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  lastbuttonState = digitalRead(buttonPin);
}

void btn_press() {
  if (ledState == HIGH) {
    ledState = LOW;
  } else {
    ledState = HIGH;
  }

  digitalWrite(ledPin, ledState);
}

void loop() {
  int buttonState = digitalRead(buttonPin);
  
  if (buttonState != lastbuttonState) {
    lastbuttonState = buttonState;
    if (buttonState == LOW) {
      btn_press();
    }
  }
}

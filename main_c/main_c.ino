int switchButtom = 2;            
int switchTop = 3;
int sensitivity = 200;

int led = 13;

void setup() {
  pinMode( switchButtom, INPUT_PULLUP);
  pinMode( switchTop, INPUT_PULLUP);
  pinMode( led, OUTPUT);
}

void loop() {

  if (digitalRead(switchButtom) == LOW) {
    if (digitalRead(switchTop) == LOW) {
      digitalWrite(led, HIGH);
    } 
    else {
      digitalWrite(led, LOW); 
    }
  } 
  else {
    digitalWrite(led, LOW); 
  }

  delay(sensitivity);
}


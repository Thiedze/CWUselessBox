/*

 switchTop (left) = LOW
 switchTop (right) = HIGH
 
 switchButtom (pressed) = HIGH
 switchButtom (released) = LOW
 
 led (on) = HIGH
 led (off) = LOW
 
 Logic:
 if switchTop == HIGH     then move arm up
 if switchTop == LOW      then move arm down
 if switchButtom == HIGH  then stop move arm
 
 */

int switchButtom = 2;            
int switchTop = 3;
int sensitivity = 200;

int led = 13;

void setup() {

  Serial.begin(9600);

  pinMode( switchButtom, INPUT_PULLUP);
  pinMode( switchTop, INPUT_PULLUP);
  pinMode( led, OUTPUT);
}

void blink_led(int blink_delay) {
  for (int round = 0; round < 10; round++)  {
    digitalWrite(led, HIGH);
    delay(blink_delay);
    digitalWrite(led, LOW);
    delay(blink_delay);
  }
}

void move_arm_up() {
  blink_led(50);
}

void move_arm_down() {
  blink_led(200);
}

void move_arm_stop() {
  digitalWrite(led, LOW);   
}

void loop() {

  if (digitalRead(switchTop) == HIGH) { 
    move_arm_up();
  } 
  else if (digitalRead(switchButtom) == LOW && digitalRead(switchTop) == LOW) { 
    move_arm_down();
  } 
  else  if (digitalRead(switchButtom) == HIGH) { 
    move_arm_stop();
  }

  delay(sensitivity);
}











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
 if switchBottom == HIGH  then stop move arm
 
 */

const static int DOWN = -1;
const static int UP = 1;
const static int STOPP = 0;

const int switchBottom = 2;            
const int switchTop = 3;

int motorSpeedUp = 255;
int motorSpeedDown = 255;

const int moterSpeedPin = 6;
const int in1 = 5;
const int in2 = 4;

const int led = 13;


volatile int ledState = LOW;
volatile int switchBottomState = LOW;
volatile int switchTopState = LOW;

volatile int moveDirection = STOPP;

volatile int currentEffect = 0;

int effect_stop_motion[15] = {
  HIGH, 100, motorSpeedUp, LOW, 2000, motorSpeedUp, HIGH, 150, motorSpeedUp, LOW, 1000, motorSpeedUp, HIGH, 200, motorSpeedUp};

int effect_normal[3] = {
  HIGH, 400, motorSpeedUp};


void setup() {

  Serial.begin(9600);
  while (!Serial);

  pinMode( switchBottom, INPUT_PULLUP);
  pinMode( switchTop, INPUT_PULLUP);

  attachInterrupt(0, switchBottomTriggert, CHANGE);
  attachInterrupt(1, switchTopTriggert, CHANGE);

  pinMode(led, OUTPUT);

  pinMode(moterSpeedPin, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
}

// Interrupt switch bottom
void switchBottomTriggert() {
  switchBottomState = digitalRead(switchBottom); 
};


//Interrupt switch top
void switchTopTriggert() {
  int currentState = digitalRead(switchTop);

  if (switchTopState == LOW && currentState == HIGH) { 
    moveDirection = UP;
  } 
  else if (switchTopState == HIGH && currentState == LOW) { 
    moveDirection = DOWN;
  }

  switchTopState = currentState;
}

void move_arm_up(int current_effect[], int array_size) {
  digitalWrite(in1, LOW);

  for (int index = 0; index < array_size; index = index + 3) {
    analogWrite(moterSpeedPin, current_effect[index+2]);
    digitalWrite(in2, current_effect[index+0]);
    delay(current_effect[index+1]);
  }

}

void move_arm_down() {
  analogWrite(moterSpeedPin, motorSpeedDown);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
}

void move_arm_stop() {
  analogWrite(moterSpeedPin, 0);
}

void loop() {

  if (switchBottomState == HIGH) { 
    move_arm_stop();
  }

  if (moveDirection == UP) {
    if (currentEffect == 0) {
      move_arm_up(effect_normal, sizeof(effect_normal) / sizeof(int));
    }
    else if (currentEffect == 1) {
      move_arm_up(effect_stop_motion, sizeof(effect_stop_motion) / sizeof(int));
    }

    currentEffect += 1;
    if (currentEffect > 1) {
      currentEffect = 0;
    }
  } 

  if (switchBottomState == LOW && moveDirection == DOWN) {
    move_arm_down();
  }

}

































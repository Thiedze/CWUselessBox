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
const static int STOP = 0;

const int switch_bottom = 2;            
const int switch_top = 3;
const int motor_control_2 = 4;
const int motor_control_1 = 5;
const int moter_speed_pin = 6;


volatile int switch_bottom_state = HIGH;
volatile int switch_top_state = LOW;

volatile int move_direction = STOP;


void setup() {

  Serial.begin(9600);
  while (!Serial);

  pinMode( switch_bottom, INPUT_PULLUP);
  pinMode( switch_top, INPUT_PULLUP);

  attachInterrupt(0, switch_bottom_triggert, CHANGE);
  attachInterrupt(1, switch_top_triggert, CHANGE);

  pinMode(moter_speed_pin, OUTPUT);
  pinMode(motor_control_1, OUTPUT);
  pinMode(motor_control_2, OUTPUT);
  
}





































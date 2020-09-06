/*
 
 switchTop (left) = LOW
 switchTop (right) = HIGH
 
 switchButtom (pressed) = HIGH
 switchButtom (released) = LOW
 
 */

const static int DOWN = -1;
const static int UP = 1;
const static int STOP = 0;
const static int DISTANCE = 42;
const static int FOLLOW= 21;

const int switch_bottom = 2;            
const int switch_top = 3;
const int motor_control_2 = 4;
const int motor_control_1 = 5;
const int moter_speed_pin = 6;

const int ir_sensor = A0;


volatile int switch_bottom_state = HIGH;
volatile int switch_top_state = LOW;


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
  
  pinMode(ir_sensor, INPUT);
}





































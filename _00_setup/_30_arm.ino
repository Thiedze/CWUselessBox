void move_arm_up(int delay_ms, int motor_speed) {
  analogWrite(moter_speed_pin, motor_speed);
  digitalWrite(motor_control_1, LOW);
  digitalWrite(motor_control_2, HIGH);
  delay(delay_ms);
}

void move_arm_down(int delay_ms, int motor_speed) {
  analogWrite(moter_speed_pin, motor_speed);
  digitalWrite(motor_control_1, HIGH);
  digitalWrite(motor_control_2, LOW);
  delay(delay_ms);
}

void move_arm_stop(int delay_ms) {
  digitalWrite(motor_control_1, LOW);
  digitalWrite(motor_control_2, LOW);
  delay(delay_ms);
}



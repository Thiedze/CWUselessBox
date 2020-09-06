int ir_sensor_value = 0;
boolean was_enenmy_out_of_range = false;

int arm_position = 0;
int enemy_position = 0; 
int max_position = 400;

void run_distance() {
  ir_sensor_value = analogRead(ir_sensor);
  
  Serial.println(ir_sensor_value);
  Serial.println(was_enenmy_out_of_range);

  if (was_enenmy_out_of_range == true && ir_sensor_value < 800) {
    mode_index += 3;
    was_enenmy_out_of_range = false;
  }

  if (ir_sensor_value > 900) {
    was_enenmy_out_of_range = true;
  }
}

void run_follow() {
  ir_sensor_value = analogRead(ir_sensor);
  enemy_position = map(ir_sensor_value, 0, 900, max_position, 0);    

  int current_position = enemy_position - arm_position;

  if (abs(current_position) > 5) {
    if (current_position > 0) {
      move_arm_up(current_position, 255);
      move_arm_stop(0);
      arm_position += current_position;
    } 
    else if(current_position <= 0 && arm_position > 0) {
      current_position *= -1; 
      move_arm_down(current_position, 255);
      move_arm_stop(0);
      arm_position -= current_position;
    }
  }

  if (switch_top_state == LOW && arm_position != 0) {
    mode_index += 3;
  }
}

void loop() {  

  if(is_mode_running == false && switch_bottom_state == HIGH && switch_top_state == HIGH) {
    select_mode();
    is_mode_running = true;
    Serial.println("============================================");
    Serial.println("start");
  }

  if (is_mode_running == true && mode[mode_index] == STOP) { 
    move_arm_stop(mode[mode_index + 1]);
    mode_index += 3;
    Serial.println("stop");
  } 
  else if (is_mode_running == true && mode[mode_index] == UP) {
    move_arm_up(mode[mode_index + 1], mode[mode_index + 2]);
    mode_index += 3;
    Serial.println("up");
  } 
  else if (is_mode_running == true && mode[mode_index] == DOWN) {
    move_arm_down(mode[mode_index + 1], mode[mode_index + 2]);
    mode_index += 3;
    Serial.println("down");
  } 

  if (is_mode_running == true && mode[mode_index] == DISTANCE) {
    run_distance();
  } 

  if (is_mode_running == true && mode[mode_index] == FOLLOW) {
    run_follow();
  } 

  if (is_mode_running == true && mode_index >= mode_size) {

    selected_mode += 1;
    if (selected_mode > mode_count) {
      selected_mode = 0;
    } 

    mode_index = 0;
    mode_size = 0;
    is_mode_running = false;
    arm_position = 0;
    enemy_position = 0;

    Serial.println("reset");
    Serial.println("============================================");
    Serial.println();
  }

}






















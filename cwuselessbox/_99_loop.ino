int ir_sensor_value = 0;
boolean was_enenmy_out_of_range = false;

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

  if (mode[mode_index] == DISTANCE) {
    ir_sensor_value = analogRead(ir_sensor);
    
    if (was_enenmy_out_of_range == true && ir_sensor_value < 900) {
      mode_index += 3;
      was_enenmy_out_of_range = false;
    }
    
    if (ir_sensor_value > 1000) {
      was_enenmy_out_of_range = true;
    }
    
  } 

  if (is_mode_running == true && mode_index >= mode_size) {

    selected_mode += 1;
    if (selected_mode > mode_count) {
      selected_mode = 0;
    } 

    mode_index = 0;
    mode_size = 0;
    is_mode_running = false;

    Serial.println("reset");
    Serial.println("============================================");
    Serial.println();
  }

}

















// Interrupt switch bottom
void switch_bottom_triggert() {
  switch_bottom_state = digitalRead(switch_bottom); 
};


//Interrupt switch top
void switch_top_triggert() {
  int current_state = digitalRead(switch_top);

  if (switch_top_state == LOW && current_state == HIGH) { 
    move_direction = UP;
  } 
  else if (switch_top_state == HIGH && current_state == LOW) { 
    move_direction = DOWN;
  }

  switch_top_state = current_state;
}

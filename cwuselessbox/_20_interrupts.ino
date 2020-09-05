// Interrupt switch bottom
void switch_bottom_triggert() {
  switch_bottom_state = digitalRead(switch_bottom); 
};


//Interrupt switch top
void switch_top_triggert() {
  switch_top_state = digitalRead(switch_top);
}

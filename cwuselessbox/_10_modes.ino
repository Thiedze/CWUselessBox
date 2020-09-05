int slow[9] = {  
  UP, 800, 170, DOWN, 800, 170, STOP, 100, 0};

int hold[12] = {  
  UP, 400, 255, STOP, 3000, 255, DOWN, 350, 255, STOP, 100, 0};

int stop_motion[21] = {  
  UP, 100, 255, STOP, 2000, 255, UP, 150, 255, STOP, 1000, 255, UP, 200, 255, DOWN, 350, 255, STOP, 100, 0};

int normal[9] = {  
  UP, 400, 255, DOWN, 350, 255, STOP, 100, 0 };

int distance[12] = {
  DISTANCE, 0, 255, UP, 400, 255, DOWN, 350, 255, STOP, 100, 0  };

int mode_count = 4;
int mode_index = 0;
int mode_size = 0;

boolean is_mode_running = false;

int selected_mode = 0;
int *mode = { 
  NULL };

void select_mode() {
  if (selected_mode == 0) {
    mode_size = sizeof(distance) / sizeof(int);
    mode = distance;
    Serial.println("mode: distance");      
  }
  else if (selected_mode == 1) {
    mode_size = sizeof(normal) / sizeof(int);
    mode = normal;
    Serial.println("mode: normal");      
  } 
  else if (selected_mode == 2) {
    mode_size = sizeof(stop_motion) / sizeof(int);
    mode = stop_motion;
    Serial.println("mode: stop motion");      
  }
  else if (selected_mode == 3) {
    mode_size = sizeof(hold) / sizeof(int);
    mode = hold;
    Serial.println("mode: hold");      
  }
  else if (selected_mode == 4) {
    mode_size = sizeof(slow) / sizeof(int);
    mode = slow;
    Serial.println("mode: slow");      
  }
}


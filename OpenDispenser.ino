#include "Valve.h"
#define SIZE 3
Valve ** valves;

void setup() {
  valves = (Valve**)calloc(SIZE, sizeof(Valve*));
  valves[0] = new Valve(13,4);
  valves[1] = new Valve(12,3);
  valves[2] = new Valve(11,2);
}
 
void loop() {

  for(int i=0; i<SIZE; i++){
    valves[i]->exec();
  }
  delay(10);
}

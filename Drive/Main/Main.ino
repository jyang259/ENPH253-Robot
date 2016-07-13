#include <phys253.h>
#include <avr/interrupt.h>
#include <QueueList.h>  /* http://playground.arduino.cc/Code/QueueList */
#include <LiquidCrystal.h>

#define NORTH 'N'
#define SOUTH 'S'
#define EAST 'E'
#define WEST 'W'
#define RIGHT 'R'
#define LEFT 'L'
#define FORWARD 'F'
#define UNDEFINED 'U'

bool passenger; // Passenger carrying status
char turnDir; // The direction of the next turn
char dir;    char* dir_p; // Direction, N,S,E,W
int pN;      int* pN_p; // Holds the previous node (pN) in memory
int cN;      int* cN_p; // Holds the current node (cN) in memory
QueueList <int> fN; //int* fN_p; // Holds all of the future nodes (fN) in memory

void setup() {
  #include <phys253setup.txt>
  passenger = false;
  dir = SOUTH; dir_p = &dir;
  cN = 2; cN_p = &cN;
  pN = 1; pN_p = &pN; //This initial value does not matter
  fN.push(5); fN.push(4); fN.push(3); fN.push(2); fN.push(5); fN.push(9); fN.push(10);fN.push(11);//fN_p = &fN; //Push the the next node value        
  enableExternalInterrupt(INT1,LOW);
  Serial.begin(9600);
  delay(1000);
}

void loop() {
  bool intersection = detectIntersection();
  if (!fN.isEmpty()){
    if (intersection == true){
      turnDir = turnDirection(cN_p,fN.pop(),dir_p);
      Serial.println("Intersection Detected");
      LCD.clear();
      LCD.home();
      LCD.print(turnDir);
      turn(turnDir);
      //followTape();
    }
    else{
      Serial.println("Following Tape");
      followTape();
    }
  }
  else{
    motor.stop_all();
    LCD.clear();
    LCD.home();
    LCD.print("Done");
    delay(10000);
  }
}

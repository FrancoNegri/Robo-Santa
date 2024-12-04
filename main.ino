#include <Servo.h>

Servo lefthand;
Servo righthand;

int current_pos = 0;

void setup() {
  lefthand.attach(9);  // attaches the servo on pin 9 to the servo object
  righthand.attach(10);  // attaches the servo on pin 10 to the servo object
  delay(1000);
  // setup servos
  lefthand.write(0); 
  righthand.write(0);
}


void goFast(int targuet_angle) {
  int foward = current_pos < targuet_angle ? 1 : -1;
  for (int pos = current_pos; pos != targuet_angle; pos = pos + foward) {
    // in steps of 1 degree
    lefthand.write(pos);              // tell servo to go to position in variable 'pos'
    righthand.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
    // a 90º rotation is 1.35 * 90º = 1.35 secs
  }
}

void goSlow(int targuet_angle) {
  int foward = current_pos < targuet_angle ? 1 : -1;
  for (int pos = current_pos; pos != targuet_angle; pos = pos + 1 ) {
    // in steps of 1 degree
    lefthand.write(pos);              // tell servo to go to position in variable 'pos'
    righthand.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
    // a 90º rotation is 1.35 * 90º = 1.35 secs
  }
}

void loop() {
}

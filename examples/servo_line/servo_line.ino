#include <RobotDriver.h> 
#include <Servo.h>
/*for Arduino UNO
IN1 pin 13
IN2 pin 12
IN3 pin 7
IN4 pin 8
EN1 pin 11
EN2 pin 10*/
/*
SERVO pin 9
*/
/*Se define la clase RobotDriver*/ 
RobotDriver robot;
void setup() {
  /*Se inicializa el objeto robot*/
  robot.init();
  
}
int cont=10;
 void loop() {
  robot.avanzar(0.25);
  robot.mover_cabeza(70);
  delay(250);  
  robot.mover_cabeza(0);
  delay(250);
  robot.avanzar(0.25);
  
  if(robot.linea_negra()==1){
      robot.retroceder(1);
      robot.avanzar(0,100,0.5);
  }
}

#include <RobotDriver.h> 
/*for Arduino UNO
IN1 pin 2
IN2 pin 4
IN3 pin7
IN4 pin6
EN1 pin 3
EN2 pin 5*/
/*Se define la clase RobotDriver*/ 
RobotDriver robot;
void setup() {
  /*Se inicializa el objeto robot*/
  robot.init();
}
void loop() {
  robot.avanzar(1);
  robot.doblar_izq(1);
  robot.avanzar(1);
  robot.doblar_izq(1);
  robot.avanzar(1);

}

#include <RobotDriver.h> 
/*for Arduino UNO
IN1 pin 13
IN2 pin 12
IN3 pin 8
IN4 pin 7
EN1 pin 11
EN2 pin 10*/
/*Se define la clase RobotDriver*/ 
RobotDriver robot;
void setup() {
  /*Se inicializa el objeto robot*/
  robot.init();
}
void loop() {
  /*robot.avanzar(delay): la variable delay está en segundos*/
  robot.avanzar(1);
  robot.doblar_izq(1);
  robot.avanzar(1);
  robot.doblar_izq(1);
  robot.avanzar(1);

}

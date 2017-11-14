#include <RobotDriver.h> 
#include <Servo.h>
/*for Arduino UNO
IN1 pin 6
IN2 pin 5
IN3 pin 7
IN4 pin 8
EN1 pin 11
EN2 pin 10*/
/*Se define la clase RobotDriver*/ 

RobotDriver robot;
void setup() {
  /*Se inicializa el objeto robot*/
  robot.init();
}
void loop() {
  /*robot.avanzar(speed1,speed2), las variables "speedx" están en el rango 0-100*/
  robot.avanzar(50,30);
  
  /*robot.doblar_izq(delay,speed): La variable delay está en segundos, y
  la variable speed está en un rango 0-100*/
  robot.doblar_izq(1,70);
  
  /*avanzar(speed1,speed2,delay): speed1 y speed2 estan en un rango 0-100, y 
  la variable delay esta en segundos*/
  robot.avanzar(40,70,1);
  
  robot.doblar_izq(1);
  
  robot.avanzar(1);

}

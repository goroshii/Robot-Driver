#include <RobotDriver.h> 
#include <Servo.h>
/*for Arduino UNO
IN1 pin 13
IN2 pin 12
IN3 pin 7
IN4 pin 8
EN1 pin 11
EN2 pin 10*/
/*Se define la clase RobotDriver*/ 
RobotDriver robot;
void setup() {
  /*Se inicializa el objeto robot*/
  robot.init();
  
  /*Se inicia una rutina de interrupción*/
  /*attachInterrupt(digitalPinToInterrupt(pin),ISR,mode)
  digitalPinToInterrupt(pin): pin puede ser 2 o 3
  ISR: es el nombre de la rutina de interrupcion
  mode: puede ser HIGH, LOW, RISING,o FALLING
  */
  attachInterrupt(digitalPinToInterrupt(2), borde, HIGH);
  
}
void loop() {
  robot.avanzar(1);
  robot.doblar_izq(1);
  robot.avanzar(1);
  robot.doblar_izq(1);
  robot.avanzar(1);

}

void borde(){
  if(robot.linea_negra()==1){
    digitalWrite(4,HIGH);
    robot.retroceder(0.5);
    robot.avanzar(0,100,0.5);
  } else {
    digitalWrite(4,LOW);
  }
}

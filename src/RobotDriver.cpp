#include "Arduino.h"
#include "RobotDriver.h"
#include <Servo.h>
Servo head;
RobotDriver::RobotDriver()
{
	_in1 = IN1;
	_in2 = IN2;
	_in3 = IN3;
	_in4 = IN4;
	_en1 = EN1;
	_en2 = EN2;
	_ser = SER;
}

void RobotDriver::init(){
	pinMode(_in1,OUTPUT);
	pinMode(_in2,OUTPUT);
	pinMode(_in3,OUTPUT);
	pinMode(_in4,OUTPUT);
	pinMode(_en1,OUTPUT);
	pinMode(_en2,OUTPUT);
	head.attach(_ser);
}
void RobotDriver::avanzar(int speed1,int speed2)
{
	/*Rueda izquierda hacia delante*/
	digitalWrite(_in1,1);
	digitalWrite(_in2,0);
	/*Rueda derecha hacia delante*/
	digitalWrite(_in3,1);
	digitalWrite(_in4,0);
	/*velocidad de la rueda depende del valor*/
	analogWrite(_en1,speed1);
	analogWrite(_en2,speed2);
}
void RobotDriver::avanzar(int speed1,int speed2,int delay)
{
	/*Rueda izquierda hacia delante*/
	digitalWrite(_in1,1);
	digitalWrite(_in2,0);
	/*Rueda derecha hacia delante*/
	digitalWrite(_in3,1);
	digitalWrite(_in4,0);
	/*velocidad de la rueda depende del valor*/
	analogWrite(_en1,speed1);
	analogWrite(_en2,speed2);
	/*Se espera el tiempo indicado y luego se apagan las ruedas*/
	delay((int)(1000*delay));
	digitalWrite(_en1,0);
	digitalWrite(_en2,0);

}
void RobotDriver::avanzar(int delay)
{
	digitalWrite(_in1,1);
	digitalWrite(_in2,0);
	/*Rueda derecha hacia delante*/
	digitalWrite(_in3,1);
	digitalWrite(_in4,0);
	/*velocidad de la rueda depende del valor*/
	digitalWrite(_en1,1);
	digitalWrite(_en2,1);
	delay((int)(1000*delay));
	digitalWrite(_en1,0);
	digitalWrite(_en2,0);

}
void RobotDriver::retroceder(int speed1,int speed2)
{
	digitalWrite(_in1,0);
	digitalWrite(_in2,1);
	/*Rueda derecha hacia atras*/
	digitalWrite(_in3,0);
	digitalWrite(_in4,1);
	/*velocidad de la rueda depende del valor*/
	analogWrite(_en1,speed1);
	analogWrite(_en2,speed2);
}
void RobotDriver::retroceder(int speed1, int speed2, int delay)
{
	digitalWrite(_in1,0);
	digitalWrite(_in2,1);
	/*Rueda derecha hacia atras*/
	digitalWrite(_in3,0);
	digitalWrite(_in4,1);
	/*velocidad de la rueda depende del valor*/
	analogWrite(_en1,speed1);
	analogWrite(_en2,speed2);
	/*Se espera el tiempo indicado y luego se apagan las ruedas*/
	delay((int)(1000*delay));
	digitalWrite(_en1,0);
	digitalWrite(_en2,0);
}
void RobotDriver::retroceder(int delay)
{
	digitalWrite(_in1,0);
	digitalWrite(_in2,1);
	/*Rueda derecha hacia atras*/
	digitalWrite(_in3,0);
	digitalWrite(_in4,1);
	/*velocidad de la rueda depende del valor*/
	digitalWrite(_en1,1);
	digitalWrite(_en2,1);
	delay((int)(1000*delay));
	digitalWrite(_en1,0);
	digitalWrite(_en2,0);	
}
void RobotDriver::doblar_izq(int delay)
{
	/*Rueda izquierda hacia atras*/
	digitalWrite(_in1,0);
	digitalWrite(_in2,1);
	/*Rueda derecha hacia delante*/
	digitalWrite(_in3,1);
	digitalWrite(_in4,0);
	/*Velocidad de giro*/
	analogWrite(_en1,100);
	analogWrite(_en2,100);
	delay((int)(1000*delay));
	digitalWrite(_en1,0);
	digitalWrite(_en2,0);
}
void RobotDriver::doblar_izq(int delay,int speed)
{
/*Rueda izquierda hacia atras*/
	digitalWrite(_in1,0);
	digitalWrite(_in2,1);
	/*Rueda derecha hacia delante*/
	digitalWrite(_in3,1);
	digitalWrite(_in4,0);
	/*Velocidad de giro*/
	analogWrite(_en1,speed);
	analogWrite(_en2,speed);
	delay((int)(1000*delay));
	digitalWrite(_en1,0);
	digitalWrite(_en2,0);
}
void RobotDriver::doblar_der(int delay){
/*Rueda izquierda hacia delante*/
	digitalWrite(_in1,1);
	digitalWrite(_in2,0);
	/*Rueda derecha hacia delante*/
	digitalWrite(_in3,0);
	digitalWrite(_in4,1);
	/*Velocidad de giro*/
	analogWrite(_en1,100);
	analogWrite(_en2,100);
	delay((int)(1000*delay));
	digitalWrite(_en1,0);
	digitalWrite(_en2,0);
}
void RobotDriver::doblar_der(int delay, int speed){
/*Rueda izquierda hacia delante*/
	digitalWrite(_in1,1);
	digitalWrite(_in2,0);
	/*Rueda derecha hacia delante*/
	digitalWrite(_in3,0);
	digitalWrite(_in4,1);
	/*Velocidad de giro*/
	analogWrite(_en1,speed);
	analogWrite(_en2,speed);
	delay((int)(1000*delay));
	digitalWrite(_en1,0);
	digitalWrite(_en2,0);
int RobotDriver::linea_negra()
{
	int lectura = analogRead(A0);
	if(lectura>500){
		return 1;
	} else{
		return 0;
	}
}
void RobotDriver::mover_cabeza(int angulo)
{
	head.write(angulo);
}

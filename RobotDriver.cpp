#include "Arduino.h"
#include "RobotDriver.h"
#include <Servo.h>
/*mapeo de velocidad, rango 0-100 a 0-255 (para pines analogos)*/
#define SPD(x)   map(x,0,100,0,255)
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
void RobotDriver::avanzar(int speed1,int speed2,float del)
{
	/*Rueda izquierda hacia delante*/
	digitalWrite(_in1,1);
	digitalWrite(_in2,0);
	/*Rueda derecha hacia delante*/
	digitalWrite(_in3,1);
	digitalWrite(_in4,0);
	/*velocidad de la rueda depende del valor*/
	analogWrite(_en1,SPD(speed1));
	analogWrite(_en2,SPD(speed2));
	/*Se espera el tiempo indicado y luego se apagan las ruedas*/
	delay((int)(1000*delay));
	digitalWrite(_en1,0);
	digitalWrite(_en2,0);

}
void RobotDriver::avanzar(float del)
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
	analogWrite(_en1,SPD(speed1));
	analogWrite(_en2,SPD(speed2));
}
void RobotDriver::retroceder(int speed1, int speed2, float del)
{
	digitalWrite(_in1,0);
	digitalWrite(_in2,1);
	/*Rueda derecha hacia atras*/
	digitalWrite(_in3,0);
	digitalWrite(_in4,1);
	/*velocidad de la rueda depende del valor*/
	analogWrite(_en1,SPD(speed1));
	analogWrite(_en2,SPD(speed2));
	/*Se espera el tiempo indicado y luego se apagan las ruedas*/
	delay((int)(1000*del));
	digitalWrite(_en1,0);
	digitalWrite(_en2,0);
}
void RobotDriver::retroceder(float del)
{
	digitalWrite(_in1,0);
	digitalWrite(_in2,1);
	/*Rueda derecha hacia atras*/
	digitalWrite(_in3,0);
	digitalWrite(_in4,1);
	/*velocidad de la rueda depende del valor*/
	digitalWrite(_en1,1);
	digitalWrite(_en2,1);
	delay((int)(1000*del));
	digitalWrite(_en1,0);
	digitalWrite(_en2,0);	
}
void RobotDriver::doblar_izq(float del)
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
	delay((int)(1000*del));
	digitalWrite(_en1,0);
	digitalWrite(_en2,0);
}
void RobotDriver::doblar_izq(float del,int speed)
{
/*Rueda izquierda hacia atras*/
	digitalWrite(_in1,0);
	digitalWrite(_in2,1);
	/*Rueda derecha hacia delante*/
	digitalWrite(_in3,1);
	digitalWrite(_in4,0);
	/*Velocidad de giro*/
	analogWrite(_en1,SPD(speed1));
	analogWrite(_en2,SPD(speed2));
	delay((int)(1000*del));
	digitalWrite(_en1,0);
	digitalWrite(_en2,0);
}
void RobotDriver::doblar_der(float del){
/*Rueda izquierda hacia delante*/
	digitalWrite(_in1,1);
	digitalWrite(_in2,0);
	/*Rueda derecha hacia delante*/
	digitalWrite(_in3,0);
	digitalWrite(_in4,1);
	/*Velocidad de giro*/
	analogWrite(_en1,100);
	analogWrite(_en2,100);
	delay((int)(1000*del));
	digitalWrite(_en1,0);
	digitalWrite(_en2,0);
}
void RobotDriver::doblar_der(float del, int speed){
/*Rueda izquierda hacia delante*/
	digitalWrite(_in1,1);
	digitalWrite(_in2,0);
	/*Rueda derecha hacia delante*/
	digitalWrite(_in3,0);
	digitalWrite(_in4,1);
	/*Velocidad de giro*/
	analogWrite(_en1,SPD(speed1));
	analogWrite(_en2,SPD(speed2));
	delay((int)(1000*del));
	digitalWrite(_en1,0);
	digitalWrite(_en2,0);
}
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

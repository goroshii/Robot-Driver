#include "Arduino.h"
#include "RobotDriver.h"
#include <Servo.h>

/*mapeo de velocidad, rango 0-100 a 0-255 (para pines analogos)*/

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
	_duration = 0;
//	_echo = ECHO;
//	_trigg = TRIGG;
}
void RobotDriver::init_ultrasonic(){
	_duration = 0;
	_echo = ECHO;
	_trigg = TRIGG;
	pinMode(_echo, OUTPUT);
	pinMode(_trigg, INPUT); //Actually, this might be unnecessary if PulseIn does it too. Not sure.
	digitalWrite(_trigg, LOW);
}

void RobotDriver::init_ultrasonic(int echo, int trigg){
	_echo = echo;
	_trigg = trigg;
	pinMode(_echo, OUTPUT);
	pinMode(_trigg, INPUT); //Actually, this might be unnecessary if PulseIn does it too. Not sure.
	digitalWrite(_trigg, LOW);
}

float RobotDriver::get_distance(){
	//First hold the trigger pin up for 10uS
	digitalWrite(_trigg, LOW);
	delayMicroseconds(4);
	digitalWrite(_trigg, HIGH);
	delayMicroseconds(10);
	digitalWrite(_trigg, LOW);
	_duration = pulseIn(_echo,HIGH,MAX_DIST);
	//Then, we wait for the incoming pulse: _echo will go from LOW to HIGH and then LOW again
	//Pulse duration will be in uS and proportional to the distance traveled
	//The proportion is half the speed of sound in cm/uS. Returns the value in cm
	
	return _duration*1.0;
}
void RobotDriver::init(bool izq_inv,bool der_inv){
	int aux_izq,aux_der;
	if(izq_inv){
		aux_izq = _in1;
		_in1 = _in2;
		_in2 = aux_izq;
		pinMode(_in1, OUTPUT);
		pinMode(_in2, OUTPUT);
	}else {
		pinMode(_in1, OUTPUT);
		pinMode(_in2, OUTPUT);
	}

	if(der_inv){
		aux_der = _in3;
		_in3 = _in4;
		_in4 = aux_der;
		pinMode(_in3, OUTPUT);
		pinMode(_in4, OUTPUT);
	} else{
		pinMode(_in3, OUTPUT);
		pinMode(_in4, OUTPUT);
	}

	pinMode(_en1, OUTPUT);
	pinMode(_en2, OUTPUT);
	head.attach(_ser);

}
void RobotDriver::init(){
	pinMode(_in1, OUTPUT);
	pinMode(_in2, OUTPUT);
	pinMode(_in3, OUTPUT);
	pinMode(_in4, OUTPUT);
	pinMode(_en1, OUTPUT);
	pinMode(_en2, OUTPUT);
	head.attach(_ser);
}

void RobotDriver::stop(){
	digitalWrite(_en1,0);
	digitalWrite(_en2,0);
	digitalWrite(_in1,0);
	digitalWrite(_in2,0);
	digitalWrite(_in3,0);
	digitalWrite(_in4,0);
}

void RobotDriver::avanzar(int speed1,int speed2)
{
	/*Rueda izquierda hacia delante*/
	digitalWrite(_in1,0);
	digitalWrite(_in2,1);
	/*Rueda derecha hacia delante*/
	digitalWrite(_in3,0);
	digitalWrite(_in4,1);
	/*velocidad de la rueda depende del valor*/
	analogWrite(_en1,SPD(speed1));
	analogWrite(_en2,SPD(speed2));
}

void RobotDriver::avanzar(int speed1,int speed2,float del)
{
	/*Rueda izquierda hacia delante*/
	digitalWrite(_in1,0);
	digitalWrite(_in2,1);
	/*Rueda derecha hacia delante*/
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

void RobotDriver::avanzar(float del)
{

	digitalWrite(_in1,0);
	digitalWrite(_in2,1);
	/*Rueda derecha hacia delante*/
	digitalWrite(_in3,0);
	digitalWrite(_in4,1);
	/*velocidad de la rueda depende del valor*/
	digitalWrite(_en1,1);
	digitalWrite(_en2,1);
	delay((int)(1000*del));
	digitalWrite(_en1,0);
	digitalWrite(_en2,0);
}

void RobotDriver::retroceder(int speed1,int speed2)
{
	digitalWrite(_in1,1);
	digitalWrite(_in2,0);
	/*Rueda derecha hacia atras*/
	digitalWrite(_in3,1);
	digitalWrite(_in4,0);
	/*velocidad de la rueda depende del valor*/
	analogWrite(_en1,SPD(speed1));
	analogWrite(_en2,SPD(speed2));
}

void RobotDriver::retroceder(int speed1, int speed2, float del)
{
	digitalWrite(_in1,1);
	digitalWrite(_in2,0);
	/*Rueda derecha hacia atras*/
	digitalWrite(_in3,1);
	digitalWrite(_in4,0);
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
	digitalWrite(_in1,1);
	digitalWrite(_in2,0);
	/*Rueda derecha hacia atras*/
	digitalWrite(_in3,1);
	digitalWrite(_in4,0);
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
	analogWrite(_en1,SPD(speed));
	analogWrite(_en2,SPD(speed));
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
	analogWrite(_en1,SPD(speed));
	analogWrite(_en2,SPD(speed));
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

/*
 Robot driver library. This library was made by :
 Damian Quiroz
 Email: damian.quiroz.13@sansano.usm.cl
 The purpose of this library is drive a litle robot with two
 weels, three light sensors and one servo motor. 
 This library is valid only on ARDUINO UNO.
*/
#ifndef ROBOTDRIVER_h
#define ROBOTDRIVER_h

#include "Arduino.h"
#include <Servo.h>
#define IN1 2
#define IN2 4
#define EN1 3
#define IN3 7
#define IN4 6
#define EN2 5
#define SER 9

class RobotDriver{
	public:
		RobotDriver();
		void init();
		void avanzar(float delay);
		void avanzar(int speed1,int speed2);
		void avanzar(int speed1,int speed2,float delay);
		void retroceder(float delay);
		void retroceder(int speed1,int speed2);
		void retroceder(int speed1, int speed2, float delay);
		void doblar_izq(float delay);	
		void doblar_izq(float delay,int speed);
		void doblar_der(float delay);
		void doblar_der(float delay,int speed);
		int linea_negra();
		void mover_cabeza(int angulo);	
	private:
		int _in1;
		int _in2;
		int _in3;
		int _in4;
		int _en1;
		int _en2;
		int _ser;
};

#endif

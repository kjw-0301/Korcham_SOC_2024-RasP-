#include <stdio.h>
#include <wiringPi.h>
#define TRIG 8
#define ECHO 9
void Trigger()
{
	//트리거 신호 (Trigger Siganl)
		digitalWrite(TRIG,0);
		delayMicroseconds(10);
		//TriggerSignal Start
		digitalWrite(TRIG,1);
		delayMicroseconds(10);
		digitalWrite(TRIG, 0);
		delayMicroseconds(200);
}



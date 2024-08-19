#include <stdio.h>
#include <wiringPi.h>
#define TRIG 8
#define ECHO 9

extern void Trigger();
double Dist()
{
	for(;;)
	{	
		//트리거 신호 (Trigger Siganl)
		Trigger();
		//ECHO 신호를 기다려줍니다.
		while(digitalRead(ECHO) != 1); // echo High
		int t1 = micros(); // Get current time[Start](in micro second)
		while(digitalRead(ECHO) != 0); // echo Low
		int t2 = micros(); //Get current time[End](in micro second)
		//double result = (t2 - t1) * ((340 / 1000000) /2 *1000) ;
		return (t2-t1) * 0.017;
		
	}
}



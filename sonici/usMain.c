#include <stdio.h>
#include <wiringPi.h>

#define TRIG 8
#define ECHO 9


extern void usISR();
extern void Trigger();
extern double Dist();
int main()
{
	wiringPiSetup();
	pinMode(TRIG,OUTPUT);
	pinMode(ECHO,OUTPUT);
	wiringPiISR(ECHO, INT_EDGE_BOTH,usISR); //ISR등록
	
	while(1)
	{
		
	}
}


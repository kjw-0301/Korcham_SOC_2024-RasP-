#include <stdio.h>
#include <wiringPi.h>
#include <pthread.h>

#define TRIG 8
#define ECHO 9
#define BUZZER 7

extern double Dist();
extern void Play(double r);

int main()
{
	wiringPiSetup();
	pinMode(TRIG, OUTPUT);
	pinMode(ECHO, INPUT);
	for(;;)
	{
		double d = Dist();
		printf("D_sonic :%.2f(Cm)\n", d);
		double r = (d>100) ? 1.0 : (d < 50) ? 4.0 : 2.5;
		Play(r);
		delay(500);
	}
	return 0;
}


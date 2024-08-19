#include <stdio.h>
#include <wiringPi.h>

#define SURV_pin 1 //wpi num(11)
int main(int argc, char **argv)
{
	wiringPiSetup();
	pinMode(SURV_pin, OUTPUT);
	for(int j =0; j <10;j++)
	{
		for(int i = 0; i < 10; i++)
		{
			digitalWrite(SURV_pin,1);
			delayMicroseconds(1000); //
			digitalWrite(SURV_pin,0);
			delayMicroseconds(19000); // 20000 => 20ms
		}
		for(int i = 0; i < 10; i++)
		{
			digitalWrite(SURV_pin,1);
			delayMicroseconds(2000); //
			digitalWrite(SURV_pin,0);
			delayMicroseconds(18000); //
		}
	}
	return 0;
}


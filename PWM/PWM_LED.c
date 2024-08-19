#include <stdio.h>
#include <wiringPi.h>

#define wpi_pin 22

int main(int n , char *s[])
{
	if(n<2)
	{
		printf("usage : pwm1 [duty rate(%%)]\n\n");
		return 1;
	}
	int duty_rate,dr_h,dr_l,period = 10;
	sscanf(s[1],"%d",&duty_rate); //sscanf >> 문자열에서 입력을 받는다.
	
	if(n>2)
		sscanf(s[2],"%d", &period);
	
	
	dr_h = (duty_rate *period) / 100;
	dr_l = (period - dr_h);
	
	wiringPiSetup(); //LED에 연결한 pin번호(wpi번호) 22번을 사용하겠다고 초기화시켜줌.
	pinMode(wpi_pin, OUTPUT);
	
	for(int i = 0; i <1000; i++)
	{
		digitalWrite(wpi_pin, 1);
		delay(dr_h);
		digitalWrite(wpi_pin, 0);
		delay(dr_l);
	}
	return 0;
}

#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>
#define wpi_pin 7

int main(int n , char *s[])
{
	if(n<2)
	{
		printf("usage : pwm [duty rate(%%)]\n\n");
		printf("		periode 10ms if empty\n");
		printf("default value : period = 10, DR = 50%%\n");
		//return 1;
	}
	int duty_rate = 50, dr ,period = 10;
	if(n>1)
		sscanf(s[1],"%d",&duty_rate); //sscanf >> 문자열에서 입력을 받는다.
	if(n>2)
		sscanf(s[2],"%d", &period);
	
	dr = (duty_rate *period) / 100; // Mark Time 
	
	wiringPiSetup(); //LED에 연결한 pin번호(wpi번호) 22번을 사용하겠다고 초기화시켜줌.
	pinMode(wpi_pin, OUTPUT);
	
	pwmSetMode(PWM_MODE_MS);
	softPwmCreate(wpi_pin,dr,period); // pwm thread를 만들어준다.첫번째 매개변수는 사용할 핀, 두번째는 pulse폭, 
								   //3번째는 범위.
	//softPwmWrite(wpi_pin,70);
	delay(5000);
	softPwmStop(wpi_pin);
	return 0;
}

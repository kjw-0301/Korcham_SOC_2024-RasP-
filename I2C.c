#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>

int main()
{
	int dh1 = wiringPiI2CSetup(0x48); //우리가 사용할 디바이스를 초기화.
	
	//Ch.3 (VR) > input 3번 채널의 아날로그 신호를 읽어옵니다. 
	//즉 입력으로 사용합니다.
	//Ain0 = 조도센서, Ain1 = 온도센서, Ain2 = 비어있음, Ain3 = 가변저항
	while(1)
	{
		wiringPiI2CWrite(dh1,00); 
		wiringPiI2CRead(dh1); //읽어온 채널을 set, clear.
		int val1 = wiringPiI2CRead(dh1); //ADC의 Sampling 과정
		delay(100);
		//float f1 = (float)((val1 / 255.0)*5.0);
		
		wiringPiI2CWrite(dh1,01); 
		wiringPiI2CRead(dh1);
		int val2 = wiringPiI2CRead(dh1); //ADC의 Sampling 과정
		delay(100);
		//float f2 = (float)((val2 / 255.0)*5.0);
		
		wiringPiI2CWrite(dh1,3); 
		wiringPiI2CRead(dh1);
		int val3 = wiringPiI2CRead(dh1); //ADC의 Sampling 과정
		delay(100);
		//float f3 = (float)((val3 / 255.0)*5.0);

		printf("VR input Level : [0]:%d [1]:%d [2]:%d\n", val1,val2,val3);
		delay(500);
		
		
		
	}
}

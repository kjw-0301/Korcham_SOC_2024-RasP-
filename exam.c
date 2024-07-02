#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>

int main()
{
	printf("\033[2J");
	int Handle = wiringPiI2CSetup(0x48);

	while(1)
	{
		wiringPiI2CWrite(Handle, 00);
		wiringPiI2CRead(Handle);
		int x_value = (wiringPiI2CRead(Handle) * 80)/255;
		delay(100);
		
		wiringPiI2CWrite(Handle, 01);
		wiringPiI2CRead(Handle);
		int y_value = (wiringPiI2CRead(Handle) *24) /255;
		delay(100);

		
		//printf("\033[2J");
		printf("\033[%d;%dH(%d,%d)", y_value, x_value, x_value,y_value);
		delay(200);
	}
	return 0;
}

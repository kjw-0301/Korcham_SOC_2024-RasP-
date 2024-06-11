#include <wiringPi.h>
#include <stdio.h>

#define r 8
#define g 9
#define y 7
#define SW1 2
#define SW2 3


int tim;
int mode = 0;
int intv = 0;
int state[40]; // all of 40 pin number status 
int stop_state = 0;
//int sw = digitalRead(2);
void Toggle(int pinNum);
void ISR_G();
void E_Stop();
int main()
{
	wiringPiSetup(); // pin Number use case (wPi)
	pinMode(SW1,INPUT); // 8 9 7 => OUTPUT, 2 = INPUT
	pinMode(SW2,INPUT); // 8 9 7 => OUTPUT, 2 = INPUT
	pinMode(r,OUTPUT);
	pinMode(g,OUTPUT);
	pinMode(y,OUTPUT);
	wiringPiISR(SW1,INT_EDGE_FALLING, ISR_G);
	wiringPiISR(SW2,INT_EDGE_FALLING, E_Stop);
	
	
	while(stop_state == 0)
	{
		
		tim = (9-intv) *100;
		if(mode)
			{
				Toggle(8);
				delay(tim);
				Toggle(9);
				delay(tim);
				Toggle(7);
				delay(tim);
			}
		else
			{
				Toggle(7);
				delay(tim);
				Toggle(9);
				delay(tim);
				Toggle(8);
				delay(tim);	
			}
		printf("current tim : %d\n", tim);	
		
		/*if(digitalRead(2) == 1)
			{
				//mode = !mode;
				intv++;
				if(intv > 12) 
				{
					intv = 1;
				}	
				printf("count : %d\n", tim);	
			}		*/
		/*digitalWrite(8,1);
		digitalWrite(9,0);
		digitalWrite(7,0);
		delay(1000);
		digitalWrite(8,0);
		digitalWrite(9,1);
		digitalWrite(7,0);
		delay(1000);
		digitalWrite(8,0);
		digitalWrite(9,0);
		digitalWrite(7,1);
		delay(1000);*/
		
	}
}
void Toggle(int pinNum)
{
	state[pinNum] = !state[pinNum];
	digitalWrite(pinNum,state[pinNum]);
}
void ISR_G()
{
	if(++intv > 8) intv =0;
	printf("interrupt occured..\n");
}
void E_Stop()
{
	printf("Emergency STOP!!\n");
	digitalWrite(8,0);
	digitalWrite(9,0);
	digitalWrite(7,0);
	stop_state = 1;
}

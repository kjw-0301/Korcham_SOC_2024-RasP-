#include <stdio.h>
#include <wiringPi.h>


#define wpi_PWM1 23
int PSC = 19;
int RANGE = 100;
int duty = 100/2;

enum {DO,Do,RE,Re,MI,PA,Pa,SOL,Sol,RA,Ra,CI};
int pitch[] = {262,277,294,311,330,349,370,392,415,440,466,494};
int range[12];
int song[] = {MI,RE,DO,RE,MI,MI,MI,RE,RE,RE,MI,SOL,SOL,MI,RE,DO,RE,MI,MI,MI,RE,RE,MI,RE,DO, -1};
int ryhtm[] = {4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4};

void calRange()//Cal Range values using song datas
{
	for(int i = 0; i < sizeof(song) / sizeof(song[i]); i++)
	{
		range[i] = 19200000 / (pitch[i] * PSC); 
	}
}
void PlaySound(int um, int r)
{
	pwmSetClock(PSC);
	pwmSetRange(range[um]);
	pwmWrite(wpi_PWM1, range[um]/2);//duty rate설정. 50%로 맞추기 위해서. 
	delay(1000/r);
	
}
int main()
{
	wiringPiSetup();
	pinMode(wpi_PWM1, PWM_OUTPUT);
	pwmSetMode(PWM_MODE_MS);
	//pwmSetClock(PSC); //PreScaler : ~ 1MHz
	//pwmSetRange(RANGE);//Range :
	//pwmWrite(wpi_PWM1,duty);
	calRange();
	for(int i = 0;song[i] != -1; i++)
	{
		//int um = range[i];
		//int ran = ryhtm[i];
		PlaySound(song[i],ryhtm[i]);
	}
	pinMode(wpi_PWM1, OUTPUT);
	return 0;
}

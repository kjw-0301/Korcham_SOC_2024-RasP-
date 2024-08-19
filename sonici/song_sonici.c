#include <stdio.h>
#include <wiringPi.h>


#define wpi_PWM1 23
extern double Sonic_();
extern double Dist();
int PSC = 19;
int RANGE = 100;
//int duty = 100/2;
enum {DO,Do,RE,Re,MI,PA,Pa,SOL,Sol,RA,Ra,CI};
int pitch[] = {262,277,294,311,330,349,370,392,415,440,466,494};
int range[12];
int song[] = {SOL,SOL,RA,RA,SOL,SOL,MI,-1,SOL,SOL,MI,MI,RE,SOL,SOL,RA,RA,SOL,SOL,MI,SOL,MI,RE,MI,DO,-1};
int ryhtm[] = {4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4};
int iFlag = 0;
void calRange()//Cal Range values using song datas
{
	for(int i = 0; i < sizeof(song) / sizeof(song[i]); i++)
	{
		range[i] = 19200000 / (pitch[i] * PSC); 
	}
}
double rate = 1;
void PlaySound(int um, int r)
{
	pwmSetClock(PSC);
	pwmSetRange(range[um]);
	pwmWrite(wpi_PWM1, range[um]/2);//duty rate설정. 50%로 맞추기 위해서. 
	delay(2000/(r*rate));
	pwmWrite(wpi_PWM1,0);
	delay(1);
}
void initSound()
{
	wiringPiSetup();
	pinMode(wpi_PWM1, PWM_OUTPUT);
	pwmSetMode(PWM_MODE_MS);
	calRange();
	iFlag = 1;
}

void Play(double r)
{
	if(!iFlag) //iFlag가 0이라면~
		initSound();
	rate = r;
	//double distance = Sonic_();
	for(int i = 0;song[i] != -1; i++)
	{
		PlaySound(song[i],ryhtm[i]/2);
	}
	pwmWrite(wpi_PWM1, 0);
}

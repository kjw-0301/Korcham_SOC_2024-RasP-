#include <stdio.h>
#include <wiringPi.h>
#define TRIG 8
#define ECHO 9

extern void Trigger();

int t1;
double dist;
//ISR에
void usISR() //ISR은 매개변수와 반환값이 없다.
{
	int tt = micros();
	int signal_echo = digitalRead(ECHO); //ECHO핀의 현재상태를 읽어온다.
	if(signal_echo == 1)t1 == tt;		//ECHO핀이 RisingEdge라면 카운트 시작
	else  						//ECHO핀이 FallingEdge라면 거리 계산시작
	{	
		dist = (tt - t1) * 0.17;
	}
}

/*double Dist()
{
	for(;;)
	{	
		//트리거 신호 (Trigger Siganl)
		Trigger();
		//ECHO 신호를 기다려줍니다.
		
		while(digitalRead(ECHO) != 1); // echo High
		int t1 = micros(); // Get current time[Start](in micro second)
		while(digitalRead(ECHO) != 0); // echo Low
		int t2 = micros(); //Get current time[End](in micro second)
		//double result = (t2 - t1) * ((340 / 1000000) /2 *1000) ;
		return (t2-t1) * 0.017;
		
	}
}*/



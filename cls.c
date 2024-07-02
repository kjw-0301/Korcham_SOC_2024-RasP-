#include <stdio.h>
int main()
{
	int x = 1;
	int y = 1;
	printf("\033[2J");
	printf("\033[%d;%dH", x,y);  //[x;yH
	return 0;
}

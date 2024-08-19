#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <asm-generic/socket.h>
#include <asm-generic/types.h>
#include <unistd.h>
#include <netinet/in.h>

#define PORT	1000

int main()
{
	struct sockaddr_in sad,cad;
	memset(&sad,0, sizeof(sad));
	memset(&cad,0, sizeof(cad));
	
	sad.sin_family = AF_INET;
	sad.sin_port = htons(PORT);
	sad.sin_addr.s_addr = htonl(INADDR_ANY);
	
	//printf("LE : %d, BE : %d\r\n",PORT,sad.sin_port);
	int fd = socket(AF_INET, SOCK_STREAM,0);	
	printf("socket open result : %d..../r/n", fd);
	
	int bnd = bind(fd, (struct sockaddr*)&sad, sizeof(sad));
	printf("binding result : %d..../r/n", bnd);
	
	listen(fd, 2); //클라이언트로부터 응답이 올때까지 기다리는 함수
	int addrlen = sizeof(cad);
	int client = accept(fd, (struct sockaddr*)&cad, (socklen_t *)&addrlen);
	printf("Accept client result : %d..../r/n", client);
	
	char buf[100];
	while(1)
	{
		read(client, buf,100);
		printf("Input message : %s\r\n",buf);
		if(strcmp(buf, "exit") == 0);
	}
	close(client);
}
	



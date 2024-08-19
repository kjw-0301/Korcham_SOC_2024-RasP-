#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>

#define PORT 1000

int main() {
    struct sockaddr_in sad, cad;
    memset(&sad, 0, sizeof(sad));
    memset(&cad, 0, sizeof(cad));

    sad.sin_family = AF_INET;
    sad.sin_port = htons(PORT);
    sad.sin_addr.s_addr = htonl(INADDR_ANY);

    int fd = socket(AF_INET, SOCK_STREAM, 0);
    printf("socket open result : %d\n", fd);

    int bnd = bind(fd, (struct sockaddr*)&sad, sizeof(sad));
    printf("binding result : %d\n", bnd);

    listen(fd, 2);
    int addrlen = sizeof(cad);
    int client = accept(fd, (struct sockaddr*)&cad, (socklen_t *)&addrlen);
    printf("Accept client result : %d\n", client);

    char buf[100];
    while (1) {
        memset(buf, 0, sizeof(buf)); 
        int bytes_read = read(client, buf, sizeof(buf) - 1);
        if (bytes_read <= 0) {
            printf("Client disconnected or read error.\n");
            break;
        }
        
        printf("Input message : %s\n", buf);
        
        if (strcmp(buf, "exit\n") == 0) {
            printf("Server shutting down...\n");
            break;
        }

        char response[100];
        snprintf(response, sizeof(response), "Message received: %s", buf);
        write(client, response, strlen(response));
    }
    
    close(client);
    close(fd);
    return 0;
}

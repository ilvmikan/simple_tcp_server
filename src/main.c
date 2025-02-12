#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

// CRIAR O SOCKET
// DEFINIR AS CONEXÕES
// ASSOCIAR 
// ESCUTAR
// ACEITAR

int main(){

    int new_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(new_socket == -1){
        perror("ERRO AO CRIAR SOCKET\n");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);
   
    if(bind(new_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1){
        perror("ERRO AO BIND\n");
        exit(EXIT_FAILURE);
    }

    if(listen(new_socket, 10) == -1){
        perror("NAO ESCUTEI\n");
        exit(EXIT_FAILURE);
    }

    printf("Servidor rodando na porta 8080.\n");

    struct sockaddr_in client_addr;
    socklen_t client_size = sizeof(client_addr);
    int client_socket = accept(new_socket, (struct sockaddr*)&client_addr, &client_size);
    
    if (client_socket == -1) {
        perror("ERRO AO ACEITAR CONEXÃO\n");
        exit(EXIT_FAILURE);
    }

    printf("Cliente conectado: %s\n", inet_ntoa(client_addr.sin_addr));

    close(client_socket);  
    close(new_socket); 

    return 0;
}

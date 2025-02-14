#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int server_fd, new_socket;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    /**
     * Criação do socket do servidor.
     *   AF_INET - IPv4
     *   SOCK_STREAM - TCP
     *   0 - Protocolo padrão (TCP)
     */
    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (server_fd == -1) {
        perror("Falha ao criar socket");
        exit(EXIT_FAILURE);
    }

    /**
     * Configuração do endereço do servidor.
     */
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; // escuta em qualquer IP disponível
    address.sin_port = htons(PORT); // converte a porta para o formato de rede

    /**
     * Vincula o socket à porta especificada (PORT 8080)
     */
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("Err: bind failed\n");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("Err: listen failed\n");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for connections on port %d...\n", PORT);

    new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen);
    if (new_socket < 0) {
        perror("Err: connection denied\n");
        exit(EXIT_FAILURE);
    }

    printf("Client connected!\n");

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = read(new_socket, buffer, BUFFER_SIZE - 1);
        
        if (bytes_received <= 0) {
            printf("Client desconnected.\n");
            break;
        }

        printf("Received: %s\n", buffer);

        if (strncmp(buffer, "exit", 4) == 0) {
            printf("closing connection with client3.\n");
            break;
        }

        char *response = "Message Received!\n";
        send(new_socket, response, strlen(response), 0);
    }

    close(new_socket);
    close(server_fd);

    return 0;
}


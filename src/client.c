#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main()
{
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        perror("Falha ao criar socket");
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
    {
        perror("Endereço inválido");
        exit(EXIT_FAILURE);
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("Conexão falhou");
        exit(EXIT_FAILURE);
    }

    printf("Conectado ao servidor! Digite mensagens ('exit' para sair)\n");

    while (1)
    {
        printf("Você: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        buffer[strcspn(buffer, "\n")] = 0;

        send(sock, buffer, strlen(buffer), 0);

        if (strncmp(buffer, "exit", 4) == 0)
        {
            printf("Encerrando conexão.\n");
            break;
        }

        memset(buffer, 0, BUFFER_SIZE);
        read(sock, buffer, BUFFER_SIZE);
        printf("Servidor: %s\n", buffer);
    }

    close(sock);

    return 0;
}

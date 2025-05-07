# Chat TCP simples (Comunicação bidirecional simples entre um servidor e cliente usando protocolo TCP)

Um simples servidor TCP em C utilizando Sockets. Ele escuta conexões na porta `8080` e permite troca de mensagens com o cliente.

## Funcionalidades
- Aceita uma única conexão por vez.
- O servidor recebe mensagens.
  
## Requisitos
- GCC Compiler
- Linux ou WSL
- Telnet

## Como rodar

### Compilação
```sh
gcc server.c -o server
gcc client.c -o client
```

### Executando o Servidor
```sh
./server
```
![image](https://github.com/user-attachments/assets/4064335f-55df-4bbe-9cdc-e79edbdbbb83)

### Executando o Cliente
Abra um **novo terminal** e rode:
```sh
./client
```
![image](https://github.com/user-attachments/assets/eeceb653-1bea-432d-b268-9e9620b7d2ca)


### Testando com Telnet
Caso não tenha um cliente (não queira executar o arquivo ./client, você pode usar o `telnet`:
```sh
telnet 0.0.0.0 8080
```

## Exemplo de Saída

### Servidor
![image](https://github.com/user-attachments/assets/a29bac7c-78a2-4e7f-9fb1-ee818b2390a5)


### Cliente
![image](https://github.com/user-attachments/assets/576f60f1-bd47-40bb-816f-6ca8562e3fb8)


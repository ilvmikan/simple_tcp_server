# Simlpes "TCP Server" em C

Um simples servidor TCP em C utilizando Sockets. Ele escuta conexões na porta `8080` e permite troca de mensagens com o cliente.

## Funcionalidades
- Aceita uma única conexão por vez.
- Recebe e responde mensagens.
- Para fechar a conexão, envie `exit`.

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

### Executando o Cliente
Abra um **novo terminal** e rode:
```sh
./client
```
Digite algo e veja se o servidor recebeu.

### Testando com Telnet
Caso não tenha um cliente TCP, você pode usar `telnet`:
```sh
telnet 0.0.0.0 8080
```

## Exemplo de Saída

### Servidor
```sh
Waiting for connections on port 8080...
Client connected!
Received: Hello, Server!
Received: exit
Closing connection with client.
```

### Cliente
```sh
Hello, Server!
exit
```

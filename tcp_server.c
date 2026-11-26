#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <arpa/inet.h> 
 
#define PORT 8080 
#define BUFFER_SIZE 1024 
 
int main() { 
    int server_fd, new_socket; 
    struct sockaddr_in address; 
    int addrlen = sizeof(address); 
    char buffer[BUFFER_SIZE] = {0}; 
    char *response = "Hello from TCP Server! Connection established successfully."; 

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) { 
        perror("Socket creation failed"); 
        exit(EXIT_FAILURE); 
    } 

    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
 
    address.sin_port = htons(PORT); 

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) { 
        perror("Bind failed"); 
        exit(EXIT_FAILURE); 
    } 

    if (listen(server_fd, 3) < 0) { 
        perror("Listen failed"); 
        exit(EXIT_FAILURE); 
    } 
    printf("TCP Server is running and listening on port %d...\n", PORT); 
 
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) { 
        perror("Accept failed"); 
        exit(EXIT_FAILURE); 
    } 
 
    read(new_socket, buffer, BUFFER_SIZE); 
    printf("Message from Client: %s\n", buffer); 
     
    send(new_socket, response, strlen(response), 0); 
    printf("Response sent back to client.\n"); 

    close(new_socket); 
    close(server_fd); 
    return 0; 
} 

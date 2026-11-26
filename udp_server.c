#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <arpa/inet.h> 
 
#define PORT 8081 
#define BUFFER_SIZE 1024 
 
int main() { 
    int sockfd; 
    char buffer[BUFFER_SIZE]; 
    char *response = "Hello UDP Client! Datagram received successfully."; 
    struct sockaddr_in servaddr, cliaddr; 
     
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) { 
        perror("Socket creation failed"); 
        exit(EXIT_FAILURE); 
    } 
     
    memset(&servaddr, 0, sizeof(servaddr)); 
    memset(&cliaddr, 0, sizeof(cliaddr)); 
     
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = INADDR_ANY; 
    servaddr.sin_port = htons(PORT); 
 
    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) { 
        perror("Bind failed"); 
        exit(EXIT_FAILURE); 
    } 
    printf("UDP Server is active and waiting for datagrams on port %d...\n", PORT); 
     
    socklen_t len = sizeof(cliaddr); 
    int n; 
     
    n = recvfrom(sockfd, (char *)buffer, BUFFER_SIZE, MSG_WAITALL, (struct sockaddr *)&cliaddr, &len); 
    buffer[n] = '\0'; 
    printf("Message from Client: %s\n", buffer); 
     
    sendto(sockfd, (const char *)response, strlen(response), MSG_CONFIRM, (const struct sockaddr *)&cliaddr, len); 
    printf("Response sent back to client.\n"); 
     
    close(sockfd); 
    return 0; 
} 

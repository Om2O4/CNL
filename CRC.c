#include <stdio.h>
#include <string.h> 
void divideCRC(charbits[], charkey[])
{
intn = strlen(bits);
intk = strlen(key);
for(inti=0;i<=n-k;i++)
{
if (bits[i]== '1')
{
for(intj=0;j<k;j++)
{
if(bits[i+j]==key[j]) 
bits[i + j] = '0';
else
bits[i + j] = '1';
}
}
}
}
int main()
{ 
char data[64]; 
char key[16]; 
char transmitted[128];
char received[128]; 
printf("Enter data : ");
scanf("%s", data); 
printf("Entergenerator(Shared Key): ");
scanf("%s", key);
intdataLength=strlen(data);
intkeyLength=strlen(key); 
/*Add zeros according to the generator length */
strcpy(transmitted, data); 
for(int i = dataLength; i < dataLength + keyLength - 1; i++) 
transmitted[i] = '0'; 
transmitted[dataLength + keyLength - 1] = '\0'; 
/*Find CRC remainder */
strcpy(received, transmitted);
divideCRC(received, key); 
/*Attach the remainder to the original data */
for(int i = 0; i < keyLength - 1; i++) 
transmitted[dataLength + i] = received[dataLength + i]; 
printf("Transmitted frame: %s\n", transmitted); 
/*Receiver side */ 
printf("Enter received frame: ");
scanf("%s", received); 
divideCRC(received, key); 
interrorFound = 0; 
intstart = strlen(received) - (keyLength - 1); 
for(int i = start; received[i] != '\0'; i++)
{
if(received[i] == '1')
{
errorFound = 1;
break; 
}
}
if(errorFound) 
printf("Status: Error detected!\n"); 
else 
printf("Status: Frame is valid.\n"); 
return 0; 
}

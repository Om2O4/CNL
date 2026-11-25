#include <stdio.h> 
#define R 4
#define C 4 
intmain()
{
intsend[R + 1][C + 1] = {0};
intreceive[R + 1][C + 1] = {0}; 
printf("Enter 4x4 binary data bits (row by row):\n"); 
/*Generate row and column parity */
for(int i = 0; i < R; i++) 
{
for(int j = 0; j < C; j++)
{
scanf("%d", &send[i][j]); 
send[i][C] = send[i][C] ^ send[i][j];
send[R][j] = send[R][j] ^ send[i][j]; 
}
}
send[R][C] = send[R][C] ^ send[i][C]; 
printf("\n--- Transmitted Matrix (with Parity Row & Col) ---\n"); 
for(int i = 0; i <= R; i++)
{
for(int j = 0; j <= C; j++) 
printf("%d ", send[i][j]); 
printf("\n"); 
}
printf("\nEnter 5x5 received matrix (separated by spaces):\n"); 
for(int i = 0; i <= R; i++)
{
for(int j = 0; j <= C; j++) 
scanf("%d", &receive[i][j]); 
}
/*Find the row having incorrect parity */
intwrongRow = -1; 
intwrongCol = -1; 
for(int i = 0; i <= R; i++)
{
intparity = 0; 
for(int j = 0; j <= C; j++) 
parity ^= receive[i][j]; 
if(parity == 1) 
wrongRow = i; 
}
/*Find the column having incorrect parity */
for(int j = 0; j <= C; j++) 
{
intparity = 0; 
for(int i = 0; i <= R; i++) 
parity ^= receive[i][j]; 
if(parity == 1) 
wrongCol = j; 
}
/*Display the result */ 
if(wrongRow == -1 && wrongCol == -1)
{
printf("\nStatus: No error detected. Matrix is valid.\n"); 
}
elseif(wrongRow != -1 && wrongCol != -1)
{
printf("\nStatus: Single-bit error detected at Row %d, Col %d!\n", 
wrongRow + 1, wrongCol + 1); 
/*Correct the faulty bit */
receive[wrongRow][wrongCol] = 
receive[wrongRow][wrongCol] ^ 1; 
printf("\n--- Corrected Matrix ---\n"); 
for(int i = 0; i <= R; i++)
{
for(int j = 0; j <= C; j++) 
printf("%d ", receive[i][j]); 
printf("\n"); 
}
}
else
{
printf("\nStatus: Multiple errors detected (cannot correct).\n"); 
}
return 0; 
} 

#include <stdio.h> 
intfindParityCount(int dataBits)
{
intparityBits = 0; 
while ((1 << parityBits) < dataBits + parityBits + 1) 
parityBits++; 
return parityBits; 
}
intisPowerOfTwo(int n) 
{
}
return (n > 0) && ((n & (n - 1)) == 0); 
void placeData(int data[], int code[], int m, int r)
{
intdataIndex = 0;
intlength = m + r; 
for(intpos = 1; pos <= length; pos++)
{
if(isPowerOfTwo(pos)) 
code[pos] = 0; 
else
code[pos] = data[dataIndex++]; 
}
}
voidgenerateParity(int code[], int r, int length)
{
for(intp = 0; p < r; p++)
{
intparityPosition = 1 << p;
intparity = 0; 
}
for(int pos = 1; pos <= length; pos++)
{
if((pos & parityPosition) != 0) 
parity ^= code[pos]; 
code[parityPosition] = parity; 
}
}
int findError(int code[], int r, int length)
{
int errorPosition = 0;
for (int p = 0; p < r; p++)
{
intparityPosition=1<<p;
intparity= 0;
for(intpos=1;pos<=length; pos++)
{
if((pos&parityPosition) != 0) 
parity^=code[pos];
}
if (parity!= 0)
errorPosition+=parityPosition; 
}
return errorPosition; 
}
voiddisplayCode(intcode[],int length)
{
for(inti=1;i<=length;i++)
printf("%d",code[i]);
printf("\n"); 
} 
int main()
{ 
int m; 
printf("Enternumberofdata bits: "); 
scanf("%d", &m); 
int r = findParityCount(m);
int length = m + r; 
int data[m]; 
int code[length + 1]; 
printf("Enterdatabits(0/1)one by one:\n"); 
for (int i = 0; i < m; i++) 
scanf("%d", &data[i]); 
placeData(data, code, m, r);
generateParity(code,r,length); 
printf("\nGeneratedHamming Code: ");
displayCode(code, length);
int errorInput; 
printf("\nEnterpositiontointroduce error (1 to %d), or 0 for no error: ", 
l en gth);
scanf("%d", &errorInput);
if(errorInput>=1&&errorInput <= length)
{
code[errorInput] ^= 1;
printf("Bitatposition%dflipped. Transmitted (corrupted) code: ", 
errorInput);
displayCode(code, length);
}
interrorPosition=findError(code, r, length); 
if(errorPosition == 0)
{
printf("\nNo error detected.\n"); 
}
else if (errorPosition <= length)
{
printf("\nError detected at position: %d\n", errorPosition); 
code[errorPosition] ^= 1; 
printf("Corrected Hamming Code: ");
displayCode(code, length); 
}
else
{
printf("\nError position is outside the Hamming code.\n"); 
}
return 0; 
}

// This C program demonstrates the switch statement without using breaks. */
#include <stdio.h>
void main() { 
char ch; 
double  a = 10, b = 20; double f; 
for(int i = 0; i<5; i++)
{
	printf("Enter math operation:");
	ch = getchar(); // reads a single char
	printf("ch = %c\n", ch); 
switch (ch){ 
case '+': f = a + b; printf("f = %g\n", f); break;
case '-': f = a - b; printf("f = %g\n", f); break;
case '*': f = a * b; printf("f = %g\n", f); break;
case '/': f = (float)a / (float)b; printf("f = %g\n", f); break;
default: printf("invalid operator\n"); 
		   } 
	ch = getchar();
}
}

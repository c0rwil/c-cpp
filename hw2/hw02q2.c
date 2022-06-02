// Carlos Corral-Williams
#include <stdio.h>
// Macro implementation
#define addm(a,b) (a+b)
#define squared_addm(a,b) (a*a)+(b*b)
#define absm(a) (a<0 ? -(a):a)
#define oddm(a) (a%2==0 ? 0:1)

int addf(int a, int b) { return a + b; }

int squared_addf(int a, int b) { return (a * a) + (b * b); }

int absf(int a) { if (a < 0) { return -(a); } else { return a; } }

int oddf(int a) { if (a % 2 == 0) { return 0; } else { return 1; } }
int a = 3, b = 6;

int main()
{

	printf("addf(a, b) = %d\n", addf(a, b));
	printf("addm(a, b) = %d\n", addm(a, b));
	printf("addf(a++, b--) = %d\n", addf(a++, b--));
	a = 3, b = 6; //resets a,b values
	printf("addm(a++, b--) = %d\n", addm(a++, b--));

	a = 3, b = 6;
	printf("squared_addf(a, b) = %d\n", squared_addf(a, b));
	printf("squared_addm(a, b) = %d\n", squared_addm(a, b));
	printf("squared_addf(--a, b++) = %d\n", squared_addf(--a, b++));

	a = 3; b = 6;
	printf("squared_addm(--a, b++) = %d\n", squared_addm(--a, b++));

	a = 3; b = 6;
	printf("absf(a) = %d\n", absf(a));
	printf("absm(a) = %d\n", absm(a));
	printf("absf(--a) = %d\n", absf(--a));
	a = 3; b = 6;
	printf("absm(--a) = %d\n", absm(--a));

	a = 3; b = 6;
	printf("oddf(a) = %d\n", oddf(a));
	printf("oddm(a) = %d\n", oddm(a));
	printf("oddf(++a) = %d\n", oddf(++a));
	a = 3; b = 6;
	printf("oddm(++a) = %d\n", oddm(++a));
}
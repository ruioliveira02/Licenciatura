#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>



int isValid(int a, int b, int c)
{
	return (a < (b + c)) && (b < (a + c)) && (c < (b + a));
}


void evaluateSides(int a, int b, int c)
{
	if((a*a == (b*b) + (c*c)) || (b*b == (a*a) + (c*c)) || (c*c == (b*b) + (a*a)))
	{
		printf("RETANGULO ");
	}
	else if(a == b && b == c)
	{
		printf("EQUILATERO ");
	}
	else if(a == b || b == c || a == c)
	{
		printf("ISOSCELES ");
	}
	else
	{
		printf("ESCALENO ");
	}
}

int main2() {

	int a = 0, b = 0, c = 0;

	assert(scanf("%d %d %d", &a, &b, &c) == 3);


	if(!isValid(a,b,c))
	{
		printf("INVALIDO\n");
		return 0;
	}

	evaluateSides(a,b,c);


	float p = 0.0f;// (a + b + c) / 2.0;

	float ar = sqrt(p * (p - a) * (p - b) * (p - c));

	p *= 2.0;


	printf("%d %.2f\n", p, ar);


	return 0;
}
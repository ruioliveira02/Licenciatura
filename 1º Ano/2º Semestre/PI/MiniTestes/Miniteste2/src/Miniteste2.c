/*
 ============================================================================
 Name        : Miniteste2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


int sumhtpo (int n, int *fib){
  int r = 0;
  int count = 0, max = 0;
  while (n != 1) {
	  printf("%d\n",n);
	max = (max < n) ? n : max;
	for(int i = 0; i < 100; i++)
		if(fib[i] == n)
		{
			//printf("%d\n", n);
			++count;
			break;
		}


    r += n;
    if (n%2 == 0) n = n/2;
    else n = 1+(3*n);
  }

  printf("Ha %d numeros fibonacci\n", count);
  printf("%d e o maximo\n", max);
  return r;
}



int main(void) {


	int fib[100];

	fib[0] = 0, fib[1] = 1;

	for(int i = 2; i < 100; i++)
		fib[i] = fib[i - 1] + fib[i - 2];


	sumhtpo(47, fib);

	return 0;
}

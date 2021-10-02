/*
 ============================================================================
 Name        : MiniTeste4.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int sumhtpo (int n, int* ar){
  int r = 0, count = 0;
  while (n != 1) {
	ar[count++] = n;
    r += n;
    if (n%2 == 0) n = n/2;
    else n = 1+(3*n);
  }
  printf("%d parcelas\n", count);
  return r;
}

void swap(int* x, int* y) {
	int z = *x;
	*x = *y;
	*y = z;
}

int sort2(int* ar, int N) {
	int count = 0;
	for(int i = 0; i < N; i++) {
		for(int j = i + 1; j < N; j++) {
			if(ar[i] < ar[j]) { //ATENCAO SINAL
				swap(&ar[i], &ar[j]);
				++count;
			}
		}
	}

	return count;
}

int sort(int* ar, int N) {
	int count = 0;
	for(int i = 0; i < N; i++) {
		for(int j = i + 1; j < N; j++) {
			if(ar[i] > ar[j]) { //ATENCAO SINAL
				swap(&ar[i], &ar[j]);
				++count;
			}
		}
	}

	return count;
}

int main(void) {
	int ar[1000];

	sumhtpo(73, ar);

	sort2(ar,115);

	for(int i = 0; i < 118; i++)
		printf("%d| %d\n", i + 1, ar[i]);

	printf("A resposta é %d\n", ar[29]);

	sumhtpo(6, ar);
	printf("%d swaps feitos\n", sort2(ar, 8));

	sumhtpo(73, ar);
	printf("%d swaps feitos\n", sort2(ar, 115));

	return EXIT_SUCCESS;
}

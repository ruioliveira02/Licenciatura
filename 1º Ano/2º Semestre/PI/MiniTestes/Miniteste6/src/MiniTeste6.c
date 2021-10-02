/*
 ============================================================================
 Name        : MiniTeste6.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


int calcula(LInt l) {
    int sum = 0;

    int index = 0, count = 0;

    while(l && count < 37) {
        if(index % 2) {
            sum += l->valor;
            ++count;
        }
        l = l->prox;
        index++;
    }

    return sum;
}



void fillArray(ABin a, ABin *ar, int* count) {
    if(a == NULL)
        return;
    if(*count > 12)
        return;
    fillArray(a->esq, ar, count);

    if(*count > 12)
        return;

    ar[(*count)] = a;
    (*count)++;
    fillArray(a->dir, ar, count);
}


ABin procura(ABin a) {
    ABin ar[16];
    int x = 0;
    fillArray(a, ar, &x);
    return ar[10];
}

int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}

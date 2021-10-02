/*
 ============================================================================
 Name        : Miniteste5.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct slist {

  int valor;
  struct slist * prox;
} *LInt;


void printLInt(LInt v) {
	while(v) {
		printf("%d ", v->valor);
		v = v->prox;
	}

	printf("\n");
}

LInt newLInt (int x, LInt xs) {
  LInt r = malloc (sizeof(struct slist));
  if (r!=NULL) {
    r->valor = x;
    r->prox = xs;
  }
  return r;
}

#define OPTION1 free(b); if (a) a->prox = NULL; a = l;





LInt init (LInt l) {
  LInt a = NULL;
  LInt b = l;
  while (b->prox) {
    a = b;
    b = b->prox;
  }
  OPTION1
  return a;
}

#define OPTION2

LInt clone (LInt l) {
  LInt r,a,b;
  r = a = b = NULL;
  while (l) {
    a = newLInt(l->valor,NULL);
    OPTION2
    l = l->prox;
  }
  return r;
}

int main(void) {
	LInt test = newLInt(1, NULL);
	LInt test2 = newLInt(2, NULL);
	test->prox = test2;
	printf("Aqui\n");
	printLInt(init(test));
	printLInt(init(test2));

	printLInt(clone(test));
	printLInt(clone(test2));
	printLInt(clone(NULL));

	return EXIT_SUCCESS;
}

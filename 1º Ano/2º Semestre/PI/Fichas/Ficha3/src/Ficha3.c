#include <stdio.h>
#include <stdlib.h>


void swapM (int *x, int *y){
    int z = *y;
    *y = *x;
    *x = z;
}

void swap (int v[], int i, int j){
    /*int h = v[i];
    v[i] = v[j];
    v[j] = h;*/
	swapM(&v[i], &v[j]);
}

void inverteArray (int v[], int N){
    int i;
    for(i = 0; i < N / 2; i++) {
        int j = v[i];
        v[i] = v[N - i - 1];
        v[N - i - 1] = j;
    }
}

void dumpV (int v[], int N){
    int i;
    for (i=0; i<N; i++) printf ("%d ", v[i]);
    putchar ('\n');
}

int soma (int v[], int N){
    int res = 0;

    int i;
    for(i = 0; i < N; i++)
        res += v[i];

    return res;
}

int maximum (int v[], int N, int *m){

    if(N <= 0)
        return 1;

    *m = v[0];

    int i;
    for(i = 1; i < N; i++)
        if(v[i] > *m)
            *m = v[i];

    return 0;
}

void quadrados (int q[], int N){
    int prev = 0;
    q[0] = prev;

    int i;
    for(i = 0; i < N; i++)
    {
        q[i]= prev;
        prev += (2*i) + 1; // (a + 1)^2 = a^2 + 2a +1
    }
}

void pascal (int v[], int N){
    int prev = 1;
    int i;

    for(i = 0; i <= N ; i++)
    {
       v[i] = prev;
       prev = (int)(prev * (float)(N - i) / (i + 1));
    }
}

void printLine(int v[], int N)
{
    int i;

    for(i = 0; i < N; i++)
    {
        printf("%d", v[i]);

        if(i != N - 1)
            printf(" ");
    }

    printf("\n");
}

void desenhaTriangulpP (int N){
    int line[N];

    int i;
    for(i = 0; i < N; i++)
    {
        pascal(line, i);
        printLine(line, i + 1);
    }
}
/*
   Prints
   1 1 4
   2 2 6
   3 3 8
   4 4 10
   5 5 12
 */
void oneA()
{
	int x [15] = {1,  2, 3, 4, 5,6,  7, 8, 9,10,11,12,13,14,15};
	int *y, *z, i;
	y = x;
	z = x + 3;
	for (i=0; i<5; i++) {
		printf ("%d %d %d\n",x[i], *y, *z);
		y = y + 1;
		z = z + 2;
	}
}

//Prints 13
void oneB()
{
	int i, j, *a, *b;
	i = 3;
	j = 5;
	a = b = 42;
	a = &i;
	b = &j;
	i++;
	j = i + *b;
	b = a;
	j = j + *b;
	printf ("%d\n", j);
}

int main()
{
	printf("Alinea 1 a) \n");
	oneA();

	printf("Alinea 1 b) \n");
	oneB();
    printf ("Testes\n");

    // teste das funções de swap

    int a, b, v[10] = {10, 6, 2, 3, 5, 1, 5, 9, 8, 7};
    int x = 3, y = 5;
    printf ("x = %d y = %d\n", x, y);
    swapM (&x, &y);
    printf ("x = %d y = %d\n", x, y);

    printf ("%d %d\n", v[0], v[9]);
    swap (v,0,9);
    printf ("%d %d\n", v[0], v[9]);

    printf ("ao invertemos o array "); dumpV (v,10);
    inverteArray (v,10);
    printf ("obtemos               "); dumpV (v,10);



    // teste das funções maximum, soma e quadrados

    x = maximum (v,10, &y);
    printf ("O maior elemento de "); dumpV (v,10);
    printf ("é %d\n", y);

    printf ("Os 10 primeiros quadrados: ");
    quadrados (v,10);
    dumpV (v,10);

    x = soma (v,10);
    printf ("A soma dos elementos de "); dumpV (v,10);
    printf ("é %d\n", x);



    // teste da função de cálculo do triangulo de Pascal

    printf ("A linha 5 do triângulo de Pascal é ");
    pascal (v,5); dumpV (v,6);

    printf ("As linhas 0 a 10 do triângulo de Pascal\n\n");
    desenhaTriangulpP (10);

    printf ("\nFim dos testes\n");

    return 0;
}

#include <stdio.h>

void dumpV (int v[], int N){
    int i;
    putchar ('{');
    for (i=0; i<N; i++) printf ("%2d ", v[i]);
    putchar ('}');
}
void simNao (int x){
    if (!x) printf (" não ");
}

int ordenado (int a[], int N){
    int i;
    
    for(i = 1; i < N; i++)
        if(a[i] < a[i - 1])
            return 0;
            
    return 1;
}

void merge (int a[], int na, int b[], int nb, int r[]){
    int ia = 0;
    int ib = 0;
    int i = 0;
    
    while(ia < na && ib < nb)
    {
        if(a[ia] < b[ib])
        {
            r[i++] = a[ia++];
        }
        else
        {
            r[i++] = b[ib++];
        }
    }
    
    while(ia < na)
        r[i++] = a[ia++];
        
    while(ib < nb)
        r[i++] = b[ib++];
}

void swap(int* a, int* b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

int partition (int v[], int N, int x){
    
    int i;
    int count = 0;
    for(i = 0; i < N; i++)
    {
        if(v[i] < x)
        {
            swap(&v[count], &v[i]);
            ++count;
        }
    }
    return count;
}

int main() {  
    int a [15] = {10, 3,45,56, 8,23,13,42,77,31,18,88,24,45, 1},
        b [10] = { 4,12,34,45,48,52,61,73,84,87}, 
        c [10] = { 1, 3, 8,22,33,35,38,41,44,49}, 
        d [50];
    int x;
    
    printf ("Testes\n\n");

    printf ("O array "); dumpV(a,15);
    simNao (ordenado (a,15)); printf (" está ordenado\n");
    printf ("O array "); dumpV(b,10);
    simNao (ordenado (b,10)); printf (" está ordenado\n");
    
    printf ("\n\nMerge dos arrays "); dumpV (b,10);
    printf ("\ne                "); dumpV (c,10); 
    merge (b, 10, c, 10, d);
    printf ("\nresulta em       "); dumpV (d,20);

    printf ("\n\n\nA partição do array  "); dumpV (a,15);
    printf ("\nusando 30 resulta em "); 
    x = partition (a,15,30); 
    dumpV (a,15); printf (" e retorna %d \n", x);

    printf ("\nFim dos testes\n");
    return 0;
}
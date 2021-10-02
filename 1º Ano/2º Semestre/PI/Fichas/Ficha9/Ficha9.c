#include <stdio.h>

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} * ABin;

ABin newABin (int r, ABin e, ABin d) {
    ABin a = malloc (sizeof(struct nodo));

    if (a!=NULL) {
        a->valor = r;
        a->esq = e;
        a->dir = d;
    }

    return a;
}
int altura(ABin a) {
    if(a == NULL)
        return 0;

    int ans = 1;

    int l = altura(a->esq), r = altura(a->dir);

    ans += (l < r) ? r : l;

    return ans;
}

int nFolhas(ABin a) {
    if(a == NULL)
        return 0;
    if(a->esq == NULL && a->dir == NULL)
        return 1;

    return nFolhas(a->esq) + nFolhas(a->dir);
}


ABin maisEsquerda(ABin a) {
    while(a != NULL && a->esq != NULL)
        a = a->esq;

    return a;
}

void imprimeNivel(ABin a, int l) {
    if(a == NULL)
        return;
    if(l == 0) {
        printf("%d\n", a->valor);
    } else {
        imprimeNivel(a->esq, l - 1);
        imprimeNivel(a->dir, l - 1);
    }
}

int procuraE (ABin a, int x) {
    if(a == NULL) 
        return 0;

    if(a->valor == x)
        return 1;

    return procuraE(a->esq, x) || procuraE(a->dir, x);
}

struct nodo *procura (ABin a, int x) {
    if(a == NULL)
        return NULL;

    if(a->valor == x)
        return a;

    if(x < a->valor)
        return procura(a->esq, x);
    else
        return procura(a->dir, x);
}


int nivel (ABin a, int x) {
    if(a == NULL)
        return -1;

    if(a->valor == x)
        return 0;

    if(x < a->valor)
        return nivel(a->esq, x);
    else
        return nivel(a->dir, x);
}


void imprimeAte (ABin a, int x) {
    if(a == NULL)
        return;
    if(a->valor > x)
        return;

    imprimeAte(a->esq, x);
    printf("%d\n", a->valor);
    imprimeAte(a->dir, x);
}

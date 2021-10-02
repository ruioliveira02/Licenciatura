#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} *ABin;


#define max(a,b) ((a < b) ? b : a)
#define min(a,b) ((a < b) ? a : b)

//28
int altura(ABin a) {
    if(a == NULL)
        return 0;
    
    int l = altura(a->esq), r = altura(a->dir);

    return 1 + max(l,r);
}

//29
ABin cloneAB (ABin a) {
    if(a == NULL)
        return NULL;
        
    ABin clone = malloc(sizeof(struct nodo));

    clone->valor = a->valor;
    clone->esq = cloneAB(a->esq);
    clone->dir = cloneAB(a->dir);

    return clone;
}

//30
void mirror (ABin *a) {
    if(*a == NULL)
        return;

    mirror(&(*a)->esq);
    mirror(&(*a)->dir);
    ABin temp = (*a)->esq;
    (*a)->esq = (*a)->dir;
    (*a)->dir = temp;
}

//31
void inorder (ABin a, LInt * l) {
    if(a == NULL)
        return;
    //Ordem trocada porque os elementos sao inseridos no inicio da lista
    inorder(a->dir, l);
    *l = newLInt(a->valor, *l);
    inorder(a->esq, l);
}

//32
void preorder2 (ABin a, LInt * l) {
    if(a == NULL)
        return;
    //Ordem trocada porque os elementos sao inseridos no inicio da lista
    preorder2(a->dir, l);
    preorder2(a->esq, l);
    //printf("%d\n", a->valor);
    *l = newLInt2(a->valor, *l);
}

void preorder (ABin a, LInt * l) {
    *l = NULL;
    preorder2(a,l);
}


//33
void posorder2 (ABin a, LInt * l) {
    if(a == NULL)
        return;
    //Ordem trocada porque os elementos sao inseridos no inicio da lista
    *l = newLInt2(a->valor, *l);
    posorder2(a->dir, l);
    posorder2(a->esq, l);
    
}

void posorder(ABin a, LInt * l) {
    *l = NULL;
    posorder2(a, l);
}


//34
int depth (ABin a, int x) {
    if(a == NULL)
        return -1;

    if(a->valor == x)
        return 1;

    int l = depth(a->esq, x), r = depth(a->dir, x);


    if(l == -1)
        return (r < 0) ? r : r + 1;
    if(r == -1)
        return (l < 0) ? l : l + 1;

    return 1 + min(l,r);
}

//35
int freeAB (ABin a) {
    if(a == NULL)
        return 0;

    int ans = 1 + freeAB(a->esq) + freeAB(a->dir);

    free(a);

    return ans;
}

//36
int pruneAB (ABin *a, int l) {
    if(*a == NULL)
        return 0;

    if(l == 0) {
        int res = freeAB(*a);
        *a = NULL;
        return res;
    }
    return pruneAB(&(*a)->esq, l - 1) + pruneAB(&(*a)->dir, l - 1);
}


//37
int iguaisAB (ABin a, ABin b) {
    if(a == NULL && b == NULL)
        return 1;
    if(a == NULL || b == NULL)
        return 0;

    return (a->valor == b->valor) && iguaisAB(a->esq, b->esq) && iguaisAB(a->dir, b->dir);
}


//38
void merge(LInt* l, LInt* r) {
    if(*l == NULL){
        *l = *r;
        return;
    }
    while(*l && (*l)->prox)
        l = &(*l)->prox;
        
    (*l)->prox = *r;
}

LInt nivelL (ABin a, int n) {
    if(a == NULL)
        return NULL;
    if(n == 0)
        return NULL;
    LInt l = nivelL(a->esq, n - 1), r = nivelL(a->dir, n - 1);
    if(n == 1) {
        LInt x = malloc(sizeof(struct lligada));
        x->valor = a->valor;
        x->prox = NULL;
        merge(&l,&x);
    }
    
    merge(&l,&r);
    
    return l;
}


//39
int nivelV (ABin a, int n, int v[]) {
    if(n < 1 || a == NULL)
        return 0;
        
    int count = nivelV(a->esq, n - 1, v);
    
    if(n == 1) {
        v[count++] = a->valor;
    }
    
    count += nivelV(a->dir, n - 1, v + count);
    return count;
}


//40
int dumpAbin (ABin a, int v[], int N) {
    if(a == NULL || N == 0)
        return 0;
        
    int count = 1 + dumpAbin(a->esq, v, N - 1);
    v[count - 1] = a->valor;
    if(N > count)
        count += dumpAbin(a->dir, v + count, N - count);
    
    return count;
}

//41
ABin somasAcA (ABin a) {
    if(a == NULL)
        return NULL;
    ABin ans = malloc(sizeof(struct nodo));
    
    ans->esq = somasAcA(a->esq);
    ans->dir = somasAcA(a->dir);
    
    ans->valor = a->valor;
    
    if(ans->esq != NULL)
        ans->valor += ans->esq->valor;
    if(ans->dir != NULL)
        ans->valor += ans->dir->valor;
        
    return ans;
}


//42
int contaFolhas (ABin a) {
    if(a == NULL)
        return 0;
    
    if(a->esq == NULL && a->dir == NULL)
        return 1;
        
    return contaFolhas(a->esq) + contaFolhas(a->dir);
}


//43
ABin cloneMirror (ABin a) {
    if(a == NULL)
        return NULL;
        
    ABin res = malloc(sizeof(struct nodo));
    
    res->valor = a->valor;
    res->esq = cloneMirror(a->dir);
    res->dir = cloneMirror(a->esq);
    
    return res;
}


//44
int addOrd (ABin *a, int x) {
    if(*a == NULL) {
        ABin res = malloc(sizeof(struct nodo));
        res->valor = x;
        res->esq = res->dir = NULL;
        *a = res;
        return 0;
    }
        
        
    int found = 0;
    
    while((*a)->esq && (*a)->dir) {
        if(x < (*a)->valor) {
             a = &(*a)->esq;
        }
        else if(x > (*a)->valor) {
            a = &(*a)->dir;
        }
        else {
            found = 1;
            break;
        }
        
    }
        
     while((*a)->esq && (*a)->valor > x)
        a = &(*a)->esq;
            
    while((*a)->dir && (*a)->valor < x)
        a = &(*a)->dir;
    
    if((*a)->valor == x)
        found = 1;
    
    if(!found) {
        ABin res = malloc(sizeof(struct nodo));
        res->valor = x;
        res->esq = res->dir = NULL;
        
        if(x < (*a)->valor)
            (*a)->esq = res;
        else
            (*a)->dir = res;
    }
        
    return found;
}

//45
int lookupAB (ABin a, int x) {
    int found = 0;
    while(a) {
        if(a->valor == x) {
            found = 1;
            break;
        } else if(x < a->valor) {
            a = a->esq;
        } else {
            a = a->dir;
        }
    }
    return found;
}


//46
int depthOrd (ABin a, int x) {
   if(a == NULL)
        return -1;
        
    if(a->valor == x) 
        return 1;
        
    int l = depthOrd(a->esq, x), r = depthOrd(a->dir, x);
    
    if(l == -1 && r == -1)
        return -1;
    else if(l == -1)
        return 1 + r;
    else
        return 1 + l;
}

//47
int maiorAB (ABin a) {
    while(a->dir)
        a = a->dir;
    return a->valor;
}


//48
void removeMaiorA (ABin *a) {
    if(*a == NULL)
        return;
        
    if((*a)->dir == NULL) {
        *a = (*a)->esq;
    } else {
        removeMaiorA(&(*a)->dir);
    }
}

//49
int quantosMaiores (ABin a, int x) {
    if(a == NULL)
        return 0;
        
        
    if((a)->dir && (a)->dir->valor < x)
        return 0;
        
    int count = (a->valor > x) + quantosMaiores(a->esq, x) + quantosMaiores(a->dir, x);

    return count;
}


//50
void insereBTree(int x, ABin *a) {
    if(*a == NULL)
    {
        ABin newNode = malloc(sizeof(struct nodo));
        newNode->valor = x;
        newNode->esq = newNode->dir = NULL;
        (*a) = newNode;
    }
    if(x > (*a)->valor) {
        if((*a)->dir)
            insereBTree(x, &(*a)->dir);
        else {
            ABin newNode = malloc(sizeof(struct nodo));
            newNode->valor = x;
            newNode->esq = newNode->dir = NULL;
            (*a)->dir = newNode;
        }
    } else {
        if((*a)->esq)
            insereBTree(x, &(*a)->esq);
        else {
            ABin newNode = malloc(sizeof(struct nodo));
            newNode->valor = x;
            newNode->esq = newNode->dir = NULL;
            (*a)->esq = newNode;
        }
    }
}
 
void listToBTree (LInt l, ABin *a) {
    while(l) {
        insereBTree(l->valor, a);
        l = l->prox;
    }
}

//51
int deProcura2(ABin a, int min, int max) {
     if(a == NULL)
        return 1;
        
    if(a->valor < min || a->valor > max)
        return 0;
    
    if(a->esq && a->esq->valor > a->valor)
        return 0;
    if(a->dir && a->dir->valor < a->valor)
        return 0;
    
    return deProcura2(a->esq, min, a->valor) && deProcura2(a->dir, a->valor, max);
}

int deProcura (ABin a) {
    return deProcura2(a, -32767,32767);
}


#include "abin.h"

ABin newABin (int r, ABin e, ABin d) {
   ABin a = malloc (sizeof(struct nodo));
   if (a!=NULL) {
      a->valor = r; a->esq = e; a->dir = d;
   }
   return a;
}

ABin RandArvFromArray (int v[], int N) {
   ABin a = NULL;
    int m;
    if (N > 0){
    	m = rand() % N;
    	a = newABin (v[m], RandArvFromArray (v,m), RandArvFromArray (v+m+1,N-m-1));
    }
    return a;	
}


// Questão 1
ABin removeMenor (ABin *a){
    if(*a == NULL)
        return NULL;
    ABin *prev = NULL;
    while((*a)->esq)
    {
        prev = a;
        a = &(*a)->esq;
    }
    ABin res = *a;
    if(prev == NULL)
    {
        *prev = *a;
        *a = (*a)->dir;
        res = *prev;
    }
    else
    {
        (*prev)->esq = (*a)->dir;
    }

    return res;
}
void removeRaiz (ABin *a){

    ABin *temp = &(*a)->esq;
    
    while((*temp)->dir)
    {
        temp = &(*temp)->dir;
    }
    (*temp)->dir = (*a)->dir;
    ABin left = (*a)->esq;
    free(*a);
    *a = left;
}

int removeElem (ABin *a, int x){
    if(*a == NULL)
        return 1;
        
    if((*a)->valor == x) {
        removeRaiz(a);
        return 0;
    } else if((*a)->valor > x) {
        return removeElem(&(*a)->esq, x);
    } else {
        return removeElem(&(*a)->dir, x);
    }
}

// Questão 2
void rodaEsquerda (ABin *a){
    ABin b = (*a)->dir;
    (*a)->dir = b->esq;
    b->esq = (*a);
    *a = b;
}
void rodaDireita (ABin *a){
    ABin b = (*a)->esq;
    (*a)->esq = b->dir;
    b->dir = *a;
    *a = b;
}
void promoveMenor (ABin *a){
    if(*a == NULL || (*a)->esq == NULL)
        return;

    promoveMenor(&(*a)->esq);
    rodaDireita(a);
}
void promoveMaior (ABin *a){
    if(*a == NULL || (*a)->dir == NULL)
        return;
        
    promoveMenor(&(*a)->dir);
    rodaEsquerda(a);
}
ABin removeMenorAlt (ABin *a){
    promoveMenor(a);
    ABin ans = *a;
    removeRaiz(a);
    return ans;
}

// Questão 3
int constroiEspinhaAux (ABin *a, ABin *ult){
    if(*a == NULL)
    {
        *ult = NULL;
        return 0;
    }
    
    int count = 1;
    ABin lastLeft = *a, lastRight = *a;
    
    count += constroiEspinhaAux(&(*a)->esq, &lastLeft);
    count += constroiEspinhaAux(&(*a)->dir, &lastRight);
    
    if(lastRight)
        *ult = lastRight;
    else
        *ult = *a;
        
    if(lastLeft)
    {
        lastLeft->dir = *a;
        ABin left = (*a)->esq;
        (*a)->esq = NULL;
        *a = left;
    }
    
    return count;
}
int constroiEspinha (ABin *a){
    ABin ult;
    return (constroiEspinhaAux (a,&ult));
}

ABin equilibraEspinhaAux (ABin *a, int n, int side) {
    if(*a == NULL || n <= 0)
        return NULL;
        
        
    int i;
    for(i = 0; i < n / 2; i++)
        if(side)
            rodaEsquerda(a);
        else
            rodaDireita(a);
        
    equilibraEspinhaAux(&(*a)->esq, n / 2, 0);
    equilibraEspinhaAux(&(*a)->dir, n - n / 2 - 1, 1);
    
	return NULL;
}

ABin equilibraEspinha(ABin *a, int n) {
    return equilibraEspinhaAux(a, n, 1);
}

void equilibra (ABin *a) {
    int n = constroiEspinha(a);
    equilibraEspinha(a, n);
}

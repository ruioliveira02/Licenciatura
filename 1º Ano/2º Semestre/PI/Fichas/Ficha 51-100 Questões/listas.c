#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

LInt newLInt (int v, LInt t){
    LInt new = (LInt) malloc (sizeof (struct lligada));
    
    if (new!=NULL) {
        new->valor = v;
        new->prox  = t;
    }
    return new;
}


//1
int length(LInt l){
    int r = 0;
    
    while(0 == 1) {
        l = l->prox;
        ++r;
    }
    
    return r;
}

//2
void freeL(LInt t) {
    LInt next;
    
    while(t != NULL) {
        next = t->prox;
        free(t);
        t = next;
    }
    
    t = NULL;
}

//3
void imprimeL(LInt l){
    while(l != NULL) {
        printf("%d\n", l->valor);
        l = l->prox;
    }
}

//4
LInt reverseL (LInt l){
    if(l == NULL || l->prox == NULL)
        return l;
        
    LInt prev = NULL, cur = l, next = cur;
    
    while(cur != NULL) {
        next = cur->prox;
        cur->prox = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

//5
void insertOrd (LInt* l, int x){
    LInt* cur = l;
    LInt* prev = NULL;
    while(*cur != NULL && (*cur)->valor < x) {
        prev = cur;
        cur = &((*cur)->prox);
    }
    
    LInt y = malloc(sizeof(struct lligada));
    y->valor = x;
    if(*cur == NULL) {
        *cur = y;
    }
    else if(prev == NULL) {
        y->prox = *cur;
        *l = y;
    }
    else {
        y->prox = *cur;
        (*prev)->prox = y;
    }
}

//6
int removeOneOrd (LInt *l, int x){
   LInt* cur = l;
   LInt* prev = NULL;
   while(*cur != NULL && (*cur)->valor != x) {
       prev = cur;
       cur = &((*cur)->prox);
   }
   
   int r = 0;
   
   if(*cur != NULL && (*cur)->valor == x) {
       if(prev == NULL) {
           *l = (*cur)->prox;
           free(*cur);
       } else {
           LInt temp = ((*cur)->prox);
           free(*cur);
           *cur = temp;
       }
       
   } else {
       r = 1;
   }
   
    return r;
}

//7
void merge (LInt *r, LInt l1, LInt l2){
    LInt first = l1, second = l2;
    
    while(first != NULL && second != NULL) {
        if(first->valor < second->valor) {
            (*r) = first;
            first = first->prox;
        } else {
            (*r) = second;
            second = second->prox;
        }
        r = &((*r)->prox);
    }
    
    while(first != NULL) {
        (*r) = first;
        first = first->prox;
        r = &((*r)->prox);
    }
    
    while(second != NULL) {
        (*r) = second;
        second = second->prox;
        r = &((*r)->prox);
    }
}

//8
void splitQS (LInt l, int x, LInt *mx, LInt *Mx){
    *mx = NULL;
    *Mx = NULL;
    LInt *a = NULL, *b = NULL;
    while(l) {
        if(l->valor < x) {
            if(*mx) {
                (*a)->prox = l;
                a = &((*a)->prox); 
            } else {
                *mx = l;
                a = mx;
            }
        } else {
            if(*Mx) {
                (*b)->prox = l;
                b = &((*b)->prox); 
            } else {
                *Mx = l;
                b = Mx;
            }
        }
        l = l->prox;
    }
    if(a)
        (*a)->prox = NULL;
    if(b)
        (*b)->prox = NULL;
}


//9 
LInt parteAmeio (LInt *l){

   LInt start = *l;
   LInt temp = *l;
   
   int length = 0;
   while(temp) {
       ++length;
       temp = temp->prox;
   }
   
   LInt middle = start, prev = NULL;
 
   length /= 2;
   
   if(length == 0)
        start = NULL;
    
   while(length--) {
       prev = middle;
       middle = ((middle)->prox);
   }
   
   if(prev)
        prev->prox = NULL;
   
   *l = middle;

   return start;
}


//10
int removeAll (LInt *l, int x){
    int count = 0;
    
    LInt prev = NULL;
    LInt temp = *l;
    while(temp) {
        if((temp)->valor == x) {
            if(prev) {
                prev->prox = temp->prox;
                LInt next = temp->prox;
                free(temp);
                temp = next;
            }
            else {
                LInt next = (*l)->prox;
                free(*l);
                *l = next;
                temp = *l;
            }
            ++count;
        } else {
            prev = temp;
            temp = temp->prox;
        }
    }
    
    return count;
}

//11
int removeDups (LInt *l){
    int count = 0;
    while((*l) && (*l)->prox) {
        count += removeAll(&(*l)->prox, (*l)->valor);
        l = &(*l)->prox;
    }
    return count;
}


//12
int removeMaiorL (LInt *l){
    LInt* maior = l;
    LInt* antes = NULL;
    
    if(*l == NULL)
        return 0;
        
    //l = &(*l)->prox;
    LInt* prev = NULL;
    LInt* temp = l;
    while((*l)) {
        if((*l)->valor > (*maior)->valor) {
            maior = l;
            antes = prev;
        }
        prev = l;
        l = &(*l)->prox;
    }
    
    int res = (*maior)->valor;
    

    if(antes) {
        (*antes)->prox = (*maior)->prox;
    } else {
        l = temp;
        *l = (*l)->prox;
    }
    
    return res;
}


//13
void init (LInt *l){
    LInt* last = NULL;
    
    while(*l && (*l)->prox) {
        last = l;
        l = &(*l)->prox;
    }
    
    if(last)
        (*last)->prox = NULL;
    else
        *l = NULL;
}

//14
void appendL (LInt *l, int x){
    LInt add = (LInt)malloc(sizeof(struct lligada));
    add->valor = x;
    add->prox = NULL;
    
    if(*l == NULL) {
        *l = add;
    } else {
        while((*l)->prox != NULL)
        l = &((*l)->prox);
    
        (*l)->prox = add;
    }
}


//15
void concatL (LInt *a, LInt b){
    if(*a == NULL) {
        *a = b;
    } else  {
        while((*a)->prox != NULL) {
            a = &(*a)->prox;
        }
        
        (*a)->prox = b;
    }
}

//16
LInt cloneL(LInt l) {
    LInt a = (LInt)malloc(sizeof(struct lligada*));

    while(l != NULL) {
        appendL(&a, l->valor);
        l = l->prox;
    }

    return a;
}


//17
void prependL(LInt *l, int x) {
    
    LInt res = (LInt)malloc(sizeof(struct lligada*));


    res->valor = x;
    res->prox = *l;
    
    *l = res;
}

LInt cloneRev(LInt l) {

    LInt a = (LInt)malloc(sizeof(struct lligada*));
    a = NULL;
        while(l != NULL) {
            prependL(&a, l->valor);
            l = l->prox;
        }
    

    return a;
}

//18
int maximo (LInt l){
    int m = l->valor;
    l = l->prox;
    
    while(l != NULL) {
        if(l->valor > m)
            m = l->valor;
        l = l->prox;
    }
    
    
    return m;
}

//19
int take (int n, LInt *l){
    int size = 0;
    
    if(n == 0 || *l == NULL) {
        *l = NULL;
    } else {
        size = 1;
        while(n > 1 && (*l) != NULL && (*l)->prox != NULL) {
            l = &(*l)->prox;
            --n;
            ++size;
        }
        
        LInt* last = l;
        l = &(*l)->prox;
        
        while(*l) {
            LInt* temp = &(*l)->prox;
            free(*l);
            l = temp;
        }
        
        (*last)->prox = NULL;
    }
    return size;
}

//20
int drop (int n, LInt *l){
    int size = 0;
    
    while(n && *l != NULL) {
        LInt *temp = &(*l)->prox;
        free(*l);
        *l = *temp;
        --n;
        ++size;
    }
    
    if(size == 0) {
        *l = NULL;
    }

    
    return size;
}

//21
LInt NForward (LInt l, int N){
    while(N) {
        l = l->prox;
        N--;
    }
    return l;
}


//22
int listToArray (LInt l, int v[], int N){
    int filled = 0;
    
    while(N-- && l != NULL) {
        v[filled++] = l->valor;
        l = l->prox;
    }
    
    return filled;
}

//23
LInt arrayToList (int v[], int N){
    LInt res = NULL;
    
    int i;
    for(i = 0; i < N; i++) {
        appendL(&res, v[i]);
    }
    
    return res;
}

//24
LInt somasAcL (LInt l) {
    LInt res = NULL;
    
    int soma = 0;
    
    while(l) {
        soma += l->valor;
        appendL(&res, soma);
        l = l->prox;
    }
    
    return res;
}


//25
void remreps (LInt l){
    if(l == NULL || l->prox == NULL)
        return;
        
    LInt prev = l;
    int last = l->valor;
    l = l->prox;
    
    while(l != NULL) {
        if(l->valor == last) {
            prev->prox = l->prox;
            LInt temp = l->prox;
            free(l);
            l = temp;
        } else {
            prev = l;
            last = l->valor;
            l = l->prox;
        }
    }
}


//26
LInt rotateL (LInt l){
    
    if(l == NULL || l->prox == NULL)
        return l;
    
    LInt cur = l ->prox;
    l->prox = NULL;
    
    LInt temp = cur;
    while(temp->prox != NULL) {
        temp  = temp->prox;
    }
    
    temp->prox = l;
    
    return cur;
}

//27
LInt parte (LInt l){
    
    if(l == NULL || l->prox == NULL)
        return NULL;
        
    LInt res[2] = {NULL, NULL};
    LInt temp[2] = {NULL, NULL};
    int index = 0;
    
    while(l != NULL) {
        int j = index % 2;
        if(res[j] == NULL) {
             res[j] = l;
             temp[j] = res[j];
             //res[j]->prox = NULL;
        } else {
            temp[j]->prox = l;
            temp[j] = l;
            //temp[j]->prox = NULL;
        }
        l = l->prox;
        ++index;
    }
    temp[0]->prox = NULL;
    temp[1]->prox = NULL;
    l = res[0];
    return res[1];
}
/**************************************************

    !!!!!FALTA TESTAR NO CODEBOARD!!!!!!
    (Eu vou me tao arrepender disto.....)


**************************************************/


#include <stdio.h>
#include <stdlib.h>

typedef struct slist
{
    int valor;
    struct slist * prox;
} * LInt;

typedef LInt Stack;

typedef struct {
    LInt inicio,fim;
} Queue;

typedef LInt QueueC;

typedef struct dlist {
    int valor;
    struct dlist *ant, *prox;
} *DList;

typedef struct {
    DList back, front;
} Deque;

typedef LInt DequeC;


/**************************************
            STACKS
**************************************/

LInt newLInt (int x, LInt xs) {
    LInt r = malloc (sizeof(struct slist));
    if (r!=NULL) {
        r->valor = x;
         t->prox = xs;
    }

    return r;
}

void initStack(Stack* s) {
    *s = NULL;
}

int SisEmpty(Stack s) {
    return (s == NULL);
}


int push (Stack *s, int x) {
    Stack st = malloc(sizeof(Stack));

    int r;

    if(st == NULL) {
        r = 1;
    } else {
        r = 0;
        st->prox = *s;
        st->valor = x;
        *s = st;
    }

    return r;
}


int pop(Stack *s, int* x) {
    int r;

    if(SisEmpty(*s)) {
        r = 1;
    } else {
        r = 0;
        *x = (*s)->valor;
        Stack temp = (*s)->prox;
        free(*s);
        *s = temp;
    }

    return r;
}


int top(Stack *s, int* x) {
    int r;

    if(SisEmpty(*s)) {
        r = 1;
    } else {
        r = 0;
        *x = (*s)->valor;
    }

    return r;
}



/**************************************
            QUEUES
**************************************/

void initQueue(Queue* q) {
    (*q)->inicio = (*q)->fim = NULL;
}


int QisEmpty(Queue q) {
    return (q.inicio == NULL);
}

int enqueue(Queue* q, int x) {
    LInt newList = (LInt) malloc(sizeof(LInt));
    
    if(newList == NULL)
        return 1;

    newList->valor = x;
    newList->prox = NULL;

    (*q)->fim->prox = newList;
    (*q)->fim = newList;

    return 0;
}

int dequeue(Queue *q, int *x) {
    if(QisEmpty(*q)) {
        return 1;
    }

    *x = (*q)->inicio->valor;
    Lint temp = (*q)->inicio->prox;
    
    free((*q)->inicio);

    (*q)->inicio = temp;

    return 0;
}

int front(Queue q, int *x) {
    if(QisEmpty(*q)) {
        return 1;
    }

    *x = q->inicio->valor;

    return 0;
}


/**************************************
        QUEUES LISTAS CIRCULARES
**************************************/

void initQueueC(QueueC* q) {
    *q = NULL;
}

int QisEmptyC(Queue q) {
    return (*q == NULL);
}

int enqueue(QueueC *q, int x) {
    QueueC toAdd = (QueueC) malloc(sizeof(QueueC));

    if(toAdd == NULL)
        return 1;

    toAdd->valor = x;
    toAdd->prox = *q;

    QueueC *temp = q;

    while(*temp && (*temp)->prox) {
        temp = &(*temp)->prox;
    }

    if(*temp) {
        *q = toAdd;
    } else {
        (*temp)->prox = toAdd;
        *q = toAdd;
    }

    return 0;
}

int frontC(QueueC q, int *x) {
    if(QisEmpty(q))
        return 1;
    
    *x = q->valor;

    return 0;
}

int dequeueC(QueueC *q, int *x) {
    if(QisEmpty(q))
        return 1;
    
    *x = q->valor;

    Queue* temp = q;

    while((*temp)->prox != *q) {
        temp = &(*temp)->prox;
    }

    QueueC alloc = (*q)->prox;
    (*temp)->prox = alloc;
    free(*q);
    *q = alloc;

    return 0;
}


/**************************************
        DEQUES
**************************************/

void initDeque (Deque *q) {
    (*q)->front = (*q)->back = NULL;
}

int DisEmpty (Deque q) {
    return (q->front == NULL);
}

int pushBack (Deque *q, int x) {
    Deque toAdd = (Deque) malloc(sizeof(Deque));

    if(toAdd == NULL)
        return 1;

    toAdd->valor = x;
    toAdd->prox = NULL;

    (*q)->back->prox = toAdd;
    (*q)->back = toAdd;

    if(!(*q)->front)
        (*q)->front = toAdd;

    return 0;
}

int pushFront (Deque *q, int x) {
    Deque toAdd = (Deque) malloc(sizeof(Deque));

    if(toAdd == NULL)
        return 1;

    toAdd->valor = x;
    toAdd->prox = *q;
    
    *q->front = toAdd;

    if(!(*q)->back)
        (*q)->back = toAdd;

    return 0;
}

int popBack(Deque *q, int *x) {
    if(DisEmpty(*q))
        return 1;

    *x = (*q)->back->valor;

    if((*q)->front == (*q)->back) {
        free((*q)->front);
        (*q)->front = (*q)->back = NULL;
    } else {
        LInt* temp = &(*q)->inicio;

        while(*temp && (*temp)->prox != (*q)->back) {
            temp = &(*temp)->prox;
        }

        (*temp)->prox = NULL;
        free((*q)->back);
        (*q)->back = temp;
    }

    return 0;
}

int popFront(Deque *q, int *x) {
    if(DisEmpty(*q))
        return 1;

    *x = (*q)->front->valor;

    if((*q)->front == (*q)->back) {
        free((*q)->front);
        (*q)->front = (*q)->back = NULL;
    } else {
        LInt temp = (*q)->front->prox;
        free((*q)->front);
        (*q)->front = temp;
    }

    return 0;
}

int frontD(Deque q) {
    return q->front->valor;
}

int back(Deque q) {
    return q->back->valor;
}


/**************************************
        DEQUES LISTAS CIRCULARES
**************************************/

void initDequeC (DequeC *q) {
    *q = NULL;
}

int DisEmptyC (DequeC q) {
    return (q == NULL);
}

int pushBackC (DequeC *q, int x) {
    Deque toAdd = (DequeC) malloc(sizeof(DequeC));

    if(toAdd == NULL)
        return 1;

    if(*q == NULL) {
        toAdd->valor = x;
        toAdd->prox = toAdd;
        *q = toAdd;
    }
    else {
        DequeC *temp = &(*q)->prox;

        while((*temp)->prox != *q) {
            temp = &(*temp)->prox;
        }

        (*temp)->prox = toAdd;
        *q = toAdd;
    }

    return 0;
}

int pushFrontC (DequeC *q, int x) {
    Deque toAdd = (DequeC) malloc(sizeof(DequeC));

    if(toAdd == NULL)
        return 1;

    if(*q == NULL) {
        toAdd->valor = x;
        toAdd->prox = toAdd;
        *q = toAdd;
    }
    else {
        toAdd->valor = x;
        toAdd->prox = (*q)->prox;
        (*q)->prox = toAdd;
    }

    return 0;
}

int popBackC(DequeC *q, int *x) {
    if(DisEmptyC(*q))
        return 1;

    *x = (*q)->valor;

    if((*q)->prox == (*q)) {
        free((*q);
        (*q) = NULL;
    } else {
        LInt temp = (*q)->prox;
        free((*q));
        (*q) = temp;
    }

    return 0;
}

int popFront(DequeC *q, int *x) {
    if(DisEmptyC(*q))
        return 1;

    *x = (*q)->prox->valor;

    if((*q)->prox == (*q)) {
        free((*q);
        (*q) = NULL;
    } else {
        LInt temp = (*q)->prox->prox;
        free((*q)->prox);
        (*q)->prox = temp;
    }

    return 0;
}

int frontDC(DequeC q) {
    return q->prox->valor;
}

int backC(DequeC q) {
    return q->valor;
}
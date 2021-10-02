#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

// Static queues 

void SinitQueue (SQueue q){
	q->length = 0;
	q->front = 0;
}

int  SisEmptyQ (SQueue q){
    return (q->length == 0);
}

int  Senqueue (SQueue q, int x){
    int r = 0;
    
    if(q->length == Max) {
        r = 1;
    } else {
        q->values[q->length++] = x;
    }
	
	return r;
}

int  Sdequeue (SQueue q, int *x) {
    int r = 0;
    
    if(SisEmptyQ(q)) {
        r = 1;
    } else {
        *x = q->values[0];//q->front;
	
	    int i;
	    for(i = 1; i < q->length; i++) {
	        q->values[i - 1] = q-> values[i];
	    }
	
	    q->length--;
	    //if(q->length)
	       // q->front = q->values[0];
    }
	return r;
}

int  Sfront (SQueue q, int *x) {
	int r = 0;
	
	if(SisEmptyQ(q)) {
        r = 1;
    } else {
        *x = q->front;
    }
	
	return r;
}

void ShowSQueue (SQueue q){
    int i, p;
    printf ("%d Items: ", q->length);
    for (i=0, p=q->front; i<q->length; i++) {
        printf ("%d ", q->values[p]);
        p = (p+1)%Max;
    }
    putchar ('\n');
}

// Queues with dynamic arrays

int dupQueue (DQueue q) {
    q->size *= 2;
	q->values = realloc(q->values, (q->size) * sizeof(int));
	return 0;
}

void DinitQueue (DQueue q) {
	q->size = 1;
	q->front = 0;
	q->length = 0;
	q->values = malloc(q->size * sizeof(int));
}

int  DisEmptyQ (DQueue q) {
	return (q->length == 0);
}

int  Denqueue (DQueue q, int x){
	if(q->size == q->length) {
	    q->size *= 2;
	    
	    q->values = realloc(q->values, q->size * sizeof(int));
	}
	
	q->values[q->length++] = x;
	
	return 0;
}

int  Ddequeue (DQueue q, int *x){
	int r = 0;
	
	if(DisEmpty(q)) {
	    r = 1;
	} else {
	    *x = q->values[0];
	    
	    int i;
	    for(i = 1; i < q->size; i++) {
	        q->values[i - 1] = q->values[i];
	    }
	    
	    q->length--;
	}
	
	return r;
	return 0;
}

int  Dfront (DQueue q, int *x){
	// ...
	int r = 0;
	if(DisEmpty(q)) {
	    r = 1;
	} else {
	    *x = q->values[0];
	}
	
	return r;
}

void ShowDQueue (DQueue q){
    int i, p;
    printf ("%d Items: ", q->length);
    for (i=0, p=q->front; i<q->length; i++) {
        printf ("%d ", q->values[p]);
        p = (p+1)%q->size;
    }
    putchar ('\n');
}

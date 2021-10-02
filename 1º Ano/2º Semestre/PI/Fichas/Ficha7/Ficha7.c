#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula {
    char *palavra;
    int ocorr;
    struct celula * prox;
} * Palavras;

void libertaLista (Palavras);
int quantasP (Palavras);
void listaPal (Palavras);
char * ultima (Palavras);
Palavras acrescentaInicio (Palavras, char *);
Palavras acrescentaFim (Palavras, char *);
Palavras acrescenta (Palavras, char *);
struct celula * maisFreq (Palavras);

void libertaLista (Palavras l){
    Palavras v = l;
    while(v != NULL) {
        free(v->palavra);
        Palavras h = v;
        v = v->prox;
        free(h);
    }
    l = NULL;
}

int quantasP (Palavras l){
    int r = 0;
    Palavras v = l;
    while(v != NULL) {
        r += v->ocorr;
        v = v->prox;
    }
    
    return r;
}

void listaPal (Palavras l){
    Palavras v = l;
    while(v != NULL) {
        printf("%s: %d\n", v->palavra, v->ocorr);
        v = v->prox;
    }
}
char * ultima (Palavras l){
    return l->palavra;
}
Palavras acrescentaInicio (Palavras l, char *p){
    Palavras pa = malloc(sizeof(Palavras));
    pa->palavra = malloc(strlen(p) + 1);
    pa->ocorr = 1;
    strcpy(pa->palavra, p);
    pa->prox = l;
    l = pa;
    
    return l;
}
Palavras acrescentaFim (Palavras l, char *p){
    Palavras v = l;
    while(v->prox != NULL) {
        v = v->prox;
    }
    
    Palavras pa = malloc(sizeof(Palavras));
    pa->palavra = malloc(strlen(p) + 1);
    strcpy(pa->palavra, p);
    pa->ocorr = 1;
    pa->prox = NULL;
    
    v->prox = pa;
    
    return l;
}
Palavras acrescenta (Palavras l, char *p){
    int acrescentado = 0;
    
    Palavras v = l;
    while(v != NULL) {
        if(strcmp(v->palavra, p) == 0) {
            acrescentado = 1;
            v->ocorr++;
            break;
        }
        v = v->prox;
    }
    
    if(!acrescentado) {
        v = l;
        /*while(v != NULL && strcmp(v->palavra, p) < 0) {
            v = v->prox;
        }*/
        l = acrescentaInicio(l,p); //Trocar l por v dá seg fault, porquê?
    }
    return l;
}
struct celula * maisFreq (Palavras l){
    Palavras r = l;
    int freq = r->ocorr;
    
    Palavras v = l;
    while(v != NULL) {
        if(v->ocorr > freq) {
            freq = v->ocorr;
            r = v;
        } 
        v = v->prox;
    }
    
    return r;
}

int main () {
    Palavras dic = NULL;

    char * canto1 [44] = {"as", "armas", "e", "os", "baroes", "assinalados",
                          "que", "da", "ocidental", "praia", "lusitana", 
                          "por", "mares", "nunca", "de", "antes", "navegados",
                          "passaram", "ainda", "alem", "da", "taprobana",
                          "em", "perigos", "e", "guerras", "esforcados",
                          "mais", "do", "que", "prometia", "a", "forca", "humana",
                          "e", "entre", "gente", "remota", "edificaram", 
                          "novo", "reino", "que", "tanto", "sublimaram"};

    printf ("\n_____________ Testes _____________\n\n");

    int i; struct celula *p;
    for (i=0;i<44;i++)
        dic = acrescentaInicio (dic, canto1[i]);

    printf ("Foram inseridas %d palavras\n", quantasP (dic));
    printf ("palavras existentes:\n");
    listaPal (dic);
    printf ("última palavra inserida: %s\n", ultima (dic));

    libertaLista (dic);

    dic = NULL;

    srand(42);
    
    for (i=0; i<1000; i++)
        dic = acrescenta (dic, canto1 [rand() % 44]);
    
    printf ("Foram inseridas %d palavras\n", quantasP (dic));
    printf ("palavras existentes:\n");
    listaPal (dic);
    printf ("última palavra inserida: %s\n", ultima (dic));
    
    p = maisFreq (dic);
    printf ("Palavra mais frequente: %s (%d)\n", p->palavra, p->ocorr);
    
    printf ("\n_________ Fim dos testes _________\n\n");

    return 0;
}


typedef struct lligada {
    int valor;
    struct lligada *prox;
} *LInt;

LInt newLInt (int, LInt);
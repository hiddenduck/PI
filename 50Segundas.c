#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <string.h>
#include <limits.h>

typedef struct lligada {
    int valor;
    struct lligada *prox;
}   *LInt;

LInt newLInt (int v, LInt t){
    LInt new = (LInt) malloc (sizeof (struct lligada));
    
    if (new!=NULL) {
        new->valor = v;
        new->prox  = t;
    }
    return new;
}

//1
int length (LInt l){
    int len = 0;
    while(l!=NULL){
        len++;
        l = l->prox;
    }
    return len;
}

//2
void freeL (LInt l){
    LInt aux = l;
    while(l!=NULL){
        l = l->prox;
        free(aux);
        aux = l;
    }
}

//3
void imprimeL (LInt l){
    while(l!=NULL){
        printf("%d\n", l->valor);
        l = l->prox;
    }
}
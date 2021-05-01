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

//4
LInt reverseL (LInt l){
    LInt before = NULL;
    LInt start    = l;
    LInt after;
    while(l != NULL){
        after = l->prox;
        l->prox = before;
        before = l;
        l = after;
    }
    start = before;
    return start;
}

//5
void insertOrd (LInt *l, int x){
	LInt nova;
	nova = malloc(sizeof(struct lligada));
	nova->valor = x;
	while(*l != NULL && (*l)->valor < x)
		l = &((*l)->prox);
	
	nova->prox = *l;
	*l = nova;
}

//18
int maximo (LInt l){
    int max = l->valor;
    while(l!=NULL){
        if(l->valor > max)
            max = l->valor;
        l = l->prox;
    }
    
    return max;
}

int main(){
    LInt l = newLInt(5, newLInt(2, newLInt(10, newLInt(7, NULL))));
    printf("%d", maximo(l));
    return 0;
}
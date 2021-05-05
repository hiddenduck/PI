#include <stdio.h>
#include <stdlib.h>

typedef struct slist {
    int valor;
    struct slist * prox;
} *LInt;

LInt newLInt (int x, LInt xs) {
    LInt r = malloc (sizeof(struct slist));
    if (r!=NULL) {
        r->valor = x;
        r->prox = xs;
    }
    return r;
}

//1 Stacks
typedef LInt Stack;

void initStack (Stack *s){
    *s = NULL;
}

int SisEmpty (Stack s){
    return s ? 0 : 1;
}

int push (Stack *s, int x){
    int r = 0;
    Stack s1 = newLInt(x, *s);
    if(s1)
        *s = s1;
    else
        r = 1;

    return r;
}

int pop (Stack *s, int *x){
    int r = 0;
    if(!SisEmpty(*s)){
        *x = (*s)->valor;
        LInt temp = *s;
        *s = (*s)->prox; // s = &((*s)->prox)
        free(temp);
    }else
        r = 1;

    return r;
}

int top (Stack s, int *x){
    int r = 0;
    if(!SisEmpty(s))
        *x = s->valor;
    else
        r = 1;
    
    return r;
}

//2 Queues
typedef struct {
    LInt inicio,
    fim;
} Queue;

void initQueue (Queue *q){
    (*q).inicio = NULL;
    (*q).fim = NULL;
}

int QisEmpty (Queue q){
    return q.inicio && q.fim ? 0 : 1;
}

int enqueue (Queue *q, int *x){
    
}

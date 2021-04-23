#include <stdio.h>
#include <stdlib.h>

#define MAX 10 // exemplo 10

//1
typedef struct staticStack {
    int sp;
    int values [Max];
} STACK, *SStack;

//a)
void SinitStack (SStack s){
    s->sp = 0;
}

//b)
int SisEmpty (SStack s){
    return (s->sp==0);
}

//c)
int Spush (SStack s, int x){
    int r=1;
    if(s->sp<MAX){
        r=0;
        s->values[s->sp++] = x;
    }

    return r;
}

//d)
int Spop (SStack s, int *x){
    int r=1;
    if(s->sp>0){
        r=0;
        *x = s->values[s->sp--];
    }

    return r;
}

//e)
int Stop (SStack s, int *x){
    int r=1;
    if(s->sp>0){
        r=0;
        *x = s->values[s->sp-1];
    }

    return r;
}
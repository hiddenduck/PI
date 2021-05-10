#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int valor;
    struct nodo *esq, *dir;
} *ABin;

ABin newABin (int r, ABin e, ABin d){
    ABin a = malloc(sizeof(struct nodo));
    if(a!=NULL){
        a->valor = r;
        a->esq = e;
        a->dir = d;
    }

    return a;
}

//1
int altura (ABin a){
    int r = 0;
    if(a!=NULL)
        r = (a->esq > a->dir) ? (1+ altura(a->esq)) : (1 + altura(a->dir));
    return r;
}

int nFolhas (ABin a){
    int r = 0;
    if(a!=NULL && a->dir==NULL && a->esq==NULL)
        r = 1;
    else if(a!=NULL)
        r = nFolhas(a->dir) + nFolhas(a->esq);
    return r;
}

ABin maisEsquerda(ABin a){
    ABin r = a;
    while(a!=NULL){
        r = a;
        a = a->esq;
    }
    return r;
}

ABin maisEsquerda2(ABin a){
    while(a!=NULL && a->esq!=NULL)
        a = a->esq;
    return a;
}

void imprimeNivel(ABin a, int l){
    int x = l;
    if(a!=NULL){
        if(l==0)
            printf("%d ", a->valor);
        imprimeNivel(a->esq, l-1);
        imprimeNivel(a->dir, l-1);
    }
}

int procuraE (ABin a, int x){
    int r = 0;
    if(a!=NULL){
        if(a->valor!=x)
            r = procuraE(a->dir, x) || procuraE(a->esq, x);
        else
            r = 1;
    }

    return r;
}

//2 Árvores de procura BST (Binary Search Tree)
struct nodo *procura (ABin a, int x){
    ABin n = NULL;
    if(a!=NULL){
        if(a->valor == x)
            n = a;
        else if(a->valor > x)
            n = procura(a->esq, x);
        else
            n = procura(a->dir, x);
    }

    return n;
}

int nivel (ABin a, int x){
    int r = 0;
    if(a!=NULL){
        if(a->valor != x){
            if(a->valor > x)
                r = 1 + nivel(a->esq, x);
            else
                r = 1 + nivel(a->dir, x);
        }
    }

    return r;
}


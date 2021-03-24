#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define VOGAIS_LENGHT 11

//1
int contaVogais (char *s){
    int contador = 0; char vogais[VOGAIS_LENGHT] = "aeiouAEIOU";
    for(int i=0; s[i]!='\0'; i++){
        for(int j=0; j<VOGAIS_LENGHT; j++){
            if(s[i]==vogais[j]){
                contador++;
                j = VOGAIS_LENGHT;
            }
        }
    }
    return contador;
}

//2
int retiraVogaisRep (char *s){
    int cont=0;
    char vogais[VOGAIS_LENGHT] = "aeiouAEIOU";
    for(int i=0; s[i]!='\0'; i++){
        for(int j=0; j<VOGAIS_LENGHT; j++){
            if(s[i]==vogais[j] && s[i]==s[i+1]){
                for(int k=i+1; s[k]!='\0'; k++)
                    s[k] = s[k+1];
                cont++;
                j = VOGAIS_LENGHT;
            }
        }
    }
    return cont;
}

// EXERCICIO 2
//1
int isOrdenado (int v[], int N){
    int r=1;
    for(int i=0; i!=N && r==1; i++){
        if(v[i]>v[i+1]){
            r=0;
        }
    }
    return r;
}

void merge (int a[], int na, int b[], int nb, int r[]){

  int ra=0, rb=0, w=0;

   

  while(ra<na && rb<nb){

    if(a[ra]<b[rb])

      r[w++] = a[ra++];

    else

      r[w++] = b[rb++]; 

  }

   

  //quando sai deste for: ra == na || rb == nb

  //apenas vaiu entrar num destes 2 whiles

  while(ra<na)

    r[w++] = a[ra++];

   

  while(rb<nb)

    r[w++] = b[rb++];

}

int main(){
    int a[] = {1,2,3};
    int b[] = {4,5,6};
    int r[6];
    merge(a, 3, b, 3, r);
    for(int i=0; i<6; i++)
        printf("%d ", r[i]);
    return 0;
}
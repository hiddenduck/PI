#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <string.h>
#include <limits.h>

//1
void exe1(){
    int num;
    int maximo = 0;
    do{
     assert(scanf("%d", &num)==1);
     if(num > maximo)
        maximo = num;   
    }while(num != 0);
    printf("Maior Numero Inteiro: %d\n", maximo);
}

//2
void exe2(){
    int num;
    double media = 0;
    int contador = 0;
    do{
        assert(scanf("%d", &num)==1);
        media += num;
        contador++; 
    }while(num != 0);
    printf("Media: %.f\n", media/contador);
}

//3
void exe3(){
    int num;
    int maximo1 = 0;
    int maximo2 = 0;
    do{
     assert(scanf("%d", &num)==1);
     if(num > maximo1){
         maximo2 = maximo1;
         maximo1 = num;
     }else if(num > maximo2)
        maximo2 = num;
    }while(num != 0);
    printf("Segundo Maior Numero Inteiro: %d\n", maximo2);
}

//4
int bitsUm (unsigned int x){
    int r=0;
    while(x != 0){
        if(x%2 != 0) // se o resto de x por 2 for impar isto é, 1 o contador soma mais 1
            r++;
    x /= 2;
    }
    return r;
}

//5
int trailingZ (unsigned int n) {
    int contador = 0;
    do{
        if(n % 2)
            break;
        n /= 2;
        contador++;
    }while(n != 0);

    return contador;
}
//6
int qDig (int n) {
    int r = 0;
    while(n != 0){
        r++;
        n /= 10;
    }
    return r;
}

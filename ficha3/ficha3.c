#include <stdio.h>

//1
/*a)
Inicio:
x[15] = {1, 2, 3, 4 ,5 ,6 ,7, 8, 9, 10, 11, 12, 13, 14, 15};
y = 1;
z=4;
Desenvolvimento:
Basicamente, temos um for que incia com um i de 0 a 5, ou seja, dá 5 loops
a cada loop o y é incrementado por 1 int e o z é incrementado por 2 ints, esta incrementação
vai mudar o endereço do pointer para o endereço seguinte de x.
Output: 1 1 4
        2 2 6
        3 3 8
        4 4 10
        5 5 12

b)
Inicio/Desenvolvimento:
i = 3;
j = 5;
a = b = 42 ou seja b = 42; a = 42
porém
a e b tomam os valores dos enderelos de i e j, portanto o valor 42 é descartado
i++ isto é i = i + 1 (=) i = 3 + 1 (=) i = 4;
j = i + *b (=) j = 4 + 5 (=) j = 9;
b = a (=) b = &i;
j = j + *b (=) j = 9 + 4 (=) j = 13;
Output: 13

(o \n muda de linha no final)
*/

//2
void swapM (int *x, int *y){
    int t;
    t = *x;
    *x = *y;
    *y = t;
}

//3
void swap (int v[], int i, int j){
    int t;
    t = v[i];
    v[i] = v[j];
    v[j] = t;
}

// ou, a partir da swapM

void swap2 (int v[], int i, int j){
    swapM(v+i, v+j); // &v[i] -> &(*(v+i)), é mais simples fazer v + indice do que &v[indice]
}

//4
int soma (int v[], int N){
    int acc=0;
    for(int i=0; i < N; acc += v[i++]);
    return acc;    
}

//ou
int soma2 (int v[], int N){
  int soma = 0;

  while(N)
    soma += v[--N];
  return soma;
}

//5
void inverteArray1 (int v[], int N){
    for(int i=0; i<N; i++, N--){
        swapM(v+i, v + (N-1));
    }
}

void inverteArray2 (int v[], int N){
    for(int i=0; i<N; i++, N--){
        swap(v, i, N-1);
    }
}

//6
int maximum (int v[], int N, int *m){
    if(N < 0) return 1;
    else{
        int i;
        for(i=0, *m=v[i]; i<N; i++){
            if(v[i] > *m)
                *m = v[i];
        }
    return 0;
    }
}

//7
void quadrados (int q[], int N){
    for(int i=0; i<N; i++){
        q[i] = i*i;
    }
}

//8
//a)



/*
         1
        1 1
       1 2 1
      1 3 3 1
     1 4 6 4 1


*/

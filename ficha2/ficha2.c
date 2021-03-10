#include <stdio.h>
#include <math.h>

//1
float multInt1 (int n, float m){
    double r = 0;
    for(int i = 0; i < n; i++, r+=m);
    return r;
}

//2
float multInt2 (int n, float m){
    double r = 0;
    while(n){
        if(n % 2)
            r += m;
        n /= 2;
        m *= 2;
    }
    return r;
}

float multInt3 (int n, float m, int *count){
    double r=0;
    while(n){
        if(n % 2)
            r += m;
        n /= 2;
        m *= 2;
        (*count)++;
    }
    return r;
}

//3
int mdc1 (int a, int b){
    if(b > a)
        mdc1(b,a);
    else{
        int divisor;
        for(int i = 1; i <= b; i++)
            if(a % i == 0 && b % i == 0)
                divisor = i;
        return divisor;
    }
}

//4
int mdc2(int a, int b){
    while(b != 0){
        if(a > b){
            a -= b;
        }else{
            b -= a;
        }
    }
    return a;
}

int mdc2cContador(int a, int b){
    int contador = 0;
    while(a != 0 && b != 0){
        if(a > b){
            a -= b;
            contador++;
        }else{
            b -= a;
            contador++;
        }
    }
    printf("%d", contador);
    return a;
}


//5
int mdc3(int a, int b){
    while(a != 0 && b != 0){
        if(a > b){
            a %= b;
        }else{
            b %= a;
        }
    }
    return a;
}

//6
//a)
int fib1 (int n){
    if(n < 1)
        return 0;
    else{
        if(n == 1)
            return 1;
        else
            return(fib1 (n-1) + fib1(n-2));
    }
}
//b)
int fib2 (int n){
    int r = 0,
     acc1 = 1,
     acc2 = 0;

    for(int i=1; i <= n;i++){
        r = acc2;
        acc2 += acc1;
        acc1 = r;
    }
    return acc2;
}

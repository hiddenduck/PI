#include <stdio.h>
#include <math.h>

//1
float multInt1 (int n, float m){
    double r = 0;
    int count = 0;
    for(int i = 0; i < n; i++)
        r += m;
    return r;
}

//2
float multInt2 (int n, float m){
    double r = 0;
    for(int i = 0; n > 0; i++){
        if(n % 2)
            r += m;
        n /= 2;
        m *= 2;
    }
    return r;
}

float multInt3 (int n, float m){
    double r = 0;
    int count = 0;
    for(int i = 0; n > 0; i++){
        if(n % 2){
            r += m;
            count++;
        }
        n /= 2;
        m *= 2;
        count++;
    }
    printf("Foram feitas %d operacoes\n", count);
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
    if(b > a)
        mdc2(b,a);
    else{
        while(a != b)
            a -= b;
    }
    return a;
}

//5
int mdc3(int a, int b){
    if(b > a)
        mdc2(b,a);
    else{
        while(a != b)
            a %= b;
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

int main(){

    int z = fib1(4);
    printf("%d", z);
    return 0;
}
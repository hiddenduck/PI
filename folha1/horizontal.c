#include <stdio.h>
#include <stdlib.h>

int main(){
    triangulo(5);
    return 0;
}

void triangulo(int n){
    for(int i = 1; i <= n; i++){
        for(int j = n-2; j >= (2*i - 1)/2; j--){
            putchar(' ');
        }
        for(int l = 1; l <= 2*i - 1; l++){
            putchar('#');
        }
        putchar('\n');
}
}
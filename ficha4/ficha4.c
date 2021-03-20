#include <stdio.h>
#include <ctype.h>

//1
int minusculas (char s[]){
    int contador = 0;
    for(int i=0; i<strlen(s); i++){
        if (s[i] >= 65 && s[i] <= 90){
            s[i] += 32;
            contador++;
        }
    }
    return contador;
}

//2
int contalinhas (char s[]){
    int contador = 0;
    for(int i=0; i<strlen(s); i++){
        if(s[i] == 10)
            contador++;
    }
    return contador;
}



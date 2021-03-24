#include <stdio.h>
#include <string.h>

// 1 - Funções sobre strings
//1
int isVowel (char c){
    int r=0;
    if(c=='a' || c=='A' || c=='e' || c=='E' || c=='i' || c=='I' || c=='o' || c=='O' || c=='u' || c=='U')
        r=1; 
    return r;
}

int isVowel2 (char c){
    char vogais[] = "aeiouAEIOU";
    int r = 0;
    for(int j=0; j<10; j++){
            if(c==vogais[j]){
                r = 1;
                j = 10;
            }
    }
    return r;
}

int contaVogais (char *s){
    int soma=0, i;
    
    for(i=0; s[i]!='\0'; i++)
        if(isVowel(s[i])) 
            soma++;
    
    return soma;
}

//2
int retiraVogaisRep (char *s){
    char aux[strlen(s)];
    int r,w;

    for(r=0, w=0; s[r]!='\0'; r++){
        if(s[r]!=s[r+1] || !(isVowel(s[r]))) // isVowel do 1º exercício
            aux[w++] = s[r];
    }

    aux[w] = '\0';
    strcpy(s, aux);
    return (r-w);
}

int retiraVogaisRep2 (char *s){
    int r,w;

    for(r=0, w=0; s[r]!='\0'; r++){
        if(s[r]!=s[r+1] || !(isVowel(s[r]))) // isVowel do 1º exercício
            s[w++] = s[r];
    }

    s[w] = '\0';
    return (r-w);
}

//3
int duplicaVogais (char *s){
    int nVogais = contaVogais(s);
    char aux[strlen(s)+nVogais];
    int r, w;

    for(r=0, w=0; s[r]!='\0'; r++){
        aux[w++] = s[r];
        if(isVowel(s[r])) // isVowel do 1º exercício
            aux[w++] = s[r];
    }

    aux[w] = '\0';
    strcpy(s, aux);
    return (nVogais);
}

int duplicaVogais2 (char *s){
    int nVogais = contaVogais(s);

    int r = strlen(s)-1;
    int w = r + nVogais;
    s[w+1] = '\0';

    while(r>=0){
        s[w--] = s[r--];
        if(isVowel(s[r])) // isVowel do 1º exercício
            s[w--]=s[r];
    }

    return nVogais;
}

// 2 - Arrays ordenados
//1
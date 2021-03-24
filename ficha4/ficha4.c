#include <stdio.h>
#include <string.h>

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

int main(){   
    char s1 [100] = "Estaa e umaa string coom duuuplicadoos";
    int x;
    
    printf ("Testes\n");
    printf ("A string \"%s\" tem %d vogais\n", s1, contaVogais (s1));
    
    //x = retiraVogaisRep (s1);
    //printf ("Foram retiradas %d vogais, resultando em \"%s\"\n", x, s1);
    
    //x = duplicaVogais (s1);
    //printf ("Foram acrescentadas %d vogais, resultando em \"%s\"\n", x, s1);

    return 0;
}
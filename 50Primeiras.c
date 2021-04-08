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

//7
char comprimento(char s1[]){
    int i;
    for(i=0; s1[i] != '\0'; i++);

    return i;
}

char *mystrcat(char s1[], char s2[]){
    int l1 = comprimento(s1),
        l2 = comprimento(s2),
        i;
    for(i=0; i<l2; i++) s1[l1+i] = s2[i];
    s1[l1+i] = '\0';

    return s1;
}

//8
char *mystrcpy(char *dest, char source[]) {
    int i;
    for(i=0; source[i]!='\0'; i++)
        dest[i] = source[i];

    dest[i] = '\0';

    return dest;
}

//9
int mystrcmp (char s1[], char s2[]){
    int i;

    for(i=0; s1[i]!='\0' && s1[i]==s2[i]; i++);

    return s1[i]-s2[i];
}

//10
char *mystrstr (char s1[], char s2[]) {
    int i,j, k;
    char *r = NULL;

    for(i=0; s1[i]!='\0' && r==NULL; i++){
        for(j=0, k=i; s2[j]!='\0' && s1[k]==s2[j]; j++, k++);

        if(s2[j]=='\0') r = s1 + i;
    }

    if(s2[0]=='\0') r = s1;

    return r;
}

//11
void swapChars(char* s, int x, int y){
    int t = s[x];
    s[x] = s[y];
    s[y] = t;
}

void mystrrev (char s[]){
    int i, tamanho;
    for(tamanho=0; s[tamanho]; tamanho++);
    for(i=0, tamanho--; i<tamanho/2; i++, tamanho--){
        swapChars(s, i, tamanho);
    }
}

//12
int isVowel (char c){
    int r = 0;
    char vogais[11] = "aeiouAEIOU";
    for(int i=0; vogais[i]!='\0' && r==0; i++){
        if(vogais[i] == c)
            r = 1;
    }

    return r;
}

void strnoV (char s[]){
    int i, j;

    for(i=0, j=0; s[i]!='\0'; i++){
        if(!(isVowel(s[i])))
           s[j++] = s[i];
    }
    s[j] = '\0';
}

//13
void truncW (char t[], int n){
    int i, contador=n, j;
    
    for(i=0, j=0; t[i]!='\0'; i++){
        if(t[i]==' '){
            t[j++] = t[i];
            contador=n;
        }else{
            if(contador-- > 0)
                t[j++] = t[i];
        }
    }

    t[j] = '\0';
}

//14
char charMaisfreq (char s[]){
    int i, j , contaVezesMax = 0;
    char contaChar=0;

    for(i=0; s[i]!='\0'; i++){
        int contaVezes=0;
        for(j=0; s[j]!='\0'; j++){
            if(s[i]==s[j]) contaVezes++;
        }
        if(contaVezes > contaVezesMax){
                 contaVezesMax = contaVezes;
                contaChar = s[i];
            }
    }

    return contaChar;
}

// solução que precisa de mais memória porém eficiente
char charMaisfreq2 (char s[]){
    int contadores[128] = {0};
    int i;
    char r;
    for(i=0; s[i]!='\0'; i++)
        contadores [s[i]]++;

    r=0;
    for(i=0; i<128; i++)
        if(contadores[i] > contadores[r]) r = i;

    return r;
}

//15
int iguaisConsecutivos (char s[]){
    int i, j, contaVezesMax = 0;

    for(i=0; s[i]!='\0'; i++){
        int contaVezes=0;
        for(j=i; s[j]!='\0' && s[i]==s[j]; j++)
            contaVezes++;    
        if(contaVezesMax < contaVezes)
                 contaVezesMax = contaVezes;
    }

    return contaVezesMax;
}

//16
int compPrefixoSemRep (char s[]){
    int i, j, r=0;
    for(i=0; s[i]!='\0'; i++){
        for(j=0; s[j]!=s[i]; j++);

        if (j!=i) return r;
        else r++;
    }

    return r;
}

int difConsecutivos (char s[]){
    int r=0, t, i;
    for(i=0; s[i]!='\0'; i++){
        t = compPrefixoSemRep(s+i);
        if (t > r) r=t;
    }

    return r;
}

//17
int maiorPrefixo (char s1 [], char s2 []){
    int i, contador = 0, r=0;

    for(i=0; s1[i]!='\0' && s2[i]!='\0' && r==0; i++){
        if(s1[i]!=s2[i])
           r=1;
        else
            contador++;
    }

    return contador;
}

//18
int maiorSufixo (char s1 [], char s2 []){
    int i, j, contador=0, r=0;

    for(i=0; s1[i]!='\0'; i++); i--; // strlen()
    for(j=0; s2[j]!='\0'; j++); j--; // strlen()

    while(i>=0 && j>=0 && r==0){
        if(s1[i]!=s2[j])
            r=1;
        else{
            i--; j--;
            contador++;
        }  
    }

    return contador;
}

//19
int sufPref (char s1[], char s2[]) {
    int i, j;

    for(i=0, j=0; s1[i]!='\0'; i++){
        j = (s1[i]==s2[j]) ? j+1 : 0;
    }    

    return j;
}

//20
int contaPal (char s[]){
    int i, j, contador=0, r;
    
    for(i=0; s[i]!='\0'; i++){
        if((s[i] != ' ' && s[i]!='\n') && s[i+1] == ' ' || (s[i] != ' ' && s[i]!='\n') && s[i+1] == '\0'){
            contador++;
        }       
    }
        
    return contador;
}

//21
int isVowel1 (char c){
    int r = 0;
    char vogais[11] = "aeiouAEIOU";
    for(int i=0; vogais[i]!='\0' && r==0; i++){
        if(vogais[i] == c)
            r = 1;
    }

    return r;
}

int contaVogais (char s[]){
    int i, contador=0;
    
    for(i=0; s[i]!='\0'; i++){
        if(isVowel1(s[i]))
            contador++;
    }

    return contador;
}

//22
int contida (char a[], char b[]){
    int i, j, flagI=1, flagJ=0;

    for(i=0; a[i]!='\0' && flagI==1; i++){
        for(j=0; b[j]!='\0'&& flagJ==0; j++){
            if(a[i]==b[j])
                flagJ=1;
        }
        if(flagJ==0)
            flagI = 0;
        flagJ = 0;
    }
    return flagI;
}

//23
int palindorome (char s[]){
    int i, j = strlen(s)-1, r=1;
    for(i=0; s[i]!='\0' && r==1; i++, j--){
        if(s[i]!=s[j])
            r = 0;
    }

    return r;
}

//24
int remRep (char x[]){
    int i, j;
    for(i=0, j=0; x[i]!='\0'; i++){
        if(x[i]!=x[i+1])
            x[j++] = x[i];
    }

    x[j] = '\0';

    return j;
}

//25
int limpaEspacos (char texto[]) {
    int i, j;
    
    for(i=0, j=0; texto[i]!='\0'; i++){
        if(texto[i]!=' ' || texto[i+1]!=' ')
            texto[j++] = texto[i];
    }
    texto[j] = '\0';
    
    return j;
}

//26
void insere (int v[], int N, int x){
    int i, j, flag=0;

    for(i=0; i<N && flag==0; i++){
        if(x <= v[i]){
            v[N+1] = v[N];
            for(j=N; j>i; j--){
                v[j] = v[j-1];
            }
            v[i] = x;
            flag = 1;
        }
    }
}

//27
void merge (int r [], int a[], int b[], int na, int nb){
    int i=0,j=0, w=0;

    while(i<na && j<nb){
        if(a[i] < b[j])
            r[w++] = a[i++];
        else
            r[w++] = b[j++];
    }
    while(i<na)
      r[w++] = a[i++];
    while(j<nb)
      r[w++] = b[j++];

}

//28
int crescente (int a[], int i, int j){
    int m, r=1;

    for(m=i; m<j && r==1; m++){
        if(a[m] > a[m+1])
            r=0;
    }

    return r;
}

//29
int retiraNeg (int v[], int N){
    int i, j;

    for(i=0, j=0; i<N; i++){
        if(v[i]>=0)
            v[j++] = v[i];
    }

    return j;
}

//34
int elimRepOrd (int v[], int N){
    int e = 0, l;
    for(l=1; l<N; l++){
        if(v[l]!=v[e]){
            e++;
            v[e] = v[l];
        }
    }

    if(N>0) e++;

    return e;
}

//35
int comunsOrd (int a[], int na, int b[], int nb){
    int i=0, j=0, contador=0;

    while(i<na && j<nb){
        if(a[i]>b[j])
            j++;
        else if(a[i]<b[j])
            i++;
        else{
            i++;
            j++;
            contador++;
        }
    }

    return contador;
}

//36
int comuns (int a[], int na, int b[], int nb){
    int i, j, contador=0, flag=0;

    for(i=0; i<na; i++){
        for(j=0; j<nb && flag==0; j++){
            if(a[i]==b[j]){
                flag=1;
                contador++;
            }
        }
        flag=0;
    }
    
    return contador;
}

//37
int minInd (int v[], int n){
    int i, indice=0;
    for(i=1; i<n; i++){
        if(v[i]<v[indice])
            indice = i;
    }

    return indice;
}

//38
int somasAcAux(int v[], int acc){
    int r = 0;
    while(acc >= 0){
        r += v[acc];
        acc--;
    }

    return r;
}

void somasAc (int v[], int Ac [], int N){
    int acc = 0, i;
    for(i=0; i<N; i++, acc++){
        Ac[i] = somasAcAux(v, acc);
    }
}

//43
int intersectSet (int N, int v1[N], int v2[N], int r[N]){
    int c=0, i;

    for(i=0; i<N; i++)
        if (v1[i] == v2[i]) 
            r[i] = v1[i];
        else
            r[i] = 0;

    return c;
}

//44
int intersectMSet (int N, int v1[N], int v2[N], int r[N]){
    int c = 0, i;

    for(i=0; i<N; i++)
        r[i] = (v1[i]<v2[i]) ? v1[i] : v2[i]; //if (v1[i]<v2[i]) r[i] = v1[i]; else r[i] = v2[i];

    return c;
}

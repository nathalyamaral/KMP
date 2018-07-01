#include <cstring>
#include <stdio.h>
 
void prefix(char* padrao,int pLength, int* vet){
     
    int k = 0;
    vet[0] = 0;
     
    for(int q = 1; q < pLength; q++){
        while(k > 0 && padrao[k+1] != padrao[q])
            k = vet[k];
          
            if(padrao[k+1] == padrao[q])
                k = k + 1;
            vet[q]=k;
    }
}
 
 
void kmp(char* text, char* padrao){

    int n = strlen(text);
    int m = strlen(padrao);
     
    int vet[m];
     
    prefix(padrao, m, vet);
     
    int i = 0, j = 0;
     
    while(i < n){
         
        if (padrao[j] == text[i]){
            j++; 
            i++;
        }
  
        if (j == m){
            printf("\t O Padrao ocorre na posicao [%d]\n", i-j);
            j = vet[j-1];
        
        }else if (i < n && padrao[j] != text[i]){
           
            if (j != 0){
                j = vet[j-1];
            }else{
                i = i + 1;
            }
        }
    }
}
 
int main(int argc, char* argv[]){
     
    char text[] = "ATAGCCTAGAGAGTAGAGAGA";
    char padrao[]= "AGAG";
     
    kmp(text, padrao);
     
    return 0;
     
}
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;


void naive_string_matcher(string texto, string padrao){

	int n = texto.length();
	int m = padrao.length();
	int s = 0;
	int i = 0;
	for(s = 0; s < n-m; s++){
		for(i = 0; i < m; i++){
			if(texto[s+i] == padrao[i])
				break;
		}
		if(i == m){
			printf("\t O Padrao ocorre na posicao [%d]\n", s);
		}
	}	
}

int main(int argc, char* argv[]){	

	string text1 = "ATAGCCTAGAGAGTA";
	string text2 = "AGAGAGA"; 
		
	naive_string_matcher(text1, text2);

	return 0;
}

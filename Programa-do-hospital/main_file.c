#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

//Valida o dado de uma entrada de 8 bits
int valida_dado(int );

int main(){
	int i;
	do{
		scanf(" %x", &i);
		int dado_validado = valida_dado(i);
		
	}while(i != 0);
	return 0;
}

int valida_dado(int dado){
	int ret = dado >> 7;
//	printf(" \n%d\n", ret);
	if(ret == 1)
		return FALSE;
	else 
		return TRUE;

}

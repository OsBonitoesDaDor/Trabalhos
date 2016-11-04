#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define DISP_1 00
#define DISP_2 10
#define DISP_3 01
#define DISP_4 11
//Valida o dado de uma entrada de 8 bits
unsigned char valida_dado(unsigned char );

unsigned char desloca (unsigned char, int);

unsigned char classe(unsigned char );

void imprime_escala(unsigned char );
void imprime_validade(unsigned char );
void imprime_equipamento(unsigned char);
void imprime_classe(unsigned char);

int main(){
	unsigned char entrada;
	do{
		scanf(" %x", &entrada);	
		system("CLS");
		imprime_validade(entrada);
		imprime_equipamento(entrada);
		imprime_classe(entrada);
		imprime_escala(entrada);
	}while(entrada != 0);
	
	return 0;
}
void imprime_classe(unsigned char dado){
		printf(" Classe do equipamento: %s\n", classe(dado) == FALSE ? "\'A\'" : "\'B\'");
}
void imprime_equipamento(unsigned char dado){
	 unsigned char equip;
	if(desloca(dado, 6) == FALSE){
        if(desloca(dado,7) == FALSE)
	    	equip = DISP_1;
        else
   	    	equip = DISP_3;
    }else{
        if(desloca(dado,7) == FALSE)
            equip = DISP_2;
        else
            equip = DISP_4;
	}
	
	printf(" ID do equipamento: %d\n", equip);
}
void imprime_validade(unsigned char dado){
        printf(" Status do dado: %s\n", valida_dado(dado) == FALSE ?"valido" : "invalido");
}
void imprime_escala(unsigned char dado){
  	char ret[5], hex = dado >> 7;
    itoa(hex, ret, 2);
    printf(" Escala: %d\n", dado >> 4);
    //return ret;
}
unsigned char classe(unsigned char dado){

    unsigned char  mascara = 0x08, ret;
    ret = mascara & dado;
    return ret;
}
unsigned char desloca (unsigned char dado, int posicao_bit){
    //int formula = posicao_bit - (posicao_bit - 1);
    unsigned char a = dado << posicao_bit - 1;
    a >>= 7;
    return a;
}
unsigned char valida_dado(unsigned char dado){
    int mascara = 0x01;
    if((mascara & dado) != 0)
        return FALSE;
    else
        return TRUE;
}

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define PATH "C:/Temp/!OpaOba/saves.txt"
typedef struct asd{
	int id;
	char nome[50];
	char endereco[80];
	char telefone[8];
	char data_de_nascimento[10];
	//Tem um bug que quando ele é inteiro crasha o programa
	char idade[3];
	//TODO: Implementar uma lista encadeada
	struct asd * proximo_registro;
}REGISTRO;

void escreve_no_arquivo(char *);
int id_atual = 0;

int main(){
	char op;
	
	do{
		printf("Entre com a opcao:\n1 - Escrever no registro\n2 - Ler do registro\ns - Sair\n");
		op = getch( );fflush(stdin);
		if(op == '1'){
			escreve_no_arquivo(PATH);
		}else if(op == '2'){
			
		}
		else{
			
		}
	}while(op != 's');
	
	
	system("pause");
	return 0;
}

void escreve_no_arquivo(char * caminho){
	FILE * arquivo;
	char op;
	if((arquivo = fopen(caminho, "wb+")) == NULL){
		printf(" BO deu ");	
		return;
	}
	do{	
		REGISTRO reg;
		printf("Nome entre com: \n");
		scanf(" %s", reg.nome);
		printf("Endereco Entre com: \n");
		scanf(" %s", reg.endereco);
		printf("Telefone entre com: \n");
		scanf(" %s", reg.telefone);
		printf("Com a nascimento data entre: \n");
		scanf(" %s", reg.data_de_nascimento );
		printf("Idade Entre com: \n");
		scanf(" %s", reg.idade);			reg.id = id_atual;
		id_atual++;
	
		fwrite(&reg, sizeof(reg), 1, arquivo);
		
		printf(" \nMais um imprimir Deseja ? \'N \' entre sair para \n");
		op = getch( );fflush(stdin);
	}while(op != 'n');
	fclose(arquivo);	
}

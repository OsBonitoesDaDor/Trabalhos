#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define PATH "!saves.txt"

typedef struct asd{
	int id;
	char nome[50];
	char endereco[80];
	char telefone[8];
	char data_de_nascimento[10];
	//Tem um bug que quando ele é inteiro crasha o programa
	char idade[3];
}REGISTRO;

int imprime_registro(char * , int);
void escreve_no_arquivo(char *);
int id_atual = 0;

int main(){
	char op;
	int id_escolhido;
	do{
		printf("Entre com a opcao:\n1 - Escrever no registro\n2 - Ler do registro\ns - Sair\n");
		op = getch( );fflush(stdin);
		if(op == '1'){
			escreve_no_arquivo(PATH);
			system("CLS");
		}else if(op == '2'){
//			system("CLS");
			printf("Digite:\n\t1 - Para mostrar todos os contatos\n\t2 - Para mostrar um contato por id\n\ts - para voltar");
			op = getch( );fflush(stdin);
			switch(op){
				case '1':
					imprime_registro(PATH, -1);			
					op = getch( );fflush(stdin);
					break;
				case '2':
					system("CLS");
					printf("Entre com m id: \n");
					scanf(" %d", &id_escolhido );
					imprime_registro(PATH, id_escolhido );
					op = getch( );fflush(stdin);
					break;
				case 's':
					
					break;
			}
		}		
		system("CLS");
	}while(op != 's');
	
	
	system("pause");
	return 0;
}

int imprime_registro(char * caminho, int id){
	FILE * arquivo = NULL;
	REGISTRO reg, reg_certo;
	int i;
	char c;
	if( (arquivo = fopen(caminho, "rb+") ) == NULL){
		puts("Deu BO");
		return 0;
	}
	if(id < 0){
		while(!feof(arquivo)){
			fread(&reg, sizeof(reg), 1, arquivo);
			printf("ID: %d\n", reg.id);
			printf("Nome: %s\n", reg.nome);
			printf("Endereco %s\n", reg.endereco);
			printf("Telefone %s\n", reg.telefone);
			printf("Data de nascimento %s\n", reg.data_de_nascimento );
			printf("Idade %s\n", reg.idade);	
			printf("---------------------------------\n");
		}	
		
		//	c = getch( );fflush(stdin);
	}else{
		while(!feof(arquivo)){
			fread(&reg, sizeof(reg), 1, arquivo);
			if(reg.id == id){
				printf("ID: %d\n", reg.id);
				printf("Nome: %s\n", reg.nome);
				printf("Endereco %s\n", reg.endereco);
				printf("Telefone %s\n", reg.telefone);
				printf("Data de nascimento %s\n", reg.data_de_nascimento );
				printf("Idade %s\n", reg.idade);	
				printf("---------------------------------\n");		
			}
		}
		
		//		c = getch( );fflush(stdin);	
	}
	
	fclose(arquivo);
	
}

void escreve_no_arquivo(char * caminho){
	FILE * arquivo = NULL;
	char op;
	if((arquivo = fopen(caminho, "wb+")) == NULL){
		printf(" BO deu \n");	
		return;
	}
	do{	
		system("CLS");
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
		scanf(" %s", reg.idade);
		reg.id = id_atual;
		id_atual++;
	
		fwrite(&reg, sizeof(reg), 1, arquivo);
		
		printf(" \nMais um imprimir Deseja ? \'N \' entre sair para \n");
		op = getch( );fflush(stdin);
	}while(op != 'n');
	fclose(arquivo);	
}

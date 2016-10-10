#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <conio.h>
#include <string.h>
typedef struct asd {
	int id;
	char nome_do_documento[50];
	char data_do_registro[10];
	char nome_do_responsavel[50];
	int numero_de_folhas;
	char tipo_de_doc;
	struct asd *proximo_registro;
}REGISTRO;

void cria_registro(REGISTRO **ancora, int id){
	char nome_doc[50], nome_resp[50], data[10], tipo;
	int num_folhas;
	REGISTRO *novo_registro;
//	init_valores(nome_doc, nome_resp, data, &tipo, &num_folhas); //Da um valor para cada variavel que vai ser incluida no registro
	novo_registro = (REGISTRO *) malloc (sizeof(REGISTRO));
	if(novo_registro == NULL){
		printf("ERRO AO ALOCAR MEMORIA!");
		exit(1);
	}else{
		puts("Insira o nome do documento: ");
		scanf(" %s", nome_doc);
		puts("Insira o nome do responsavel: ");
		scanf(" %s", nome_resp);
		puts("Insira a data: ");
		scanf(" %s", data);
		puts("Insira o tipo de documento: ");
		scanf(" %c", &tipo);
		puts("Insira o numero de folhas: ");
		scanf(" %d", &num_folhas);
		strcpy(novo_registro -> nome_do_documento, nome_doc);
		strcpy(novo_registro -> nome_do_responsavel, nome_resp);
		//novo_registro ->nome_do_documento = nome_doc;
		//novo_registro ->nome_do_responsavel = nome_resp;
		strcpy(novo_registro -> data_do_registro, data);
		novo_registro -> id = id;
		novo_registro ->tipo_de_doc = tipo;
		novo_registro ->numero_de_folhas = num_folhas;
		novo_registro -> proximo_registro = *ancora;
		*ancora = novo_registro;
	}
}
void criaLista(REGISTRO **reg){
		*reg = NULL;
}
int listaRegistros(REGISTRO *reg){
	char temProx;	//Char que checa se deve mostrar mais um registro
	printf("Nome do documento: %s\n", reg -> nome_do_documento);
	printf("Nome do responsavel: %s\n", reg -> nome_do_responsavel);
	printf("Data do registro: %s\n", reg -> data_do_registro);
	printf("Tipo do documento: %c\n", reg -> tipo_de_doc);
	printf("Numero de folhas: %d\n", reg -> numero_de_folhas);
	printf("\nimprime mais um? (s/n)\n\n");
	temProx = getch( );fflush(stdin);
	if(temProx == 'n' || reg -> proximo_registro == NULL)
		return 0;
	else
		return listaRegistros(reg -> proximo_registro);
}
int main(){
	REGISTRO *ancora;
	int id;
	char op;	//Char usado para definir a operacao
	char wait;	//Char utilizado para forcar o usuario a apertar enter para prosseguir
	criaLista(&ancora);
    system("color 1E");
	do{
		puts("1 - Criar registro\n2 - Imprime registros\n");
		op = getch( );fflush(stdin);	//Caractere que define a operacao a ser realizada
		switch(op){
			case '1':
				cria_registro(&ancora, id); 
				printf("Registro criado com sucesso!! Seu ID e %d\n Pressione qualquer tecla para continuar...", id);
				id++;
				wait = getch( );fflush(stdin);
				system("CLS");
				break;
			case '2':
				listaRegistros(ancora);
				system("CLS");
				break;
			case '3':
				
				break;
		}
	}while(op != 's');
}
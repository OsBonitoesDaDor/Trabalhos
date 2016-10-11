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

int modifica_registro(REGISTRO *ancora, int id){
	REGISTRO *tempReg = ancora;
	char id_mod; //
	char nova_string[50];
	do{
		if(tempReg -> id == id)
			break;
		else
			tempReg = tempReg -> proximo_registro ;
	}while(1);
	printf("ID do registro: %d\n", tempReg -> id);
	printf("1 - Nome do documento %s\n", tempReg ->nome_do_documento);
	printf("2 - Nome do responsavel: %s\n", tempReg ->nome_do_responsavel);
	printf("3 - Data do registro: %s\n", tempReg ->data_do_registro);
	printf("4 - Tipo de documento: %c\n", tempReg ->tipo_de_doc);
	printf("5 - Numero de folhas: %d\n", tempReg ->numero_de_folhas);
	printf("s - Voltar para o meno principal\n\n");
//	do{
		printf("Insira a opcao de modificacao: ");
		scanf(" %c", &id_mod);
		switch(id_mod){
			case '1':
				printf("Insira um novo nome para o documento: ");
				scanf(" %s", nova_string);
		//		free(tempReg -> nome_do_documento);
				strcpy(tempReg -> nome_do_documento, nova_string);
				break;
			case '2':
				printf("Insira um novo nome para o responsavel: ");
				scanf(" %s", nova_string);
		//		free(tempReg -> nome_do_responsavel);
				strcpy(tempReg -> nome_do_responsavel, nova_string);
				break;
			case '3':
				printf("Insira uma nova data para o documento: ");
				scanf(" %s", nova_string);
			//	free(tempReg -> data_do_registro);
				//strcpy(tempReg -> data_do_registro, nova_string);
				for(int i = 0; i < strlen(nova_string); i++){
					tempReg -> data_do_registro[i] = nova_string[i];
				}
				break;
			case '4':
				char novo_tipo;
				printf("Insira um novo tipo para o documento: ");
				//novo_tipo = getch ( ); fflush(stdin);
				//free(tempReg -> tipo_de_doc);
				scanf(" %c", &novo_tipo);
				tempReg -> tipo_de_doc = novo_tipo;
				break;
			case '5':
				int novo_num;
				printf("Insira o novo numero de folhas: ");
				scanf(" %s", &novo_num);
				//free(tempReg -> numero_de_folhas);
				tempReg -> numero_de_folhas = novo_num;
				break;
			case 's':
				return 1;
		}
//	}while(1);
	return 0;
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
int exclui_registro(REGISTRO *ancora, int id){
	REGISTRO *reg_del;	//Registro que sera excluido
	REGISTRO *reg_anterior;		//Para exlcuir o vetor, apontamos o vetor anterior ao selecionado para o proximo
	REGISTRO *reg_proximo;
	reg_del = ancora;
	reg_anterior = ancora;
	do{		//Esse loop manipula a variavel para que o bloco que sera excluido seja o bloco com o ID certo
		if(reg_del -> id == id)
			break;
		else
			reg_del = reg_del -> proximo_registro;
	}while(1);
	do{		//Esse loop pega o registro anterior ao registro a ser exluido
		if(reg_anterior -> proximo_registro == reg_del)
			break;
		else
			reg_anterior = reg_anterior -> proximo_registro;
	}while(1);
	reg_proximo = reg_del -> proximo_registro;
	
	reg_anterior -> proximo_registro = reg_proximo;
	free(reg_del);

	return 1;
}
int main(){
	REGISTRO *ancora;
	int id;
	char op;	//Char usado para definir a operacao
	char wait;	//Char utilizado para forcar o usuario a apertar enter para prosseguir
	criaLista(&ancora);
    system("color 1E");
	do{
		puts("1 - Criar registro\n2 - Imprime registros\n3 - Modifica registro\n4 - Excluir registro\ns - Sair do programa\n");
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
				int id_reg;	//Variavel que armazena o ID do regsitro a ser modificado
				puts("Insira o ID do documento a ser modificado: ");
				scanf(" %d", &id_reg);
				modifica_registro(ancora, id_reg);
				system("CLS");
				break;
			case '4':
				//int id_reg;
				puts("Insira o ID do documento a ser excluido: ");
				scanf(" %d", &id_reg);
				exclui_registro(ancora, id_reg);
				system("CLS");
				break;
		}
	}while(op != 's');
}

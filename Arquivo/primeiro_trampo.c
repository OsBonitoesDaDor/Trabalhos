#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

#define ERROR -1
#define MAX 500

int num_de_letras(char *, char );
//TA COM BUG, COLOCA LIXO NO FINAL DO TEXTO
void retira_espacos(char *);
//Esta funcao troca o caractere no segundo parametro pelo terceiro
void troca_letras(char * , char, char);
//TA COM BUG, COLOCA LIXO NO FINAL DO TEXTO
void copia_arquivo(char *, char *);

int main(){
	char caminho[100], destino[100], op;
	do{
		printf(" Entre com a operacao:\n1 - Contar o numero de letras\n2 - Retirar espacos em branco\n3 - Trocar as letras A por B\n4 - Copiar arquivos\ns - Sair\n");	
		op = getch( );fflush(stdin);
		switch(op){
			case '1':
				printf("Entre com o caminho para o arquivo: ");
				scanf(" %s", caminho);
				printf(" Tem %d letras a neste documento\n", num_de_letras(caminho, 'a'));
				break;
			case '2':
				printf("Entre com o caminho para o arquivo: ");
				scanf(" %s", caminho);
				retira_espacos(caminho);
				printf("\nFEITO!\n"); 
				break;
			case '3':
				printf("Entre com o caminho para o arquivo: ");
				scanf(" %s", caminho);
				troca_letras(caminho, 'a', 'b');
				printf("\nFEITO!\n"); 
				break;
			case '4':
				printf("Entre com o caminho para o arquivo fonte: ");
				scanf(" %s", caminho);
				printf("Entre com o caminho para o arquivo destino: ");
				scanf(" %s", destino);
				copia_arquivo(caminho, destino);
				printf("\nFEITO!\n"); 
				break;
		}
		op = getch( );fflush(stdin);
		system("CLS");
	}while(op != 's');
	
	return 0;
}

void copia_arquivo(char * caminho_fonte, char * caminho_destino){
	FILE * fonte, * destino;
	int a;
	if( (fonte = fopen(caminho_fonte, "r") ) == NULL){
		printf(" Deu merda");
		return;
	}
	
	do{
		a = fgetc(fonte);
		if(fputc(a, destino) == EOF){
			printf("Deu BO");
			return;
		}
	}while(a != EOF);
	fclose(fonte);
	fclose(destino);
}

void troca_letras(char * caminho, char alvo, char substituto){
	FILE * arquivo;
	char ch, buffer[500];
	int i;
	if( (arquivo = fopen(caminho, "rb") ) == NULL){
		printf(" Deu merda");
		return;
	}
	
	do{
		ch = fgetc(arquivo);
		if(ch == 'a' || ch == 'A' || ch == 0x41 || ch == 0x61 && ch != EOF)
			buffer[i] = 'b';
		else if(ch != EOF)
			buffer[i] = ch;
		i++;
	}while(ch != EOF);
	fclose(arquivo);
	arquivo = fopen(caminho, "wb");
	fprintf(arquivo, "%s", buffer);
	fclose(arquivo);
}


int num_de_letras(char * caminho, char letra){

	FILE * arquivo;
	int ret = 0, ch;
	if( (arquivo = fopen(caminho, "r")) == NULL)
		return ERROR;
	do{
		ch = fgetc(arquivo);
		if(ch == 'a')
			ret++;
	}while(ch != EOF);
	fclose(arquivo);
	
	return ret;
}

void retira_espacos(char * caminho){
	FILE * arquivo;
	int i = 0, j;
	char * buffer = new char[500], ch;
	if( (arquivo = fopen(caminho, "r")) == NULL){
		printf(" Deu merda");
		return;
	}
	do{
		ch = fgetc(arquivo);
		if(ch != ' ' && ch != EOF&& ch != '\0'){
			buffer[i] = ch;
			i++;
		}
		printf(" \n%c %d\n", ch, i);
	}while(ch != EOF);
	fclose(arquivo);
	arquivo = fopen(caminho, "w");
	fprintf(arquivo, "%s", buffer);
	fclose(arquivo);
}

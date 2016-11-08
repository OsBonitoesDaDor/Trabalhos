#include <stdio.h>
#include <stdlib.h>

#define PATH "C:/Users/Bruno Pastre/Documents/"
typedef struct asd{
	int id;
	char nome[50];
	char endereco[80];
	char telefone[8];
	char data_de_nascimento[10];
	//Tem um bug que quando ele é inteiro crasha o programa
	char idade[3];
	//TODO: Implementar uma lista encadeada
	//struct asd * proximo_registro;
}REGISTRO;

int id_atual = 0;
REGISTRO cria_registro();
void grava_todos_registros(char *, REGISTRO *);

int main(){
	REGISTRO reg = cria_registro();
	printf(" To Aqui");
	grava_todos_registros("a1.txt", &reg);
	
	system("pause");
	return 0;
}
void grava_todos_registros(char * caminho, REGISTRO * registros){
	FILE * arquivo = fopen(caminho, "w");
	fprintf(arquivo, "ID: %d\n", registros -> id);
	fprintf(arquivo, "Nome: %s\n", registros -> nome);
	fprintf(arquivo, "Endereco: %s\n", registros -> endereco);
	fprintf(arquivo, "Telefone: %s\n", registros -> telefone);
	fprintf(arquivo, "Data de nascimento: %s\n", registros -> data_de_nascimento);
	fprintf(arquivo, "Idade: %s\n", registros -> idade);
	fclose(arquivo);
}
REGISTRO cria_registro(){
	REGISTRO reg;
	printf("Entre com o nome: ");
	scanf(" %s", reg.nome);
	printf("Entre com o endereco: ");
	scanf(" %s", reg.endereco);
	printf("Entre com o telefone: ");
	scanf(" %s", reg.telefone);
	printf("Entre com a data de nascimento: ");
	scanf(" %s", reg.data_de_nascimento );
	printf("Entre com a idade: ");
	scanf(" %s", reg.idade);
	reg.id = id_atual;
	id_atual++;
	return reg;
}

void grava_registro_por_id(){
	
}

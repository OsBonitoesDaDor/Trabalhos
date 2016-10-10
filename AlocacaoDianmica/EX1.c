#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <process.h>
#include <conio.h>
#define MAX 9

typedef struct {
    int id_bloco;
    int *end_in;
    char *conteudo;
    int tamb;
    int cont_texto;
    int add;
}bloco;

void criar(int, bloco *);
void imprime_bloco(bloco *);
void novo_bloco(int *, bloco *);
void inserir (int , bloco *);
void excluir(int *,int, bloco *);
void redefine(bloco *, int *);

int main(){
    bloco bloco_vet[MAX];
    int cont_bloco = 0,k;
    char ch, op, i;
    system("color 1E");
    do{
        system("CLS");
        printf("1 - criar bloco de memoria\n2 - listar blocos\n3 - incluir texto no bloco\n4 - excluir blocos\n5 - redefinir tamanho do bloco\ns - Sair\n");
        ch = getch( );fflush(stdin);
        switch(ch)
    {
    case '1': // cria novo bloco
        novo_bloco(&cont_bloco, &bloco_vet[0]);
        break;
    case '2': // Consulta
        for (i=0; i<cont_bloco;i++){
            imprime_bloco(&bloco_vet[i]);
            printf("\nImprime mais um(s/n)?\n\n");
            op = getch ( );fflush(stdin);
            if (op == 'n')
            break;
        }
        break;
        case '3': // Modifica
            puts("insira o id do bloco");
            scanf("%d",&k);
            if (k>cont_bloco)
                puts("erro, não tem este bloco");
            else{
                inserir(k, &bloco_vet[0]);
            }
            break;

        case '4': // exclui
            puts("insira o id do bloco");
            scanf("%d",&k);
            if (k>cont_bloco)
                puts("erro, não tem este bloco");
            else{
                excluir(&cont_bloco,k, &bloco_vet[0]);
            }

            break;

        case '5': // exclui
            puts("insira o id do bloco");
            scanf("%d",&k);
            if (k>cont_bloco || k>cont_bloco)
                puts("erro, não tem este bloco");
            else{
                redefine(&bloco_vet[k], &cont_bloco);
            }

            break;
        }
    }while (ch != 's');

//system("PAUSE");
return 0;
}

 // cria novo bloco de memotria
void novo_bloco(int *idx, bloco *pt_mov){
    int *pt_str,bytes, t;
    char *loc;
    //system("CLS");
    printf("bloco Id = %d\n\n",(*idx));
    printf("insira o tamanho do bloco\n\n");
    scanf("%d",&bytes);
    t=*idx;
    if (( (pt_mov+t)->conteudo = (char *)calloc(bytes,sizeof(char))) == NULL)
    {
        puts("erro, tamanho nao suportado");
        exit(1);
    }
    else{
    	int i, proximo_id;
        printf("bloco de tamanho %d criado com sucesso\n\n",bytes);
		while(proximo_id == (pt_mov + proximo_id) -> id_bloco){
			proximo_id++;
		}
 
        (pt_mov + t)->id_bloco = proximo_id;
        (pt_mov+t)->tamb = bytes;
        (pt_mov+t)->cont_texto = 0;
        (pt_mov+t)->add=0;
        (pt_mov+t)->end_in = (int *)((pt_mov+t)->conteudo);
        (*idx)++;
    }
    char ch;
    ch = getch( );fflush(stdin);
}

void imprime_bloco(bloco *mov)
{
    //system("CLS");
    printf("\nid do bloco %x",mov->id_bloco);
    printf("\nendereco inicial %x",mov->end_in);

    if(mov->add == 0)
        printf("\nconteudo nao adicionado");
    else
        printf("\nconteudo do bloco: %s",mov->conteudo);
    
    printf("\ntamanho %d",mov->tamb);
    char ch;
    ch = getch( );fflush(stdin);
}

void inserir(int k, bloco *vet)
{
    int total=(vet+k)->tamb;
    char *add_conteudo, carac[total];
    add_conteudo = (vet+k)->conteudo;
    puts("insira sua string");
    scanf("%s",&carac);
    (vet+k)->add = 1;
    
    if(total < strlen(carac))
        puts("erro - string muito grande para comportar na memoria");
    else
        strcat(add_conteudo, carac);
        
    char ch;
    ch = getch( );fflush(stdin);
}

void excluir(int *idx,int inicial , bloco *vet)
{
    int cont = (*idx)-1;
    int j,i;

    for(j=inicial; j<cont; j++)
    {
        i=j+1;
        (vet+j)->id_bloco = (vet+i)->id_bloco;
        (vet+j)->end_in = (vet+i)->end_in;
        (vet+j)->tamb = (vet+i)->tamb;
        (vet+j)->cont_texto = (vet+i)->cont_texto;
        (vet+j)->add = (vet+i)->add;
    }
    (*idx)--; //como excluimos um termo deve tirar-lo da contagem do vetor.
    char ch;
    ch = getch( );fflush(stdin);
}

void redefine(bloco *vet, int *idx)
{
    char *string_antiga = vet -> conteudo;
	int novo_tamanho;
	int tamanho_antigo = vet -> tamb;
	int i;
	printf(" Tamanho atual do bloco: %d\n", tamanho_antigo);
	puts("Insira um novo tamanho: ");
	scanf(" %d", &novo_tamanho);
	char *pt_aux;
	if(novo_tamanho < tamanho_antigo){
		pt_aux = (char *)malloc(novo_tamanho * sizeof(char));
		if(pt_aux == NULL){
			exit(1);
		}else{
			for(i = 0; i < novo_tamanho; i++){
				pt_aux[i] = string_antiga[i];
			}
			pt_aux[novo_tamanho] = '\0';
			free(vet -> conteudo);
			
			vet -> conteudo = pt_aux;
			vet -> tamb = novo_tamanho;
			vet -> end_in = (int *) (vet-> conteudo);
		}
	}
    char ch;
    ch = getch( );fflush(stdin);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define max 4
char * funcao_e(char *, char *);
char * funcao_ou(char *, char *);



int main ()
{

    char valor_binario1[max], valor_binario2[max];
    fflush(stdin);
    scanf(" %s",valor_binario1); fflush(stdin);

    fflush(stdin);
    scanf(" %s",valor_binario2); fflush(stdin);


    printf("valor = %s",funcao_ou(valor_binario1, valor_binario2));

    return 0;
}



char * funcao_e(char *valor_binario1, char *valor_binario2)
{
    int i;
    //char resultado[max];
    char *resultado = malloc( 5 * sizeof(char));
    for(i=0;    i<max;  i++)
    {
        if ( (valor_binario1[i] != '0')  && (valor_binario2[i] != '0'))
        {
            resultado[i] = '1';
        }
        else
        {
            resultado[i] = '0';
        }
    }
    resultado[4] = '\0';
    return resultado;
}

char * funcao_ou(char *valor_binario1, char *valor_binario2)
{
    int i;
    //char resultado[max];
    char *resultado = malloc( 5 * sizeof(char));
    for(i=0;    i<max;  i++)
    {
        if ( (valor_binario1[i] != '0')  || (valor_binario2[i] != '0'))
        {
            resultado[i] = '1';
        }
        else
        {
            resultado[i] = '0';
        }
    }
    resultado[4] = '\0';
    return resultado;
}

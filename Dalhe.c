#include <stdio.h>
#include <String.h>
#include<stdlib.h>
#include <math.h>

char * intToChar(int entr, char * res){
	int casas = 0, temp = entr, cont = 0;
	double i;
	char ho;
	
	do{
		casas++;
		temp = temp / 10;
	}while(temp >= 1);
	char  dal[casas];
	temp = entr;

	while(temp != 0){
		ho = ( temp % 10) + '0'; 
		temp/= 10;
		dal[cont] = ho;
		cont++;
	}
	printf("\ndal: %s\n", dal);
	strcpy(res, dal);
	return dal;
}

char *dubToStr(double entr, char *res){
    //Eliminamos a virgula
    int conv = entr * 100;
    //Ex: entr = 14.43, conv = 1443, primeiraParte = 14
    int primeiraParte = conv / 100;
    //Ex: entr = entr = 14.43, conv = 1443, primeiraParte = 14, decimais = (14.43 - 14)*100 =  0.43*100 = 43
    int decimais = (entr - primeiraParte) * 100;
    char * strPP , * strSP, temp[100];
    printf("1, %d, %d", primeiraParte, decimais);
    //Essa funcao converte os inteiros em String
 	intToChar(primeiraParte, strPP);
 	intToChar(decimais, strSP);
 	printf("pp %s, sp %s", strPP, strSP);
    strcpy(temp, strPP);
    strcat(temp, ".");
    strcat(temp, "strSP);
    printf("\ntemp:%s\n", temp);
    return temp;
}

int main()
{
    printf("Hello, World!\n");
    double dalhe = 232.14;
    char  * doubEmString = dubToStr(dalhe, doubEmString);
    printf("%s", doubEmString);
    return 0;
}


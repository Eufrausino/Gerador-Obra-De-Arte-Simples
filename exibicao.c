#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LINHAS 20
#define COLUNAS 80

void imprimeMoldura(char quadro[][COLUNAS], int linhas, int colunas)
{
	for(int i = 0; i < linhas; i++)
	{
		for(int j = 0; j < colunas; j++)printf("%c", quadro[i][j]);
		printf("\n");
	}
}

int main()
{
	srand(time(NULL));

	char quadro[LINHAS][COLUNAS];
	//Desenho da moldura
	for(int i = 0; i < LINHAS; i++)
	{
		for(int j = 0; j < COLUNAS; j++)
		{
			quadro[i][j] = ' ';

			if((i >= 1 && i < LINHAS - 1)&&(j == 0 || j == COLUNAS - 1)) quadro[i][j] = '|';

			if(i == 0 || i == LINHAS -1) quadro[i][j] = '-';
		}
	}
	imprimeMoldura(quadro, LINHAS, COLUNAS);

	return 0;
}

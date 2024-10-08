#include <time.h>
#include "obraDeArte.h"

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
	
	//Menu
	int selecao = 0;
	int qtdFiguras;

	printf("Bem-vindo a exibição de obras de arte da UFV!\n");
	printf("Qual tipo de obra de arte te interessa mais?");
	printf("\n1) Simples\n2) Cruz\n3) Marcação\n4) Surpresa\n5) Secreta\n");
	scanf("%d",&selecao);
	
	if(selecao < 5 && selecao > 0)
	{
		printf("Quantas obras você pretende ver? ");
		scanf("%d",&qtdFiguras);
		if(qtdFiguras <= 0) qtdFiguras = (rand() % 100)+1;
		else if(qtdFiguras > 100) qtdFiguras = 100;
	}
	
	switch (selecao)
	{
		case 1:
			geraObra1(quadro, qtdFiguras);
			break;
		case 2:
			geraObra2(quadro,qtdFiguras);
			break;
		case 3:
			geraObra3(quadro, qtdFiguras);
			break;
		case 4:
			geraObraMisturada(quadro, qtdFiguras);
			break;
		case 5:
			geraObraPessoal(quadro);
		default:
			break;
	}

	imprimeQuadro(quadro);

	return 0;
}

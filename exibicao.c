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
	geraObra1(quadro,3);
	geraObra2(quadro,4);
	geraObra3(quadro, 2);
	imprimeQuadro(quadro);

	return 0;
}

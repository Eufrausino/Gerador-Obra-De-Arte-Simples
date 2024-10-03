#include "obraDeArte.h"

void imprimeMoldura(char quadro[][COLUNAS])
{
	for(int i = 0; i < LINHAS; i++)
	{
		for(int j = 0; j < COLUNAS; j++)printf("%c", quadro[i][j]);
		printf("\n");
	}
}

int geraNumeroAleatorioX()
{
	return (rand()%LINHAS)+1; 
}

int geraNumeroAleatorioY()
{
	return (rand()%COLUNAS)+1;
}

void geraObra1(char quadro[][COLUNAS], int qtdFiguras)
{
	int colisao[LINHAS][COLUNAS];
	int determinaPosicaoX;
	int determinaPosicaoY;

	for(int i = 0; i < LINHAS; i++)
	{
		for(int j = 0; j < COLUNAS; j++)
		{
			if(i == 0 || i == LINHAS-1) colisao[i][j] = 1;
			else if(j == 0 || j == COLUNAS-1) colisao[i][j] = 1;
			else colisao[i][j] = 0;
		}
	}

	for(int i = 0; i < qtdFiguras; i++)
	{
		determinaPosicaoX = geraNumeroAleatorioX();
		determinaPosicaoY = geraNumeroAleatorioY();
		if(determinaPosicaoX == 0 || determinaPosicaoX == LINHAS - 1 || determinaPosicaoY == 0 || determinaPosicaoY == COLUNAS -1
		|| colisao[determinaPosicaoX][determinaPosicaoY] != 0)
		{
			while(colisao[determinaPosicaoX][determinaPosicaoY] != 0)
			{	
				determinaPosicaoX = geraNumeroAleatorioX();
				determinaPosicaoY = geraNumeroAleatorioY();
			}
		}

		quadro[determinaPosicaoX][determinaPosicaoY] = '*';
		colisao[determinaPosicaoX][determinaPosicaoY] = 1;
	}
}

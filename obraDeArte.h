#ifndef OBRADEARTE_h
#define OBRADEARTE_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINHAS 20
#define COLUNAS 80

//Struct para gerenciar melhor as artes ASCII
typedef struct Pokemon
{
	char* img;
}pkm;

void imprimeQuadro(char quadro[][COLUNAS]);
void geraObra1(char quadro[][COLUNAS], int qtdFiguras);
void geraObra2(char quadro[][COLUNAS], int qtdFiguras);
void geraObra3(char quadro[][COLUNAS], int qtdFiguras);
void geraObraMisturada(char quadro[][COLUNAS], int qtdFiguras);
void geraObraPessoal(char quadro[][COLUNAS]);
int geraNumeroAleatorioX();
int geraNumeroAleatorioY();
void contarLinhasColunas(pkm pkmn, int *linhas, int *colunas);

#endif

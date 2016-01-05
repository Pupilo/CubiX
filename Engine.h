/*################################################################################################
	<Magic Cube transforma um arquivo em seis matrizes alocadas na memoria, tendo como principio
    o cubo magico, executa rotaçoes de forma criptografar o arquivo, a saida e um arquivo encriptado
    que possui como chave a sequencia de desembaralhamento reversa que foi executada.>>
    Copyright (C) 2013 Willian.A.Mayan

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
################################################################################################*/


/*####################################################################################
#	engine.h -> old version -> Rubik.h
#	Autor: Willian.A.Mayan
#	Data: 02-03-2013
# 	Versao: 0.0.4
####################################################################################*/

#ifndef _ENGINE_H_
#define _ENGINE_H_

//My structs
/*##################################
	Estrutura da matriz dinamica 
	Limite de numeros:
	linhas:
	colunas:
 ##################################*/
typedef struct Matrix{
	char **matrix;
	long long int rows;
	long long int columns;
}Matrix;

/*##################################
Estrutura que contem seis(6) ponteiros
para matrizes dinamicas, cada ponteiro
representa um lado referenciando uma
matriz de bytes de um arquivo.
*##################################*/
typedef struct Cubic
{
    Matrix *Side_A;
    Matrix *Side_B;
    Matrix *Side_C;
    Matrix *Side_D;
    Matrix *Side_E;
    Matrix *Side_F;
}Cubic;

//My Functions
//##################################

/*Funç~ao que recebe os parametros passado pelo usuario e realiza testes*/ 
int treatment(int argc, char **argv);

/*Funç~ao que calcula o tamanho do arquivo em bytes, recebe o nome do arquivo como parametro*/
long file_size(char *argv);		//============> mudar argv para n_arquivo

/*Funç~ao que recebe um valor como parametro e calcula a quantidade de bytes para uma matriz quadrada perfeita*/
int calculate_matrix(long valor);   /*Revis~ao realizada em 23 fev 2013*/

/*Falta documentar - imprime matriz*/
void showMatrix(Matrix *matriz);

/*Imprime as faces do cubo*/
void showCubic(Cubic *cubicRF);

/*Criaçao da matriz dinamica*/
Matrix* init(const int row, const int column);

/*Limpa matrizes alocadas*/
void _delete(Matrix *matrix);

/*Limpa estrutura de cubo alocado na memoria*/
void _delete_cubic(Cubic *cubo);

/*Funç~ao para preenchimento da matriz - Rever conceitos - Criar preenchimento recursivo*/
void P_Matriz(long long int rows, long long int columns, Matrix *_matriz, char *argv);  //============> mudar argv para n_arquivo

/*Funç~ao para alocaç~ao de memoria do cubo*/
Cubic* cubicX(long long int ordem, char *argv);

/*Funç~ao que preenche matrizes recebendo um ponteiro para o arquivo, retorna um ponteiro de arquivo*/
FILE* P_cubicX(FILE *pointer, Matrix *matriX, long long int ordem);

#endif /* _ENGINE_H_ */

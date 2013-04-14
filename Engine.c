/*################################################################################################
	<Magic Cube transforma um arquivo em seis matrizes alocadas na memoria, tendo como principio
    o cubo magico, executa rotaçoes de forma criptografar o arquivo, a saida e um arquivo encriptado
    que possui como chave a sequencia de desembaralhamento reversa que foi executada.>
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
#	engine.c -> old version-> Rubik.c
#	Autor: Willian.A.Mayan
#	Data: 02-03-2013
# 	Versao: 0.0.4
#	Compilanç~ao: gcc -c -g Engine.c
####################################################################################*/

//Lib standart
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

//My lib
#include "Engine.h"

//------------------------------------------------------------------------------------------------------------------
/*Funç~ao que recebe os parametros passado pelo usuario e realiza testes*/
int treatment(int argc, char **argv){

    if(argc == 2){
        return 1;
    }
    else
    {
        printf("Nao foi recebido um arquivo como parametro\nPrograma encerrado!!\n");
        exit(0);
    }
}

//------------------------------------------------------------------------------------------------------------------
/*Funç~ao que calcula o tamanho do arquivo em bytes*/
int file_size(char *argv){

    FILE *arquivo;                                      // ponteiro para o arquivo
    long tamanho;                                       // tamanho em bytes do arquivo
    printf("Arquivo: %s\n",argv);                       //Pode ser removido
    arquivo = fopen(argv, "r");					        // abre o arquivo para leitura
    
    if (arquivo != NULL) {            					// verifica se o arquivo foi aberto com sucesso
            fseek(arquivo, 0, SEEK_END);				// movimenta a posição corrente de leitura no arquivo para o seu fim
            tamanho = ftell(arquivo);					// pega a posição corrente de leitura no arquivo       
            printf("O arquivo %s possui %ld bytes\n",argv, tamanho);	// imprime o tamanho do arquivo

    } 
    else {
        printf("Arquivo inexistente \n");
    }
return tamanho;
}

//------------------------------------------------------------------------------------------------------------------
/*Funç~ao que recebe um valor como parametro e calcula a quantidade de bytes para uma matriz quadrada perfeita*/
/*Revis~ao realizada em 23 fev 2013*/
int calculate_matrix(long valor){

    double Qtd;
    double inteiro;
    double fracionario;
    int resultado;
    long final;

    Qtd = valor / 6;                 
    printf("1. (Qtd / 6)= %f\n", Qtd);
    
    Qtd = sqrt(Qtd);                        
    printf("2. (sqrt(Qtd)) Raiz²= %f\n", Qtd);
    
    fracionario = modf(Qtd, &inteiro);      
    printf("3. Fracionario: %f\n", fracionario);   
    printf("4. Inteiro: %f\n", inteiro);

    if (fracionario != 0){
        resultado = inteiro + 1;
        printf("5. Resultado final: %d\n",resultado);
        
        resultado = pow(resultado,2) * 6;   
        printf("6. Resultado final^2 * 6: %d\n", resultado);

        final = resultado - valor;
        printf("7. Quantidade de bytes lixos inseridos:%d\n",final);

        resultado = sqrt(resultado/6);
        printf("8. Ordem da matriz: %d X %d\n",resultado,resultado);

        printf("9. Valor total em MB: %d\n",( ( (resultado * resultado) *6) / 1024 ) );

        printf("10. Valor total de bytes para matriz: %d bytes", ( (resultado * resultado) *6) );

        return resultado; //retorna a ordem da matriz
    }
    printf("5. Valor de Qtd: %d\n", inteiro);
    //if (Qtd == 1)
        return (int)inteiro;
}

//------------------------------------------------------------------------------------------------------------------
/*Funç~ao que imprime os valores contido na matriz passada como parametro*/
void showMatrix(Matrix *matriz){
  int i,j;
  for(i=0; i< matriz->rows; i++){
    for(j=0; j< matriz->columns; j++){
      printf("%c ", matriz->matrix[i][j]);
    }
    puts("");
  }
}

//------------------------------------------------------------------------------------------------------------------
/*Funç~ao que recebe o cubo como parametro e imprime suas faces*/
void showCubic(Cubic *cubicRF){
    printf("\n\nMatriz A\n");
    showMatrix(cubicRF->Side_A);
    printf("\n\nMatriz B\n");
    showMatrix(cubicRF->Side_B);
    printf("\n\nMatriz C\n");
    showMatrix(cubicRF->Side_C);
    printf("\n\nMatriz D\n");
    showMatrix(cubicRF->Side_D);
    printf("\n\nMatriz E\n");
    showMatrix(cubicRF->Side_E);
    printf("\n\nMatriz F\n");
    showMatrix(cubicRF->Side_F);
}

//------------------------------------------------------------------------------------------------------------------
/*Criaçao da matriz dinamica*/
Matrix* init(const int row, const int column){
  
  int i;
  Matrix* matriz = (Matrix*) malloc(1*sizeof(Matrix));
  
  matriz->matrix = (char**) malloc(row * sizeof(char*));
  
  for(i=0; i<column; i++)
    matriz->matrix[i] = (char*) malloc(column * sizeof(char));

  matriz->rows = row;
  matriz->columns = column;
  
  return matriz;
}

//------------------------------------------------------------------------------------------------------------------
/*Funç~ao para criaç~ao do cubo*/
Cubic* cubicX(long long int ordem, char *argv){

    FILE *pointer;
    Cubic* cubo = (Cubic*) malloc(1*sizeof(Cubic));

    //printf("\nCriaçao do Cubo\n"); //REMOVER

    //Alocando espaço para as matrizes                
    cubo->Side_A = init(ordem, ordem);
    cubo->Side_B = init(ordem, ordem);
    cubo->Side_C = init(ordem, ordem);
    cubo->Side_D = init(ordem, ordem);
    cubo->Side_E = init(ordem, ordem);
    cubo->Side_F = init(ordem, ordem);

    pointer = fopen(argv, "rb"); //Abre arquivo binario para leitura
    if (!pointer){
        printf("Erro na abertura do arquivo!!!\n");
    }

    fseek(pointer,0,SEEK_SET);                //Posiciona o ponteiro do arquivo no inicio do arquivo
    pointer = P_cubicX(pointer, cubo->Side_A, ordem);
    pointer = P_cubicX(pointer, cubo->Side_B, ordem);
    pointer = P_cubicX(pointer, cubo->Side_C, ordem);
    pointer = P_cubicX(pointer, cubo->Side_D, ordem);
    pointer = P_cubicX(pointer, cubo->Side_E, ordem);
    pointer = P_cubicX(pointer, cubo->Side_F, ordem);


    fclose(pointer); //Fechar o arquivo
    //showCubic(cubo);



return cubo;
}

//------------------------------------------------------------------------------------------------------------------
/*Funç~ao que preenche matrizes recebendo um ponteiro para o arquivo, retorna um ponteiro de arquivo*/
FILE* P_cubicX(FILE *pointer, Matrix *matriX, long long int ordem){

    long long int i, j;
    
    for(i = 0 ; i < ordem; i++){
        for(j = 0 ; j < ordem; j++){
            if (!feof(pointer)) {    
                matriX->matrix[i][j] = getc(pointer);
            }
            else
            {
                //criar funçao para preencher com lixo
                matriX->matrix[i][j] = '.';
            }
        }
    }
    return pointer;
}

//------------------------------------------------------------------------------------------------------------------
/*Funç~ao para preenchimento das matrizes*/
void P_Matriz(long long int rows, long long int columns, Matrix *_matriz, char *argv){
    
    long i,j;
    FILE *arquivo;

    printf("\n[DEBUG] Preenchendo Matriz\n");  //Remover - somente para debug
    printf("linha: %d \n", rows);               //Remover - somente para debug
    printf("coluna: %d \n", columns);         //Remover - somente para debug
    printf("Nome do arquivo: %s\n\n", argv); //Remover - somente para debug
    arquivo = fopen(argv, "r");             // abre o arquivo para leitura
  
    fseek(arquivo,0,SEEK_SET);                //Posiciona o ponteiro do arquivo no inicio do arquivo

    for(i = 0 ; i < columns; i++){
        for(j = 0 ; j < rows; j++){
            if (!feof(arquivo)) {    
                _matriz->matrix[i][j] = getc(arquivo);
            }
            else
            {
                //criar funçao para preencher com lixo
                printf(".");
            }
        }
    }

    fclose(arquivo);
    //Retorar ponteiro do arquivo
}

//------------------------------------------------------------------------------------------------------------------
/*Limpa matrizes alocadas*/
void _delete(Matrix *matrix){
  int i; 

  for(i=0;i < matrix->rows; i++)
    free(matrix->matrix[i]);
  
  free(matrix->matrix);
  free(matrix);
}

//------------------------------------------------------------------------------------------------------------------
/*Limpa estrutura de cubo alocado na memoria*/
void _delete_cubic(Cubic *cubo){
    _delete(cubo->Side_A);
    _delete(cubo->Side_B);
    _delete(cubo->Side_C);
    _delete(cubo->Side_D);
    _delete(cubo->Side_E);
    _delete(cubo->Side_F);
}

//------------------------------------------------------------------------------------------------------------------
/*                                            Salvar em arquivo                                                   */
//------------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------------------
/*Salva o cubo criptografado em arquivo
Revisado: 14 abr 2013 - Willian.A.Mayan - PENDENTE*/
void save_cubic(Cubic *cubicSave){
    
    long long int i, j;

    FILE *texto_cifrado; //Mudar nome da variavel

    texto_cifrado = fopen("texto_cifrado.cub", "w+b");
    printf("Salvando arquivo:\n"); //[DEBUG]
    //fwrite(&nome,sizeof(nome),1,arquivo);
    //Matriz A
    for(i = 0 ; i < cubicSave->Side_A->rows ; i++){
        for(j = 0 ; j < cubicSave->Side_A->columns ; j++){
            fwrite( &cubicSave->Side_A->matrix[i][j], sizeof(cubicSave->Side_A->matrix[i][j]) , sizeof(cubicSave->Side_A->matrix[i][j]), texto_cifrado );
        }
        /*A linha abaixo estava incrementando ^@ no arquivo, o que tornava o arquivo maior e sua decriptografia inviavel, analisar este pedaço*/
        //fwrite( &cubicSave->Side_A->matrix[i][j], sizeof(cubicSave->Side_A->matrix[i][j]) , sizeof(cubicSave->Side_A->matrix[i][j]), texto_cifrado  );
    }
    
    //Matriz B
    for(i = 0 ; i < cubicSave->Side_B->rows ; i++){
        for(j = 0 ; j < cubicSave->Side_B->columns ; j++){
            fwrite( &cubicSave->Side_B->matrix[i][j], sizeof(cubicSave->Side_B->matrix[i][j]) , 1, texto_cifrado );
        }
        /*A linha abaixo estava incrementando ^@ no arquivo, o que tornava o arquivo maior e sua decriptografia inviavel, analisar este pedaço*/
        //fwrite( &cubicSave->Side_B->matrix[i][j], sizeof(cubicSave->Side_B->matrix[i][j]) , 1, texto_cifrado );
    }
    
    //Matriz C
    for(i = 0 ; i < cubicSave->Side_C->rows ; i++){
        for(j = 0 ; j < cubicSave->Side_C->columns ; j++){
            fwrite( &cubicSave->Side_C->matrix[i][j], sizeof(cubicSave->Side_C->matrix[i][j]) , 1, texto_cifrado );
        }
        /*A linha abaixo estava incrementando ^@ no arquivo, o que tornava o arquivo maior e sua decriptografia inviavel, analisar este pedaço*/
        //fwrite( &cubicSave->Side_C->matrix[i][j], sizeof(cubicSave->Side_C->matrix[i][j]) , 1, texto_cifrado );
    }
    
    //Matriz D
    for(i = 0 ; i < cubicSave->Side_D->rows ; i++){
        for(j = 0 ; j < cubicSave->Side_D->columns ; j++){
            fwrite( &cubicSave->Side_D->matrix[i][j], sizeof(cubicSave->Side_D->matrix[i][j]) , 1, texto_cifrado );
        }
        /*A linha abaixo estava incrementando ^@ no arquivo, o que tornava o arquivo maior e sua decriptografia inviavel, analisar este pedaço*/
        //fwrite( &cubicSave->Side_D->matrix[i][j], sizeof(cubicSave->Side_D->matrix[i][j]) , 1, texto_cifrado );
    }
    
    //Matriz E
    for(i = 0 ; i < cubicSave->Side_E->rows ; i++){
        for(j = 0 ; j < cubicSave->Side_E->columns ; j++){
            fwrite( &cubicSave->Side_E->matrix[i][j], sizeof(cubicSave->Side_E->matrix[i][j]) , 1, texto_cifrado );
        }
        /*A linha abaixo estava incrementando ^@ no arquivo, o que tornava o arquivo maior e sua decriptografia inviavel, analisar este pedaço*/
        //fwrite( &cubicSave->Side_E->matrix[i][j], sizeof(cubicSave->Side_E->matrix[i][j]) , 1, texto_cifrado );
    }
    
    //Matriz F
    for(i = 0 ; i < cubicSave->Side_F->rows ; i++){
        for(j = 0 ; j < cubicSave->Side_F->columns ; j++){
            fwrite( &cubicSave->Side_F->matrix[i][j], sizeof(cubicSave->Side_F->matrix[i][j]) , 1, texto_cifrado );
        }
        /*A linha abaixo estava incrementando ^@ no arquivo, o que tornava o arquivo maior e sua decriptografia inviavel, analisar este pedaço*/
        //fwrite( &cubicSave->Side_F->matrix[i][j], sizeof(cubicSave->Side_F->matrix[i][j]) , 1, texto_cifrado );
    }
    printf("\n Matrizes OK\n");
    fcloseall(texto_cifrado);
    printf("\n Fechou o arquivo\n");
}

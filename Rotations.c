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
#   engine.h -> old version -> Rubik.h //refazer
#   Autor: Willian.A.Mayan
#   Data: 02-03-2013
#   Versao: 0.0.4
####################################################################################*/

//library standarts
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//my library
#include "Engine.h"
#include "Rotations.h"

//------------------------------------------------------------------------------------------------------------------
/*                                                  Rotaçoes                                                      */
//------------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------------------
/*Rotaç~ao frontal: Sentido da rotaçao: Matriz 1 a Matri 4*/
/*cubicRF = cubo para rotaç~ao frontal.
Revisado: 14 abr 2013 - Willian.A.Mayan*/
void from_rotation(Cubic *cubicRF, long long int columns){ 

    Matrix *auxiliar;       //Matriz auxiliar
    long long int i, j;     //Variaveis auxiliares para loop

    printf("\n\nNumero de coulnas: %d\n",cubicRF->Side_A->columns );
    printf("Numero da coluna para rotaçao: %d\n", columns);

    auxiliar = init(0,columns);

    for(i = 0 ; i < cubicRF->Side_A->columns ; i++){        //Auxiliar = Side_A
        auxiliar->matrix[0][i] = cubicRF->Side_A->matrix[i][columns]; //error
    }
    for(i = 0 ; i < cubicRF->Side_A->columns ; i++){        //Side_A = Side_D
        cubicRF->Side_A->matrix[i][columns] = cubicRF->Side_D->matrix[i][columns];
    }
    for(i = 0 ; i < cubicRF->Side_D->columns ; i++){        //Side_D = Side_C
        cubicRF->Side_D->matrix[i][columns] = cubicRF->Side_C->matrix[i][columns];
    }
    for(i = 0 ; i < cubicRF->Side_C->columns ; i++){        //Side_C = Side_B
        cubicRF->Side_C->matrix[i][columns] = cubicRF->Side_B->matrix[i][columns];
    }
    for(i = 0 ; i < cubicRF->Side_B->columns ; i++){        //Side_B = auxiliar
        cubicRF->Side_B->matrix[i][columns] = auxiliar->matrix[0][i];
    }
}

//------------------------------------------------------------------------------------------------------------------
/*Rotaç~ao frontal: Sentido da rotaçao: Matriz 4 a Matri 1*/
/*cubicRF = cubo para rotaç~ao frontal inversa.
Revisado: 14 abr 2013 - Willian.A.Mayan*/
void from_rotation_invers(Cubic *cubicRF, long long int columns){ 

    Matrix *auxiliar;
    long long int i, j;     //Variaveis auxiliares para loop

    printf("\n\nNumero de coulnas: %d\n",cubicRF->Side_A->columns );    //[DEBUG]
    printf("Numero da coluna para rotaçao: %d\n", columns);             //[DEBUG]

    auxiliar = init(0,columns);

    for(i = 0 ; i < cubicRF->Side_D->columns ; i++){        //Auxiliar = Side_D
        auxiliar->matrix[0][i] = cubicRF->Side_D->matrix[i][columns];
    }
    for(i = 0 ; i < cubicRF->Side_D->columns ; i++){        //Side_D = Side_A
        cubicRF->Side_D->matrix[i][columns] = cubicRF->Side_A->matrix[i][columns];
    }
    for(i = 0 ; i < cubicRF->Side_A->columns ; i++){        //Side_A = Side_B
        cubicRF->Side_A->matrix[i][columns] = cubicRF->Side_B->matrix[i][columns];
    }
    for(i = 0 ; i < cubicRF->Side_B->columns ; i++){        //Side_B = Side_C
        cubicRF->Side_B->matrix[i][columns] = cubicRF->Side_C->matrix[i][columns];
    }
    for(i = 0 ; i < cubicRF->Side_C->columns ; i++){        //Side_C = auxiliar
        cubicRF->Side_C->matrix[i][columns] = auxiliar->matrix[0][i];
    }
}

//------------------------------------------------------------------------------------------------------------------
/*Rotaçao no eixo X
Requer Revis~ao*/
void X_rotation(Cubic *cubicRF, long long int rows){

    Matrix *auxiliar;
    long long int i, j;     //Variaveis auxiliares para loop

    printf("\n\nNumero de coulnas: %d\n",cubicRF->Side_E->rows );
    printf("Numero da coluna para rotaçao: %d\n", rows);

    //auxiliar = vector_dinamic(cubicRF->Side_A->rows);   //Criaçao do vetor auxiliar
    auxiliar = init(0,rows);
    
    //Preenchendo vetor auxiliar
    for(i = 0 ; i < cubicRF->Side_E->rows ; i++){        //Auxiliar = Side_E
        auxiliar->matrix[0][i] = cubicRF->Side_E->matrix[rows][i]; //error
    }

/* ERROR - Revisar este ponto, os valores das matrizes est~ao sendo perdidos devido a implementaç~ao
errada com base na logica da inserç~ao dos elementos das matrizes*/

    for(i = 0 ; i < cubicRF->Side_E->rows ; i++){        //Side_E = Side_B
        cubicRF->Side_E->matrix[rows][i] = cubicRF->Side_B->matrix[rows][i]; //error
    }
    for(i = 0 ; i < cubicRF->Side_B->rows ; i++){        //Side_B = Side_F
        cubicRF->Side_B->matrix[rows][i] = cubicRF->Side_F->matrix[rows][i]; //error
    }
    for(i = 0 ; i < cubicRF->Side_F->rows ; i++){        //Side_F = Side_D
        cubicRF->Side_F->matrix[rows][i] = cubicRF->Side_D->matrix[rows][i]; //error
    }
    for(i = 0 ; i < cubicRF->Side_D->rows ; i++){        //Side_D = auxiliar
        cubicRF->Side_D->matrix[rows][i] = auxiliar->matrix[0][i]; //error
    }
}

//------------------------------------------------------------------------------------------------------------------
/*Rotaçao inversa no eixo X
Requer Revis~ao*/
void X_rotation_invers(Cubic *cubicRF, long long int rows){

    Matrix *auxiliar;
    long long int i, j;     //Variaveis auxiliares para loop

    printf("\n\nNumero de coulnas: %d\n",cubicRF->Side_E->rows );
    printf("Numero da coluna para rotaçao: %d\n", rows);

    auxiliar = init(0,rows);
    
    //Preenchendo vetor auxiliar
    for(i = 0 ; i < cubicRF->Side_D->rows ; i++){        //Auxiliar = Side_D
        auxiliar->matrix[0][i] = cubicRF->Side_D->matrix[rows][i]; //error
    }

    for(i = 0 ; i < cubicRF->Side_D->rows ; i++){        //Side_D = Side_F
        cubicRF->Side_D->matrix[rows][i] = cubicRF->Side_F->matrix[rows][i]; //error
    }
    for(i = 0 ; i < cubicRF->Side_F->rows ; i++){        //Side_F = Side_B
        cubicRF->Side_F->matrix[rows][i] = cubicRF->Side_B->matrix[rows][i]; //error
    }
    for(i = 0 ; i < cubicRF->Side_B->rows ; i++){        //Side_B = Side_E
        cubicRF->Side_B->matrix[rows][i] = cubicRF->Side_E->matrix[rows][i]; //error
    }
    for(i = 0 ; i < cubicRF->Side_E->rows ; i++){        //Side_E = auxiliar
        cubicRF->Side_E->matrix[rows][i] = auxiliar->matrix[0][i]; //error
    }
}

//------------------------------------------------------------------------------------------------------------------
/*Salva o cubo criptografado em arquivo*/
void save_cubic_revers(long long int size, Cubic *cubicSave){
    
    long long int i, j, size_file = 0;

    FILE *texto_cifrado; //Mudar nome da variavel

    texto_cifrado = fopen("texto_puro.cub", "w+b");

    //fwrite(&nome,sizeof(nome),1,arquivo);
    //Matriz A
    for(i = 0 ; i < cubicSave->Side_A->rows ; i++){
        for(j = 0 ; j < cubicSave->Side_A->columns ; j++){
            fwrite( &cubicSave->Side_A->matrix[i][j], sizeof(cubicSave->Side_A->matrix[i][j]) , sizeof(cubicSave->Side_A->matrix[i][j]), texto_cifrado );
            if (size_file == size){ //Modificaç~ao provisoria
                fcloseall(texto_cifrado);
                printf("\n Fechou o arquivo com tamanho: %d\n", size_file);
            }
            size_file++;
        }
        fwrite( &cubicSave->Side_A->matrix[i][j], sizeof(cubicSave->Side_A->matrix[i][j]) , sizeof(cubicSave->Side_A->matrix[i][j]), texto_cifrado  );
    }
    
    //Matriz B
    for(i = 0 ; i < cubicSave->Side_B->rows ; i++){
        for(j = 0 ; j < cubicSave->Side_B->columns ; j++){
            fwrite( &cubicSave->Side_B->matrix[i][j], sizeof(cubicSave->Side_B->matrix[i][j]) , 1, texto_cifrado );
            if (size_file == size){ //Modificaç~ao provisoria
                fcloseall(texto_cifrado);
                printf("\n Fechou o arquivo com tamanho: %d\n", size_file);
            }
            size_file++;
        }
        fwrite( &cubicSave->Side_B->matrix[i][j], sizeof(cubicSave->Side_B->matrix[i][j]) , 1, texto_cifrado );
    }
    
    //Matriz C
    for(i = 0 ; i < cubicSave->Side_C->rows ; i++){
        for(j = 0 ; j < cubicSave->Side_C->columns ; j++){
            fwrite( &cubicSave->Side_C->matrix[i][j], sizeof(cubicSave->Side_C->matrix[i][j]) , 1, texto_cifrado );
            if (size_file == size){ //Modificaç~ao provisoria
                fcloseall(texto_cifrado);
                printf("\n Fechou o arquivo com tamanho: %d\n", size_file);
            }
            size_file++;
        }
        fwrite( &cubicSave->Side_C->matrix[i][j], sizeof(cubicSave->Side_C->matrix[i][j]) , 1, texto_cifrado );
    }
    
    //Matriz D
    for(i = 0 ; i < cubicSave->Side_D->rows ; i++){
        for(j = 0 ; j < cubicSave->Side_D->columns ; j++){
            fwrite( &cubicSave->Side_D->matrix[i][j], sizeof(cubicSave->Side_D->matrix[i][j]) , 1, texto_cifrado );
            if (size_file == size){ //Modificaç~ao provisoria
                fcloseall(texto_cifrado);
                printf("\n Fechou o arquivo com tamanho: %d\n", size_file);
            }
            size_file++;
        }
        fwrite( &cubicSave->Side_D->matrix[i][j], sizeof(cubicSave->Side_D->matrix[i][j]) , 1, texto_cifrado );
    }
    
    //Matriz E
    for(i = 0 ; i < cubicSave->Side_E->rows ; i++){
        for(j = 0 ; j < cubicSave->Side_E->columns ; j++){
            fwrite( &cubicSave->Side_E->matrix[i][j], sizeof(cubicSave->Side_E->matrix[i][j]) , 1, texto_cifrado );
            if (size_file == size){ //Modificaç~ao provisoria
                fcloseall(texto_cifrado);
                printf("\n Fechou o arquivo com tamanho: %d\n", size_file);
            }
            size_file++;
        }
        fwrite( &cubicSave->Side_E->matrix[i][j], sizeof(cubicSave->Side_E->matrix[i][j]) , 1, texto_cifrado );
    }
    
    //Matriz F
    for(i = 0 ; i < cubicSave->Side_F->rows ; i++){
        for(j = 0 ; j < cubicSave->Side_F->columns ; j++){
            fwrite( &cubicSave->Side_F->matrix[i][j], sizeof(cubicSave->Side_F->matrix[i][j]) , 1, texto_cifrado );
        if (size_file == size){ //Modificaç~ao provisoria
                fcloseall(texto_cifrado);
                printf("\n Fechou o arquivo com tamanho: %d\n", size_file);
            }
            size_file++;
        }
        fwrite( &cubicSave->Side_F->matrix[i][j], sizeof(cubicSave->Side_F->matrix[i][j]) , 1, texto_cifrado );
    }
    printf("\n Matrizes OK\n");
    fcloseall(texto_cifrado);
    printf("\n Fechou o arquivo\n");
}
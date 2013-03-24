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
/*cubicRF = cubo para rotaç~ao frontal.*/
void from_rotation(Cubic *cubicRF, long long int columns){ 

    Matrix *auxiliar;
    long long int i, j;                                     //Variaveis auxiliares para loop

    printf("\n\nNumero de coulnas: %d\n",cubicRF->Side_A->columns );
    printf("Numero da coluna para rotaçao: %d\n", columns);

    //auxiliar = vector_dinamic(cubicRF->Side_A->columns);   //Criaçao do vetor auxiliar
    auxiliar = init(0,columns);

    //Preenchendo vetor auxiliar
    for(i = 0 ; i < cubicRF->Side_A->columns ; i++){        //Auxiliar = Side_A
        //printf("Original: %d: %c \n",i, cubicRF->Side_A->matrix[i][columns]);
        auxiliar->matrix[0][i] = cubicRF->Side_A->matrix[i][columns]; //error
    }

    for(i = 0 ; i < cubicRF->Side_A->columns ; i++){        //Side_A = Side_D
        //printf("Original: %d: %c \n",i, cubicRF->Side_A->matrix[i][columns]);
        cubicRF->Side_A->matrix[i][columns] = cubicRF->Side_D->matrix[i][columns]; //error
    }

    for(i = 0 ; i < cubicRF->Side_D->columns ; i++){        //Side_D = Side_C
        //printf("Original: %d: %c \n",i, cubicRF->Side_D->matrix[i][columns]);
        cubicRF->Side_D->matrix[i][columns] = cubicRF->Side_C->matrix[i][columns]; //error
    }

    for(i = 0 ; i < cubicRF->Side_C->columns ; i++){        //Side_C = Side_B
        //printf("Original: %d: %c \n",i, cubicRF->Side_D->matrix[i][columns]);
        cubicRF->Side_C->matrix[i][columns] = cubicRF->Side_B->matrix[i][columns]; //error
    }

    for(i = 0 ; i < cubicRF->Side_B->columns ; i++){        //Side_B = auxiliar
        //printf("Original: %d: %c \n",i, cubicRF->Side_D->matrix[i][columns]);
        cubicRF->Side_B->matrix[i][columns] = auxiliar->matrix[0][i]; //error
    }
}

//------------------------------------------------------------------------------------------------------------------
/*Rotaç~ao frontal: Sentido da rotaçao: Matriz 4 a Matri 1*/
/*cubicRF = cubo para rotaç~ao frontal inversa.*/
void from_rotation_invers(Cubic *cubicRF, long long int columns){ 

    Matrix *auxiliar;
    long long int i, j;                                     //Variaveis auxiliares para loop

    printf("\n\nNumero de coulnas: %d\n",cubicRF->Side_A->columns );
    printf("Numero da coluna para rotaçao: %d\n", columns);

    //auxiliar = vector_dinamic(cubicRF->Side_A->columns);   //Criaçao do vetor auxiliar
    auxiliar = init(0,columns);

    //Preenchendo vetor auxiliar
    for(i = 0 ; i < cubicRF->Side_D->columns ; i++){        //Auxiliar = Side_D
        auxiliar->matrix[0][i] = cubicRF->Side_D->matrix[i][columns]; //error
    }

    for(i = 0 ; i < cubicRF->Side_D->columns ; i++){        //Side_D = Side_A
        cubicRF->Side_D->matrix[i][columns] = cubicRF->Side_A->matrix[i][columns]; //error
    }

    for(i = 0 ; i < cubicRF->Side_A->columns ; i++){        //Side_A = Side_B
        cubicRF->Side_A->matrix[i][columns] = cubicRF->Side_B->matrix[i][columns]; //error
    }

    for(i = 0 ; i < cubicRF->Side_B->columns ; i++){        //Side_B = Side_C
        cubicRF->Side_B->matrix[i][columns] = cubicRF->Side_C->matrix[i][columns]; //error
    }

    for(i = 0 ; i < cubicRF->Side_D->columns ; i++){        //Side_D = auxiliar
        cubicRF->Side_D->matrix[i][columns] = auxiliar->matrix[0][i]; //error
    }
}
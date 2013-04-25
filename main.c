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

/*
Chave:
Usuario fornece uma senha(chave)
essa senha calcula a rotaç~ao com base no time do computador 00:00 -> 23:59
cada caracter dessa chave muda seu comportamento em relaçao ao tempo, a nunca sera somente por causa do tempo ex: 01:00, sempre randomico as posiç~oes
e horarios.

e implementado uma cahve de tempo, que com base nesse tempo pode se calcular as rotaç~oes
tempo>chave

Estudar viabilidade$
*/

/*################################################################################################
# 	Programa de Criptografia Cubica
#	Autor: Willian.A.Mayan
#	Data: 02-03-2013
# 	Versao: 0.0.4
#	Dedicado: GNU RUY - Grupo de Software Livre da Faculdade Ruy Barbosa
#	Compilaç~ao: gcc -w -g -o main.o main.c engine.o Menu.o -lm
################################################################################################*/

//library standarts
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//my library
#include "Engine.h"
#include "Rotations.h"
#include "Menu.h"

int main(int argc, char *argv[]){

	/* Variaveis da funçao*/
	int op; //Variavel para escolha do menu
	char *texto_puro; //Arquivo recebido como parametro pelor argv
	long long int size, ordem_matriz;

	/*Inicio*/
	treatment(argc, argv); //Testa parametros recebidos
	if(strcmp(argv[1],"-c") == 0) {
		op = 1;
	} else if(strcmp(argv[1],"-d") == 0) {
                op = 2;
        } else {
		return -1;
	}
	texto_puro = argv[2];

	switch(op){
		case 1: 
				size = file_size(texto_puro);
				ordem_matriz = calculate_matrix(size);
				Cubic* Cubic_Text = cubicX(ordem_matriz,texto_puro);
				
				showCubic(Cubic_Text);		//Matriz Original

				//Criptografia
				from_rotation(Cubic_Text, 1);	//Rotaç~ao frontal
				X_rotation(Cubic_Text, 1);		//Rotaç~ao horizontal
				//Y_rotation(Cubic_Text, 1);		//Rotaç~ao vertical
				
				//Matriz Criptografada
				showCubic(Cubic_Text);		//[DEBUG]
				
				//salvar em arquivo
				save_cubic(Cubic_Text);

				//Limpa Memoria
				_delete_cubic(Cubic_Text);
				free(Cubic_Text);

				printf("Criptografia finalizada com sucesso!!\n");	//[DEBUG]

		break;
		case 2: 
				printf("Iniciando decriptografia\n");				//[DEBUG]
				size = file_size(texto_puro); 
				ordem_matriz = calculate_matrix(size);
				
				printf("\nOrdem da matriz %d\n", ordem_matriz );	//[DEBUG]
				
				Cubic* Cubic_Cript = cubicX(ordem_matriz,texto_puro);

				//printf("###########################\nCubo criptografado\n###########################\n");//[DEBUG]
				//showCubic(Cubic_Cript);			//[DEBUG]

				//Iniciando testes
				X_rotation_invers(Cubic_Cript, 1);		//Rotaç~ao lateral inversa
				from_rotation_invers(Cubic_Cript, 1);//iniciar rotaçao

				//printf("###########################\nCubo decriptografado\n###########################\n");//[DEBUG]
				//showCubic(Cubic_Cript);				//[DEBUG]
				
				save_cubic_revers(size, Cubic_Cript);	//salvar em arquivo   //Rever esta funç~ao
				_delete_cubic(Cubic_Cript);				//Limpar memoria 
				free(Cubic_Cript);						//Limpar memoria 
				printf("Decriptografia finalizada com sucesso!!\n");	//[DEBUG]
		break;
	}
return 0;
}

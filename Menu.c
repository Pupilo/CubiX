/*################################################################################################
	<Breve descriç~ao do programa.>
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
#	Menu.c
#	Autor: Willian.A.Mayan
# 	Versao: 0.0.4
#	Vers~ao: 0.0.1
#	Compilanç~ao: gcc -c -g Menu.c
####################################################################################*/

#include <stdio.h>

void banner(){
	printf("##########################################################################\n");
	printf("Prototipo de criptografia Rubik versao 0.1								  \n");
    printf("Defesa do Bacharelado de Ciencia da computaçao, Faculdade Ruy Barbosa     \n");
	printf("Idealizador:\n");
	printf("Willian.A.Mayan\n\n");
	printf("Desenvolvedores:\n");
	printf("Jerffeson\n");
	printf("Willian.A.Mayan\n");
	printf("##########################################################################\n\n");
}

void help(){
	printf("##########################################################################\n");
	printf("[OPÇOES]\n\n");
	printf("d - Criptografa o arquivo passado como argumento\n");
	printf("c - Decriptografar o arquivo passado como argumento\n\n");
	printf("[EXEMPLOS]\n\n");
	printf("./CubiX -c arquivo_texto_puro\n");
	printf("./CubiX -d arquivo_texto_cifrado\n");
	printf("./CubiX -h help\n");
}

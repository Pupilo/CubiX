######################################################################################
#	<Magic Cube transforma um arquivo em seis matrizes alocadas na memoria, tendo como principio
#    o cubo magico, executa rotaçoes de forma criptografar o arquivo, a saida e um arquivo encriptado
#    que possui como chave a sequencia de desembaralhamento reversa que foi executada>
#    Copyright (C) 2013 Willian.A.Mayan
#
#    This program is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with this program.  If not, see <http://www.gnu.org/licenses/>.
####################################################################################

####################################################################################
#	Autor: Willian.A.Mayan
#	Data: 02-03-2013
# 	Versao: 0.0.4
#	Compilanç~ao: ./compilar.sh
####################################################################################
#Compilação do programa

#!/bin/bash

#Compilar libs
gcc -c -g Engine.c
gcc -c -g Menu.c
gcc -c -g Rotations.c

#Compilar o main
gcc -w -g -o main.o main.c Engine.o Menu.o Rotations.o -lm


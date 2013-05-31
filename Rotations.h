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
#   engine.h -> old version -> CubiX.h //refazer
#   Autor: Willian.A.Mayan
#   Data: 02-03-2013
#   Versao: 0.0.4
####################################################################################*/

//------------------------------------------------------------------------------------------------------------------
/*                                                  Rotaçoes                                                      */
//------------------------------------------------------------------------------------------------------------------

/*Rotaçao frontal
Revisado: 14 abr 2013 - Willian.A.Mayan*/
void from_rotation(Cubic *cubicRF, long long int columns);

/*Rotaçao frontal inverso
Revisado: 14 abr 2013 - Willian.A.Mayan*/
void from_rotation_invers(Cubic *cubicRF, long long int columns);

/*Rotaçao no eixo X
Revisado: 15 abr 2013 - Willian.A.Mayan*/
void X_rotation(Cubic *cubicRF, long long int rows);

/*Rotaçao inversa no eixo X
Revisado: 15 abr 2013 - Willian.A.Mayan*/
void X_rotation_invers(Cubic *cubicRF, long long int rows);

/*Rotaçao no eixo Y*/
void Y_rotation(Cubic *cubicRF, long long int rows);

/*Rotaçao inversa no eixo Y*/
void Y_rotation_invers(Cubic *cubicRF, long long int rows);

/*Rotaçao no eixo Z*/
void Z_rotation(Cubic *cubicRF, long long int rows);

/*Rotaçao inversa no eixo Y*/
void Z_rotation_invers(Cubic *cubicRF, long long int rows);

//------------------------------------------------------------------------------------------------------------------
/*                                            Salvar em arquivo                                                   */
//------------------------------------------------------------------------------------------------------------------

/*Salva o cubo criptografado em arquivo*/
void save_cubic(Cubic *cubicSave);

/*Salva o cubo decriptografado em arquivo*/
void save_cubic_revers(long long int size, Cubic *cubicSave);
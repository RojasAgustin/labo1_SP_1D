/*
 * parser.h
 *
 *  Created on: 19 nov. 2021
 *      Author: Usuario
 */

#ifndef PARSER_H_
#define PARSER_H_
#include <stdio.h>
#include <stdlib.h>
#include "perros.h"
#include "ll.h"
/**
 * @fn int parserBinario(FILE*, LinkedList*)
 * \brief Parsea los datos los datos de los perros desde el archivo !!!
 * \param pFile FILE* El puntero al archivo
 * \param listadoPerros LinkedList* La lista de perros
 * \return retorno int 0 si puede añadir del archivo a la lista con exito. -1 hay un error.
 *
 */
int parserBinario(FILE* pFile , LinkedList* listadoPerros);
/**
 * @fn int parserTexto(FILE*, LinkedList*)
 * \brief Parsea los datos los datos de los perros desde el archivo ¡¡¡
 *
 * \param pFile FILE* El puntero al archivo
 * \param listadoPerros LinkedList* La lista de perros
 * \return retorno int 0 si puede añadir del archivo a la lista con exito. -1 hay un error.
 *
 */
int parserTexto(FILE* pFile , LinkedList* listadoPerros);

#endif /* PARSER_H_ */

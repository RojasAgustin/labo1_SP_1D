/*
 * abm.h
 *
 *  Created on: 19 nov. 2021
 *      Author: Usuario
 */

#ifndef ABM_H_
#define ABM_H_
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "ll.h"
#include "parser.h"
#include "perros.h"
/**
 * @fn int cargarTexto(char*, LinkedList*)
 * @brief Carga los datos de los perros desde el archivo que recibe como parametro en una linked list
 *
 * @param path La ruta del archivo
 * @param listadoPerros El listado donde se van a guardar
 * @return retorno int -1 si no encuentra el archivo. 0 si lo puede abrir
 */
int cargarTexto(char* path , LinkedList* listadoPerros);
/**
 * @fn int listadoPerros(LinkedList*)
 * @brief Imprime el listado de perros por pantalla
 *
 * @param listadoPerros el listado de perros
 * @return retorno int -1 si hay un error (la lista apunta a NULL) 0 si hay perros cargados
 */
int listadoPerros(LinkedList* listadoPerros);
/**
 * @fn int listadoPerrosConRacion(LinkedList*)
 * @brief Imprime el listado de los perros con el campo de las comidas
 *
 * @param listadoPerros el listado de perros
 * @return retorno int -1 si hay un error (la lista apunta a NULL) 0 si hay perros cargados
 */
int listadoPerrosConRacion(LinkedList* listadoPerros);
/**
 * @fn int guardarGalgos(char*, LinkedList*)
 * @brief Guarda los datos de los galgos en el archivo que recibe como parametro
 *
 * @param path Donde se guardan los datos
 * @param listadoGalgos El listado de los galgos
 * @return retorno int -1 si no puede crear el archivo y si el listado o el archivo apunta a NULL. 0 si lo puede crear y escribir.
 */
int guardarGalgos(char* path , LinkedList* listadoGalgos);


#endif /* ABM_H_ */

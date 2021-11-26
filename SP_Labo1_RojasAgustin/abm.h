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
int cargarTexto(char* path , LinkedList* listadoPerros);
int listadoPerros(LinkedList* listadoPerros);
int listadoPerrosConRacion(LinkedList* listadoPerros);
int guardarGalgos(char* path , LinkedList* listadoGalgos);


#endif /* ABM_H_ */

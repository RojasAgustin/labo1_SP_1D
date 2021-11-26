/*
 * perros.h
 *
 *  Created on: 19 nov. 2021
 *      Author: Usuario
 */

#ifndef PERROS_H_
#define PERROS_H_
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "ll.h"
#include "string.h"

typedef struct
{
	int id;
	char nombre[21];
	float peso;
	int edad;
	char raza[21];
	float cantidadComidaRacion;
}ePerrito;
/**
 * @fn ePerrito ePerrito_constructor*()
 * @brief Crea espacio para un puntero a ePerrito y lo devuelve
 *
 * @return perriRetorno ePerrito* El puntero a ePerrito
 */
ePerrito* ePerrito_constructor();
/**
 * @fn ePerrito ePerrito_constructorParam*(int, char*, int, char*)
 * @brief Crea un puntero a ePerrito, guarda los parametros en él y lo devuelve
 *
 * @param id El id del perro
 * @param nombre El nombre del perro
 * @param edad La edad del perro
 * @param raza La raza del perro
 * @param peso El peso del perro
 *
 * @return perri ePerrito* El puntero a ePerrito
 */
ePerrito* ePerrito_constructorParam(int id,char* nombre, int edad,char* raza,float peso);
/**
 * @fn int ePerrito_setID(ePerrito*, int)
 * @brief Guarda el valor del parametro id en el campo id del puntero a ePerrito
 *
 * @param this ePerrito* el puntero al perro
 * @param id int el ID a cargar
 * @return retorno int 0 si lo puede cargar.-1 si hay un error
 */
int ePerrito_setID(ePerrito* this, int id);
/**
 * @fn int ePerrito_getID(ePerrito*)
 * @brief Guarda el valor del campo id en una variable y la retorna
 *
 * @param this ePerrito* el puntero al perro
 * @return id int donde se guarda el dato
 */
int ePerrito_getID(ePerrito* this);
/**
 * @fn int ePerrito_setNombre(ePerrito*, char*)
 * @brief Guarda el valor del parametro nombre en el campo nombre del puntero a perro
 *
 * @param this ePerrito* el puntero al perro
 * @param nombre char* el nombre a cargar
 * @return retorno int 0 si lo puede cargar.-1 si hay un error
 */
int ePerrito_setNombre(ePerrito* this, char* nombre);
/**
 * @fn char ePerrito_getNombre*(ePerrito*)
 * @brief Guarda el valor del campo nombre en una variable y la retorna
 *
 * @param this ePerrito* el puntero al perro
 * @return nombre char* donde se guarda el dato
 */
char* ePerrito_getNombre(ePerrito* this);
/**
 * @fn int ePerrito_setEdad(ePerrito*, int)
 * @brief Guarda el valor del parametro edad en el campo edad del puntero a ePerrito
 *
 * @param this ePerrito* el puntero al perro
 * @param edad int la edad a cargar
 * @return retorno int 0 si lo puede cargar.-1 si hay un error
 */
int ePerrito_setEdad(ePerrito* this, int edad);
/**
 * @fn int ePerrito_getEdad(ePerrito*)
 * @brief Guarda el valor del campo edad en una variable y la retorna
 *
 * @param this ePerrito* el puntero al perro
 * @return edad int donde se guarda el dato
 */
int ePerrito_getEdad(ePerrito* this);
/**
 * @fn int ePerrito_setRaza(ePerrito*, char*)
 * @brief Guarda el valor del parametro raza en el campo raza del puntero a perro
 *
 * @param this ePerrito* el puntero al perro
 * @param raza char* el nombre a cargar
 * @return retorno int 0 si lo puede cargar.-1 si hay un erro
 */
int ePerrito_setRaza(ePerrito* this, char* raza);
/**
 * @fn char ePerrito_getRaza*(ePerrito*)
 * @brief Guarda el valor del campo raza en una variable y la retorna
 *
 * @param this ePerrito* el puntero al perro
 * @return raza char* donde se guarda el dato
 */
char* ePerrito_getRaza(ePerrito* this);
/**
 * @fn int ePerrito_setPeso(ePerrito*, float)
 * @brief Guarda el valor del parametro peso en el campo peso del puntero a ePerrito
 *
 * @param this ePerrito* el puntero al perro
 * @param peso float el peso a cargar
 * @return retorno int 0 si lo puede cargar.-1 si hay un error
 */
int ePerrito_setPeso(ePerrito* this, float peso);
/**
 * @fn float ePerrito_getPeso(ePerrito*)
 * @brief Guarda el valor del campo peso en una variable y la retorna
 *
 * @param this ePerrito* el puntero al perro
 * @return peso float donde se guarda el dato
 */
float ePerrito_getPeso(ePerrito* this);
/**
 * @fn int ePerrito_sortearPorNombre(void*, void*)
 * @brief Ordena el listado por nombre ascendente, comparando los perros que recibe como parametro
 *
 * @param perro1 El primer perro
 * @param perro2 El segundo perro
 * @return retorno int 1 El nombre del primer perro es mayor
 * 					   0 Si son iguales
 * 					   -1 Si el nombre del segundo es mayor
 */
int ePerrito_sortearPorNombre(void* perro1,void* perro2);
/**
 * @fn int ePerrito_laQueMapea(void*)
 * @brief Calcula el campo de las raciones multiplicando el peso por 23.
 *
 * @param perro el perro al que se le va a asignar el campo de las raciones
 * @return retorno int -1 si el perro que recibe como parametro apunta a NULL. 0 si puede calcular el campo.
 */
int ePerrito_laQueMapea(void*perro);
/**
 * @fn int ePerrito_laQueFiltra(void*)
 * @brief Verifica que las condiciones se cumplan para que ll_filter pueda agregar al perro a la lista nueva
 *
 * @param perro el perro que se va a examinar.
 * @return int retorno -1 si el perro apunta a NULL. 0 si no se cumplen las condiciones. 1 si se cumplen.
 */
int ePerrito_laQueFiltra(void*perro);
/**
 * @fn LinkedList ePerrito_generarListaDeGalgos*(LinkedList*)
 * @brief Crea la lista con los filtros llamando a ll_filter con la funcion que filtra como parametro y la devuelve
 *
 * @param listadoPerros La lista de perros original
 * @return listaFiltrada LinkedList* la lista de los galgos
 */
LinkedList* ePerrito_generarListaDeGalgos(LinkedList* listadoPerros);
/**
 * @fn void ePerrito_destructor(ePerrito*)
 * @brief Borra el espacio de memoria asignado al perro
 *
 * @param this ePerrito* El puntero al perro
 */
void ePerrito_destructor(ePerrito* this);


#endif /* PERROS_H_ */

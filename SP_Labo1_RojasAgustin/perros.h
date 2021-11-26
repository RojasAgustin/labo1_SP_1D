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
 * @brief Crea un puntero a ePerrito, guarda los parametros en el y lo devuelve
 *
 * @param id El id del perro
 * @param nombre El nombre del perro
 * @param edad La edad del perro
 * @param raza La raza del perro
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
 * @param edad int el ID a cargar
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
 * @fn void ePerrito_destructor(ePerrito*)
 * @brief Borra el espacio de memoria asignado al perro
 *
 * @param this ePerrito* El puntero al perro
 */
int ePerrito_setPeso(ePerrito* this, float peso);
float ePerrito_getPeso(ePerrito* this);
int ePerrito_sortearPorNombre(void* perro1,void* perro2);
int ePerrito_laQueMapea(void*perro);
int ePerrito_laQueFiltra(void*perro);
LinkedList* ePerrito_generarListaDeGalgos(LinkedList* listadoPerros);
void ePerrito_destructor(ePerrito* this);


#endif /* PERROS_H_ */

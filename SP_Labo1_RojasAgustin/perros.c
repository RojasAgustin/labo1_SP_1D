/*
 * perros.c
 *
 *  Created on: 19 nov. 2021
 *      Author: Usuario
 */
#include "perros.h"

ePerrito* ePerrito_constructor()
{
	ePerrito* perriRetorno = NULL;
	perriRetorno = (ePerrito*) malloc (sizeof(ePerrito));
	return perriRetorno;
}

ePerrito* ePerrito_constructorParam(int id, char* nombre, int edad,char* raza,float peso)
{
	ePerrito* perri = NULL;
	perri = ePerrito_constructor();
	if(perri != NULL){
		ePerrito_setID(perri, id);
		ePerrito_setNombre(perri, nombre);
		ePerrito_setEdad(perri, edad);
		ePerrito_setRaza(perri, raza);
		ePerrito_setPeso(perri, peso);
	}
	return perri;
}

int ePerrito_setNombre(ePerrito* this, char* nombre)
{
	int seCargo = 0;
	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		seCargo = 1;
	}
	return seCargo;
}

char* ePerrito_getNombre(ePerrito* this)
{
	char* nombre = NULL;
	if(this != NULL)
	{
		nombre = this->nombre;
	}
	return nombre;
}

int ePerrito_setEdad(ePerrito* this, int edad)
{
	int seCargo = 0;
	if(this != NULL)
	{
		this->edad = edad;
		seCargo = 1;
	}
	return seCargo;
}

int ePerrito_getEdad(ePerrito* this)
{
	int edad;
	if(this != NULL)
	{
		edad = this->edad;
	}
	return edad;
}
int ePerrito_setPeso(ePerrito* this, float peso)
{
	int seCargo = 0;
	if(this != NULL)
	{
		this->peso = peso;
		seCargo = 1;
	}
	return seCargo;
}
float ePerrito_getPeso(ePerrito* this)
{
	float peso;
	if(this != NULL)
	{
		peso = this->peso;
	}
	return peso;
}
int ePerrito_setID(ePerrito* this, int id)
{
	int seCargo = 0;
	if(this != NULL)
	{
		this->id = id;
		seCargo = 1;
	}
	return seCargo;
}

int ePerrito_getID(ePerrito* this)
{
	int id;
	if(this != NULL)
	{
		id = this->id;
	}
	return id;
}
int ePerrito_setRaza(ePerrito* this, char* raza)
{
	int seCargo = 0;
	if(this != NULL && raza != NULL)
	{
		strcpy(this->raza, raza);
		seCargo = 1;
	}
	return seCargo;
}

char* ePerrito_getRaza(ePerrito* this)
{
	char* raza = NULL;
	if(this != NULL)
	{
		raza = this->raza;
	}
	return raza;
}
int ePerrito_sortearPorNombre(void* perro1,void* perro2){
	int retorno =1;
	ePerrito* perroUno;
	ePerrito* perroDos;
	if(perro1!=NULL && perro2!=NULL){
		perroUno = (ePerrito*)perro1;
		perroDos = (ePerrito*)perro2;
		if(strcmp(perroUno->nombre,perroDos->nombre)==-1){
			retorno =-1;
		}
		else{
			if(strcmp(perroUno->nombre,perroDos->nombre)==0){
				retorno =0;
			}
		}
		perroUno = NULL;
		perroDos = NULL;
	}
	return retorno;
}
int ePerrito_laQueMapea(void* perro){
	int retorno =-1;
	ePerrito* perroMapeado = NULL;
	if(perro != NULL){
		perroMapeado = (ePerrito*) perro;
		perroMapeado->cantidadComidaRacion = perroMapeado->peso*23;
		retorno = 0;
	}
	return retorno;
}
int ePerrito_laQueFiltra(void* perro){
	int retorno = -1;
	ePerrito* auxPerro = NULL;
	if(perro!=NULL){
		auxPerro = (ePerrito*)perro;
		retorno = 0;
		if(stricmp(auxPerro->raza,"Galgo") == 0 && auxPerro->cantidadComidaRacion < 200 && auxPerro->edad > 10){
			retorno = 1;
		}
	}
	return retorno;
}
LinkedList* ePerrito_generarListaDeGalgos(LinkedList* listadoPerros){
	LinkedList* listaFiltrada = NULL;
	if(listadoPerros != NULL){
		listaFiltrada = ll_filter(listadoPerros, ePerrito_laQueFiltra);
	}
	return listaFiltrada;
}
void ePerrito_destructor(ePerrito* this)
{
	if(this != NULL)
	{
		free(this);
		this = NULL;
	}
}

/*
 * abm.c
 *
 *  Created on: 19 nov. 2021
 *      Author: Usuario
 */
#include "abm.h"
#include <stdio.h>
#include "stdlib.h"
int cargarTexto(char* path , LinkedList* listadoPerros){
	int retorno =-1;
	FILE* pFile;
	pFile = fopen(path,"r");
	if(pFile !=NULL){
		parserTexto(pFile, listadoPerros);
		fclose(pFile);
		pFile = NULL;
		retorno =0;
	}
    return retorno;
}
int listadoPerros(LinkedList* listadoPerros){
	int retorno =-1;
	int id;
	char nombre[21];
	int edad;
	char raza[21];
	float peso;
	ePerrito* pPerro = NULL;
	if(listadoPerros!=NULL){
		printf("%-10s %-21s %-10s %-10s %-21s\n","ID","Nombre","Peso","Edad","Raza");
		for(int i=0;i<ll_len(listadoPerros);i++){
			//Usando los getters
			pPerro = ll_get(listadoPerros, i);
			id = ePerrito_getID(pPerro);
			ePerrito_getNombre(pPerro,nombre);
			edad = ePerrito_getEdad(pPerro);
			ePerrito_getRaza(pPerro,raza);
			peso = ePerrito_getPeso(pPerro);
			printf("%-10d %-21s %-10.2f %-10d %-21s\n",id,nombre,peso,edad,raza);
		}
		retorno = 0;
	}
    return retorno;
}
int listadoPerrosConRacion(LinkedList* listadoPerros){
	int retorno =-1;
	ePerrito* pPerro = NULL;
	if(listadoPerros!=NULL){
		printf("%-10s %-21s %-10s %-10s %-21s %-10s\n","ID","Nombre","Peso","Edad","Raza","Racion");
		for(int i=0;i<ll_len(listadoPerros);i++){
			pPerro = ll_get(listadoPerros, i);
			printf("%-10d %-21s %-10.2f %-10d %-21s %-10.2f\n",pPerro->id,pPerro->nombre,pPerro->peso,pPerro->edad,pPerro->raza,pPerro->cantidadComidaRacion);
		}
		retorno = 0;
	}
    return retorno;
}

int guardarGalgos(char* path , LinkedList* listadoGalgos){
	int retorno =-1;
	ePerrito* galgo = NULL;
	FILE* pFile;
	if(path != NULL && listadoGalgos!=NULL){
		pFile = fopen(path,"w");
		if(pFile!=NULL){
			for(int i=0;i<ll_len(listadoGalgos);i++){
				galgo = ll_get(listadoGalgos, i);
				fprintf(pFile,"%d,%s,%f,%d,%s,%f\n",galgo->id,galgo->nombre,galgo->peso,galgo->edad,galgo->raza,galgo->cantidadComidaRacion);//Datos
			}
			printf("Galgos cargados en %s con exito\n",path);
			fclose(pFile);
			pFile = NULL;
			retorno =0;
		}
	}
    return retorno;
}

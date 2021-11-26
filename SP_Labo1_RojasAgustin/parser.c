/*
 * parser.c
 *
 *  Created on: 19 nov. 2021
 *      Author: Usuario
 */
#include "parser.h"
int parserTexto(FILE* pFile , LinkedList* listadoPerros){
	int retorno =-1;
	char* nombre = (char*)malloc(sizeof(char)*25);
	char* id = (char*)malloc(sizeof(char)*10);
	char* peso = (char*)malloc(sizeof(char)*10);
	char* edad = (char*)malloc(sizeof(char)*10);
	char* raza = (char*)malloc(sizeof(char)*10);
	if(listadoPerros != NULL){
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]", id, nombre,peso,edad,raza);
		while(!feof(pFile)){
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]", id, nombre,peso,edad,raza);
			if(feof(pFile)){
				break;
			}
			ePerrito* unPerro = ePerrito_constructorParam(atoi(id), nombre, atoi(edad), raza,atof(peso));
			 if(unPerro != NULL){
				 ll_add(listadoPerros, unPerro);
				 retorno=0;
			 }
		}
		fclose(pFile);
		if(retorno ==0){
			printf("Perros agregados con exito.\n");
		}
	}
    return retorno;
}



/*
 ============================================================================
 Name        : segundoparcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 .
 */


#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "ll.h"
#include "abm.h"
#include "perros.h"

int main(void) {
	setbuf(stdout,NULL);
    int option = 0;
	int (*pSort) (void*,void*);
    int banderaCarga = 0;
    int banderaMapeado = 0;
    LinkedList* listaPerros = ll_newLinkedList();
    LinkedList* listaGalgos = NULL;
    do{
    	option = getInteger("------------------------\n"
							"1-Cargar los datos de los perros desde el archivo perritos.csv \n"
							"2-Listar perros ascendente por nombre\n"
							"3-Agregar las raciones de comida (mapeo)\n"
							"4-Listar perros con raciones\n"
							"5-Filtrar galgos\n"
							"6-Guardar galgos en galgosFlaquitos.csv\n"
							"7-Salir\n"
							"Elija una opcion: ", "\nError. Ingrese una opcion entre 1 y 7", 1, 7);

        switch(option)
        {
            case 1:
            	if(banderaCarga == 0){
            		cargarTexto("perritos.csv", listaPerros);
            		banderaCarga = 1;
            	}
            	else{
            		printf("Ya se han cargado los datos\n");
            	}
            	system("pause");
                break;
            case 2:
            	if(ll_len(listaPerros) > 0){
            		pSort = ePerrito_sortearPorNombre;
            		printf("Ordenando los perros, esto puede tardar un rato.\n");
            		ll_sort(listaPerros, pSort, 1);
            		listadoPerros(listaPerros);
            	}
            	else{
            		printf("No hay perros cargados\n");
            	}
            	system("pause");
            	break;
            case 3:
            	if(ll_len(listaPerros) > 0){
            		ll_map(listaPerros, ePerrito_laQueMapea);
            		banderaMapeado = 1;
            		printf("Se calcularon las raciones de comida de los perros\n");
            	}
            	else{
            		printf("No hay perros cargados\n");
            	}
            	system("pause");
            	break;
            case 4:
            	if(ll_len(listaPerros) > 0){
            		if(banderaMapeado == 1){
            			listadoPerrosConRacion(listaPerros);
            		}
            		else{
            			printf("No se mapeo todavia.\n");
            		}
            	}
            	else{
            		printf("No hay perros cargados\n");
            	}
            	system("pause");
            	break;
            case 5:
				if(ll_len(listaPerros) > 0){
					if(banderaMapeado == 1){
						listaGalgos = ePerrito_generarListaDeGalgos(listaPerros);
						printf("Estos son los galgos que cumplen los requisitos:  \n");
						listadoPerrosConRacion(listaGalgos);
					}
					else{
						printf("No se mapeo todavia.\n");
					}
					system("pause");
					break;
            	}
            	else{
            		printf("No hay perros cargados\n");
            	}
            	system("pause");
            	break;
            case 6:
            	if(ll_len(listaPerros) > 0){
            		if(ll_len(listaGalgos) > 0){
            			guardarGalgos("galgosFlaquitos.csv", listaGalgos);
            		}
            		else{
            			printf("No se filtraron los galgos todavia\n");
            		}
            	}
            	else{
            		printf("No hay perros cargados\n");
            	}
            	system("pause");
            	break;
            case 7:
            	ll_deleteLinkedList(listaPerros);
            	break;
        }
    }while(option != 7);
	return EXIT_SUCCESS;
}

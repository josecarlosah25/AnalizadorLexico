#include <stdio.h>
#include <stdlib.h>


int numClave = 0;

typedef struct{
	int clave;
	char* palabra;
	Nodo* siguiente;
}Nodo;

typedef struct{
	Nodo* head = NULL;
	head->siguiente = NULL;

}Lista;

void insertar(Lista* listaActual, char* valor){
	Nodo* temp = listaActual->head;
	Nodo* actual = (Nodo *)malloc(sizeof(Node));

	if(temp == NULL){
		actual->clave = numClave;
		actual->palabra = valor;
		actual->siguiente = temp;
		temp = actual;
		temp->siguiente = NULL;

	}

	while(temp != NULL){
		if(temp->siguiente == NULL){
			actual->clave = numClave + 1;
			actual->palabra = valor;
			actual->siguiente = temp;
			temp->siguiente = actual;
		}
		temp = temp->siguiente;

	}

}

void imprimirLista(Lista* listaActual){
	Nodo* 
}


Nodo* crearLista(int cantidadNodos, Lista listaActual){
	Nodo* head = NULL;
	Nodo* temp = NULL;

	for(int i = 0; i < cantidadNodos; i++){
		temp = (Nodo*)malloc(sizeof(Nodo));

	}
}


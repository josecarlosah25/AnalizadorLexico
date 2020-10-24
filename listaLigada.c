#include <stdio.h>
#include <stdlib.h>

int numClave = 0;

typedef struct Nodo{
	int clave;
	char* palabra;
	struct Nodo* siguiente;
}Nodo;

typedef struct {
	Nodo* head;

}Lista;

Lista crearLista(){
	Lista lista;
	lista.head = NULL;
	return lista;
}

void insertar(Lista* listaActual, char* valor){
	Nodo* temp = listaActual->head;
	Nodo* actual = (Nodo *)malloc(sizeof(Nodo));

	if(temp == NULL){
		actual->clave = numClave;
		actual->palabra = valor;
		actual->siguiente = NULL;
		listaActual->head = actual;
		//printf("Si inserte\n");
	}
	else{
		while(temp->siguiente != NULL)
			temp = temp->siguiente;
			//if(temp->siguiente == NULL){
		numClave++;
		actual->clave = numClave;
		actual->palabra = valor;
		actual->siguiente = NULL;
		temp->siguiente = actual;
		//printf("Si inserte\n");
			
	}
	

}

void imprimirLista(Lista listaActual){
	
	if (listaActual.head == NULL)
		printf("Lista vacia\n");
	else{
		Nodo* ptr = listaActual.head;
		while(ptr!= NULL){
			printf("%d -> %s\n", ptr->clave, ptr->palabra);
			ptr = ptr->siguiente;
		}
	}
}

void busqueda(Lista* listaActual, int dato){
    Nodo *temp = listaActual->head;
    while (temp != NULL) {
        if (temp->clave == dato){
            printf("\n Se encuentra el numero %d en la lista \n", dato);
            break;
        }
        else
            temp = temp->siguiente;
    }
}

int main(){
	Lista tabla = crearLista();
	insertar(&tabla, "hola");
	insertar(&tabla, "buenos");
	insertar(&tabla, "dias");
	insertar(&tabla, "a");
	insertar(&tabla, "todos");
	imprimirLista(tabla);
}
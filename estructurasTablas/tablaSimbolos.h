#include <stdio.h>
#include <stdlib.h>

typedef struct NodoSimb{
	int clave;
	char* nombre;
	int tipo;
	struct NodoSimb* siguiente;
}NodoSimb;

typedef struct {
	NodoSimb* head;

}TablaSimbolos;

TablaSimbolos crearTablaSimbolos(){
	TablaSimbolos tablaSimbolos;
	tablaSimbolos.head = NULL;
	return tablaSimbolos;
}

int insertarTablaSimbolos(TablaSimbolos* tabSimbActual, char* valor){
	NodoSimb* temp = tabSimbActual->head;
	NodoSimb* actual = (NodoSimb *)malloc(sizeof(NodoSimb));

	if(temp == NULL){
		actual->clave = 0;
		actual->nombre = valor;
		actual->siguiente = NULL;
		actual->tipo = -1;
		tabSimbActual->head = actual;
		//printf("La posicion que ocupa la cadena en la tabla es: %d\n", actual->clave);
		return actual->clave;
	}
	else{
		while(temp->siguiente != NULL)
			temp = temp->siguiente;

		actual->clave = temp->clave + 1;
		actual->nombre = valor;
		actual->siguiente = NULL;
		actual->tipo = -1;
		temp->siguiente = actual;
		//printf("La posicion que ocupa la cadena en la tabla es: %d\n", actual->clave);
		return actual->clave;
	}
	

}

void imprimirTablaSimbolos(TablaSimbolos tabSimbActual){
	
	if (tabSimbActual.head == NULL)
		printf("La tabla esta vacia\n");
	else{
		NodoSimb* actual = tabSimbActual.head;
		printf("\nPosicion \t_ \tNombre \t_ \tTipo\n");
		while(actual!= NULL){
			printf(" %d \t\t| \t %s \t\t| \t %d\n", actual->clave, actual->nombre, actual->tipo);
			actual = actual->siguiente;
		}
	}
}

int buscarTablaSimbolos(TablaSimbolos* tabSimbActual, char* cadena){
    NodoSimb *temp = tabSimbActual->head;
    while (temp != NULL) {
        if (temp->nombre == cadena){
            //printf("\nSe encuentra la palabra %s en el Tabla de Simbolos y su clave es %d \n", cadena, temp->clave);
            return temp->clave;
            //break;
        }
        else
            temp = temp->siguiente;
    }
    return -1;
}


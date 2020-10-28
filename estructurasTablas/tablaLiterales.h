#include <stdio.h>
#include <stdlib.h>

typedef struct NodoLit{
	int clave;
	char* cadena;
	struct NodoLit* siguiente;
}NodoLit;

typedef struct {
	NodoLit* head;

}TablaLiterales;

TablaLiterales crearTablaLiterales(){
	TablaLiterales tablaLit;
	tablaLit.head = NULL;
	return tablaLit;
}

int insertarTablaLiterales(TablaLiterales* tablaLit, char* valor){
	NodoLit* temp = tablaLit->head;
	NodoLit* actual = (NodoLit *)malloc(sizeof(NodoLit));

	if(temp == NULL){
		actual->clave = 0;
		actual->cadena = valor;
		actual->siguiente = NULL;
		tablaLit->head = actual;
		//printf("La posicion que ocupa la cadena en la tabla es: %d\n", actual->clave);
		return actual->clave;
	}
	else{
		while(temp->siguiente != NULL)
			temp = temp->siguiente;

		actual->clave += temp->clave + 1;
		actual->cadena = valor;
		actual->siguiente = NULL;
		temp->siguiente = actual;
		printf("La posicion que ocupa la cadena en la tabla es: %d\n", actual->clave);
		return actual->clave;
			
	}
	

}

void imprimirTablaLiterales(TablaLiterales tablaLit){
	
	if (tablaLit.head == NULL)
		printf("La tabla esta vacia\n");
	else{
		NodoLit* actual = tablaLit.head;
		printf("\nPosicion \t_ \tCadena\n");
		while(actual!= NULL){
			printf(" %d \t\t| \t %s\n", actual->clave, actual->cadena);
			actual = actual->siguiente;
		}
	}
}


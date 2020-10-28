#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NodoOp{
	int clave;
	char caracteres[2];
	struct NodoOp* siguiente;
}NodoOp;

typedef struct {
	NodoOp* head;

}TablaOperadores;

TablaOperadores crearTablaOperadores(){
	TablaOperadores tabOperadores;
	tabOperadores.head = NULL;
	return tabOperadores;
}

void insertarTablaOperadores(TablaOperadores* tabOpActual, char valor[2]){
	NodoOp* temp = tabOpActual->head;
	NodoOp* actual = (NodoOp *)malloc(sizeof(NodoOp));

	if(temp == NULL){
		actual->clave = 0;
		strcpy(actual->caracteres, valor);
		actual->siguiente = NULL;
		tabOpActual->head = actual;
	}
	else{
		while(temp->siguiente != NULL)
			temp = temp->siguiente;

		actual->clave = temp->clave + 1;
		strcpy(actual->caracteres, valor);
		actual->siguiente = NULL;
		temp->siguiente = actual;
	}
	

}

void imprimirTablaOperadores(TablaOperadores tabOpActual){
	
	if (tabOpActual.head == NULL)
		printf("La tabla esta vacia\n");
	else{
		NodoOp* actual = tabOpActual.head;
		printf("\nPosicion \t_ \tCaracter\n");
		while(actual!= NULL){
			printf(" %d \t\t| \t %s\n", actual->clave, actual->caracteres);
			actual = actual->siguiente;
		}
	}
}

char buscarTablaOperadores(TablaOperadores* tabOpActual, char operador[2]){
    NodoOp *temp = tabOpActual->head;
    while (temp != NULL) {
        if (temp->caracteres == operador){
        	if(strcmp(operador, "**") == 0){
        		int clavePotencia = 0;
        		printf("\nSe encuentra el simbolo %s en la Tabla de Operadores y su clave es %d \n", operador, clavePotencia);
        		return clavePotencia;
        		//break;
        	}
        	else{
            	printf("\nSe encuentra el simbolo %c en la Tabla de Operadores y su simbolo es %s \n", operador[0], temp->caracteres);
            	return temp->caracteres;
            	//break;
        	}
        }
        else
            temp = temp->siguiente;
    }

    return 'F';
}


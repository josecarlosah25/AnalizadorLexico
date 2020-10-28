#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NodoCat{
	int clave;
	char* contenido;
	struct NodoCat* siguiente;
}NodoCat;

typedef struct {
	NodoCat* head;

}Catalogo;

Catalogo crearCatalogo(){
	Catalogo catalogo;
	catalogo.head = NULL;
	return catalogo;
}

void insertarCatalogo(Catalogo* catActual, char* valor){
	NodoCat* temp = catActual->head;
	NodoCat* actual = (NodoCat *)malloc(sizeof(NodoCat));

	if(temp == NULL){
		actual->clave = 0;
		actual->contenido = valor;
		actual->siguiente = NULL;
		catActual->head = actual;
	}
	else{
		while(temp->siguiente != NULL)
			temp = temp->siguiente;

		actual->clave = temp->clave + 1;
		actual->contenido = valor;
		actual->siguiente = NULL;
		temp->siguiente = actual;
			
	}
	

}

void imprimirCatalogo(Catalogo catActual){
	
	if (catActual.head == NULL)
		printf("La tabla esta vacia\n");
	else{
		NodoCat* actual = catActual.head;
		printf("\nPosicion \t_ \tContenido\n");
		while(actual!= NULL){
			printf(" %d \t\t| \t %s\n", actual->clave, actual->contenido);
			actual = actual->siguiente;
		}
	}
}

int buscarCatalogo(Catalogo* catActual, char* cadena){
    NodoCat *temp = catActual->head;
    while (temp != NULL) {
        if (strcmp(temp->contenido,cadena)==0){
            printf("\nSe encuentra el valor %s en el catalogo y su clave es %d \n", cadena, temp->clave);
            return temp->clave;
            break;
        }
        else
            temp = temp->siguiente;
    }
return -1;
}


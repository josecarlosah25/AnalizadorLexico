#include <stdio.h>
#include <stdlib.h>
#include "catalogos.h"
#include "tablaLiterales.h"
#include "tablaCaracteres.h"
#include "tablaOpAritmeticos.h"
#include "tablaSimbolos.h"

Catalogo generarTabPalabrasRes(){
	Catalogo palReserv = crearCatalogo();

	insertarCatalogo(&palReserv, "bool");
	insertarCatalogo(&palReserv, "break");
	insertarCatalogo(&palReserv, "case");
	insertarCatalogo(&palReserv, "char");
	insertarCatalogo(&palReserv, "continue");
	insertarCatalogo(&palReserv, "default");
	insertarCatalogo(&palReserv, "do");
	insertarCatalogo(&palReserv, "else");
	insertarCatalogo(&palReserv, "float");
	insertarCatalogo(&palReserv, "for");
	insertarCatalogo(&palReserv, "if");
	insertarCatalogo(&palReserv, "int");
	insertarCatalogo(&palReserv, "return");
	insertarCatalogo(&palReserv, "string");
	insertarCatalogo(&palReserv, "switch");
	insertarCatalogo(&palReserv, "while");
	insertarCatalogo(&palReserv, "void");

	return palReserv;
}

Catalogo generarTabOpRelacionales(){
	Catalogo tabOpRel = crearCatalogo();

	insertarCatalogo(&tabOpRel, "!=");
	insertarCatalogo(&tabOpRel, "==");
	insertarCatalogo(&tabOpRel, ">");
	insertarCatalogo(&tabOpRel, "<");
	insertarCatalogo(&tabOpRel, ">=");
	insertarCatalogo(&tabOpRel, "<=");

	return tabOpRel;
}

TablaCaracteres generarTabSimbEspecial(){
	TablaCaracteres tabSimbEsp = crearTablaCaracteres();

	insertarTablaCaracteres(&tabSimbEsp, '{');
	insertarTablaCaracteres(&tabSimbEsp, '}');
	insertarTablaCaracteres(&tabSimbEsp, ',');
	insertarTablaCaracteres(&tabSimbEsp, ':');
	insertarTablaCaracteres(&tabSimbEsp, '(');
	insertarTablaCaracteres(&tabSimbEsp, ')');
	insertarTablaCaracteres(&tabSimbEsp, '[');
	insertarTablaCaracteres(&tabSimbEsp, ']');

	return tabSimbEsp;
}

TablaCaracteres generarTabOpAsignacion(){
	TablaCaracteres tabOpAsig = crearTablaCaracteres();

	insertarTablaCaracteres(&tabOpAsig, '=');

	return tabOpAsig;
}

TablaOperadores generarTabOpAritmeticos(){
	TablaOperadores tabOpArit = crearTablaOperadores();

	insertarTablaOperadores(&tabOpArit, "+");
	insertarTablaOperadores(&tabOpArit, "-");
	insertarTablaOperadores(&tabOpArit, "*");
	insertarTablaOperadores(&tabOpArit, "/");
	insertarTablaOperadores(&tabOpArit, "%");
	insertarTablaOperadores(&tabOpArit, "**");
	insertarTablaOperadores(&tabOpArit, "]");

	return tabOpArit;
}


int main(){
	Catalogo palReserv = generarTabPalabrasRes();
	Catalogo opRel = generarTabOpRelacionales();
	TablaCaracteres simbEsp = generarTabSimbEspecial();
	TablaCaracteres opAsig = generarTabOpAsignacion();
	TablaOperadores opArit = generarTabOpAritmeticos();

	imprimirCatalogo(palReserv);
	imprimirCatalogo(opRel);
	imprimirTablaCaracteres(simbEsp);
	imprimirTablaCaracteres(opAsig);
	imprimirTablaOperadores(opArit);

	TablaLiterales ctesReales = crearTablaLiterales();
	TablaLiterales cadenas = crearTablaLiterales();
	TablaSimbolos tabSimb = crearTablaSimbolos();

	insertarTablaLiterales(&cadenas, "La");
	insertarTablaLiterales(&cadenas, "Neta");
	insertarTablaLiterales(&cadenas, "No");
	insertarTablaLiterales(&cadenas, "Me");
	insertarTablaLiterales(&cadenas, "Gusta");
	insertarTablaLiterales(&cadenas, "Como");
	insertarTablaLiterales(&cadenas, "Se");
	insertarTablaLiterales(&cadenas, "Da");
	insertarTablaLiterales(&cadenas, "Esta");
	insertarTablaLiterales(&cadenas, "Materia");

	imprimirTablaLiterales(cadenas);


}

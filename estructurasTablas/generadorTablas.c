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

	return tabOpArit;
}



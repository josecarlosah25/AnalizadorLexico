%{
#include <string.h>
#include <stdlib.h>
#include "estructurasTablas/generadorTablas.c"

/*Programa que lee un programa y hace el reconocimiento del lenguaje
	definido por la clase

Elaborado por : 
	-Alcántara Hoyos José Carlos
	-Vargas Guerrero Armando
*/

FILE *archSal;
char* tmp;
int clase;
int valor;
Catalogo palReserv;
Catalogo opRel;
TablaCaracteres simbEsp;
TablaCaracteres opAsig;
TablaOperadores opArit;
TablaLiterales ctesReales;
TablaLiterales cadenas;
TablaLiterales ctesEnteras;
TablaSimbolos tabSimb;
%}

/*Expresiones regulares recurrentes*/
whatEver [^""]
dig [0-9]
letras [a-zA-Z]
/*Definimos las cosas que omitimos*/
tab \t
salto \n
spaceBar (\ )
comment @[^\n]*{salto}
omite {tab}|{salto}|{spaceBar}
/*Definimos las palabras reservadas*/
pR1 (bool)|(break)|(case)|(char)|(continue)|(default)
pR2 (else)|(float)|(for)|(if)|(int)|(return)|(string)|(switch)
pR3 (do)|(while)|(void)
palRes {pR1}|{pR2}|{pR3}
/*Definimos operadores relacionales*/
opRel (!=)|(==)|(>)|(<)|(>=)|(<=)
/*Definimos simbolos especiales*/
simbEsp (\{)|(\})|(,)|(:)|(\()|(\))|(\[)|(\])
/*Definimos el op de asignacion*/
asig =
/*Definimos op aritmeticos*/
opArit (\+)|(\-)|(\*)|(\/)|(\*\*)|(%)
/*Definimos las constantes numéricas enteras*/
cNumEnt {dig}{1,14}
/*Definimos las constantes numéricas reales*/
dot \.
notCien (E|e)((-?)|(\+?)){dig}{1,5}
cNumReal {dig}{1,10}{dot}({dig}{1,10}{notCien}?)
/*Definimos las cadenas*/
str \"{whatEver}*\"
/*Definimos los identificadores*/
ident {letras}({letras}|{dig}|_)*
%%
{palRes} {clase=1; valor=buscarCatalogo(&palReserv,yytext);
fprintf(archSal,"(%d,%d)\n",clase,valor);}
{opRel} {clase=5; valor=buscarCatalogo(&opRel,yytext);
fprintf(archSal,"(%d,%d)\n",clase,valor);}
{simbEsp} {clase=2; valor=buscarTablaCaracteres(&simbEsp,yytext[0]);
fprintf(archSal,"(%d,%d)\n",clase,valor);}
{asig} {clase=4; valor=buscarTablaCaracteres(&opAsig,yytext[0]);
fprintf(archSal,"(%d,%d)\n",clase,valor);}
{opArit} {clase=8;
fprintf(archSal,"(%d,%c)\n",clase,buscarTablaOperadores(&opArit,yytext));}
{cNumReal} {clase=0; 
tmp=(char *)malloc(strlen(yytext)*sizeof(char));
strcpy(tmp,yytext);
valor=insertarTablaLiterales(&ctesReales,tmp);
fprintf(archSal,"(%d,%d)\n",clase,valor);}
{str} {clase=7; 
tmp=(char *)malloc(strlen(yytext)*sizeof(char));
strcpy(tmp,yytext);
valor=insertarTablaLiterales(&cadenas,tmp);
fprintf(archSal,"(%d,%d)\n",clase,valor);}
{comment}|{omite} {}
{cNumEnt} {clase=6; 
tmp=(char *)malloc(strlen(yytext)*sizeof(char));
strcpy(tmp,yytext);
/*valor=insertarTablaLiterales(&ctesEnteras,tmp);*/
fprintf(archSal,"(%d,%d)\n",clase,atoi(tmp));}
{ident} {clase=3; 
tmp=(char *)malloc(strlen(yytext)*sizeof(char));
strcpy(tmp,yytext);
if(buscarTablaSimbolos(&tabSimb,tmp)!=-1){
	valor=buscarTablaSimbolos(&tabSimb,tmp);
}else{
	valor=insertarTablaSimbolos(&tabSimb,tmp);
}
fprintf(archSal,"(%d,%d)\n",clase,valor);}
%%
int main(int argc,char *argv[])
{
	palReserv = generarTabPalabrasRes();
	opRel = generarTabOpRelacionales();
	simbEsp = generarTabSimbEspecial();
	opAsig = generarTabOpAsignacion();
	opArit = generarTabOpAritmeticos();

	imprimirCatalogo(palReserv);
	imprimirCatalogo(opRel);
	imprimirTablaCaracteres(simbEsp);
	imprimirTablaCaracteres(opAsig);
	imprimirTablaOperadores(opArit);

	ctesReales = crearTablaLiterales();
	cadenas = crearTablaLiterales();
	ctesEnteras = crearTablaLiterales();
	tabSimb = crearTablaSimbolos();

	yyin=fopen(argv[1],"r");
	archSal=fopen("salida.txt","w");
	fprintf(archSal, "-----TOKENS GENERADOS----\n");
	yylex();
	imprimirTablaLiterales(cadenas, archSal);
	imprimirTablaLiterales(ctesEnteras, archSal);
	imprimirTablaLiterales(ctesReales, archSal);
	imprimirTablaSimbolos(tabSimb, archSal);


	close(archSal);
}

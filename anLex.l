%{
#include "estructurasTablas/catalogos.h"
#include "estructurasTablas/tablaLiterales.h"
#include "estructurasTablas/tablaCaracteres.h"
#include "estructurasTablas/tablaOpAritmeticos.h"
#include "estructurasTablas/tablaSimbolos.h"

/*Programa que lee un programa y hace el reconocimiento del lenguaje
	definido por la clase

Elaborado por : 
	-Alcántara Hoyos José Carlos
	-Vargas Guerrero Armando
*/

FILE *archSal;
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
{palRes} {fprintf(archSal,"%s: es una palabra reservada\n",yytext);}
{opRel} {fprintf(archSal,"%s: es un operador relacional\n",yytext);}
{simbEsp} {fprintf(archSal,"%s: es un simbolo especial\n",yytext);}
{asig} {fprintf(archSal,"%s: es el simbolo de asignación\n",yytext);}
{opArit} {fprintf(archSal,"%s: es un operador aritmetico\n",yytext);}
{cNumReal} {fprintf(archSal,"%s: Es un numero real valido\n",yytext);}
{str} {fprintf(archSal,"%s: esto es una cadena\n",yytext);}
{comment} {fprintf(archSal,"%s: esto es un comment\n",yytext);}
{cNumEnt} {fprintf(archSal,"%s: esto es un numero entero\n",yytext);}
{ident} {fprintf(archSal,"%s: es un identificador\n",yytext);}
%%
main(int argc,char *argv[])
{
	yyin=fopen(argv[1],"r");
	archSal=fopen("salida.txt","w");
	yylex();
	close(archSal);
}

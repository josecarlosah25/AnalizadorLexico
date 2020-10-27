%{
/*Programa que lle un programa y hace el reconocimiento de 
	constantes enteras del lenguaje C
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
{cNumReal} {fprintf(archSal,"%s: Es un numero real valido\n",yytext);}
{omite} {fprintf(archSal,"%s: omitido\n",yytext);}
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

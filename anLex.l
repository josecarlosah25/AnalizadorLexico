%{
/*Programa que lle un programa y hace el reconocimiento de 
	constantes enteras del lenguaje C
Elaborado por : 
	-Alcántara Hoyos José Carlos
	-Vargas Guerrero Armando
*/
%}
/*Expresiones regulares recurrentes*/
whatEver [^""]
dig [0-9]
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
/*Def*/
%%
{cNumReal} {printf("Es un numero real valido\n");}
{omite} {printf("voy a omitir algo\n");}
{str} {printf("esto es una cadena\n");}
{comment} {printf("esto es un comment");}
{cNumEnt} {printf("esto es un numero entero");}
%%
main()
{
	yylex();
}

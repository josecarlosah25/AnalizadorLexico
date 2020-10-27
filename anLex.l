%{
/*Programa que lle un programa y hace el reconocimiento de 
	constantes enteras del lenguaje C
Elaborado por : 
	-Alcántara Hoyos José Carlos
	-Vargas Guerrero Armando
*/
%}
/*Definimos las cosas que omitimos*/
tab \t
salto \n
spaceBar (\ )
omite {tab}|{salto}|{spaceBar}
/*Definimos las constantes numéricas reales*/
dig [0-9]
dot \.
notCien (E|e)((-?)|(\+?)){dig}{1,5}
cNumReal {dig}{1,10}{dot}({dig}{1,10}{notCien}?)
%%
{cNumReal} {printf("Es un numero real valido\n");}
{omite} {}
%%
main()
{
	yylex();
}


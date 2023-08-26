#include <stdio.h>
#include <stdlib.h>

int registro();
void lectura();
int ingresar();


void main(){
	int op,exit=1;
	while(exit==1){
	printf("\n\nIntroduzca una opcion\n1- Escribir\n2- Leer\n3- Ingresar contrasena\n4- Salir\n\n");
	scanf("%d", &op);
	switch(op){
	case 1:
		registro();
		break;
	case 2:
		lectura();
		break;
	case 3:
		ingresar();
		break;
	case 4:
		exit=2;
		break;
	}
}
}

void lectura(){
char p1;
FILE *ar;
if ((ar = fopen("ARCHIVO.txt", "r")) != NULL)
{
	printf("La informacion dentro del archivo es:\t");
	while (feof(ar)==0)
/* Se leen caracteres del archivo mientras no se detecte el fin del
?archivo. */
{
p1 = fgetc(ar); /* Lee el caracter del archivo. */
printf("%c",p1); /* Despliega el caracter en la pantalla. */
}
fclose(ar);
}
else
printf("No se puede abrir el archivo");
}

int registro()
{
fflush(stdin);	
FILE *ar;
char cadena[150];
char documento[]="ARCHIVO.txt";


if ((ar = fopen(documento, "w")))
    {
    	printf("\nIntroduzca el nuevo texto: \n");
        gets(cadena);
        fprintf(ar, "%s", cadena);
        fclose(ar);
        printf("la cadena se ha actualizado exitosamente");
        printf("\nla nueva cadena es: %s\n\n", cadena);
    }
fflush(stdin);	
}

int ingresar(){
fflush(stdin);
char p1,p2;
FILE *ar;
if ((ar = fopen("ARCHIVO.txt", "r")) != NULL)
{
	while (!feof(ar)==0)
/* Se leen caracteres del archivo mientras no se detecte el fin del
?archivo. */
{
p1 = fgetc(ar); /* Lee el caracter del archivo. */
}
	printf("Ingrese la contrasena:");
	gets(&p2);
	if (p1==p2)
	printf("Tiene acceso");
	else
	printf("Clave incorrecta");
fclose(ar);
}
else
printf("No se puede abrir el archivo");
}


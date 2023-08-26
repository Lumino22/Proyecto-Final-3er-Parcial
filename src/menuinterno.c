void pensum(){
	int pensum;
	printf("\n\t\tPENSUM\n\n");
	printf("Elige la carrera que quiere buscar: \n1- Ingenieria Electrica\n2- Ingenieria Industrial\n3- Ingieneria en sistema\n\n");
	scanf("%d",&pensum);
	switch (pensum){
		case 1:
			printf("\tPrimer cuatrimeste\n Lengua Espanola 1\n Hist. de la tec. electr.\n Ofimatica\n Precalculo\n\n");
			printf("\tSegundo cuatrimeste\n Lengua Espanola 2\n Electricidad Basica\n Taller de electricidad Basica\n calculo\n Tecnologia de la inform. y com.\n\n");
			printf("\tTercer cuatrimeste\n Redaccion Profesional\n 1\n Taller de circ. Elect. 1\n calculo 2\n Ingles 2\n\n");
			printf("\tCuarto cuatrimeste\n Fundamentos de estadistica\n Circuitos Elect 2\n Taller de circ. Elect. 2\n calculo 3\n Ingles 3\n\n");
			printf("\tQuinto cuatrimeste\n Inst. Electricas\n Taller Inst. Elect.\n Electronica 1\n Taller Electronica 1\n Calculo 4\n\n");
			break;
		case 2:
			printf("\tPrimer cuatrimeste\n Lengua Espanola 1\n Geometria Descriptiva\n Ofimatica\n Precalculo\n Introd. a la ing. Indust.\n\n");
			printf("\tSegundo cuatrimeste\n Lengua Espanola 2\n Algoritmo computacional\n Reflexion Filosofica\n calculo\n\n");
			printf("\tTercer cuatrimeste\n Redaccion Profesional\n Seguridad e Higiene Indus.\n Logica Matematica\n calculo 2\n Ingles 2\n\n");
			printf("\tCuarto cuatrimeste\n Fundamentos de estadistica\n Inform. Aplicada IID\n Temas de Histroia Dominicana\n calculo 3\n Ingles 3\n\n");
			printf("\tQuinto cuatrimeste\n Diseño y Dibujo Indus.\n Procesos Industriales\n Taller de Procesos Indus.\n Algebra Lineal\n Calculo 4\n");
			break;
		case 3:
			printf("\tPrimer cuatrimeste\n Lengua Espanola 1\n Algoritmos computacionales\n Orientacion Universitaria\n Precalculo\n\n");
			printf("\tSegundo cuatrimeste\n Lengua Espanola 2\n Logica computacional\n Reflexion Filosofica\n calculo\n\n");
			printf("\tTercer cuatrimeste\n Redaccion Profesional\n Analisis de sistemas\n Logica Matematica\n calculo 2\n Ingles 2\n\n");
			printf("\tCuarto cuatrimeste\n Fundamentos de estadistica\n Inform. Aplicada IID\n Temas de Histroia Dominicana\n calculo 3\n Ingles 3\n\n");
			printf("\tQuinto cuatrimeste\n Analisis computacional 2\n Estudio del trabajo\n Lab de Estudio del trabajo\n calculo\n Tecnologia de la inform. y com.\n\n");
			break;
		default: printf("La opcion seleccionada no es valida");
	}
}


void lectura(){
char p1;
FILE *ar;
if ((ar = fopen("ARCHIVO.txt", "r")) != NULL) 
{
	while (!feof(ar))
{
p1 = fgetc(ar); /* Lee el caracter del archivo. */
putchar(p1); /* Despliega el caracter en la pantalla. */
}
fclose(ar);
}
else
printf("No se puede abrir el archivo");
}


void escritura(){
	FILE *archivo;
char cadena[10];
char documento[]="ARCHIVO.txt";


if ((archivo = fopen(documento, "w+")))
    {
    	fflush(stdin);
    	printf("\nIntroduzca el proximo cuatrimeste a inscribir");
        gets(cadena);
        if(strcmp(cadena,"1\0")==0)
        	printf("Materias:\n\tPrimer cuatrimeste\n Lengua Espanola 1\n Hist. de la tec. electr.\n Ofimatica\n Precalculo\n\n");
        if(strcmp(cadena,"2\0")==0)
        	printf("Materias:\n\tSegundo cuatrimeste\n Lengua Espanola 2\n Electricidad Basica\n Taller de electricidad Basica\n calculo\n Tecnologia de la inform. y com.\n\n");
        if(strcmp(cadena,"3\0")==0)
        	printf("Materias:\n\tTercer cuatrimeste\n Redaccion Profesional\n 1\n Taller de circ. Elect. 1\n calculo 2\n Ingles 2\n\n");
        if(strcmp(cadena,"4\0")==0) 
        	printf("Materias:\n\tCuarto cuatrimeste\n Fundamentos de estadistica\n Circuitos Elect 2\n Taller de circ. Elect. 2\n calculo 3\n Ingles 3\n\n");
        if(strcmp(cadena,"5\0")==0) 
        	printf("Materias:\n\tQuinto cuatrimeste\n Inst. Electricas\n Taller Inst. Elect.\n Electronica 1\n Taller Electronica 1\n Calculo 4\n\n");
        fprintf(archivo, "%s", cadena);
        fclose(archivo);
        printf("Se ha inscrito exitosamente");
        printf("\nSu nuevo ciclo es el: %s\n\n", cadena);
    }


if((archivo=fopen(documento, "rt"))==NULL)
   printf("ha ocurrido un error al abrir el archivo\n",documento);
fclose(archivo); 
}




void lectura1(){
char p1;
FILE *ar;
if ((ar = fopen("ARCHIVO1.txt", "r")) != NULL) 
{
	while (!feof(ar))
{
p1 = fgetc(ar); /* Lee el caracter del archivo. */
putchar(p1); /* Despliega el caracter en la pantalla. */
}
fclose(ar);
}
else
printf("No se puede abrir el archivo");
}


void escritura1(){
	FILE *archivo;
char cadena[10];
char documento[]="ARCHIVO1.txt";


if ((archivo = fopen(documento, "w+")))
    {
    	fflush(stdin);
    	printf("\nIntroduzca el proximo cuatrimeste a inscribir");
        gets(cadena);
        if(strcmp(cadena,"1\0")==0)
        	printf("Materias:\n\tPrimer cuatrimeste\n Lengua Espanola 1\n Geometria Descriptiva\n Ofimatica\n Precalculo\n Introd. a la ing. Indust.\n\n");
        if(strcmp(cadena,"2\0")==0)
        	printf("Materias:\n\tSegundo cuatrimeste\n Lengua Espanola 2\n Algoritmo computacional\n Reflexion Filosofica\n calculo\n\n");
        if(strcmp(cadena,"3\0")==0)
        	printf("Materias:\n\tTercer cuatrimeste\n Redaccion Profesional\n Seguridad e Higiene Indus.\n Logica Matematica\n calculo 2\n Ingles 2\n\n");
        if(strcmp(cadena,"4\0")==0) 
        	printf("Materias:\n\tCuarto cuatrimeste\n Fundamentos de estadistica\n Inform. Aplicada IID\n Temas de Histroia Dominicana\n calculo 3\n Ingles 3\n\n");
        if(strcmp(cadena,"5\0")==0) 
        	printf("Materias:\n\tQuinto cuatrimeste\n Inst. Electricas\n Taller Inst. Elect.\n Electronica 1\n Taller Electronica 1\n Calculo 4\n\n");
        fprintf(archivo, "%s", cadena);
        fclose(archivo);
        printf("Se ha inscrito exitosamente");
        printf("\nSu nuevo ciclo es el: %s\n\n", cadena);
    }


if((archivo=fopen(documento, "rt"))==NULL)
   printf("ha ocurrido un error al abrir el archivo\n",documento);
fclose(archivo); 
}




void lectura2(){
char p1;
FILE *ar;
if ((ar = fopen("ARCHIVO2.txt", "r")) != NULL) 
{
	while (!feof(ar))
{
p1 = fgetc(ar); /* Lee el caracter del archivo. */
putchar(p1); /* Despliega el caracter en la pantalla. */
}
fclose(ar);
}
else
printf("No se puede abrir el archivo");
}


void escritura2(){
	FILE *archivo;
char cadena[10];
char documento[]="ARCHIVO2.txt";


if ((archivo = fopen(documento, "w+")))
    {
    	fflush(stdin);
    	printf("\nIntroduzca el proximo cuatrimeste a inscribir");
        gets(cadena);
        if(strcmp(cadena,"1\0")==0)
        	printf("Materias:\n\tPrimer cuatrimeste\n Lengua Espanola 1\n Algoritmos computacionales\n Orientacion Universitaria\n Precalculo\n\n");
        if(strcmp(cadena,"2\0")==0)
			printf("Materias:\n\tSegundo cuatrimeste\n Lengua Espanola 2\n Logica computacional\n Reflexion Filosofica\n calculo\n\n");       
		 if(strcmp(cadena,"3\0")==0)
			printf("Materias:\n\tTercer cuatrimeste\n Redaccion Profesional\n Analisis de sistemas\n Logica Matematica\n calculo 2\n Ingles 2\n\n");
        if(strcmp(cadena,"4\0")==0) 
			printf("Materias:\n\tCuarto cuatrimeste\n Fundamentos de estadistica\n Inform. Aplicada IID\n Temas de Histroia Dominicana\n calculo 3\n Ingles 3\n\n");
        if(strcmp(cadena,"5\0")==0) 
			printf("Materias:\n\tQuinto cuatrimeste\n Analisis computacional 2\n Estudio del trabajo\n Lab de Estudio del trabajo\n calculo\n Tecnologia de la inform. y com.\n\n");
        fprintf(archivo, "%s", cadena);
        fclose(archivo);
        printf("Se ha inscrito exitosamente");
        printf("\nSu nuevo ciclo es el: %s\n\n", cadena);
    }


if((archivo=fopen(documento, "rt"))==NULL)
   printf("ha ocurrido un error al abrir el archivo\n",documento);
fclose(archivo); 
}



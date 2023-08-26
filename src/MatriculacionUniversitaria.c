#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include "libreria.h"

int electrica=1,industrial=1,sistema=1,contabilidad=1,electronica=1,lenguas=1;;

typedef struct {
    int matricula; //Sirve para almacenar la matricula escogida
    char contrasena[20]; //Sirve para anadir o modificar la contrasena del usuario
    char carrera[30]; //Sirve para visualizar que carrera el estudiante escogio
    int carrer; //Sirve para comparar informaciones numericas con respecto a la carrera escogida
    int ciclos; //Sirve para guardar la informacion de en cual ciclo va
} matriculacion;



void continuar()
{
    printf("Presione una tecla para continuar\n\n");
    getch();
    system("cls");
}


void registro()
{
	int carrera,exi=0;
	char carr;
    FILE *arch;
    arch=fopen("usuario.dat","ab");
    if (arch==NULL)
        exit(1);
    matriculacion usuario;
    fflush(stdin);
    printf("Ingrese la matricula del usuario (sin espacios/guiones): ");
    scanf("%i",&usuario.matricula);
    fflush(stdin);
    printf("Ingrese la contrasena: ");
    gets(usuario.contrasena);
    printf("Ingrese el numero de la carrera universitaria a cursar: \n1- Ingenieria Electrica\n2- Ingenieria Industrial\n3- Ingieneria en sistema\n4- Contabilidad\n5- Ingenieria Electronica\n6- Lenguas Modernas\n\n");
    scanf("%i",&carrera);
    while(exi==0){
    switch(carrera){
    	case 1:
				fflush(stdin);
				printf("Ha seleccionado Ingenieria Electrica\nPara confirmar, escriba *Ingenieria Electrica*: ");
    			fgets(usuario.carrera,30,stdin);
    			usuario.carrer=1;
    			usuario.ciclos=1;
    			exi=1;
    		break;
    	case 2:
    			fflush(stdin);
				printf("Ha seleccionado Ingenieria Industrial\nPara confirmar, escriba *Ingenieria Industrial*: ");
    			fgets(usuario.carrera,30,stdin);
    			usuario.carrer=2;
    			usuario.ciclos=1;
    			exi=1;
    		break;
    	case 3:
    			fflush(stdin);
				printf("Ha seleccionado Ingenieria en sistema\nPara confirmar, escriba *Ingenieria en sistema*: ");
    			fgets(usuario.carrera,30,stdin);
    			usuario.carrer=3;
    			usuario.ciclos=1;
    			exi=1;    		
    		break;
    	case 4:
    			fflush(stdin);
				printf("Ha seleccionado Contabilidad\nPara confirmar, escriba *Contabilidad*: ");
    			fgets(usuario.carrera,30,stdin);
    			usuario.carrer=4;
    			usuario.ciclos=1;
    			exi=1;
    		break;
    	case 5:
    			fflush(stdin);
				printf("Ha seleccionado Ingenieria Electronica\nPara confirmar, escriba *Ingenieria Electronica*: ");
    			fgets(usuario.carrera,30,stdin);
    			usuario.carrer=5;
    			usuario.ciclos=1;
    			exi=1;
    		break;
    	case 6:
    			fflush(stdin);
				printf("Ha seleccionado Lenguas Modernas\nPara confirmar, escriba *Lenguas Modernas*: ");
    			fgets(usuario.carrera,30,stdin);
    			usuario.carrer=6;
    			usuario.ciclos=1;
    			exi=1;
			break;	
    	default: printf("La opcion seleccionada es invalida");
	}
	}
    fwrite(&usuario, sizeof(matriculacion), 1, arch);
    fclose(arch);
    continuar();
}


void listado()
{
	fflush(stdin);
	system("cls");
    FILE *arch;
    int numero=1,con,intentos=2,salida=0; 
    char admin[20];
    arch=fopen("usuario.dat","rb");
    if (arch==NULL)
        exit(1);
    matriculacion usuario;
    fread(&usuario, sizeof(matriculacion), 1, arch);
    printf("\n\tEl listado de matriculas es:\n\n");
    while(!feof(arch))
    {
        printf("Matricula %d: %i \tCarrera universitaria %d: %s\n\n", numero,usuario.matricula,numero,usuario.carrera);
        numero++;
        fread(&usuario, sizeof(matriculacion), 1, arch);
    }
    fclose(arch);
    printf("\n\n Desea ver las contrasenas? \n\t1- Si\n\t2- No\n");
    scanf("%d",&con);
    if(con==1){
    	numero=1;
    	fflush(stdin);
    	system("cls");
    	while(salida!=3){
    	printf("\nDigite la contrasena de administrador: ");
    	gets(admin);
    	if(strcmp(admin,"utesa") == 0){
    		system("cls");
			printf("\nEnhorabuena, eres el administrador\n\n");
			arch=fopen("usuario.dat","rb");
			if (arch==NULL)
			exit(1);
			matriculacion usuario;
			fread(&usuario, sizeof(matriculacion), 1, arch);
    		    while(!feof(arch))
    			{
        			printf("Matricula %d: %i\t Contrasena %d: %s\n\n", numero,usuario.matricula,numero,usuario.contrasena);
        			numero++;
        			fread(&usuario, sizeof(matriculacion), 1, arch);
    			}
    			fclose(arch);
    			salida=3;
    	}
    	else{
    		printf("\nLa contrasena digitada es incorrecta, intente nuevamente (intentos restantes %d)\n", intentos--);
    		salida++;
    	}
    }
	}
    continuar();
}


void ingreso(){
	int a=0;
    FILE *arch;
    arch=fopen("usuario.dat","rb");
    if (arch==NULL)
        exit(1);
    printf("\nDigite una matricula existente para ingresar: ");
    int mat;
    scanf("%i", &mat);
    char cont[20],presel[30];
    matriculacion usuario;
    int hay=0;//La variable hay me ayudara a identificar si existe un alumno bajo la matricula ingresada
    fread(&usuario, sizeof(matriculacion), 1, arch);
    while(!feof(arch))
    {
        if (mat==usuario.matricula)
        {
        	fflush(stdin);
           printf("Digite su contrasena: ");
           gets(cont);
           int resultado=strcmp(cont,usuario.contrasena);
           int salir=0;
           if(resultado==0){
           	system("cls");
           	printf("Ha accedido exitosamente\n\n\tMENU INTERNO\n");
           		int opt;
           		fflush(stdin);
				printf("\n1- Preseleccion\n2- Pago de cuotas\n3- Calificaciones\n4- Cerrar sesion\n\n");
				scanf("%d",&opt);
				switch(opt){
				case 1:
					fflush(stdin);
					if(usuario.carrer==1){
					printf("Usted estudia Ingenieria Electrica y le toca el ciclo %d", usuario.ciclos++);
					ciclos(a);
				}
					if(usuario.carrer==2)
					printf("Usted estudia Ingenieria Industrial y le toca el ciclo %d", industrial++);
					if(usuario.carrer==3)
					printf("Usted estudia Ingenieria en sistema y le toca el ciclo %d", sistema++);
					if(usuario.carrer==4)
					printf("Usted estudia Contabilidad y le toca el ciclo %d", 5);
					if(usuario.carrer==5)
					printf("Usted estudia Ingenieria Electronica y le toca el ciclo %d", 5);
					if(usuario.carrer==6)
					printf("Usted estudia Lenguas Modernas y le toca el ciclo %d", 5);
					salir=1;
					break;
				case 2:
					break;
				case 3:
					break;
				}
           }
           else
            printf("Contrasena incorrecta\n");
            hay=1;
            break;
        }
        fread(&usuario, sizeof(matriculacion), 1, arch);
    }
    if (hay==0)
        printf("No existe un usuario con dicha matricula\n");
    fclose(arch);
    
    continuar();
}


void contrasena(){
	FILE *arch;
	char cont[30];
    arch=fopen("usuario.dat","r+b");
    if (arch==NULL)
        exit(1);
    printf("Ingrese la matricula a la cual desea modificar la contrasena: ");
    int matri;
    scanf("%i", &matri);
    matriculacion usuario;
    int existe=0;
    fread(&usuario, sizeof(matriculacion), 1, arch);
    while(!feof(arch))
    {
        if (matri==usuario.matricula)
        {
        	fflush(stdin);
           printf("Digite la contrasena antigua: ");
           gets(cont);
           int resultado=strcmp(cont,usuario.contrasena);
        	if(resultado==0){
           	system("cls");
           	printf("\tInformacion Actual: \n");
           printf("%d \t %s \t %s",usuario.matricula,usuario.carrera,usuario.contrasena);
           printf("\nIngrese la nueva contrasena a actualizar: ");
           gets(usuario.contrasena);
           char pos=ftell(arch)-sizeof(matriculacion);
           fseek(arch,pos,SEEK_SET);
           fwrite(&usuario, sizeof(matriculacion), 1, arch);
           printf("Se modifico la contrasena para el usuario\n");
           existe=1;
           break;}
        }
        else
        	printf("La contrasena esta incorrecta");
        fread(&usuario, sizeof(matriculacion), 1, arch);
    }
    if (existe==0)
        printf("No existe un producto con dicho codigo\n");
    fclose(arch);
    continuar();
}



void main(){
	FILE *arch;
    arch=fopen("productos.dat","wb");
    if (arch==NULL)
    exit(1);
    fclose(arch);
    
	int opcion;
	do{
		printf("\t\tMENU\n\n1- Registrar usuario y contrasena\n2- Ver usuarios\n3- Ingresar\n4- Pensum\n5- Cambiar contrasena\n6- Salir\n");
        printf("Ingrese su opcion:");
        scanf("%i",&opcion);
        switch (opcion) {
            case 1: registro();
                   break;
            case 2: listado();
            	break;
            case 3: ingreso();
            	break;
            case 4: pensum();
            	break;
            case 5: contrasena();
            	break;
        }
    } while (opcion!=6 & opcion<6);
}
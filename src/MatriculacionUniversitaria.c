#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    int matricula;
    char contrasena[20];
} matriculacion;


void continuar()
{
    printf("Presione una tecla para continuar\n\n");
    getch();
    system("cls");
}


void registro()
{
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
        printf("Matricula %d: %i \n\n", numero,usuario.matricula);
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
    	if(strcmp(admin,"utesalamejor") == 0){
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
    FILE *arch;
    arch=fopen("usuario.dat","rb");
    if (arch==NULL)
        exit(1);
    printf("Digite una matricula existente para ingresar: ");
    int mat;
    scanf("%i", &mat);
    char cont[20];
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
           if(resultado==0)
           	printf("Ha accedido exitosamente\n");
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


void main(){
	FILE *arch;
    arch=fopen("productos.dat","wb");
    if (arch==NULL)
    exit(1);
    fclose(arch);
    
	int opcion;
	do{
		printf("\t\tMENU\n\n1- Registrar usuario y contrasena\n2- Ver usuarios\n3- Ingresar\n4- Salir\n");
        printf("Ingrese su opcion:");
        scanf("%i",&opcion);
        switch (opcion) {
            case 1: registro();
                   break;
            case 2: listado();
            	break;
            case 3: ingreso();
            	break;
        }
    } while (opcion!=4);
}

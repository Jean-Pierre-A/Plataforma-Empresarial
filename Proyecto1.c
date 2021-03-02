#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct estudiante
 {
     int cedula;
     char nombre[30];
     int semestre;
 } *memoriaDB;

int registros = 0, registrosUsados = 0, uso = 0;
FILE *OUT_FILE, *IN_FILE;
char nombreBD[30];

void mkdb (char nombre[30], int registros);

void savedb (char nombreArchivo[30], char nombre[30], int registros);

void mkreg (int cedula,char nombre[30], int semestre, int registros); 

void readall(int registros);

void loaddb(char nombreArchivo[30]);

void readsize();

void readreg(int cedula2);

void exitProgram();

int main()
{

 
 char comando [100], nombreArchivo[30], nombreArchivoLoad[30], nombreEstudiante[30];
 int cedula = 0, semestre = 0;

do
{
    printf("Ingrese el Comando a realizar \n");
    fscanf(stdin, "%s", comando);
    getc(stdin);


    if(strncmp(comando,"mkdb", 4)==0)
    {
          fscanf(stdin, "%s", nombreBD);
          fscanf(stdin, "%d", &registros);

          mkdb(nombreBD, registros);
       
    }
    else if(strncmp(comando,"loaddb", 6)==0)
    {
        fscanf(stdin, "%s", nombreArchivoLoad);
        loaddb(nombreArchivoLoad);
    }
    else if(strncmp(comando,"savedb",6)==0)
    {

        fscanf(stdin, "%s", nombreArchivo);
        printf("%s\n", nombreArchivo);
        savedb(nombreArchivo, nombreBD, registros);

    }
    else if(strncmp(comando,"readall", 7)==0)
    {

        readall(registrosUsados);

    }
    else if(strncmp(comando,"readsize",8)==0)
    {

        readsize();

    }
    else if(strncmp(comando,"mkreg", 5)==0)
    {    
         fscanf(stdin, "%d", &cedula);
        //getc(stdin);
         fscanf(stdin, "%s", nombreEstudiante);
        // getc(stdin);
         fscanf(stdin, "%d", &semestre);
         mkreg(cedula, nombreEstudiante, semestre, registros);



    }
    else if(strncmp(comando,"readreg", 7)==0)
    {
        fscanf(stdin, "%d", &cedula);
        readreg(cedula);


    }
    else if(strncmp(comando,"exit", 4)==0)
    {
       exitProgram();
       break;
    }
    else
    {
        printf("Ingrese Un Comando Que este entre:\n1.mkdb nombre tamaño\n2.loaddb nombre \n3.savedb nombre \n4.readall \n5.readsize \n6.mkreg cedula nombre semestre \n7.readreg cedula \n8.exit\n");

    }

}while(1);
free(memoriaDB);
return 0;

}

void mkdb (char nombre[30], int registros)
{
    
     memoriaDB = malloc(sizeof(struct estudiante)*registros);
     printf("La Base de Datos %s  Ha sido Creada Satisfactoriamente con %d registros\n", nombre, registros);
}

void savedb(char nombreArchivo[30], char nombre[30], int registros)
{
   
    printf("El Nombre del Archivo es %s de la base de datos es %s y registros %d\n", nombreArchivo, nombre, registros);
    OUT_FILE =  fopen(nombreArchivo, "w");
    fprintf(OUT_FILE, "%s %d \n", nombre, registros);

    for(int i=0; i < registros; i++)
    {
        fprintf(OUT_FILE,"%d ", (memoriaDB+i)->cedula);
        fprintf(OUT_FILE,"%s ", (memoriaDB+i)->nombre);
        fprintf(OUT_FILE,"%d\n", (memoriaDB+i)->semestre);
        
    }

    fclose(OUT_FILE);
    
}

void mkreg (int cedula,char nombre[30], int semestre, int registros)
{
    //free(memoriaDB);
    printf("La cedula es  %d, el nombre es %s,  y el semestre %d  \n", cedula, nombre, semestre);

    for(int i=0; i < registros; i++)
    {
        if((memoriaDB+i)->cedula==0) 
        {
        (memoriaDB+i)->cedula = cedula;
        strcpy((memoriaDB+i)->nombre,nombre);
        (memoriaDB+i)->semestre = semestre;
        i = registros;
        registrosUsados++;
        }
        
    }

}

void readall(int registros )
{    
    for(int i=0; i < registros; i++)
    {
        printf("%d", i+1);
        printf(" Cedula es %d ", (memoriaDB+i)->cedula);
        printf("El nombre  es %s ", (memoriaDB+i)->nombre);
        printf("El semestre es  es %d \n", (memoriaDB+i)->semestre);
    }


}

void loaddb(char nombreArchivo[30])
{   
    IN_FILE =  fopen(nombreArchivo, "r");

    char nombreBD[30];
      
    int cedula;
    char nombre[30];
    int semestre;


    fscanf(IN_FILE, "%s", nombreBD);
    fscanf(IN_FILE, "%d", &registros);

    mkdb(nombreBD, registros);
    for(int i = 0; i < registros; i++)
    {  
         fscanf(IN_FILE, "%d", &cedula);
         fscanf(IN_FILE, "%s", nombre);
         fscanf(IN_FILE, "%d", &semestre);

         if(cedula != 0)
         {
                 mkreg(cedula,nombre,semestre,registros);
         }

    }


    fclose(IN_FILE);
}

void readsize()
{
    printf("La Base De Datos tiene %d y usa %d registros ", registros,registrosUsados);
}

void readreg(int cedula2)
{
    int entro = 0;
     for(int i=0; i < registros; i++)
    {
        if((memoriaDB+i)->cedula == cedula2)
        {
            printf("Registro Encontrado");
            printf(" Cedula es %d ", (memoriaDB+i)->cedula);
            printf("El nombre  es %s ", (memoriaDB+i)->nombre);
            printf("El semestre es  es %d \n", (memoriaDB+i)->semestre);
            entro = 1;

        }

        
    }

    
        if(entro == 0)
        {
            printf("No se Encuentra La Cedula \n");
        }
        
}

void exitProgram()
{
        int salir = 0;
        char  ArchivoSalida[30];
        printf("¿Desea Guardar La base de datos? Si lo desea Digite 1 de Lo contrario Cualquier tecla \n");
        fscanf(stdin, "%d", &salir);
        if(salir == 1)
        {
            printf("Ingrese el Nombre del Archivo Para Guardar la BD \n");
            fscanf(stdin, "%s", ArchivoSalida);
            savedb(ArchivoSalida, nombreBD, registros); 

        }
        else
        {   
            printf("Hasta La proxima");

        }

       
}

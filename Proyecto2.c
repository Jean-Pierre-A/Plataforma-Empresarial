#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct estudiante
 {
     int cedula;
     char nombre[30];
     int semestre;
 } estudiante;

typedef struct baseDatos
 {
     char nombreBase[30];
     int registrosBase;
     int registrosBaseUsados;
     struct estudiante* P_registros;

 } bases;
estudiante *memoriaDB , *memoriaDB2;
estudiante *memoriaDB3 [50];
bases *memoriaBases ,*Activa, *memoriaBases2[20];
int registros = 0, registrosUsados = 0, uso = 0, ContBDS = 0;
FILE *OUT_FILE, *IN_FILE;
char nombreBD[30];

void mdb (char nombre[30], int registros);
void mreg (int cedula,char nombre[30], int semestre); 
void svdb ();
void radb();
void ldb(char nombreArchivo[30]);
void rsdb();
void rr(int cedula2);
void exitProgram();
void lsdbs();
void gdb();
void sdb(char nombre [30]);

int main()
{

 
 char comando [100],nombreArchivoLoad[30], nombreEstudiante[30], nombreActiva[30];
 int cedula = 0, semestre = 0;

do
{
    printf("Ingrese el Comando a realizar \n");
    fscanf(stdin, "%s", comando);
    getc(stdin);


    if(strncmp(comando,"mdb", 3)==0)
    {
          fscanf(stdin, "%s", nombreBD);
          fscanf(stdin, "%d", &registros);

       mdb(nombreBD,registros);

         
       
    }
    else if(strncmp(comando,"ldb", 3)==0)
    {
        fscanf(stdin, "%s", nombreArchivoLoad);
        ldb(nombreArchivoLoad);
        
    }
    else if(strncmp(comando,"svdb",3)==0)
    {      
        svdb( );
        
    }
    else if(strncmp(comando,"radb", 4)==0)
    {       
         radb(registros);
    }
    else if(strncmp(comando,"rsdb",4)==0)
    {

        rsdb();

    }
    else if(strncmp(comando,"mreg", 4)==0)
    {    
         fscanf(stdin, "%d", &cedula);
        //getc(stdin);
         fscanf(stdin, "%s", nombreEstudiante);
        // getc(stdin);
         fscanf(stdin, "%d", &semestre);

         mreg(cedula, nombreEstudiante, semestre);
   


    }
    else if(strncmp(comando,"rr", 2)==0)
    {
        fscanf(stdin, "%d", &cedula);
        rr(cedula);
       

    }
    else if(strncmp(comando,"lsdbs", 4)==0)
    {
      lsdbs();
    }
     else if(strncmp(comando,"gdb", 3)==0)
    {   
      gdb();
    }
     else if(strncmp(comando,"sdb", 3)==0)
    {
       fscanf(stdin, "%s",nombreActiva);
       sdb(nombreActiva);
    }

    else if(strncmp(comando,"exit", 4)==0)
    {
       exitProgram();
       break;
    }
    else
    {
        printf("Ingrese Un Comando Que este entre:\n1.mdb nombre tamaño\n2.ldb nombre \n3.lsdbs  \n4.gbd \n5.sdb nombre \n6.svdb \n7.radb \n8.rsdb \n9.mreg cedula nombre semestre\n10.rr cedula\n");
    }

}while(1);
free(memoriaDB);
free(memoriaBases);
return 0;

}

void mdb (char nombre[30], int registros)
{       
       // printf("LLevas %d Bases",ContBDS);
        if(ContBDS == 0)
        {
           printf("Entra Por primera vez\n");
           memoriaDB = malloc(sizeof(struct estudiante)*registros*2);
           memoriaBases = malloc(sizeof(struct baseDatos)*20);
           //memoriaBases = (bases(*))malloc(sizeof(bases));
          // printf(" memoria %d  nombre %s semestre %d",memoriaDB -> cedula, memoriaDB -> nombre, memoriaDB -> semestre);
          strcpy((memoriaBases)->nombreBase,nombre);
          memoriaBases-> P_registros = memoriaDB;
          memoriaBases-> registrosBase = registros;
          Activa  = memoriaBases;
        }
        else
        {  

            printf("Entra Por %d vez\n", ContBDS);
           memoriaDB = malloc(sizeof(struct estudiante)*registros*2);
          // memoriaBases = (bases(*))malloc(sizeof(bases));
          // printf(" memoria %d  nombre %s semestre %d",memoriaDB -> cedula, memoriaDB -> nombre, memoriaDB -> semestre);
          strcpy((memoriaBases+ContBDS)->nombreBase,nombre);
         (memoriaBases+ContBDS)-> P_registros = (memoriaDB+ContBDS);
         (memoriaBases+ContBDS)-> registrosBase = registros;
          Activa  =(memoriaBases+ContBDS);
           
        }

        printf("La Base de Datos %s Ha sido Satisfactoriamente Creada  \n", ((memoriaBases+ContBDS)->nombreBase));
        ContBDS++;
        ContBDS++;
}

void mreg (int cedula,char nombreE[30], int semestre)
{
     printf("La cedula es  %d, el nombre es %s,  y el semestre %d  \n", cedula, nombreE, semestre);

       for(int i=0; i < registros; i++)
    {
        if( ((Activa->P_registros)+i)->cedula==0) 
        {
         ((Activa->P_registros)+i)->cedula = cedula;
        strcpy( ((Activa->P_registros)+i)->nombre,nombreE);
        ((Activa->P_registros)+i)->semestre = semestre;
        registrosUsados++;
        Activa-> registrosBaseUsados ++;
        break;
        }
        
    }

}

void radb()
{
    //printf("La Base De Datos es %s \n", Activa-> nombreBase );
    printf("--------------------------------------------------------------------------------\n");
    printf("|La Base De Datos Activa es %s, con tamaño de %d y tiene %d Registros usados |\n",Activa -> nombreBase, Activa -> registrosBase, Activa -> registrosBaseUsados);
    for(int i=0; i < registros; i++)
    {
        printf("|%d", i+1);
        printf(" Cedula es %d ", ((Activa->P_registros)+i)->cedula);
        printf("El nombre  es %s ",  ((Activa->P_registros)+i)->nombre);
        printf("El semestre es  es %d |\n", ((Activa->P_registros)+i)->semestre);
    }
    printf("--------------------------------------------------------------------------------\n");
}

void svdb ( )
{
    
    printf("La base de datos es %s y registros %d\n",Activa-> nombreBase, registros);
    OUT_FILE =  fopen(Activa-> nombreBase, "w");
    fprintf(OUT_FILE, "%s %d \n",Activa-> nombreBase, registros);

    for(int i=0; i < registros; i++)
    {
        fprintf(OUT_FILE,"%d ", ((Activa->P_registros)+i)->cedula);
        fprintf(OUT_FILE,"%s ", ((Activa->P_registros)+i)->nombre);
        fprintf(OUT_FILE,"%d\n", ((Activa->P_registros)+i)->semestre);
        
    }

    printf("Base De Datos Exitosamente Guardada\n");

    fclose(OUT_FILE);
}

void ldb(char nombreArchivo[30])
{   
    IN_FILE =  fopen(nombreArchivo, "r");

    if(IN_FILE == NULL)
    {
        printf("No se Puede Abrir Correctamente \n");
        main();
    }

    char nombreBD[30];
      
    int cedula = 0;
    char nombre[30];
    int semestre = 0;


    fscanf(IN_FILE, "%s", nombreBD);
    fscanf(IN_FILE, "%d", &registros);

    mdb(nombreBD, registros);
    for(int i = 0; i < registros; i++)
    {  
         fscanf(IN_FILE, "%d", &cedula);
         fscanf(IN_FILE, "%s", nombre);
         fscanf(IN_FILE, "%d", &semestre);

         if(cedula != 0)
         {
                 mreg(cedula,nombre,semestre);
         }

    }


    fclose(IN_FILE);

}

void rsdb()
{
    printf("La Base De Datos es %s y tiene %d y usa %d registros \n",Activa-> nombreBase, Activa -> registrosBase, Activa -> registrosBaseUsados);
}

void rr(int cedula2)
{
    int entro = 0;
     for(int i=0; i < registros; i++)
    {
        if(((Activa->P_registros)+i)->cedula == cedula2)
        {
            printf("Registro Encontrado");
            printf(" Cedula es %d ", ((Activa->P_registros)+i)->cedula);
            printf("El nombre  es %s ", ((Activa->P_registros)+i)->nombre);
            printf("El semestre es  es %d \n", ((Activa->P_registros)+i)->semestre);
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
        printf("La Base de Datos Activa es %s ", Activa-> nombreBase );
        printf("¿Desea Guardar La base de datos? Si lo desea Digite 1 de Lo contrario Cualquier tecla \n");
        fscanf(stdin, "%d", &salir);
        if(salir == 1)
        {
           
            svdb(nombreBD, registros); 

        }
        else
        {   
            printf("Hasta La proxima");

        }

       
}

void lsdbs()
{
    int j = 0;
    printf("Las Bases De Datos en Memoria Son %d \n",ContBDS/2);

    printf("---------------------------------------------------\n");

    for(int i = 0; i < ContBDS; i=i+2)
    {
        printf("| %d. %s, con %d tamañao y %d Registros usados |\n",j+1,(memoriaBases+i) -> nombreBase, (memoriaBases+i) -> registrosBase, (memoriaBases+i) -> registrosBaseUsados);
        j++;
    }

    
    printf("---------------------------------------------------\n");
}

void gdb()
{
    printf("----------------------------------------------------------------------------------------\n");
    printf("|La Base De Datos Activa es %s, con tamaño de %d y tiene %d Registros usados |\n",Activa -> nombreBase, Activa -> registrosBase, Activa -> registrosBaseUsados);
    printf("----------------------------------------------------------------------------------------\n");
}

void sdb(char nombre [30])
{
    int entro = 0;
    for(int i = 0; i < ContBDS; i++)
    {
        if(strcmp((memoriaBases+i)-> nombreBase, nombre) == 0)
        {
            Activa = (memoriaBases+i);
            printf("La Base De Datos Ha Sido Activada Satisfactoriamente\n");
            entro = 1;
            break;
        }
      
    }

    if(entro == 0)
    {
        printf("La Base No Fue encontrada\n");
    }
}



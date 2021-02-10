#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char (* MemoriaMats)[20];
double *MemoriaNotas;
int *MemoriaCreditos;
int main()
{
    int numMaterias = 0;
    double Promedio, Totalc ;
    char *a;

    printf("Bienvenido Por favor Ingrese el Numero de Materias en el Semestre \n");
    scanf("%d", &numMaterias);
    getc(stdin);
    
     MemoriaMats = (char (*)[20])malloc(sizeof(char [20])*numMaterias);
     MemoriaNotas = (double *)malloc(sizeof(double)* numMaterias);
     MemoriaCreditos = (int *)malloc(sizeof(int)* numMaterias);

    for(int i = 0; i < numMaterias ; i++)
    {
        printf("Ingrese el nombre de la Materia \n");
        scanf("%s", (char *)(MemoriaMats + i));
        getc(stdin);
        
        printf("Ingrese la Nota de la Materia \n");
        scanf("%lf", (double *)(MemoriaNotas + i));
        getc(stdin);
        
        printf("Ingrese los creditos de la Materia \n");
        scanf("%d", (int *)(MemoriaCreditos + i));
        getc(stdin);
        

    }
    
    printf("--------------------------------------\n");
    printf("Materia || Nota ||  Creditos ||\n");
    for(int i=0; i < numMaterias; i++)
    {
        printf("%s || %4.1lf || %8d || \n", (char *)(MemoriaMats+i), *(MemoriaNotas + i), *(MemoriaCreditos + i) );
        Promedio += (*(MemoriaNotas + i))*(*(MemoriaCreditos + i));
        Totalc += *(MemoriaCreditos + i);
    }
    
    printf("--------------------------------------\n");

    printf("El Promedio Ponderado es %4.1lf ", Promedio/Totalc);

    free(MemoriaMats);
    free(MemoriaNotas);
    free(MemoriaCreditos);
    
       return 0;

}

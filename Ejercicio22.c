#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

void FunNot(FILE * IN_FILE, FILE * salida);
void FunXor(FILE * IN_FILE, FILE * salida);

int main()
{
    
    char archivoEnt [MAX], archivoSal [MAX];
    int eleccion = 0;
    printf("Bienvenido");
    printf("Ingrese el Nombre del Archivo de entrada \n");
    scanf("%s", archivoEnt );
    printf("Ingrese el Nombre del Archivo de Salida \n");
    scanf("%s", archivoSal );

    FILE *IN_FILE;
    FILE *OUT_FILE;
    IN_FILE = fopen(archivoEnt, "r");
    OUT_FILE =fopen(archivoSal, "w");

  
    if(IN_FILE == NULL)
    {
        printf("No se pueden abrir, ya que esta Nulo \n");
    }

    printf("Que funcion quiere usar:\n 1) NOT \n 2) XOR \n");
    scanf("%d", &eleccion);

    if(eleccion == 1)
    {
         FunNot(IN_FILE,OUT_FILE);

    }
    else if (eleccion == 2)
    {
         FunXor(IN_FILE,OUT_FILE);
    }
    else
    {
        printf("Seleccione Una Opción Valida");
    }
    return 0;
}

void FunNot(FILE  * IN_FILE, FILE * salida)
{
    int carac;
    while(1)
    {
        carac = fgetc(IN_FILE);
        if (carac == EOF)
        {
            break;
        }
     carac = ~carac;
      fputc(carac, salida);

    }
    
}

void FunXor(FILE  * IN_FILE, FILE * salida)
{
    int carac;
    while(1)
    {
        carac = fgetc(IN_FILE);
        if (carac == EOF)
        {
            break;
        }
      carac = carac^0xFF;
      fputc(carac, salida);

    }
      

}

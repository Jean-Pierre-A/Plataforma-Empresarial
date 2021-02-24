#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

void FunNot(FILE * IN_FILE, FILE * salida);
void FunXor(FILE * IN_FILE, FILE * salida);

int main(int argc, char *argv[])
{
    char *eleccion;
   
   
  
    FILE *IN_FILE;
    FILE *OUT_FILE;
    IN_FILE =  fopen(argv[1], "r");
    OUT_FILE = fopen(argv[2], "w");
    eleccion = argv[3];
    
    if(IN_FILE == NULL)
    {
        printf("No se pueden abrir, ya que esta Nulo \n");
    }


    if((strncmp("NOT",eleccion,3)==0))
    {
         FunNot(IN_FILE,OUT_FILE);

    }
    else if ((strncmp("XOR",eleccion,3)==0))
    {
         FunXor(IN_FILE,OUT_FILE);
    }
    else
    {
        printf("Seleccione Una Opción Valida");
    }
     fclose(IN_FILE);
    fclose(OUT_FILE);
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

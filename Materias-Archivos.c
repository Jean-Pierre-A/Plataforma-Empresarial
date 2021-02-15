
#include <stdio.h>
#include <stdlib.h>

char FILE_TO_READ[] = "TEST.txt";

int main()
{
  char cadena1[50];
 
  char *linea;
  double notaMateria, promedioPonderado;
  double *prom;
  int totalMaterias, totalCreditos, creditosMateria, lineaTotal, materiaganada,materiaperdida;
  int lon;

  FILE *read, *write;
  
  read = fopen(FILE_TO_READ,"r");
  write = fopen("Informe.txt","wt");
  
 fprintf(write, "%s","     Materia      Nota    Creditos \n");
  
 while(linea != NULL ){

 fgets(cadena1,50,read);
 printf ("%s",cadena1);
 totalMaterias++;
 
 fscanf(read,"%lf", &notaMateria);
 if(notaMateria > 2.9)
 {
     materiaganada ++;
 }
 printf("Las notas son %4.1lf \n", notaMateria);
 
 fscanf(read,"%d", &creditosMateria);
 printf("Los creditos son %d \n", creditosMateria);
 
 totalCreditos += creditosMateria;
 
  printf("Los creditos 2 son %d \n", creditosMateria);
 

 lon = strlen(cadena1);
 char cadena2 [lon];
 
 for (int i = 0; i <lon-1;i++){
     cadena2[i] = cadena1[i];
 }
 fprintf(write, "%s", cadena2);  fprintf(write, "%s", "  ");
 fprintf(write, "%4.1lf", notaMateria);  fprintf(write, "%s", "     ");
 fprintf(write, "%d", creditosMateria);  fprintf(write, "%s", " \n");
 
 for (int i = 0; i <50;i++){
     cadena1[i] = NULL;
 }
 
  printf("Los creditos 3 son %d \n", creditosMateria);
  

  
 notaMateria = 0;
 creditosMateria = 0;
 
 linea =  fgets(cadena1,50,read);
 
 printf("TOTAL creditosMateria %d \n", totalCreditos);

}

 

 materiaperdida = totalMaterias - materiaganada;
 fprintf(write, "%s", "__________________________________\n");
 fprintf(write, "Total de Materias %d \n", totalMaterias);
 fprintf(write,"Materias Ganadas %d \n", materiaganada);
 fprintf(write,"Materias Perdidas %d \n", materiaperdida);
 //fprintf(write, "El promedio Ponderado es %lf \n", *prom);
 printf("TOTAL creditosMateria 2 %d \n", totalCreditos);
 printf("total de creditos %d", totalCreditos);
 
  fclose(read);
  fclose(write);
 
  
  return 0;
  
  
}


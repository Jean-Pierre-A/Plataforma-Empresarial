#include <stdio.h>
#include <string.h>
#include <stdint.h>


uint8_t arrayCommon(int32_t* arr1, int32_t arr1Size,int32_t* arr2, int32_t arr2Size, int32_t* arrRes, int32_t arrResSize);

int main(void)
{
    int n = 0, nDos = 0;
    int arrResultado [100];
    uint8_t resultado ;

    printf("Entra la longitud del primer arreglo ");
    scanf("%d", &n);

     int arr[n];
    printf("Insertar los Elementos uno por uno  \n");

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    

    
    printf("Entra la longitud del Segundo arreglo ");
    scanf("%d", &nDos);
    int arrDos [nDos];
    printf("Insertar los Elementos uno por uno  \n");

      for(int i = 0; i < nDos; i++)
    {
        scanf("%d", &arrDos[i]);
    }

    if(n > nDos){
    resultado = arrayCommon(arr, n , arrDos, nDos, arrResultado, n);
    }
    else
    {
        resultado = arrayCommon(arr, n , arrDos, nDos, arrResultado, nDos);
    }
    printf("El resultaddo es %d \n", resultado);
    
}


uint8_t arrayCommon(int32_t* arr1, int32_t arr1Size,int32_t* arr2, int32_t arr2Size, int32_t* arrRes, int32_t arrResSize)
{

    uint8_t cont = 0;
    int k = 0, r=0, repetido = 0;


    if(arr1Size >= arr2Size)
    {

        for(int i = 0; i < arr1Size; i++)
        {

            for(int j=0; j < arr2Size; j++)
            {

                if(*(arr1 + i)== *(arr2 + j)){

                      k = *(arr2 + j);

                      repetido = 0;

                      for(int i=0; i < arrResSize; i++)
                      {

                          if(arrRes[i]==k)
                          {
                              repetido = 1;

                          }

                      }

                      if(repetido==0)
                      {
                          cont++;
                          for(int i=arrResSize-1; i > 0; i--)
                          {
                              arrRes[i] = arrRes[i-1];
                          }

                          arrRes[0]=k;
                          printf("Numero en comun %d \n", k);

                      }

                  

   
                }

            }

        }
    }

    
    if(arr2Size > arr1Size)
    {
        for(int i = 0; i < arr2Size; i++)
        {
         for(int j=0; j < arr1Size; j++)
            {


                
            }
        }
    }

    for(int i = cont-1; i >=0; i--)
    {
          printf("Resultado[%d]: %d\n",r, arrRes[i] );
          r++;
    }

    return cont;
   

}

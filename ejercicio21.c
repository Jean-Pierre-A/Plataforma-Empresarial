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

    resultado = arrayCommon(arr, n , arrDos, nDos, arrResultado, n);

    printf("El resultaddo es %d \n", resultado);
    
}


uint8_t arrayCommon(int32_t* arr1, int32_t arr1Size,int32_t* arr2, int32_t arr2Size, int32_t* arrRes, int32_t arrResSize)
{

    uint8_t cont = 0, cont2 = 0, cont3 = 0;
    int k = 0, tama = 0;

    if(arr1Size >= arr2Size)
    {

        for(int i = 0; i < arr1Size; i++)
        {

            for(int j=0; j < arr2Size; j++)
            {

                if(*(arr1 + i)== *(arr2 + j)){

                    *(arrRes + cont) = *(arr1 + i);
                    
                    cont++;
                    cont2++;

   
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

                if(*(arr2 + i)== *(arr1 + j))
                {
                    
                    *(arrRes + cont) = *(arr2 + i);
                    cont++;
                    cont2++;

                }
            }
        }
    }

 for(int i = 0; i < cont; i++)
    {
          printf("Resultadoini[%d]: %d\n",i, *(arrRes+i) );
    }
  
    for(int i=0; i < cont; i++)
    {
        
        for(int j =i+1; i< cont; j++)
        {
            if(arrRes[i]== arrRes[j])
            {
                k = j;
                cont3 ++;
                while(k < cont)
                {
                    arrRes[k] = arrRes[k+1];

                    k++;

                }

                cont--;
                j--;

            }
            
        }
        
    }

    
     for(int i=0; i < cont2; i++)
     {
         if(*(arrRes+i) > 1 && *(arrRes+i)< 10000)
         {

             tama++;

         }
     }


         printf("con %d y con2 %d y con3 %d y tama%d, longi  %d \n", cont, cont2, cont3, tama);

    for(int i = 0; i < tama+1; i++)
    {
          printf("Resultado[%d]: %d\n",i, arrRes[i] );
    }

    return cont2;
   

}
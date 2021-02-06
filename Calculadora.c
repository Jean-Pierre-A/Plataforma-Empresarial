
#include <stdio.h>

int main()
{
    float primerD, segundoD, resultado;
    char signo, control;
    control = 's';
    while(control != 'q'){
        printf("Ingrese el Primer digito \n");
        scanf("%f", &primerD);
        printf("El primer digito es: %.3f\n", primerD);
        printf("Ingrese el segundo digito \n");
        scanf("%f", &segundoD);
        printf("El segundo digito es ..: %.3f\n", segundoD);
        printf("Ingrese el signo de la operació, puede ser + , - , / , * \n");
        scanf("\n%c", &signo);
        printf("El signo de la operacion es : %c\n", signo);
        
        
       switch(signo){
           
           case '+': 
                printf("\nLa operación es suma");
    		 	resultado = primerD + segundoD;
    			break;
    			
        	case '-': 
                printf("\nLa operación es resta");
        		resultado = primerD - segundoD;
        		break;
        		
        	case '*': 
                printf("\nLa operación es Multiplicacion");
        		resultado = primerD * segundoD;
        		break;
        		
        	case '/': 
                printf("\nLa operación es Division");
            	resultado = primerD / segundoD;
            	break;
            	
           
       }
       
         printf("\n\nEl resultado de la operación es: %.3f\n", resultado);
         printf("\n Para seguir diguite s para parar digite q\n");
         scanf("\n%c", &control);
          
        
        
        
    }
    return 0;
}
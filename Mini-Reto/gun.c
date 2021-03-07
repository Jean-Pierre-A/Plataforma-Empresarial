   #include <stdlib.h>
   #include <stdio.h>

    typedef int bool_t;

        // Attribute structure
     typedef struct {
       int bullets;
       int velocidad;
       char tipo;
     } gun_t;

     gun_t* gun_new() {
       return (gun_t*)malloc(sizeof(gun_t));
     }

     // Constructor

     void gun_ctor(gun_t* gun, int inicio_balas, int velocidad, char tipoG)
     {
         gun->bullets = 0;
         
           if (inicio_balas > 0)
            {
             gun->bullets = inicio_balas;
            }
           if (velocidad > 0)
           {
            gun ->velocidad = velocidad;
           } 

           gun->tipo = tipoG;

     }

     void gun_dtor(gun_t* gun) {
       
     }

    bool_t gun_has_bullets(gun_t* gun)
     {
       return (gun->bullets > 0);
     }

     void gun_shoot(gun_t* gun)
    {
       gun->bullets--;
       printf("PIUUUK!!!");
     }

    void gun_recargar(gun_t* gun) 
    {
       gun->bullets = 10;
       printf("Se Recargo Exitosamente\n");
     }

    

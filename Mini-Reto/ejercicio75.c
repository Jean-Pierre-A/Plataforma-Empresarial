#include <stdio.h>
#include <stdlib.h>
#include "gun.h"
#include "player.h"
int main(int argc, char* argv[])
 {
    char Arma;
    char nombre[30];
    int velocidad=0, op = 0 ;
    printf("BIENVENDIO A CALL OF DUTY RETO MEDALLO\n");
    printf("POV °°Estas en el parque botero te persiguen Un vendedor de BONICE y un Chamo°°\n");
    printf("Selecciona Tu Arma Digita la letra que Corresponde  \n A)Pistola Sencilla\n B) Escopeta Scorpion \n C) Francotiradora x10 \n D) Samsung Galaxy Note\n");
    getc(stdin);
    scanf("%c", Arma);
    printf("Ya que tienes tu Arma es Hora de Ponerte Un Apodo, Se Creativo\n");
    scanf("%s", nombre);
    printf("Evaluemos tu Experiencia \n1) Manco pero con ganas \n2)Se alguito, relax \n3) Profesional Lomo plateado \n4) Keanu reeves\n");
    scanf("%d", &velocidad);
    struct gun_t* gun = gun_new();
    gun_ctor(gun, 10, velocidad, Arma);
   struct player_t* player = player_new();
    player_ctor(player, nombre);
    printf("Se Acerca Un Vendedor de BONICE sospechosamente\n");
    printf("¿Quieres Recojer tu Arma? 1) Si 2) No \n");
    scanf("%d", &op);
    if(op== 1)
    {
      player_pickup(player, gun);
        while (gun_has_bullets(gun))
     {
       player_shoot(player);
     }

              
      gun_recargar(gun);

               
    while (gun_has_bullets(gun)) 
    {
      player_shoot(player);
    }
     player_drop(player);
    }
    else
    {
      printf("El Vendedor De Bonice te Asesino \n");
      printf("GAME OVER!!!\n");

    }
            
  
          
    player_dtor(player);
    free(player);
    gun_dtor(gun);
    free(gun);
    return 0;

     }

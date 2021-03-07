 #ifndef GUN_H_
     #define GUN_H_

        typedef int bool_bull;
        struct gun_t;

        struct gun_t* gun_new();

        //Constructor

        void  gun_ctor(struct gun_t*, int, int, char);
        // Desctructor

        void gun_dtor(struct gun_t*);

         bool_bull gun_has_bullets (struct gun_t*);
         void gun_shoot(struct gun_t*);
         void gun_recargar(struct gun_t*);

     #endif 

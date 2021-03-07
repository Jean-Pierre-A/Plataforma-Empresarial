  #ifndef PLAYER_H_
  #define PLAYER_H_

     
     struct player_t;
     struct gun_t;

    
     struct player_t* player_new();

 
     void player_ctor(struct player_t*, const char*);

    
     void player_dtor(struct player_t*);

     
     void player_pickup(struct player_t*, struct gun_t*);
     void player_shoot(struct player_t*);
     void player_drop(struct player_t*);

     #endif 

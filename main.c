#include "./minilibx/mlx.h"
#include <stdio.h>
#include "./logic/get_next_line.h"
#include <stdlib.h>


int main() {

    t_game  game;
    
    // - FLOOD FILL CHECK - //
    check_flood_fill_map(&game);

    // - INIT GAME -// 
    create_map(&game);
    calculate_len(&game, game.map[0]);
    check_map(&game);
    count_collectibles(&game);
    window_size(&game);
   
    char *path = "./images_op_end/first_image.xpm";

    display_image_before(&game, path);

    display_player_pos(&game);
  
    drawGrid(&game);
    
    mlx_key_hook(game.win, controls_working, &game);    

    mlx_loop(game.mlx);
    
    return 0;
}




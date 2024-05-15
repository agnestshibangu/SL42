#include "./minilibx/mlx.h"
#include <stdio.h>
#include "./logic/get_next_line.h"
#include <stdlib.h>


int main() {

    t_game  game;
    
    // - FLOOD FILL CHECK - //
    // create map
    create_map(&game);
    map_len(&game);
    // // make floodfill || make sure floodfill is OK
    display_player_pos(&game);
    flood_map(&game, game.player_pos_x, game.player_pos_y);
    check_flood_fill(&game);
    // 
    // destroy map
    map_free_after_flood_fill(&game);


    // - CREATE MAP -// 
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




// mallocer la structure
// checker floodfill    
// mallocer mlx
// 

#include "./minilibx/mlx.h"
#include <stdio.h>
#include "./includes/so_long.h"
#include "./gnlsolong/get_next_line.h"
#include <stdlib.h>


int main() {

    t_game  game;

    create_map(&game);

    calculate_len(&game, game.map[0]);

    check_map(&game);

    count_collectibles(&game);

    printf("printf game width === %d\n", game.map_width);
    printf("printf game height === %d\n", game.map_height);

    int window_width;
    int window_height;

    // printf("printf xpm width === %d", game.xpm_width);
    // printf("printf xpm height === %d", game.xpm_height);


    window_width = game.map_width * 29; // 20
    window_height = (game.map_height - 1) * 28; // 12
    game.mlx = mlx_init();
    game.win = mlx_new_window(game.mlx, window_width, window_height, "game map");

    char *path = "first_image.xpm";

    display_image_before(&game, path);

    display_player_pos(&game);
  
    drawGrid(&game);
    
    mlx_key_hook(game.win, controls_working, &game);    

    mlx_loop(game.mlx);
    
    return 0;
}




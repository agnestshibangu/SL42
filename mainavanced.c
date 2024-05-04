// mallocer la structure
// checker floodfill    
// mallocer mlx
// 

#include "./minilibx/mlx.h"
#include <stdio.h>
#include "./includes/so_long.h"
#include "./gnlsolong/get_next_line.h"
#include <stdlib.h>

int	exit_point(t_game *game)
{
	int	line;

	line = 0;
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	exit(0);
}

int main() {

    t_game  game;

    create_map(&game);

    calculate_len(&game, game.map[0]);

    check_map(&game);
    count_collectibles(&game);

    game.win_width = 600;
    game.win_height = 600;
    game.mlx = mlx_init();
    game.win = mlx_new_window(game.mlx, 600, 600, "game map");

    char *path = "first_image.xpm";
    display_image_before(&game, path);

    display_player_pos(&game);
  
    drawGrid(&game);
    
    mlx_key_hook(game.win, controls_working, &game);    

    mlx_loop(game.mlx);
    
    return 0;
}




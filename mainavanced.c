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

    int fd; 
    char *treated_line;

    game.xpm_height = 20;
    game.xpm_width = 20;

    char *name_file;
    name_file = "file2.ber";

    check_extension_file_name(name_file);
    malloc_game();

    fd = open(name_file, O_RDONLY);
    ft_memset(&game, 0, sizeof(t_game));
    // malloc map

    while (1) {
        treated_line = get_next_line(fd);
        // printf("here %s", treated_line);
        save_line_in_map(&game, treated_line);
        if (!treated_line)
			break ;
    }
    
    calculate_len(&game, game.map[0]);

    check_map(&game);
    count_collectibles(&game);

    game.mlx = mlx_init();
    game.win = mlx_new_window(game.mlx, 600, 600, "game map");
    

    game.xpm_height = 50;
    game.xpm_width = 50;


    display_player_pos(&game);
  
    drawGrid(&game);
    
    mlx_key_hook(game.win, controls_working, &game);    

    mlx_loop(game.mlx);
    
    return 0;
}




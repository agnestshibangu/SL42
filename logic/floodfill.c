#include "get_next_line.h"

int map_free_after_flood_fill(t_game *game)
{
    int     nbr_of_lines;

    nbr_of_lines = 0;

    if (game->map != NULL)
    {
        // printf("game map not NULL \n");
        while (game->map[nbr_of_lines++])
            free(game->map[nbr_of_lines]);
        free(game->map);
        // printf("game map freed successfully\n");
    }
    ft_memset(game, 0, sizeof(t_game));
    //printf("memset successfull");
    return (0);
}

void map_len(t_game *game)
{
    int len;

    len = 0;
    while (game->map[0][len])
        len++;
    game->map_width = len;
    printf("map len : %d", game->map_width);
}

void	flood_map(t_game *game, int x, int y) // x and y parameters are the character begining pos
{
	if (game->map[y][x] == '1' || game->map[y][x] == 'F')
		return ;
	game->map[y][x] = 'F';
	flood_map(game, x, y + 1);
	flood_map(game, x, y - 1);
	flood_map(game, x + 1, y);
	flood_map(game, x - 1, y);
}

int     check_flood_fill(t_game *game)
{
    int i;
    int j;

    i = 0;
    j = 0;

    flood_map(game, game->player_pos_x, game->player_pos_y);
    while (game->map[i])
    {
        while (game->map[i][j])
        {   
            if (game->map[i][j] == 'C' || game->map[i][j] == 'E')
            {
                printf(" ! error flood fill error ! ");
                return (-1);
            }
            printf("%c", game->map[i][j]);
            j++;
        }
        i++;
        j = 0;
    }
    printf("\n");
    printf("CHECK FLOOD FILL DONE \n");
    return (0);
}

int     check_flood_fill_map(t_game *game)
{
    create_map(game); // create map from .ber file 
    map_len(game); // calculate map width
    display_player_pos(game); // define player pos
    flood_map(game, game->player_pos_x, game->player_pos_y); // flood fill
    check_flood_fill(game); // check flood fill
    map_free_after_flood_fill(game); // free everything before beginning game
    
    printf("\n");
    printf(" !!! check flood fill DONE !!!");
    return (1);
}


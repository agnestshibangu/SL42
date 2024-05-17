#include "get_next_line.h"

int     display_player_pos(t_game *game)
{
    int x;
    int y;

    y = 0;
    ft_printf("map height %d\n", game->map_height);
    ft_printf("map width %d\n", game->map_width);
    while (y < game->map_height)
    {
        x = 0;
        while (x < game->map_width - 1)
        {
            if (game->map[y][x] == 'P')
            {
                game->player_pos_x = x;
                game->player_pos_y = y;
                ft_printf("player pos x %d\n", game->player_pos_x);
                ft_printf("player pos y %d\n", game->player_pos_y);
                game->map[y][x] = '0';
                return (0);
            }
            x++;
        }
        y++;
    }
    ft_printf("PLAYER POSITION\n");
    return (1);
}

void portal(t_game *game)
{
    if (game->got_collectibles == game->nb_collectibles
        && game->map[game->player_pos_y][game->player_pos_x] == 'E' )
    {
        char *path = "./images_op_end/image_end.xpm";
        mlx_clear_window(game->mlx, game->win);
        free_game(game); // this function frees everything !
        display_image_before(game, path);
    }
}

void walking(t_game *game)
{
    game->steps += 1;
    // printf("step %d", game->steps);
    fflush(stdout); 
}


int move_right(t_game *game)
{   
    int x = 0;
    int y = 0;

    x = game->player_pos_x;
    y = game->player_pos_y;

    if (game->map[y][x + 1] == '1')
        return (0);
    else
    {
        game->player_pos_x += 1;
        game->player_sprite = 0;
        walking(game);
        if (game->map[y][x + 1] == 'C')
        {
            game->got_collectibles++;
            game->map[y][x + 1] = '0';
        }  
       
    }
    drawGrid(game);
    portal(game);
    return (0);
}

int move_left(t_game *game)
{   
    int x = 0;
    int y = 0;

    x = game->player_pos_x;
    y = game->player_pos_y;

    if (game->map[y][x - 1] == '1')
        return (0);
    else
    {
        game->player_pos_x -= 1;
        game->player_sprite = 2;
        walking(game);
        if (game->map[y][x - 1] == 'C')
        {
            game->got_collectibles++;
            fflush(stdout);  
            game->map[y][x - 1] = '0';
        }  
    }
    drawGrid(game);
    portal(game);
    return (0);
}

int move_up(t_game *game)
{   
    int x = 0;
    int y = 0;

    x = game->player_pos_x;
    y = game->player_pos_y;

    if (game->map[y - 1][x] == '1')
        return (0);
    else
    {
        game->player_pos_y -= 1;
        game->player_sprite = 1;
        walking(game);
        if (game->map[y - 1][x] == 'C')
        {
            game->got_collectibles++;
            ft_printf("GOT %d\n", game->got_collectibles);
            fflush(stdout);  
            game->map[y - 1][x] = '0';
        }  

    }
    drawGrid(game);
    portal(game);
    return (0);
}

int move_down(t_game *game)
{   
    int x = 0;
    int y = 0;

    x = game->player_pos_x;
    y = game->player_pos_y;

    if (game->map[y + 1][x] == '1')
        return (0);
    else
    {
        game->player_pos_y += 1;
        game->player_sprite = 3;
        walking(game);
        if (game->map[y + 1][x] == 'C')
        {
            game->got_collectibles++;
            ft_printf("GOT %d\n", game->got_collectibles);
            fflush(stdout);             
            game->map[y + 1][x] = '0';
        }  
    }
    drawGrid(game);
    portal(game);
    return (0);
}



   
int	controls_working(int command, t_game *game)
{
	if (command == 100)
    {
        move_right(game);
    }
    else if (command == 97)  
    {
        move_left(game);
    }
    else if (command == 119)  
    {
        move_up(game);
    }
    else if (command == 115)  
    {
        move_down(game);
    }
	return (1);
}

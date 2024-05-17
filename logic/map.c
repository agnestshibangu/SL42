#include "get_next_line.h"

void    animation_caracter(t_game *game, int x, int y)
{
    // right 
    char *xpm_path_perso = "./images/perso.xpm";
    char *xpm_path_perso_right_right = "./images/perso_right_right.xpm";
    //
    void *xpm_img_perso = mlx_xpm_file_to_image(game->mlx, xpm_path_perso, &game->xpm_width, &game->xpm_height);
    void *xpm_img_perso_right_right = mlx_xpm_file_to_image(game->mlx, xpm_path_perso_right_right, &game->xpm_width, &game->xpm_height);
    
    // up 
    char *xpm_path_perso_up = "./images/perso_up.xpm";
    char *xpm_path_perso_up_up = "./images/perso_up_up.xpm";
    //
    void *xpm_img_perso_up = mlx_xpm_file_to_image(game->mlx, xpm_path_perso_up, &game->xpm_width, &game->xpm_height);
    void *xpm_img_perso_up_up = mlx_xpm_file_to_image(game->mlx, xpm_path_perso_up_up, &game->xpm_width, &game->xpm_height);
    
    // left
    char *xpm_path_perso_left = "./images/perso_left.xpm";
    char *xpm_path_perso_left_left = "./images/perso_left_left.xpm";
    //
    void *xpm_img_perso_left = mlx_xpm_file_to_image(game->mlx, xpm_path_perso_left, &game->xpm_width, &game->xpm_height);
    void *xpm_img_perso_left_left = mlx_xpm_file_to_image(game->mlx, xpm_path_perso_left_left, &game->xpm_width, &game->xpm_height);
    
    // down
    char *xpm_path_perso_down = "./images/perso_down.xpm";
     char *xpm_path_perso_down_down = "./images/perso_down_down.xpm";
    //
    void *xpm_img_perso_down = mlx_xpm_file_to_image(game->mlx, xpm_path_perso_down, &game->xpm_width, &game->xpm_height);
    void *xpm_img_perso_down_down = mlx_xpm_file_to_image(game->mlx, xpm_path_perso_down_down, &game->xpm_width, &game->xpm_height);

    // right
    if ((game->player_sprite == 0) && (game->steps % 2 == 0))
        mlx_put_image_to_window(game->mlx, game->win, xpm_img_perso, x * game->xpm_width, y * game->xpm_height);
    else if ((game->player_sprite == 0) && (game->steps % 2 != 0))
        mlx_put_image_to_window(game->mlx, game->win, xpm_img_perso_right_right, x * game->xpm_width, y * game->xpm_height);
    
    // up
    if ((game->player_sprite == 1) && (game->steps % 2 == 0))
        mlx_put_image_to_window(game->mlx, game->win, xpm_img_perso_up, x * game->xpm_width, y * game->xpm_height);
    else if ((game->player_sprite == 1) && (game->steps % 2 != 0))
        mlx_put_image_to_window(game->mlx, game->win, xpm_img_perso_up_up, x * game->xpm_width, y * game->xpm_height);

    // left
    else if ((game->player_sprite == 2) && (game->steps % 2 == 0))
        mlx_put_image_to_window(game->mlx, game->win, xpm_img_perso_left, x * game->xpm_width, y * game->xpm_height);
    else if ((game->player_sprite == 2) && (game->steps % 2 != 0))
        mlx_put_image_to_window(game->mlx, game->win, xpm_img_perso_left_left, x * game->xpm_width, y * game->xpm_height);

    // down
    else if ((game->player_sprite == 3) && (game->steps % 2 == 0))
        mlx_put_image_to_window(game->mlx, game->win, xpm_img_perso_down, x * game->xpm_width, y * game->xpm_height);
    else if ((game->player_sprite == 3) && (game->steps % 2 != 0))
        mlx_put_image_to_window(game->mlx, game->win, xpm_img_perso_down_down, x * game->xpm_width, y * game->xpm_height);

}



void drawGrid(t_game *game) {

    char *xpm_path_wall = "./images/wall.xpm"; 
    char *xpm_path_ground = "./images/ground.xpm";
    char *xpm_path_collectible = "./images/collectible.xpm";
    char *xpm_path_door = "./images/portal.xpm";

    void *xpm_img_wall = mlx_xpm_file_to_image(game->mlx, xpm_path_wall, &game->xpm_width, &game->xpm_height);
    void *xpm_img_ground = mlx_xpm_file_to_image(game->mlx, xpm_path_ground, &game->xpm_width, &game->xpm_height);

    void *xpm_img_collectible = mlx_xpm_file_to_image(game->mlx, xpm_path_collectible, &game->xpm_width, &game->xpm_height);
    void *xpm_img_door = mlx_xpm_file_to_image(game->mlx, xpm_path_door, &game->xpm_width, &game->xpm_height);

    int y;
    int x;

    y = 0;


    while (y < game->map_height)
    {
        x = 0;
        while (x < game->map_width - 1)
        {
            if ((game->player_pos_y == y) && (game->player_pos_x == x))
            {
                animation_caracter(game, x, y);
            }
            else if (game->map[y][x] == '1')
                mlx_put_image_to_window(game->mlx, game->win, xpm_img_wall, x * game->xpm_width, y * game->xpm_height);
            else if (game->map[y][x] == '0')
                mlx_put_image_to_window(game->mlx, game->win, xpm_img_ground, x * game->xpm_width, y * game->xpm_height);
            else if (game->map[y][x]  == 'C')  
                mlx_put_image_to_window(game->mlx, game->win, xpm_img_collectible, x * game->xpm_width, y * game->xpm_height);
            else if (game->map[y][x]  == 'E') 
                mlx_put_image_to_window(game->mlx, game->win, xpm_img_door, x * game->xpm_width, y * game->xpm_height);
            x++;
        }
        y++;
    }
}

void    count_collectibles(t_game *game)
{
  int y;
    int x;

    y = 0;


    while (y < game->map_height)
    {
        x = 0;
        while (x < game->map_width - 1)
        {
            if (game->map[y][x]  == 'C') 
                game->nb_collectibles += 1;
            x++;
        }
        y++;
    }
    ft_printf("TOTAL COLLECTIBLES: %d\n", game->nb_collectibles);
    fflush(stdout);   
}




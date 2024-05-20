#include "get_next_line.h"

void    animation_caracter(t_game *game, int x, int y)
{
    // void *xpm_img_perso = mlx_xpm_file_to_image(game->mlx, game->images.xpm_path_perso, &game->xpm_w, &game->xpm_h);
    // void *xpm_img_per_rr = mlx_xpm_file_to_image(game->mlx, game->img.x_p_per_rr, &game->x_w, &game->x_h);
    // void *xpm_i_per_u = mlx_xpm_file_to_image(game->mlx, game->img.x_p_per_u, &game->x_w, &game->x_h);
    // void *xpm_img_per_uu = mlx_xpm_file_to_image(game->mlx, game->img.x_p_per_uu, &game->x_w, &game->x_h);
    // void *xpm_img_per_l = mlx_xpm_file_to_image(game->mlx,  game->img.x_p_per_l, &game->x_w, &game->x_h);
    // void *xpm_img_per_ll = mlx_xpm_file_to_image(game->mlx,  game->img.x_p_per_ll, &game->x_w, &game->x_h);
    // void *xpm_img_per_d = mlx_xpm_file_to_image(game->mlx,  game->img.x_p_per_d, &game->x_w, &game->x_h);
    // void *xpm_img_per_dd = mlx_xpm_file_to_image(game->mlx,  game->img.x_p_per_dd, &game->x_w, &game->x_h);

    // right
    if ((game->player_sprite == 0) && (game->steps % 2 == 0))
        mlx_put_image_to_window(game->mlx, game->win, game->img.x_i_per, x * game->x_w, y * game->x_h);
    else if ((game->player_sprite == 0) && (game->steps % 2 != 0))
        mlx_put_image_to_window(game->mlx, game->win, game->img.x_i_per_rr, x * game->x_w, y * game->x_h);
    
    // up
    if ((game->player_sprite == 1) && (game->steps % 2 == 0))
        mlx_put_image_to_window(game->mlx, game->win, game->img.x_i_per_u, x * game->x_w, y * game->x_h);
    else if ((game->player_sprite == 1) && (game->steps % 2 != 0))
        mlx_put_image_to_window(game->mlx, game->win, game->img.x_i_per_uu, x * game->x_w, y * game->x_h);

    // left
    else if ((game->player_sprite == 2) && (game->steps % 2 == 0))
        mlx_put_image_to_window(game->mlx, game->win, game->img.x_i_per_l, x * game->x_w, y * game->x_h);
    else if ((game->player_sprite == 2) && (game->steps % 2 != 0))
        mlx_put_image_to_window(game->mlx, game->win, game->img.x_i_per_ll, x * game->x_w, y * game->x_h);

    // down
    else if ((game->player_sprite == 3) && (game->steps % 2 == 0))
        mlx_put_image_to_window(game->mlx, game->win, game->img.x_i_per_d, x * game->x_w, y * game->x_h);
    else if ((game->player_sprite == 3) && (game->steps % 2 != 0))
        mlx_put_image_to_window(game->mlx, game->win, game->img.x_i_per_dd, x * game->x_w, y * game->x_h);

}



void drawGrid(t_game *game) {

    char *xpm_path_wall = "./images/wall.xpm"; 
    char *xpm_path_ground = "./images/ground.xpm";
    char *xpm_path_collectible = "./images/collectible.xpm";
    char *xpm_path_door = "./images/portal.xpm";

    void *xpm_img_wall = mlx_xpm_file_to_image(game->mlx, xpm_path_wall, &game->x_w, &game->x_h);
    void *xpm_img_ground = mlx_xpm_file_to_image(game->mlx, xpm_path_ground, &game->x_w, &game->x_h);

    void *xpm_img_collectible = mlx_xpm_file_to_image(game->mlx, xpm_path_collectible, &game->x_w, &game->x_h);
    void *xpm_img_door = mlx_xpm_file_to_image(game->mlx, xpm_path_door, &game->x_w, &game->x_h);

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
                mlx_put_image_to_window(game->mlx, game->win, xpm_img_wall, x * game->x_w, y * game->x_h);
            else if (game->map[y][x] == '0')
                mlx_put_image_to_window(game->mlx, game->win, xpm_img_ground, x * game->x_w, y * game->x_h);
            else if (game->map[y][x]  == 'C')  
                mlx_put_image_to_window(game->mlx, game->win, xpm_img_collectible, x * game->x_w, y * game->x_h);
            else if (game->map[y][x]  == 'E') 
                mlx_put_image_to_window(game->mlx, game->win, xpm_img_door, x * game->x_w, y * game->x_h);
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




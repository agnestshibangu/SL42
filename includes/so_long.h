#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../minilibx/mlx.h"

# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100


/* -------------------------------------------------------------------------- */
/*                                                                         */
/* -------------------------------------------------------------------------- */
// 1 on efface le player en affichant le sol a player pos 
// 2 on affiche la texture du player a dest pos  = player pos x y  +- 1
// 3 2fonctions necessaires : quit qui va free toutes tes images en cas de victoire ou de defaite DANS le jeu
// et quit early qui va free AVANT que tu lances le jeu et donc initialise les textures, comme par exemple la map du flood fill



// typedef struct s_data {

// }   t_data;


typedef struct s_pos
{
    int x;
    int y;
}   t_pos;

typedef struct s_player
{
    t_pos   player_pos;
    t_pos   dest_pos;
    int     got_c;
    int     direction;
}   t_player;

typedef struct s_collectibles
{
    t_pos   collec_pos;
}   t_collectibles;

typedef struct s_img
{
    void    *img;
    char    *path_to_xpm;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
    int     width;
    int     height;
}   t_img;


typedef struct s_textures
{
    t_img   ground;
    t_img   wall;
    t_img   player;
    t_img   collectibles;
    t_img   door;
}   t_textures;

typedef struct s_map
{
    int     **map_for_flood_fill;
    char    **true_map;
    int        nb_of_collec;
    int        nb_of_player;
    int        nb_of_exit;
}   t_map;

typedef struct s_data
{
    t_pos           pos;
    t_player        player;
    t_collectibles  collectibles;
    t_map           map;
    t_textures      textures;
}               t_data;




// typedef struct s_caracter {
//     int pos_x;
//     int pos_y;
// }               t_caracter;

/* -------------------------------------------------------------------------- */
/*                                                                         */
/* -------------------------------------------------------------------------- */

// void    init_caracter_position(t_caracter *caracter);

// void    displayMapWithGrid(mlx, mlx_win, img, xpm_img_ground, xpm_img_wall, map, num_rows, num_cols, spacing);

// void displayMapWithGrid(void *mlx, void *mlx_win, t_data img, void *xpm_img_ground, void *xpm_img_wall, char map[][10], int num_rows, int num_cols, int spacing);

// void displayMapWithGrid(t_map *map);
/* -------------------------------------------------------------------------- */
/*                                                                         */
/* -------------------------------------------------------------------------- */




#endif

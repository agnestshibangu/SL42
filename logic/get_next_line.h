#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// #include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1 
# endif

// x = xpm   i = img
typedef struct s_img
{
    char        *x_p_per;
    char        *x_p_per_rr;
    char        *x_p_per_u;
    char        *x_p_per_uu;
    char        *x_p_per_l;
    char        *x_p_per_ll;
    char        *x_p_per_d;
    char        *x_p_per_dd;
    void        *x_i_per;
	void        *x_i_per_rr;
	void        *x_i_per_u;
	void        *x_i_per_uu;
	void        *x_i_per_l;
	void        *x_i_per_ll;
	void        *x_i_per_d;
	void        *x_i_per_dd;


}               t_img;

// x_h == xpm_height
typedef struct s_game
{
    char        **map;
    int         map_height;
    int         map_width;
    int         player_pos_x;
    int         player_pos_y;
    int         player_sprite;
    int         steps;
    void        *mlx;
    void        *win;
    int         x_h;
    int         x_w;
    int         nb_collectibles;
    int         got_collectibles;
    int         game_complete;
    int         win_w;
    int         win_h;
    t_img    img; 
}               t_game;

#include "../my_printf/ft_printf.c"
#include "./gnl_utils.c"
#include "./gnl.c"
#include "./checkmap.c"
#include "./checkmap2.c"
#include "./checkmap3.c"
#include "./map.c"
#include "./init.c"
#include "./free.c"
#include "./controls.c"
#include "./floodfill.c"


int	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int i);
char	*ft_strjoin(char const *s1, char const *s2);
static char *make_line(int fd, char *buffer, char *storage);
static char	*extract(char *line);
char	*get_next_line(int fd);
static void	*ft_memset(void *b, int c, size_t length);
int     calculate_len(t_game *game, char *treated_line);
//int     calculate_len(char *treated_line);

void    display_image_before(t_game *game, char *path);

static int	save_line_in_map(t_game *game, char *line);
int     check_rectangle(t_game *game);
int     check_walls_horizontal(t_game *game);
int     check_walls_vertical(t_game *game);
int     check_allowed_caracters(t_game *game);
t_game *malloc_game(void);
int check_if_rectancle(t_game *game);
int check_map(t_game *game);
void 	init_images(t_game *game);

// map
void    create_map(t_game *game);
void    drawGrid(t_game *game);
void    count_collectibles(t_game *game);
void    window_size(t_game *game);

// floodfill
void    map_len(t_game *game);
void	flood_map(t_game *game, int x, int y);
int     check_flood_fill(t_game *game);
int     map_free_after_flood_fill(t_game *game);
int     check_flood_fill_map(t_game *game);

// void drawGrid(void *mlx, void *mlx_win, int xpm_width, int xpm_height, t_game *game);
// moves
int     display_player_pos(t_game *game);
int	controls_working(int command, t_game *game);
int move_right(t_game *game);
int move_left(t_game *game);
int move_up(t_game *game);
int move_down(t_game *game);
void    move_forward(t_game *game, int y, int x);
void portal(t_game *game);
void    animation_caracter(t_game *game, int x, int y);
// increase step count for animation
void walking(t_game *game);

// free.c
int     free_game(t_game *game);



#endif
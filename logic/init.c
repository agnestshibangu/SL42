/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:12:40 by agtshiba          #+#    #+#             */
/*   Updated: 2024/05/17 13:24:22 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	create_map(t_game *game)
{
	int		fd;
	char	*treated_line;
	char	*name_file;

	name_file = "./ber_files/file2.ber";
	check_extension_file_name(name_file);
	fd = open(name_file, O_RDONLY);
	ft_memset(game, 0, sizeof(t_game));
	while (1) {
		treated_line = get_next_line(fd);
		save_line_in_map(game, treated_line);
		if (!treated_line)
			break ;
	}
}

void	display_image_before(t_game *game, char *path)
{
	void	*img;
	img = mlx_xpm_file_to_image(game->mlx, path, &game->win_w, &game->win_h);

	if (!img){
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		return;
	}
	mlx_put_image_to_window(game->mlx, game->win, img, 0, 0);
	mlx_do_sync(game->mlx);
	usleep(3000000);
	mlx_clear_window(game->mlx, game->win);
}

void	window_size(t_game *game)
{
	int	win_w;
	int	win_h;

	win_w = (game->map_width - 1) * 31;
	win_h = game->map_height * 31;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, win_w, win_h, "game map");
	ft_printf("window size");
}

void 	init_images(t_game *game)
{
	t_game *g = game;
	void *m = g->mlx;
	int *h = &g->x_h;
	int *w = &g->x_w;
	
	g->img.x_p_c = "./images/perso.xpm";
	g->img.x_p_c_rr = "./images/perso_right_right.xpm";
	g->img.x_p_c_u = "./images/perso_up.xpm";
	g->img.x_p_c_uu = "./images/perso_up_up.xpm";	
	g->img.x_p_c_l = "./images/perso_left.xpm";
    g->img.x_p_c_ll = "./images/perso_left_left.xpm";
	g->img.x_p_c_d = "./images/perso_down.xpm";
    g->img.x_p_c_dd = "./images/perso_down_down.xpm";

	g->img.x_i_c = mlx_xpm_file_to_image(m, g->img.x_p_c, w, h);
	g->img.x_i_c_rr = mlx_xpm_file_to_image(m, g->img.x_p_c_rr, w, h);
	g->img.x_i_c_u = mlx_xpm_file_to_image(m, g->img.x_p_c_u, w, h);
	g->img.x_i_c_uu = mlx_xpm_file_to_image(m, g->img.x_p_c_uu, w, h);
	g->img.x_i_c_l = mlx_xpm_file_to_image(m, g->img.x_p_c_l, w, h);
	g->img.x_i_c_ll = mlx_xpm_file_to_image(m, g->img.x_p_c_ll, w, h);
	g->img.x_i_c_d = mlx_xpm_file_to_image(m, g->img.x_p_c_d, w, h);
	g->img.x_i_c_dd = mlx_xpm_file_to_image(m, g->img.x_p_c_dd, w, h);
}
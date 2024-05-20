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
}

void 	init_images(t_game *game)
{
	game->img.x_p_per = "./images/perso.xpm";
	game->img.x_p_per_rr = "./images/perso_right_right.xpm";
	game->img.x_p_per_u = "./images/perso_up.xpm";
	game->img.x_p_per_uu = "./images/perso_up_up.xpm";	
	game->img.x_p_per_l = "./images/perso_left.xpm";
    game->img.x_p_per_ll = "./images/perso_left_left.xpm";
	game->img.x_p_per_d = "./images/perso_down.xpm";
    game->img.x_p_per_dd = "./images/perso_down_down.xpm";

	game->img.x_i_per = mlx_xpm_file_to_image(game->mlx, game->img.x_p_per, &game->x_w, &game->x_h);
	game->img.x_i_per_rr = mlx_xpm_file_to_image(game->mlx, game->img.x_p_per_rr, &game->x_w, &game->x_h);
	game->img.x_i_per_u = mlx_xpm_file_to_image(game->mlx, game->img.x_p_per_u, &game->x_w, &game->x_h);
	game->img.x_i_per_uu = mlx_xpm_file_to_image(game->mlx, game->img.x_p_per_uu, &game->x_w, &game->x_h);
	game->img.x_i_per_l = mlx_xpm_file_to_image(game->mlx, game->img.x_p_per_l, &game->x_w, &game->x_h);
	game->img.x_i_per_ll = mlx_xpm_file_to_image(game->mlx, game->img.x_p_per_ll, &game->x_w, &game->x_h);
	game->img.x_i_per_d = mlx_xpm_file_to_image(game->mlx, game->img.x_p_per_d, &game->x_w, &game->x_h);
	game->img.x_i_per_dd = mlx_xpm_file_to_image(game->mlx, game->img.x_p_per_dd, &game->x_w, &game->x_h);
}
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
	void	*image;
	image = mlx_xpm_file_to_image(game->mlx, path, &game->win_width, &game->win_height);
	if (!image){
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		return;
	}
	mlx_put_image_to_window(game->mlx, game->win, image, 0, 0);
	mlx_do_sync(game->mlx);
	usleep(3000000);
	mlx_clear_window(game->mlx, game->win);
}

void	window_size(t_game *game)
{
	int	window_width;
	int	window_height;

	window_width = (game->map_width - 1) * 31;
	window_height = game->map_height * 31;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, window_width, window_height, "game map");
}

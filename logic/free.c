/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:34:23 by agtshiba          #+#    #+#             */
/*   Updated: 2024/05/17 12:34:30 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	free_game(t_game *game)
{
	int	nbr_of_lines;

	nbr_of_lines = 0;
	if (game->map != NULL)
	{
		while (game->map[nbr_of_lines++])
			free(game->map[nbr_of_lines]);
		free(game->map);
		printf("game map freed successfully\n");
	}
	if (game->win != NULL)
	{
		mlx_destroy_window(game->mlx, game->win);
		game->win = NULL;
		printf("window destroyed !\n");
	}
	if (game->mlx != NULL)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		exit (0);
	}
	return (0);
}

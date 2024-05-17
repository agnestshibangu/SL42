/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:38:36 by agtshiba          #+#    #+#             */
/*   Updated: 2024/05/17 13:57:55 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	*ft_memset(void *b, int c, size_t length)
{
	unsigned char	*p;

	p = (unsigned char *)b;
	while (length--)
	{
		*p++ = (unsigned char)c;
	}
	return (b);
}

t_game	*malloc_game(void)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (game == NULL)
	{
		printf("Allocation de mémoire pour game a échoué");
		return (NULL);
	}
	return (game);
}

int	calculate_len(t_game *game, char *line)
{
	int	len;

	len = 0;
	while (line[len])
		len++;
	game->map_width = len;
	return (0);
}

static int	save_line_in_map(t_game *game, char *line)
{
	char	**temp;
	int		i;

	if (!line)
		return (0);
	i = 0;
	game->map_height++;
	temp = (char **)malloc(sizeof(char *) * (game->map_height + 1));
	temp[game->map_height] = NULL;
	while (i < game->map_height - 1)
	{
		temp[i] = game->map[i];
		i++;
	}
	temp[i] = line;
	if (game->map != NULL)
		free(game->map);
	game->map = temp;
	return (1);
}

int	check_rectangle(t_game *game)
{
	int	height;
	int	i;

	height = game->map_height;
	i = 0;
	while (i < height)
		i++;
	return (1);
}

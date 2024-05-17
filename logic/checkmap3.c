int	check_map(t_game *game)
{
	check_walls_horizontal(game);
	check_walls_vertical(game);
	check_allowed_caracters(game);
	check_if_rectancle(game);
	return (0);
}

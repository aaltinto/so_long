/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaltinto <aaltinto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:35:08 by aaltinto          #+#    #+#             */
/*   Updated: 2023/12/20 13:12:04 by aaltinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	path_checker(t_vars *vars, int length)
{
	char	**visited;

	visited = (char **)ft_calloc(sizeof(char **), vars->width);
	if (visited == NULL)
		return (free_func(vars->map, NULL, NULL, vars->length),
			ft_putendl_fd("Error\nMalloc error!", 2), 0);
	while (length--)
	{
		visited[length] = (char *)ft_calloc(sizeof(char), vars->width);
		if (visited[length] == NULL)
			return (free_func(vars->map, NULL, NULL, vars->length),
				ft_putendl_fd("Error\nMalloc error!", 2), 0);
	}
	pass_the_map(vars, vars->img.p_x, vars->img.p_y, &visited);
	if (!check_visited(vars, visited))
		return (0);
	return (free_func(visited, NULL, NULL, vars->length), 1);
}

void	free_func(char **map, char *str1, char *str2, int check)
{

	if (check != 0)
	{
		while (check--)
			free(map[check]);
		free(map);
	}
	if (str1)
		free(str1);
	if (str2)
		free(str2);
}

void	window_image(t_vars *vars)
{
	int	x;
	int	y;

	x = 60;
	y = 60;
	vars->img.back = mlx_xpm_file_to_image(vars->mlx,
			"textures/sea1.xpm", &x, &y);
	vars->img.wall = mlx_xpm_file_to_image(vars->mlx,
			"textures/Rock1.xpm", &x, &y);
	vars->img.player = mlx_xpm_file_to_image(vars->mlx,
			"textures/man1.xpm", &x, &y);
	vars->img.exit = mlx_xpm_file_to_image(vars->mlx,
			"textures/island.xpm", &x, &y);
	vars->img.collect = mlx_xpm_file_to_image(vars->mlx,
			"textures/aidkit1.xpm", &x, &y);
	if (vars->img.back == NULL || vars->img.wall == NULL
		|| vars->img.player == NULL || vars->img.exit == NULL
		|| vars->img.collect == NULL)
	{
		ft_putendl_fd("Error\nconvert error", 2);
		close_windows(vars);
	}
}

int	close_windows(t_vars *vars)
{
	int	i;

	i = -1;
	if (vars->img.player != NULL)
		mlx_destroy_image(vars->mlx, vars->img.player);
	if (vars->img.collect != NULL)
		mlx_destroy_image(vars->mlx, vars->img.collect);
	if (vars->img.exit != NULL)
		mlx_destroy_image(vars->mlx, vars->img.exit);
	if (vars->img.back != NULL)
		mlx_destroy_image(vars->mlx, vars->img.back);
	if (vars->img.wall != NULL)
		mlx_destroy_image(vars->mlx, vars->img.wall);
	if (vars->map != NULL)
	{
		while (vars->map[++i])
			free(vars->map[i]);
		free(vars->map);
	}
	mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
}

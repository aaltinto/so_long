/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaltinto <aaltinto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:59:43 by aaltinto          #+#    #+#             */
/*   Updated: 2023/12/20 13:21:14 by aaltinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	character_check(char *str)
{
	char	x;
	int		i;

	i = -1;
	while (str[++i])
	{
		x = str[i];
		if (str[0] == '\n')
			return (ft_putendl_fd("Error\nInvalid map", 2), 0);
		if (x == '\n')
		{
			if (str[i + 1] == '\n')
				return (ft_putendl_fd("Error\nInvalid map", 2), 0);
		}
		else if (x != '1' && x != '0' && x != 'C' && x != 'P'
			&& x != 'E')
			return (ft_putendl_fd("Error\nInvalid map", 2), 0);
	}
	return (1);
}

static int	is_valid(t_vars *vars, int x, int y, char **visited)
{
	if ((x < 0 || x > vars->width) && (y < 0 || y > vars->length))
		return (0);
	if (vars->map[y][x] == '1' || visited[y][x] == 'F')
		return (0);
	if (vars->map[y][x] == 'E')
	{
		visited[y][x] = 'F';
		return (0);
	}
	return (1);
}

void	pass_the_map(t_vars *vars, int x, int y, char ***visited)
{
	if (!is_valid(vars, x, y, *visited))
		return ;
	(*visited)[y][x] = 'F';
	pass_the_map(vars, x -1, y, visited);
	pass_the_map(vars, x +1, y, visited);
	pass_the_map(vars, x, y -1, visited);
	pass_the_map(vars, x, y +1, visited);
}

int	check_visited(t_vars *vars, char **visited)
{
	int		i;
	int		j;

	i = -1;
	while (++i < vars->length)
	{
		j = -1;
		while (++j < vars->width)
			if ((vars->map[i][j] == 'C' || vars->map[i][j] == 'E')
				&& visited[i][j] != 'F')
				return (free_func(visited, NULL, NULL, vars->length),
					ft_putendl_fd("Error\nMap is not playable!", 2), 0);
	}
	return (1);
}

int	path_checker(t_vars *vars, int length)
{
	char	**visited;

	visited = (char **)ft_calloc(sizeof(char **), vars->width);
	if (visited == NULL)
		return (free_func(vars->map, NULL, NULL, vars->length),
			ft_putendl_fd("Error\nMalloc error!", 2), 0);
	while (length--)
	{
		visited[length] = (char *)malloc(sizeof(char) * vars->width);
		if (visited[length] == NULL)
			return (free_func(vars->map, NULL, NULL, vars->length),
				ft_putendl_fd("Error\nMalloc error!", 2), 0);
	}
	pass_the_map(vars, vars->img.p_x, vars->img.p_y, &visited);
	if (!check_visited(vars, visited))
		return (0);
	return (free_func(visited, NULL, NULL, vars->length), 1);
}

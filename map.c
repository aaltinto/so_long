/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaltinto <aaltinto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:55:09 by aaltinto          #+#    #+#             */
/*   Updated: 2023/12/15 15:05:19 by aaltinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	extention_control(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (file[len - 1] != 'r' || file[len - 2] != 'e'
		|| file[len - 3] != 'b' || file[len - 4] != '.')
		return (0);
	return (1);
}

static int	border_n_size_check(t_vars *vars)
{
	int		i;
	int		j;
	size_t	tmp;

	tmp = ft_strlen(vars->map[0]);
	i = -1;
	while (vars->map[++i])
	{
		if (ft_strlen(vars->map[i]) != tmp)
			return (ft_putendl_fd("Error\nInvalid map!", 2), 0);
		j = -1;
		while (vars->map[i][++j])
		{
			if ((i == 0) || vars->map[i + 1] == 0)
				if (vars->map[i][j] != '1')
					return (ft_putendl_fd("Invalid map!", 2), 0);
			if ((vars->map[i][j + 1] == 0 || j == 0)
				&& vars->map[i][j] != '1')
				return (ft_putendl_fd("Invalid map!", 2), 0);
		}
	}
	vars->length = i;
	vars->width = j;
	return (1);
}

static int	player_control(t_vars *vars)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (vars->map[++i])
	{
		j = 0;
		while (vars->map[i][++j])
		{
			if (vars->map[i][j] == 'P')
				count ++;
			if (vars->map[i][j] == 'P')
			{
				vars->img.p_x = j;
				vars->img.p_y = i;
			}
		}
	}
	if (count != 1)
		return (ft_putendl_fd("Error\nPlayer count error", 2), 0);
	vars->move = 0;
	return (1);
}

static int	exit_collect_control(t_vars *vars)
{
	int	i;
	int	j;
	int	exit_count;
	int	collect_count;

	i = 0;
	exit_count = 0;
	collect_count = 0;
	while (vars->map[++i])
	{
		j = 0;
		while (vars->map[i][++j])
		{
			if (vars->map[i][j] == 'E')
				exit_count ++;
			if (vars->map[i][j] == 'C')
				collect_count ++;
		}
	}
	if (exit_count != 1)
		return (ft_putendl_fd("Error\nExit count error", 2), 0);
	if (collect_count < 1)
		return (ft_putendl_fd("Error\nCollectable count error", 2), 0);
	vars->count = collect_count;
	return (1);
}

int	map_control(char *arg, t_vars *vars)
{
	if (!extention_control(arg))
		return (ft_putendl_fd("Error\nInvalid file\n", 2), 0);
	vars->map = map_reader(arg);
	if (!vars->map || !border_n_size_check(vars)
		|| !player_control(vars) || !exit_collect_control(vars))
		return (0);
	if (!path_checker(vars, vars->length))
		return (0);
	return (1);
}

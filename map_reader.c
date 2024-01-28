/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaltinto <aaltinto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:59:43 by aaltinto          #+#    #+#             */
/*   Updated: 2023/12/20 13:21:37 by aaltinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_get_next_line/get_next_line.h"
#include <fcntl.h>

static int	character_check(char *str)
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

char	**map_reader(char *map)
{
	char	**ret;
	char	*map_holder;
	char	*line;
	char	*tmp;
	int		fd;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (ft_putendl_fd("Error\nNo such file!\n", 2), NULL);
	map_holder = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		tmp = map_holder;
		map_holder = ft_strjoin(tmp, line);
		free_func(NULL, line, tmp, 0);
	}
	if (!character_check(map_holder))
		exit (1);
	ret = ft_split(map_holder, '\n');
	free(map_holder);
	close(fd);
	return (ret);
}

static int	is_valid(t_vars *vars, int x, int y, char **visited)
{
	if ((x < 0 || x > vars->width) && (y <= 0 || y >= vars->length))
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
	pass_the_map(vars, x, y -1, visited);
	pass_the_map(vars, x +1, y, visited);
	pass_the_map(vars, x, y +1, visited);
}

int	check_visited(t_vars *vars, char **visited)
{
	int		i;
	int		j;

	i = -1;
	while (vars->map[++i])
	{
		j = -1;
		while (vars->map[i][++j])
			if ((vars->map[i][j] == 'C' || vars->map[i][j] == 'E')
				&& visited[i][j] != 'F')
				return (free_func(visited, NULL, NULL, vars->length),
					ft_putendl_fd("Error\nMap is not playable!", 2), 0);
	}
	return (1);
}

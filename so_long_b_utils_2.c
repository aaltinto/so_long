/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_b_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaltinto <aaltinto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 18:21:20 by aaltinto          #+#    #+#             */
/*   Updated: 2023/12/15 15:05:31 by aaltinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "ft_get_next_line/get_next_line.h"
#include <fcntl.h>

void	string_put(t_vars *vars)
{
	char	*move_count;

	move_count = ft_itoa(vars->move);
	mlx_string_put(vars->mlx, vars->win, 20, 35, 0x00FF00, "move count: ");
	mlx_string_put(vars->mlx, vars->win, 100, 35, 0x00FF00, move_count);
	free(move_count);
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
	ret = NULL;
	ret = ft_split(map_holder, '\n');
	return (close(fd), free(map_holder), ret);
}

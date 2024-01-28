/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaltinto <aaltinto@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:35:08 by aaltinto          #+#    #+#             */
/*   Updated: 2023/11/03 13:35:13 by aaltinto         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_func(char **map, char *str1, char *str2, int check)
{
	int	i;

	i = 0;
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

static int	window_image2(t_vars *vars, int x, int y)
{
	vars->img.player[0] = mlx_xpm_file_to_image(vars->mlx,
			"textures/man1.xpm", &x, &y);
	vars->img.player[1] = mlx_xpm_file_to_image(vars->mlx,
			"textures/man2.xpm", &x, &y);
	vars->img.exit = mlx_xpm_file_to_image(vars->mlx,
			"textures/island.xpm", &x, &y);
	vars->img.collect[0] = mlx_xpm_file_to_image(vars->mlx,
			"textures/aidkit1.xpm", &x, &y);
	vars->img.collect[1] = mlx_xpm_file_to_image(vars->mlx,
			"textures/aidkit2.xpm", &x, &y);
	if (vars->img.player[0] == NULL || vars->img.player[1] == NULL
		|| vars->img.exit == NULL || vars->img.collect[0] == NULL
		|| vars->img.collect[1] == NULL || vars->img.collect[1] == NULL)
		return (0);
	return (1);
}

void	window_image(t_vars *vars, int x, int y)
{
	vars->img.back[0] = mlx_xpm_file_to_image(vars->mlx,
			"textures/sea1.xpm", &x, &y);
	vars->img.back[1] = mlx_xpm_file_to_image(vars->mlx,
			"textures/sea2.xpm", &x, &y);
	vars->img.wall[0] = mlx_xpm_file_to_image(vars->mlx,
			"textures/Rock1.xpm", &x, &y);
	vars->img.wall[1] = mlx_xpm_file_to_image(vars->mlx,
			"textures/Rock2.xpm", &x, &y);
	if (!window_image2(vars, x, y) || vars->img.back[1] == NULL
		|| vars->img.back[0] == NULL || vars->img.back[1] == NULL
		|| vars->img.back[0] == NULL)
	{
		ft_putendl_fd("convert error", 2);
		close_windows(vars);
	}
}

int	close_windows(t_vars *vars)
{
	if (vars->img.player[0] != NULL)
		mlx_destroy_image(vars->mlx, vars->img.player[0]);
	if (vars->img.player[1] != NULL)
		mlx_destroy_image(vars->mlx, vars->img.player[1]);
	if (vars->img.collect[0] != NULL)
		mlx_destroy_image(vars->mlx, vars->img.collect[0]);
	if (vars->img.collect[1] != NULL)
		mlx_destroy_image(vars->mlx, vars->img.collect[1]);
	if (vars->img.exit != NULL)
		mlx_destroy_image(vars->mlx, vars->img.exit);
	if (vars->img.back[0] != NULL)
		mlx_destroy_image(vars->mlx, vars->img.back[0]);
	if (vars->img.back[1] != NULL)
		mlx_destroy_image(vars->mlx, vars->img.back[1]);
	if (vars->img.wall[0] != NULL)
		mlx_destroy_image(vars->mlx, vars->img.wall[0]);
	if (vars->img.wall[1] != NULL)
		mlx_destroy_image(vars->mlx, vars->img.wall[1]);
	if (vars->map != NULL)
		free_func(vars->map, NULL, NULL, vars->length);
	mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
}

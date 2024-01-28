/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaltinto <aaltinto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:40:41 by aaltinto          #+#    #+#             */
/*   Updated: 2023/12/20 13:09:43 by aaltinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_vars *vars, char c, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.back, x, y);
	if (c == 'P')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img.player, x, y);
	if (c == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.wall, x, y);
	if (c == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img.collect, x, y);
	if (c == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.exit, x, y);
}

int	built_map(t_vars *vars)
{
	int	i;
	int	j;

	mlx_clear_window(vars->mlx, vars->win);
	i = -1;
	while (vars->map[++i])
	{
		j = -1;
		while (vars->map[i][++j])
			put_image(vars, vars->map[i][j], (j * 64), (i * 64));
	}
	return (1);
}

int	change_position(t_vars *vars, int x, int y)
{
	if (vars->map[y][x] == '1')
		return (1);
	if (vars->map[y][x] == 'E' && vars->count)
		return (1);
	if (vars->map[y][x] == 'C')
		vars->count--;
	if (vars->map[y][x] == 'E' && !vars->count)
		close_windows(vars);
	vars->map[y][x] = 'P';
	vars->map[vars->img.p_y][vars->img.p_x] = '0';
	vars->img.p_x = x;
	vars->img.p_y = y;
	mlx_clear_window(vars->mlx, vars->win);
	built_map(vars);
	vars->move++;
	ft_printf("Movement count: %i\n", vars->move);
	return (0);
}

int	walk(int keycode, t_vars *vars)
{
	if (keycode == ESC)
		close_windows(vars);
	if (keycode == A)
		change_position(vars, vars->img.p_x - 1, vars->img.p_y);
	if (keycode == S)
		change_position(vars, vars->img.p_x, vars->img.p_y + 1);
	if (keycode == D)
		change_position(vars, vars->img.p_x + 1, vars->img.p_y);
	if (keycode == W)
		change_position(vars, vars->img.p_x, vars->img.p_y - 1);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_vars	vars;

	if (argc == 2)
	{
		if (!map_control(argv[1], &vars))
			exit(1);
		vars.mlx = mlx_init();
		if (vars.mlx == NULL)
			return (ft_putendl_fd("Error\nmlx couldn't set", 2), 1);
		vars.win = mlx_new_window(vars.mlx, (vars.width * 64), vars.length * 64,
				"so_long");
		if (vars.win == NULL)
			return (free(vars.mlx),
				ft_putendl_fd("Error\nwin couldn't opened", 2), 1);
		window_image(&vars);
		built_map(&vars);
		mlx_hook(vars.win, 17, 0, close_windows, &vars);
		mlx_hook(vars.win, 02, 0, walk, &vars);
		mlx_loop_hook(vars.mlx, built_map, &vars);
		mlx_loop(vars.mlx);
	}
	else
		ft_putendl_fd("Error\nInvalid argument!", 2);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaltinto <aaltinto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:42:16 by aaltinto          #+#    #+#             */
/*   Updated: 2023/12/15 14:58:58 by aaltinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include "mlx/mlx.h"
# include <stdlib.h>

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2

typedef struct s_data
{
	void	*player;
	int		p_x;
	int		p_y;
	void	*collect;
	void	*wall;
	void	*exit;
	void	*back;
}	t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		move;
	int		count;
	char	**map;
	int		width;
	int		length;
	t_data	img;
}				t_vars;

int		map_control(char *arg, t_vars *vars);
void	free_func(char **map, char *str1, char *str2, int check);
int		built_map(t_vars *vars);
void	window_image(t_vars *vars);
int		close_windows(t_vars *vars);
int		path_checker(t_vars *vars, int length);
int		check_visited(t_vars *vars, char **visited);
void	pass_the_map(t_vars *vars, int x, int y, char ***visited);
char	**map_reader(char *map);

#endif

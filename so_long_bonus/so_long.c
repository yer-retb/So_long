/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 00:05:31 by yer-retb          #+#    #+#             */
/*   Updated: 2022/07/02 12:52:02 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_soul(int x, int y)
{
	g_soul.backround = mlx_xpm_file_to_image
		(g_soul.mlx, "./xpm/backround.xpm", &y, &x);
	g_soul.player = mlx_xpm_file_to_image
		(g_soul.mlx, "./xpm/Player.xpm", &y, &x);
	g_soul.p_down = mlx_xpm_file_to_image
		(g_soul.mlx, "./xpm/P_down.xpm", &y, &x);
	g_soul.p_left = mlx_xpm_file_to_image
		(g_soul.mlx, "./xpm/P_left.xpm", &y, &x);
	g_soul.p_right = mlx_xpm_file_to_image
		(g_soul.mlx, "./xpm/P_right.xpm", &y, &x);
	g_soul.enem_one = mlx_xpm_file_to_image(g_soul.mlx, "./xpm/1.xpm", &y, &x);
	g_soul.enem_tow = mlx_xpm_file_to_image(g_soul.mlx, "./xpm/2.xpm", &y, &x);
	g_soul.enem_thre = mlx_xpm_file_to_image(g_soul.mlx, "./xpm/3.xpm", &y, &x);
	g_soul.enem_four = mlx_xpm_file_to_image(g_soul.mlx, "./xpm/4.xpm", &y, &x);
	g_soul.enem_five = mlx_xpm_file_to_image(g_soul.mlx, "./xpm/5.xpm", &y, &x);
	g_soul.c1 = mlx_xpm_file_to_image(g_soul.mlx, "./xpm/c1.xpm", &y, &x);
	g_soul.open_door = mlx_xpm_file_to_image
		(g_soul.mlx, "./xpm/opendoor.xpm", &y, &x);
	g_soul.close_door = mlx_xpm_file_to_image
		(g_soul.mlx, "./xpm/closdoor.xpm", &y, &x);
	g_soul.wall = mlx_xpm_file_to_image(g_soul.mlx, "./xpm/wall.xpm", &y, &x);
}

void	image_to_win(int i, int j)
{
	if (g_soul.map[i][j] == '1')
		mlx_put_image_to_window(g_soul.mlx, g_soul.mlx_win,
			g_soul.wall, j * 64, i * 64);
	if (g_soul.map[i][j] == 'E')
		mlx_put_image_to_window(g_soul.mlx, g_soul.mlx_win,
			g_soul.close_door, j * 64, i * 64);
	if (g_soul.map[i][j] == 'C')
		mlx_put_image_to_window(g_soul.mlx, g_soul.mlx_win,
			g_soul.c1, j * 64, i * 64);
	if (g_soul.map[i][j] == '0')
		mlx_put_image_to_window
			(g_soul.mlx, g_soul.mlx_win, g_soul.backround, j * 64, i * 64);
	if (g_soul.map[i][j] == 'X')
		mlx_put_image_to_window(g_soul.mlx, g_soul.mlx_win,
			g_soul.enem_five, j * 64, i * 64);
	if (g_soul.map[i][j] == 'P')
		mlx_put_image_to_window(g_soul.mlx, g_soul.mlx_win,
			g_soul.player, j * 64, i * 64);
}

void	put_image(void)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < g_soul.length)
	{
		j = 0;
		while (g_soul.map[i][j] != '\0')
		{
			image_to_win(i, j);
			j++;
		}
		i++;
	}
}

void	the_image(void)
{
	int	x;
	int	y;
	int	i;
	int	j;

	i = 0;
	x = 0;
	y = 0;
	g_soul.mlx = mlx_init();
	g_soul.mlx_win = mlx_new_window(g_soul.mlx,
			(g_soul.width) * 64, g_soul.length * 64, "so_long");
	init_soul(x, y);
	while (i < g_soul.length)
	{
		j = -1;
		while (++j < g_soul.width)
			mlx_put_image_to_window
				(g_soul.mlx, g_soul.mlx_win, g_soul.backround, j * 64, i * 64);
		i++;
	}
}

int	main(int ac, char **av)
{
	int	x;

	x = 0;
	if (ac != 2)
		print_error('a');
	check_ber(av[1]);
	g_soul.size = size_of_allocation(av);
	ft_map(av, g_soul.size);
	check_wall();
	the_image();
	put_image();
	count_enemies();
	set_enemies();
	mlx_loop_hook(g_soul.mlx, render_enemie, &x);
	mlx_hook(g_soul.mlx_win, 2, 0, move_player, NULL);
	mlx_hook(g_soul.mlx_win, 17, 0, exit_game, NULL);
	mlx_loop(g_soul.mlx);
}

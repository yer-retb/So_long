/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 00:05:31 by yer-retb          #+#    #+#             */
/*   Updated: 2022/06/29 10:36:47 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_position(int i, int j, char c)
{
	if (c == 'u')
		mlx_put_image_to_window(g_soul.mlx, g_soul.mlx_win,
			g_soul.player, j * 64, i * 64);
	if (c == 'd')
		mlx_put_image_to_window(g_soul.mlx, g_soul.mlx_win,
			g_soul.p_down, j * 64, i * 64);
	if (c == 'l')
		mlx_put_image_to_window(g_soul.mlx, g_soul.mlx_win,
			g_soul.p_left, j * 64, i * 64);
	if (c == 'r')
		mlx_put_image_to_window(g_soul.mlx, g_soul.mlx_win,
			g_soul.p_right, j * 64, i * 64);
}

void	image_to_win(int i, int j, char c)
{
	if (g_soul.map[i][j] == '1')
		mlx_put_image_to_window(g_soul.mlx, g_soul.mlx_win,
			g_soul.wall, j * 64, i * 64);
	if (g_soul.map[i][j] == 'E')
		mlx_put_image_to_window(g_soul.mlx, g_soul.mlx_win,
			g_soul.close_door, j * 64, i * 64);
	if (g_soul.map[i][j] == 'C')
		mlx_put_image_to_window(g_soul.mlx, g_soul.mlx_win,
			g_soul.coin, j * 64, i * 64);
	if (g_soul.map[i][j] == 'P')
		player_position(i, j, c);
}

void	put_image(char c)
{
	int	i;
	int	j;

	i = 0;
	mlx_put_image_to_window
		(g_soul.mlx, g_soul.mlx_win, g_soul.backround, 0, 0);
	while (i < g_soul.length)
	{
		j = 0;
		while (g_soul.map[i][j] != '\0')
		{
			image_to_win(i, j, c);
			j++;
		}
		i++;
	}
}

void	init_soul(int x, int y)
{
	g_soul.backround = mlx_xpm_file_to_image
		(g_soul.mlx, "brr1.xpm", &y, &x);
	g_soul.player = mlx_xpm_file_to_image(g_soul.mlx, "Player.xpm", &y, &x);
	g_soul.p_down = mlx_xpm_file_to_image(g_soul.mlx, "P_down.xpm", &y, &x);
	g_soul.p_left = mlx_xpm_file_to_image(g_soul.mlx, "P_left.xpm", &y, &x);
	g_soul.p_right = mlx_xpm_file_to_image(g_soul.mlx, "P_right.xpm", &y, &x);
	g_soul.enem_one = mlx_xpm_file_to_image(g_soul.mlx, "1.xpm", &y, &x);
	g_soul.enem_tow = mlx_xpm_file_to_image(g_soul.mlx, "2.xpm", &y, &x);
	g_soul.enem_thre = mlx_xpm_file_to_image(g_soul.mlx, "3.xpm", &y, &x);
	g_soul.enem_four = mlx_xpm_file_to_image(g_soul.mlx, "4.xpm", &y, &x);
	g_soul.enem_five = mlx_xpm_file_to_image(g_soul.mlx, "5.xpm", &y, &x);
	g_soul.coin = mlx_xpm_file_to_image(g_soul.mlx, "coin.xpm", &y, &x);
	g_soul.open_door = mlx_xpm_file_to_image
		(g_soul.mlx, "opendoor.xpm", &y, &x);
	g_soul.close_door = mlx_xpm_file_to_image
		(g_soul.mlx, "closdoor.xpm", &y, &x);
	g_soul.wall = mlx_xpm_file_to_image(g_soul.mlx, "wall.xpm", &y, &x);
}

void	the_image(void)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	g_soul.mlx = mlx_init();
	g_soul.mlx_win = mlx_new_window(g_soul.mlx,
			(g_soul.width) * 64, g_soul.length * 64, "so_long");
	init_soul(x, y);
}

int	render_enemie(void)
{
	int	i;
	int	j;

	i = 0;
	if (g_soul.cont >= 40000)
		g_soul.cont = 0;
	while (i < g_soul.length)
	{
		j = 0;
		while (g_soul.map[i][j] != '\0')
		{
			if (g_soul.map[i][j] == 'X' && g_soul.cont < 6000)
				mlx_put_image_to_window(g_soul.mlx, g_soul.mlx_win,
					g_soul.enem_one, j * 64, i * 64);
			if (g_soul.map[i][j] == 'X' && g_soul.cont > 6000 && g_soul.cont > 12000)
				mlx_put_image_to_window(g_soul.mlx, g_soul.mlx_win,
					g_soul.enem_tow, j * 64, i * 64);
			if (g_soul.map[i][j] == 'X' && g_soul.cont > 12000 && g_soul.cont > 18000)
				mlx_put_image_to_window(g_soul.mlx, g_soul.mlx_win,
					g_soul.enem_thre, j * 64, i * 64);
			if (g_soul.map[i][j] == 'X' && g_soul.cont > 18000 && g_soul.cont > 22000)
				mlx_put_image_to_window(g_soul.mlx, g_soul.mlx_win,
					g_soul.enem_four, j * 64, i * 64);
			if (g_soul.map[i][j] == 'X' && g_soul.cont > 22000 && g_soul.cont >= 36000)
				mlx_put_image_to_window(g_soul.mlx, g_soul.mlx_win,
					g_soul.enem_five, j * 64, i * 64);
			g_soul.cont++;
			j++;
		}
		i++;
	}
	return (0);
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
	put_image('u');
	mlx_loop_hook(g_soul.mlx, render_enemie, &x);
	mlx_hook(g_soul.mlx_win, 2, 0, move_player, NULL);
	mlx_hook(g_soul.mlx_win, 17, 0, exit_game, NULL);
	mlx_loop(g_soul.mlx);
}

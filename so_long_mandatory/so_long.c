/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 00:05:31 by yer-retb          #+#    #+#             */
/*   Updated: 2022/06/27 11:22:14 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	image_to_win(int i, int j)
{
	if (g_soul.map[i][j] == '1')
		mlx_put_image_to_window(g_soul.mlx, g_soul.mlx_win,
			g_soul.wall, j * 64, i * 64);
	if (g_soul.map[i][j] == '0')
		mlx_put_image_to_window(g_soul.mlx, g_soul.mlx_win,
			g_soul.backround, j * 64, i * 64);
	if (g_soul.map[i][j] == 'E')
		mlx_put_image_to_window(g_soul.mlx, g_soul.mlx_win,
			g_soul.close_door, j * 64, i * 64);
	if (g_soul.map[i][j] == 'C')
		mlx_put_image_to_window(g_soul.mlx, g_soul.mlx_win,
			g_soul.coin, j * 64, i * 64);
	if (g_soul.map[i][j] == 'P')
		mlx_put_image_to_window(g_soul.mlx, g_soul.mlx_win,
			g_soul.player, j * 64, i * 64);
}

void	put_image(void)
{
	int	i;
	int	j;

	i = 0;
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

void	init_soul(int x, int y)
{
	g_soul.backround = mlx_xpm_file_to_image
		(g_soul.mlx, "backround.xpm", &y, &x);
	g_soul.player = mlx_xpm_file_to_image(g_soul.mlx, "Player.xpm", &y, &x);
	g_soul.p_down = mlx_xpm_file_to_image(g_soul.mlx, "P_down.xpm", &y, &x);
	g_soul.p_left = mlx_xpm_file_to_image(g_soul.mlx, "P_left.xpm", &y, &x);
	g_soul.p_right = mlx_xpm_file_to_image(g_soul.mlx, "P_right.xpm", &y, &x);
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
	if (ac != 2)
		print_error('a');
	check_ber(av[1]);
	g_soul.size = size_of_allocation(av);
	ft_map(av, g_soul.size);
	check_wall();
	the_image();
	put_image();
	mlx_key_hook(g_soul.mlx_win, move_player, NULL);
	mlx_hook(g_soul.mlx_win, 17, 1L << 2, exit_game, NULL);
	mlx_loop(g_soul.mlx);
}

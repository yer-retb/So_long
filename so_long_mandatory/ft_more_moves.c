/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_more_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 11:10:29 by yer-retb          #+#    #+#             */
/*   Updated: 2022/06/27 12:33:27 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_door(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < g_soul.length)
	{
		j = 0;
		while (g_soul.map[i][j] != '\0')
		{
			if (g_soul.cont_coin == 0 && g_soul.map[i][j] == 'E')
				mlx_put_image_to_window(g_soul.mlx, g_soul.mlx_win,
					g_soul.open_door, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

void	right(int i, int j)
{
	if (checker(i, j + 1))
		return ;
	if (g_soul.map[i][j + 1] == 'C')
		g_soul.cont_coin -= 2;
	g_soul.map[i][j + 1] = 'P';
	g_soul.map[i][j] = '0';
	mlx_put_image_to_window(g_soul.mlx, g_soul.mlx_win,
		g_soul.backround, j * 64, i * 64);
	mlx_put_image_to_window(g_soul.mlx, g_soul.mlx_win,
		g_soul.backround, (j + 1) * 64, i * 64);
	mlx_put_image_to_window(g_soul.mlx, g_soul.mlx_win,
		g_soul.p_right, (j + 1) * 64, i * 64);
	g_soul.steps++;
	ft_printf("%d\n", g_soul.steps);
}

void	ft_move_right(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < g_soul.length)
	{
		j = 0;
		while (g_soul.map[i][j] != '\0')
		{
			if (g_soul.map[i][j] == 'P' && g_soul.map[i][j + 1] != '1')
			{
				right(i, j);
				open_door();
				return ;
			}
			j++;
		}
		i++;
	}
}

void	left(int i, int j)
{
	if (checker(i, j - 1))
		return ;
	if (g_soul.map[i][j - 1] == 'C')
		g_soul.cont_coin -= 2;
	g_soul.map[i][j - 1] = 'P';
	g_soul.map[i][j] = '0';
	mlx_put_image_to_window(g_soul.mlx, g_soul.mlx_win,
		g_soul.backround, j * 64, i * 64);
	mlx_put_image_to_window(g_soul.mlx, g_soul.mlx_win,
		g_soul.backround, (j - 1) * 64, i * 64);
	mlx_put_image_to_window(g_soul.mlx, g_soul.mlx_win,
		g_soul.p_left, (j - 1) * 64, i * 64);
	g_soul.steps++;
	ft_printf("%d\n", g_soul.steps);
}

void	ft_move_left(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < g_soul.length)
	{
		j = 0;
		while (g_soul.map[i][j] != '\0')
		{
			if (g_soul.map[i][j] == 'P' && g_soul.map[i][j - 1] != '1')
			{
				left(i, j);
				open_door();
				return ;
			}
			j++;
		}
		i++;
	}
}

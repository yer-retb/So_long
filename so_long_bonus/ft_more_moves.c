/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_more_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 11:10:29 by yer-retb          #+#    #+#             */
/*   Updated: 2022/06/29 08:58:00 by yer-retb         ###   ########.fr       */
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
	put_image('r');
	g_soul.steps++;
	g_soul.conter = ft_itoa(g_soul.steps);
	mlx_string_put(g_soul.mlx, g_soul.mlx_win, 27, 19, 0xFFD700, g_soul.conter);
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
				enemie(i, (j + 1));
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
	put_image('l');
	g_soul.steps++;
	g_soul.conter = ft_itoa(g_soul.steps);
	mlx_string_put(g_soul.mlx, g_soul.mlx_win, 27, 19, 0xFFD700, g_soul.conter);
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
				enemie(i, (j - 1));
				left(i, j);
				open_door();
				return ;
			}
			j++;
		}
		i++;
	}
}

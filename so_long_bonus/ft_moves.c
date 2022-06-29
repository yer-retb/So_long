/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 09:03:46 by yer-retb          #+#    #+#             */
/*   Updated: 2022/06/29 08:58:07 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checker(int i, int j)
{
	if (g_soul.map[i][j] == 'E' && g_soul.cont_coin != 0)
		return (1);
	else if (g_soul.map[i][j] == 'E' && g_soul.cont_coin == 0)
	{
		//ft_printf("%d\n", g_soul.steps + 1);
		ft_printf("\033[1;32mYOU WIN\n");
		exit(1);
	}
	return (0);
}

int	enemie(int i, int j)
{
	if (g_soul.map[i][j] == 'X')
	{
		//ft_printf("%d\n", g_soul.steps + 1);
		ft_printf("\033[1;31mYOU LOSE\n");
		exit(1);
	}
	return (0);
}

void	up(int i, int j)
{
	if (checker(i - 1, j))
		return ;
	if (g_soul.map[i - 1][j] == 'C')
		g_soul.cont_coin -= 2;
	g_soul.map[i - 1][j] = 'P';
	g_soul.map[i][j] = '0';
	put_image('u');
	g_soul.steps++;
	g_soul.conter = ft_itoa(g_soul.steps);
	mlx_string_put(g_soul.mlx, g_soul.mlx_win, 27, 19, 0xFFD700, g_soul.conter);
}

void	ft_move_up(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < g_soul.length)
	{
		j = 0;
		while (g_soul.map[i][j] != '\0')
		{
			if (g_soul.map[i][j] == 'P' && g_soul.map[i - 1][j] != '1')
			{
				enemie((i - 1), j);
				up(i, j);
				open_door();
				return ;
			}
			j++;
		}
		i++;
	}
}

void	down(int i, int j)
{
	if (checker(i + 1, j))
		return ;
	if (g_soul.map[i + 1][j] == 'C')
		g_soul.cont_coin -= 2;
	g_soul.map[i + 1][j] = 'P';
	g_soul.map[i][j] = '0';
	put_image('d');
	g_soul.steps++;
	g_soul.conter = ft_itoa(g_soul.steps);
	mlx_string_put(g_soul.mlx, g_soul.mlx_win, 27, 19, 0xFFD700, g_soul.conter);
}

void	ft_move_down(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < g_soul.length)
	{
		j = 0;
		while (g_soul.map[i][j] != '\0')
		{
			if (g_soul.map[i][j] == 'P' && g_soul.map[i + 1][j] != '1')
			{
				enemie((i + 1), j);
				down(i, j);
				open_door();
				return ;
			}
			j++;
		}
		i++;
	}
}

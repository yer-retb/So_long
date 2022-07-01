/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 09:03:46 by yer-retb          #+#    #+#             */
/*   Updated: 2022/07/01 13:40:14 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checker(int i, int j)
{
	if (g_soul.map[i][j] == 'E' && g_soul.cont_coin != 0)
		return (1);
	else if (g_soul.map[i][j] == 'E' && g_soul.cont_coin == 0)
	{
		ft_printf("\033[1;32mYOU WIN\n");
		ft_free();
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
	mlx_put_image_to_window(g_soul.mlx, g_soul.mlx_win,
		g_soul.backround, j * 64, i * 64);
	mlx_put_image_to_window(g_soul.mlx, g_soul.mlx_win,
		g_soul.backround, j * 64, (i - 1) * 64);
	mlx_put_image_to_window(g_soul.mlx, g_soul.mlx_win,
		g_soul.player, j * 64, (i - 1) * 64);
	g_soul.steps++;
	if (g_soul.conter != NULL)
		free(g_soul.conter);
	g_soul.conter = ft_itoa(g_soul.steps);
	put_string_in_win(g_soul.conter);
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
				enemie();
				up(i, j);
				g_soul.king.i--;
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
	mlx_put_image_to_window(g_soul.mlx, g_soul.mlx_win,
		g_soul.backround, j * 64, i * 64);
	mlx_put_image_to_window(g_soul.mlx, g_soul.mlx_win,
		g_soul.backround, j * 64, (i + 1) * 64);
	mlx_put_image_to_window(g_soul.mlx, g_soul.mlx_win,
		g_soul.p_down, j * 64, (i + 1) * 64);
	g_soul.steps++;
	if (g_soul.conter != NULL)
		free(g_soul.conter);
	g_soul.conter = ft_itoa(g_soul.steps);
	put_string_in_win(g_soul.conter);
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
				enemie();
				down(i, j);
				g_soul.king.i++;
				open_door();
				return ;
			}
			j++;
		}
		i++;
	}
}

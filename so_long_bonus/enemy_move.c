/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:35:59 by yer-retb          #+#    #+#             */
/*   Updated: 2022/07/01 15:22:35 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy_right(int i)
{
	mlx_put_image_to_window(g_soul.mlx, g_soul.mlx_win,
		g_soul.backround, (g_soul.enem[i].j) * 64,
		(g_soul.enem[i].i) * 64);
	mlx_put_image_to_window(g_soul.mlx, g_soul.mlx_win,
		g_soul.enem_thre, (g_soul.enem[i].j + 1) * 64,
		(g_soul.enem[i].i) * 64);
		g_soul.map[g_soul.enem[i].i][g_soul.enem[i].j] = '0';
		g_soul.map[g_soul.enem[i].i][g_soul.enem[i].j + 1] = 'X';
		g_soul.enem[i].j++;
	get_direction();
}

void	enemy_left(int i)
{
	mlx_put_image_to_window(g_soul.mlx, g_soul.mlx_win,
		g_soul.backround, (g_soul.enem[i].j) * 64,
		(g_soul.enem[i].i) * 64);
	mlx_put_image_to_window(g_soul.mlx, g_soul.mlx_win,
		g_soul.enem_five, (g_soul.enem[i].j - 1) * 64,
		(g_soul.enem[i].i) * 64);
	g_soul.map[g_soul.enem[i].i][g_soul.enem[i].j] = '0';
	g_soul.map[g_soul.enem[i].i][g_soul.enem[i].j - 1] = 'X';
	g_soul.enem[i].j--;
	get_direction();
}

void	move_enemie(void)
{
	int	i;

	i = 0;
	while (i < g_soul.enemies)
	{
		enemie();
		if (g_soul.map[g_soul.enem[i].i][g_soul.enem[i].j] == 'X'
			&& g_soul.map[g_soul.enem[i].i][g_soul.enem[i].j + 1] != '1'
				&& g_soul.enem[i].dir == 1)
			enemy_right(i);
		else if (g_soul.map[g_soul.enem[i].i][g_soul.enem[i].j] == 'X'
			&& g_soul.map[g_soul.enem[i].i][g_soul.enem[i].j - 1] != '1'
				&& g_soul.enem[i].dir == 0)
			enemy_left(i);
		i++;
	}
}

void	put_string_in_win(char *str)
{
	mlx_put_image_to_window(g_soul.mlx, g_soul.mlx_win, g_soul.wall, 64, 0);
	mlx_string_put(g_soul.mlx, g_soul.mlx_win, 0, 19, 0xFFD700, str);
}

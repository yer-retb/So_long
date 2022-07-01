/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:26:22 by yer-retb          #+#    #+#             */
/*   Updated: 2022/07/01 15:17:48 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_enemies(void)
{
	int	i;
	int	j;

	i = 0;
	while (g_soul.map[i])
	{
		j = 0;
		while (g_soul.map[i][j])
		{
			if (g_soul.map[i][j] == 'X')
				g_soul.enemies++;
			else if (g_soul.map[i][j] == 'P')
			{
				g_soul.king.i = i;
				g_soul.king.j = j;
			}
			j++;
		}
		i++;
	}
}

void	set_enemies(void)
{
	int	i;
	int	j;
	int	z;

	i = 0;
	z = 0;
	g_soul.enem = malloc (sizeof(t_enemie) * g_soul.enemies);
	while (g_soul.map[i])
	{
		j = 0;
		while (g_soul.map[i][j])
		{
			if (g_soul.map[i][j] == 'X')
			{
				g_soul.enem[z].i = i;
				g_soul.enem[z].j = j;
				g_soul.enem[z++].dir = 1;
			}
			j++;
		}
		i++;
	}
}

void	get_direction(void)
{
	int	i;

	i = 0;
	while (i < g_soul.enemies)
	{
		if (g_soul.enem[i].dir == 1)
		{
			if (g_soul.map[g_soul.enem[i].i][g_soul.enem[i].j + 1] == '1'
				|| g_soul.map[g_soul.enem[i].i][g_soul.enem[i].j + 1] == 'C'
				|| g_soul.map[g_soul.enem[i].i][g_soul.enem[i].j + 1] == 'E')
				g_soul.enem[i].dir = 0;
		}
		else
		{
			if (g_soul.map[g_soul.enem[i].i][g_soul.enem[i].j - 1] == '1'
				|| g_soul.map[g_soul.enem[i].i][g_soul.enem[i].j - 1] == 'C'
				|| g_soul.map[g_soul.enem[i].i][g_soul.enem[i].j - 1] == 'E')
				g_soul.enem[i].dir = 1;
		}
		i++;
	}
}

void	enemie(void)
{
	int	i;

	i = 0;
	while (i < g_soul.enemies)
	{
		if (g_soul.enem[i].i == g_soul.king.i
			&& g_soul.enem[i].j == g_soul.king.j)
		{
			ft_printf("\033[1;31mYOU LOSE\n");
			ft_free();
			exit(1);
		}
		i++;
	}
}

int	render_enemie(void)
{
	if (g_speed == 2000)
	{
		get_direction();
		move_enemie();
		g_speed = 0;
	}
	g_speed++;
	return (0);
}

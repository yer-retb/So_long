/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 09:20:53 by yer-retb          #+#    #+#             */
/*   Updated: 2022/06/30 18:26:30 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(char c)
{
	if (c == 'a')
	{
		ft_printf("\033[1;31mCHECK YOUR ARGS \n");
		exit(1);
	}
	if (c == 'M')
	{
		ft_printf("\033[1;31mCHECK YOUR MAP \n");
		exit(1);
	}
	if (c == 'm')
	{
		ft_printf("\033[1;31mEMPTY MAP \n");
		exit(1);
	}
	if (c == 'b')
	{
		ft_printf("\033[1;31mCHECK YOUR .ber \n");
		exit(1);
	}
}

void	check_ber(char *av)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = "reb.";
	while (av[i] != '\0')
		i++;
	i--;
	while (str[j] != '\0')
	{
		if (str[j] != av[i])
			print_error('b');
		i--;
		j++;
	}
}

void	ft_map(char **av, int size)
{
	int	fd;
	int	idx;

	idx = 0;
	fd = open(av[1], O_RDWR);
	g_soul.map = malloc(sizeof(char *) * (size + 1));
	g_soul.map[idx] = get_next_line(fd);
	if (g_soul.map[0] == NULL)
		print_error('m');
	while (g_soul.map[idx] != NULL)
		g_soul.map[++idx] = get_next_line(fd);
	g_soul.map[idx] = NULL;
	if (g_soul.the_n[0] == '\n')
		print_error('M');
	if (g_soul.the_n[g_soul.width] == '\n')
		print_error('M');
}

int	move_player(int keyhook)
{
	if (keyhook == 13 || keyhook == 126)
		ft_move_up();
	if (keyhook == 1 || keyhook == 125)
		ft_move_down();
	if (keyhook == 0 || keyhook == 123)
		ft_move_left();
	if (keyhook == 2 || keyhook == 124)
		ft_move_right();
	if (keyhook == 53)
		exit(1);
	return (0);
}

int	exit_game(int key)
{
	if (key == 0)
		exit(1);
	return (0);
}


void	count_enemies()
{
	int i;
	int j;

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

void	set_enemies()
{
	int i;
	int j;
	int z;

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

void	get_direction()
{
	int i;

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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 09:20:53 by yer-retb          #+#    #+#             */
/*   Updated: 2022/06/27 11:03:31 by yer-retb         ###   ########.fr       */
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

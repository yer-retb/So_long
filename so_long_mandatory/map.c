/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 11:20:02 by yer-retb          #+#    #+#             */
/*   Updated: 2022/07/01 13:16:20 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_number_of_char(char str)
{
	if (str == '0')
		g_soul.zero = 1;
	if (str == 'P')
		g_soul.p += 1;
	if (str == 'E')
		g_soul.e = 1;
	if (str == 'C')
		g_soul.c = 1;
}

void	venemd_map(void)
{
	if (g_soul.zero != 1 || g_soul.c != 1 || g_soul.e != 1 || g_soul.p != 2)
		print_error('M');
}

void	check_wall(void)
{
	int	i;
	int	j;
	int	size;

	i = -1;
	while (++i < g_soul.length)
	{
		j = ft_strlen(g_soul.map[i]) - 1;
		if (g_soul.map[i][0] != '1' || g_soul.map[i][j] != '1')
			print_error('M');
	}
	size = -1;
	while (++size < g_soul.length)
	{
		i = ft_strlen(g_soul.map[size]) - 1;
		if (i != j)
			print_error('M');
	}
	j = -1;
	while (++j < ft_strlen(g_soul.map[0]) - 1)
	{
		if (g_soul.map[0][j] != '1' || g_soul.map[g_soul.length - 1][j] != '1')
			print_error('M');
	}
	venemd_map();
}

int	size_of_allocation(char *name)
{
	int		fd;
	char	*str;

	fd = open(name, O_RDWR);
	str = get_next_line(fd);
	g_soul.width = ft_strlen(str);
	while (str != NULL)
	{
		g_soul.length++;
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	return (g_soul.length);
}

void	ft_free(void)
{
	int	i;

	i = 0;
	while (i < g_soul.length)
	{
		free(g_soul.map[i]);
		i++;
	}
	free(g_soul.map);
}

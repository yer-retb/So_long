/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 18:38:06 by yer-retb          #+#    #+#             */
/*   Updated: 2022/07/01 13:34:32 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar(char c)
{
	if (write(1, &c, 1))
		g_count++;
}

void	ft_free(void)
{
	int	i;

	i = 0;
	while (g_soul.map[i])
	{
		free(g_soul.map[i]);
		i++;
	}
	free(g_soul.map);
}

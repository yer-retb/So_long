/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 07:59:42 by yer-retb          #+#    #+#             */
/*   Updated: 2022/06/29 08:36:44 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_int(long int x)

{
	int			j;
	long int	n;

	n = x;
	j = 1;
	if (n < 0)
	{
		n = n * -1;
		j++;
	}
	while (n > 9)
	{
		n = n / 10;
		j++;
	}
	return (j);
}

char	*strjoin(char *s1, char *s2)

{
	int		i;
	int		len_1;
	int		len_2;
	char	*p;

	i = -1;
	if (s1 && s2)
	{
		len_1 = ft_strlen(s1);
		len_2 = ft_strlen(s2);
		p = (char *)malloc ((len_1 + len_2) * sizeof(char) + 1);
		if (!p)
			return (NULL);
		while (s1[++i] != '\0')
			p[i] = s1[i];
		i = -1;
		while (s2[++i] != '\0')
			p[len_1 + i] = s2[i];
		p[len_1 + i] = '\0';
		return (p);
	}
	return (NULL);
}

char	*ft_itoa(int n)

{
	int			i;
	char		*rsl;
	int			count;
	long int	tmp;

	count = count_int(n);
	i = 0;
	rsl = (char *)malloc(sizeof (char) * (count + 1));
	if (!rsl)
		return (NULL);
	rsl[count] = '\0';
	count--;
	tmp = n;
	if (tmp < 0)
		tmp = tmp * -1;
	while (count >= 0)
	{
		rsl[count] = (tmp % 10) + 48;
		tmp = tmp / 10;
		count--;
	}
	if (n < 0)
		rsl[0] = '-';
	rsl = strjoin("score : ",rsl);
	return (rsl);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 23:52:14 by yer-retb          #+#    #+#             */
/*   Updated: 2022/06/29 08:00:10 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct n_list {
	int		size;
	char	*conter;
	char	*line_width;
	char	**map;
	int		width;
	int		length;
	char	*the_n;
	void	*mlx;
	void	*mlx_win;
	void	*backround;
	void	*open_door;
	void	*close_door;
	void	*wall;
	void	*coin;
	void	*player;
	void	*p_left;
	void	*p_down;
	void	*p_right;
	void	*enem_one;
	void	*enem_tow;
	void	*enem_thre;
	void	*enem_four;
	void	*enem_five;
	int		cont;
	int		cont_coin;
	int		zero;
	int		c;
	int		p;
	int		e;
	int		steps;
}	t_list;

t_list		g_soul;
int			g_count;

void	print_error(char c);
int		size_of_allocation(char **av);
void	check_ber(char *av);
void	ft_map(char **av, int size);
void	check_number_of_char(char str);
void	ft_move_up(void);
void	ft_move_down(void);
void	ft_move_right(void);
void	ft_move_left(void);
void	put_image(char c);
int		move_player(int keyhook);
int		exit_game(int key);
int		checker(int i, int j);
void	check_wall(void);
void	open_door(void);
int		enemie(int i, int j);
char	*ft_itoa(int n);

/* get next line */

int		ft_strlen(char *str);
int		ft_strchr(char *ptr);
int		no_buf(char *s);
char	*get_next_line(int fd);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *str, int start, int len);
char	*check_the_n(char *saved, char c);
char	*after_the_n(char *after, char d);
int		check_map(char *str);
void	check_number_of_char(char str);

/* ft_printf */

int		ft_printf(const char *format, ...);
void	ft_putstr(char *s);
void	ft_putchar(char c);
void	ft_putnbr(long long n);
void	ft_puthexa(unsigned long n, char letter);

#endif
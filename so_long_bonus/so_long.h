/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 23:52:14 by yer-retb          #+#    #+#             */
/*   Updated: 2022/07/01 15:32:20 by yer-retb         ###   ########.fr       */
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

typedef struct n_enemie {
	int	i;
	int	j;
	int	dir;
}	t_enemie;

typedef struct n_player{
	int	i;
	int	j;
}	t_player;

typedef struct n_list {
	int			width;
	int			length;
	int			size;
	int			cont_coin;
	int			zero;
	int			c;
	int			p;
	int			e;
	int			steps;
	int			enemies;
	int			spid;
	char		*conter;
	char		*line_width;
	char		**map;
	char		*the_n;
	void		*mlx;
	void		*mlx_win;
	void		*backround;
	void		*open_door;
	void		*close_door;
	void		*wall;
	void		*player;
	void		*p_left;
	void		*p_down;
	void		*p_right;
	void		*enem_one;
	void		*enem_tow;
	void		*enem_thre;
	void		*enem_four;
	void		*enem_five;
	void		*c1;
	void		*c2;
	void		*c3;
	void		*c4;
	void		*c5;
	void		*c6;
	void		*c7;
	void		*c8;
	t_enemie	*enem;
	t_player	king;
}	t_list;

t_list	g_soul;
int		g_count;
int		g_speed;

int		size_of_allocation(char **av);
int		move_player(int keyhook);
int		exit_game(int key);
int		checker(int i, int j);
int		render_enemie(void);
char	*ft_itoa(int n);
void	print_error(char c);
void	check_ber(char *av);
void	ft_map(char **av, int size);
void	check_number_of_char(char str);
void	ft_move_up(void);
void	ft_move_down(void);
void	ft_move_right(void);
void	ft_move_left(void);
void	put_image(void);
void	check_wall(void);
void	open_door(void);
void	enemie(void);
void	put_string_in_win(char *str);
void	count_enemies(void);
void	set_enemies(void);
void	get_direction(void);
void	ft_free(void);
void	move_enemie(void);

/* get next line */

int		ft_strlen(char *str);
int		ft_strchr(char *ptr);
int		no_buf(char *s);
int		check_map(char *str);
char	*get_next_line(int fd);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *str, int start, int len);
char	*check_the_n(char *saved, char c);
char	*after_the_n(char *after, char d);
void	check_number_of_char(char str);

/* ft_printf */

int		ft_printf(const char *format, ...);
void	ft_putstr(char *s);
void	ft_putchar(char c);
void	ft_putnbr(long long n);
void	ft_puthexa(unsigned long n, char letter);

#endif

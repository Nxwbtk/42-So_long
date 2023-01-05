/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 01:07:57 by bsirikam          #+#    #+#             */
/*   Updated: 2023/01/06 03:08:32 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# if BUFFER_SIZE < 1
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdarg.h>
# include "./MLX/mlx.h"
# ifndef KEY_H
#  define KEY_H

#  define X_EVENT_KEY_PRESS        2
#  define X_EVENT_KEY_RELEASE    3
#  define X_EVENT_KEY_EXIT        17
#  ifdef __linux__
#   define KEY_CTRL            65507
#   define KEY_ENTER            65293
#   define KEY_SPACE            32
#   define KEY_ESC            65307
#   define KEY_LEFT            65361
#   define KEY_RIGHT            65363
#   define KEY_UP            65362
#   define KEY_DOWN            65364
#   define KEY_A                97
#   define KEY_S                115
#   define KEY_D                100
#   define KEY_W                119
#   define KEY_R                114
#  else
#   define KEY_CTRL            256
#   define KEY_ENTER            36
#   define KEY_SPACE            49
#   define KEY_ESC            53
#   define KEY_LEFT            123
#   define KEY_RIGHT            124
#   define KEY_UP            126
#   define KEY_DOWN            125
#   define KEY_A                0
#   define KEY_S                1
#   define KEY_D                2
#   define KEY_W                13
#   define KEY_R                15
#  endif

# endif

typedef struct s_map
{
	char			**map;
	int				p_pos_r;
	int				p_pos_c;
	int				height;
	int				walk;
	int				c;
	int				take_c;
	int				step;
	int				r_decoy;
	int				c_decoy;
	void			*mlx;
	void			*win;
	void			*wall;
	void			*floor;
	void			*player;
	void			*collect;
	void			*exit;
}				t_map;

typedef struct s_sarabun
{
	char	**map;
	int		hight;
	int		len;
	int		p_pos_r;
	int		p_pos_c;
	int		num_c;
	int		num_c_can_read;
	int		num_e;
}			t_sarabun;

char	*ft_strrchr(const char *s, int c);
void	ft_check_file(char *av);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
ssize_t	ft_piset_len(const char *s);
int		ha_nee(char *str, char c);
ssize_t	ft_strlen(const char *s);
char	*free_line(char *line);
void	ft_check_ber(char *av, t_sarabun *sarabun);
void	ft_get_line(int fd, t_sarabun *sarabun, char *av);
void	ft_check_line(char *line, t_sarabun *sarabun);
char	*ft_strchr(const char *s, int c);
void	ft_create_map(char *av, t_sarabun *sarabun);
void	ft_check_frame(t_sarabun *sarabun);
int		ft_printf(const char *format, ...);
int		ft_fmt(const char c, va_list args);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		ft_uint(unsigned int n);
int		ft_point(unsigned long p);
int		ft_xlek(unsigned long x);
int		ft_xyai(unsigned long X);
void	ft_ha_p(t_sarabun *sarabun);
int		ft_slen_no_nl(char *s);
void	ft_flood_fill(char **map, t_sarabun *sarabun, int row, int column);
void	check_c_e(t_sarabun *sarabun);
void	ft_create_real_map(t_map *map_real, t_sarabun *sarabun, char *av);
void	ft_render(t_map *real_map, t_sarabun *sarabun);
void	ft_floor(t_map *real_map, t_sarabun *sarabun);
void	ft_wall(t_map *real_map);
void	ft_free_map(t_sarabun *sarabun);
void	ft_free_render(t_map *real_map);
int		ft_key_hook(int key_code, t_map *real_map);
void	ft_put_img(char c, t_map *real_map, int h, int l);
void	ft_come_hook(t_map *real_map);
void	ft_close(t_map *real_map);
void	ft_dern(t_map *m, int r, int c);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <hguillau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 02:02:24 by akunegel          #+#    #+#             */
/*   Updated: 2024/11/19 06:58:57 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include "includes/gnl/get_next_line.h"
# include "mlx.h"

# define WIN_WIDTH 	1080
# define WIN_HEIGHT 520
# define TILE_SIZE	100
//#define M_PI 3.1415926
# define M_P2		1.5707963		// M_PI/2 / norminette je te hais
# define M_P3		4.7123889		// (3*M_PI)/2 / norminette je te hais
# define FOV		60
# define MOVE_SPEED	10
# define ROT_SPEED	0.05
# define EPSILON	0.000001

typedef struct s_raycasting
{
	double		r_angle;
	double		distance;
	int			flag;
	double		t_px;
	double		b_px;
	double		step_x;
	double		step_y;
	int			text_x;
	int			text_y;
	double		wall_x;
	double		h_x;
	double		v_y;
}				t_raycasting;

typedef struct s_player
{
	int		x;
	int		y;
	double	pos_x;
	double	pos_y;
	double	a;
	double	fov_rad;
	char	dir;
}				t_player;

typedef struct s_texture
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_texture;

typedef struct s_i
{
	t_texture	no;
	t_texture	so;
	t_texture	we;
	t_texture	ea;
}				t_i;

typedef struct s_images
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_images;

typedef struct s_map
{
	char	**map;
	int		length;	//height
	int		width;
}				t_map;

typedef struct s_paths
{
	char	*pfile;
	char	*ps;
	char	*pw;
	char	*pn;
	char	*pe;
	char	*pc;
	char	*pf;
}				t_paths;

typedef struct s_textures
{
	int	*rgbc;
	int	*rgbf;
	int	rgbc_hex;
	int	rgbf_hex;
	int	bc;
	int	bf;
}				t_textures;

typedef struct s_data
{
	int						bfile;
	int						bool;
	double					move_x;
	double					move_y;
	t_player				p;
	t_map					map;
	t_paths					paths;
	t_textures				t;
	t_raycasting			r;
	t_i						images;
	void					*mlx;
	void					*mlx_win;
	int						fd;
	char					**file;
	char					**tmp;
}				t_data;

int				ft_exit(t_data *data, char *err);
int				ft_strlen(char *str);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strcpy(char *dest, char *src);
void			parsing(t_data *data);
void			get_file(t_data *data);
void			*ft_calloc(size_t count, size_t size);
int				get_line_nb(t_data *data);
void			get_clean_file(t_data *data);
int				line_is_empty(char *line);
void			get_paths(t_data *data);
void			check_t_paths(t_data *data);
void			extract_xpm(t_data *data, char *pre, char *line, int i);
int				ft_atoi(const char *str);
int				*convert_rgb(char *d, t_data *data);
char			**ft_split(char const *s, char c);
void			check_c(t_data *data);
void			check_f(t_data *data);
unsigned int	rgb_to_hex(int *rgb);
int				check_valid_rgb(t_data *data);
void			check_rgb(t_data *data);
void			get_map(t_data *data);
int				get_longest_line(char **file);
int				get_map_lines(char **file, t_data *data);
void			check_map_chars(t_data *data, int i);
void			check_map_playable(t_data *data, int x, int y);
void			get_images(t_data *data);
int				handle_keypress(int keycode, t_data *data);
void			free_tmp_int(char **tmp);
void			check_map_chars_extended(t_data *data, int i, int j);
void			cpy_tmp_file(t_data *data, int i, int j);
void			free_map(t_data *data);

// The Game !!
void			start_mlx(t_data *data);
int				game_loop(t_data *data);
void			ft_mov_cam(t_data *data, int key);
void			ft_move(t_data *data, int keycode);
void			my_mlx_pixel_put(t_images *img, int x, int y, int color);
void			cast_ray(t_data *data, t_images *img);
void			draw_wall(t_data *data, int ray, t_images *img);
double			nor_angle(double angle);

//textures
void			get_images(t_data *data);
int				get_color_from_texture(t_texture *t, int x, int y);
void			get_text_x(t_data *data, t_texture *t);

#endif

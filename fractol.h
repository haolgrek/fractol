/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 11:32:29 by rluder            #+#    #+#             */
/*   Updated: 2016/03/26 18:28:58 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# include <stdlib.h>
# include <mlx.h>

typedef struct		s_brs
{
	int				ex;
	int				ey;
	int				dx;
	int				dy;
	int				gdx;
	int				gdy;
	int				i;
	int				gxincr;
	int				gyincr;
}					t_brs;

typedef struct		s_pos
{
	int				x1;
	int				y1;
	int				x2;
	int				y2;
}					t_pos;

/*typedef struct		s_data
{
	int				*tab;
	int				len;
	int				y;
	struct s_data	*next;
}					t_data;*/

typedef struct		s_mlx
{
	int				gap;
	int				height;
	int				imgx;
	int				imgy;
	void			*mlx;
	void			*win;
	void			*img;
	int				bits;
	int				size;
	int				endian;
	int				*intab;
	int				xsize;
	int				ysize;
	int				maxx;
	int				maxy;
	int				color;
	int				*colors;
	char			*data;
	int				nfract;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	double			zoom;
	double			iter_max;
	int				image_x;
	int				image_y;
	int				x;
	int				y;
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
	double			i;
	double			tmp;
	int				**btab;
	double			j;
	double			k;
}					t_mlx;

t_mlx				*init_mlx(char *file);
void				other_events(int keycode, t_mlx *m);
int					*fillintab(char *file, t_mlx *m, int *intab);
int					*blacktab(t_mlx *m);
int					keys(int keycode, t_mlx *m);
int					checkline(char *str);
void				other_events(int keycode, t_mlx *m);
void				reset(t_mlx *m);
int					*zerotab(t_mlx *m);
void				mandelbrot(t_mlx *m);
void				julia(t_mlx *m);
void				burningship(t_mlx *m);
void				douady(t_mlx *m);
void				doublebrot(t_mlx *m);
void				galaxy(t_mlx *m);
void				racinesinh(t_mlx *m);
void				do_fract(t_mlx *m);

#endif

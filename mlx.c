/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 19:56:14 by rluder            #+#    #+#             */
/*   Updated: 2016/03/21 19:28:46 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*void	directions(int keycode, t_mlx *m)
{
	if (keycode == 126)
		m->imgy -= 10;
	else if (keycode == 124)
		m->imgx += 10;
	else if (keycode == 125)
		m->imgy += 10;
	else if (keycode == 123)
		m->imgx -= 10;
}

int		keys(int keycode, t_mlx *m)
{
	if (keycode == 53)
		exit(0);
	directions(keycode, m);
	if (keycode == 69 && m->maxx * (m->gap + 2) < m->xsize)
		m->gap++;
	else if (keycode == 78 && m->gap > 0)
		m->gap--;
	else if (keycode == 83)
		m->color -= 512;
	else if (keycode == 84)
		m->color += 512;
	else if (keycode == 89 && m->height > -3)
		m->height--;
	else if (keycode == 91 && m->height < 3)
		m->height++;
	else if (keycode == 15)
		reset(m);
	mlx_clear_window(m->mlx, m->win);
	other_events(keycode, m);
	mlx_put_image_to_window(m->mlx, m->win, m->img, m->imgx, m->imgy);
	return (0);
}*/

int		*init_colors()
{
	int	*cols;
	int	i;
	int	r;
	int	g;
	int	b;

	i = 0;
	cols = malloc (sizeof(int) * 50 + 1);
	while (i < 50)
	{
		r = 0x00FF0000 * 50 / (i + 51);
		g = 0x0000FF00 * 50 / (i + 51);
		b = 0x000000FF * 50 / (i + 51);
		cols[i] = b + r + g;
		i++;
	}
	cols[50] = 0;
	return (cols);
}

void	init_mandelbrot(t_mlx *m)
{
	m->x1 = -2.1;
	m->x2 = 0.6;
	m->y1 = -1.2;
	m->y2 = 1.2;
	m->zoom = 400;
	m->iter_max = 50;
	m->image_x = (m->x2 - m->x1) * m->zoom;
	m->image_y = (m->y2 - m->y1) * m->zoom;
}

int		*fillintab(char *file, t_mlx *m, int *intab)
{
//	if (ft_strcmp(file, "julia") == 0)
//		julia(m);
	m->colors = init_colors();
	if (ft_strcmp(file, "mandelbrot") == 0)
	{
		init_mandelbrot(m);
		ft_putendl("in fillintab");
		mandelbrot(m);
		intab[0] = 0xFFFFFF;
		intab[1025] = 0xFFFFFF;
		ft_putendl("out fillintab");
	}
//	else if (ft_strcmp(file, "burningship") == 0)
//		burningship(m);
	return (intab);
}

/*	int	i;
	int	x;
	int	y;

	while (file)
	{
		i = 0;
		while (i < (file->len - 1))
		{
			x = i * m->gap - file->tab[i] * m->height;
			y = file->y * m->gap * m->xsize - file->tab[i] * m->height *
				m->xsize;
			if ((x + y + 135300) >= 0)
			{
				intab[x + y + 135300] = 0xFFFFFF
					- (file->tab[i] * 256);
			}
			i++;
		}
		file = file->next;
	}
	return (intab);
}*/
/*
int		**ft_create_btab(t_mlx *m)
{
	int	**btab;
	int	i;

	i = 0;
	btab = (int**)malloc(sizeof(int*) * ((int)m->image_y + 1));
	while (i < (int)m->image_y)
	{
		btab[i] = &m->intab[i * (int)image_x]
		i++;
	}
	btab[i] = NULL;
	return (btab);
}*/

t_mlx	*init_mlx(char *file)
{
	t_mlx	*m;
//	int		*max;

//	max = max_sizes(file);
	m = malloc(sizeof(t_mlx));
//	m->height = 1;
	m->color = 16707215;
	m->data = file;
	m->mlx = mlx_init();
	m->xsize = 1024;
	m->ysize = 1024;
//	m->maxx = max[0];
//	m->maxy = max[1];
	m->imgx = 0;
	m->imgy = 0;
//	m->gap = 1;
	m->win = mlx_new_window(m->mlx, m->xsize, m->ysize, "Fractol");
	m->img = mlx_new_image(m->mlx, m->xsize, m->ysize);
	m->intab = fillintab(file, m, (int*)mlx_get_data_addr(m->img, &m->bits,
				&m->size, &m->endian));
//	m->btab = ft_create_tab(m);
	return (m);
}

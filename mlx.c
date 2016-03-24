/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 19:56:14 by rluder            #+#    #+#             */
/*   Updated: 2016/03/24 22:28:11 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	other_events(int keycode, t_mlx *m)
{
	if (keycode == 89 || keycode == 91 || keycode == 69 || keycode == 78)
	{
		if (m->nfract == 1)
			mandelbrot(m);
		else if (m->nfract == 2)
		{
			julia(m);
		}
		else if (m->nfract == 3)
			burningship(m);
	}
	mlx_put_image_to_window(m->mlx, m->win, m->img, m->imgx, m->imgy);
}

void	directions(int keycode, t_mlx *m)
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
	if (keycode == 69)
		m->zoom = m->zoom + 10;
	else if (keycode == 78 && m->zoom > 10)
		m->zoom = m->zoom - 10;
	else if (keycode == 83)
		m->color -= 512;
	else if (keycode == 84)
		m->color += 512;
	else if (keycode == 89 && m->iter_max > 10)
		m->iter_max = m->iter_max - 10;
	else if (keycode == 91)
		m->iter_max = m->iter_max + 10;
	mlx_clear_window(m->mlx, m->win);
	other_events(keycode, m);
	mlx_put_image_to_window(m->mlx, m->win, m->img, m->imgx, m->imgy);
	return (0);
}

int		mouse(int x, int y, t_mlx *m)
{
	if (x <= (int)m->image_x && y <= (int)m->image_y && x >= 0 && y >= 0)
	{
		m->j = x * 0.0005;
		m->k = y * 0.0005;
		ft_putnbr(m->j);
		ft_putchar(';');
		ft_putnbr(m->k);
		ft_putchar('\n');
		mlx_clear_window(m->mlx, m->win);
		julia(m);
		mlx_put_image_to_window(m->mlx, m->win, m->img, m->imgx, m->imgy);
	}
	return (0);
}

int		mousebutton(int button, int x, int y, t_mlx *m)
{
	int	i;

	if ((button == 5 || button == 1) && x <= (int)m->image_x && y <= (int)m->image_y)
	{
		m->zoom = m->zoom + 20;
		m->iter_max = m->iter_max + 20;
	}
	mlx_clear_window(m->mlx, m->win);
	other_events(89, m);
	mlx_put_image_to_window(m->mlx, m->win, m->img, m->imgx, m->imgy);
	return (0);
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

void	init_julia(t_mlx *m)
{
	m->x1 = -1.5;
	m->x2 = 1.5;
	m->y1 = -1.5;
	m->y2 = 1.5;
	m->zoom = 400;
	m->iter_max = 50;
	m->j = 0;
	m->k = 0;
	m->image_x = (m->x2 - m->x1) * m->zoom;
	m->image_y = (m->y2 - m->y1) * m->zoom;
}

void	init_burningship(t_mlx *m)
{
	m->x1 = -1.7;
	m->x2 = 1;
	m->y1 = -1.7;
	m->y2 = 1.7;
	m->zoom = 400;
	m->iter_max = 50;
	m->image_x = (m->x2 - m->x1) * m->zoom;
	m->image_y = (m->y2 - m->y1) * m->zoom;
}


int		**ft_create_btab(t_mlx *m)
{
	int	**btab;
	int	i;

	i = 0;
	btab = malloc(sizeof(int*) * m->xsize);
	while (i < m->xsize)
	{
		btab[i] = &m->intab[i * m->xsize];
		i++;
	}
	btab[i] = NULL;
	return (btab);
}

void	do_fract(t_mlx *m)
{
	if (ft_strcmp("mandelbrot", m->data) == 0)
	{
		m->nfract = 1;
		init_mandelbrot(m);
		mandelbrot(m);
	}
	else if (ft_strcmp("julia", m->data) == 0)
	{
		m->nfract = 2;
		init_julia(m);
		julia(m);
	}
	else if (ft_strcmp("burningship", m->data) == 0)
	{
		m->nfract = 3;
		init_burningship(m);
		burningship(m);
	}
}

t_mlx	*init_mlx(char *file)
{
	t_mlx	*m;

	m = malloc(sizeof(t_mlx));
	m->data = file;
	m->mlx = mlx_init();
	m->xsize = 1200;
	m->ysize = 1200;
	m->imgx = 0;
	m->imgy = 0;
	m->win = mlx_new_window(m->mlx, m->xsize, m->ysize, "Fractol");
	m->img = mlx_new_image(m->mlx, m->xsize, m->ysize);
	m->intab = (int*)mlx_get_data_addr(m->img, &m->bits, &m->size, &m->endian);
	m->btab = ft_create_btab(m);
	do_fract(m);
	mlx_hook(m->win, 2, 1, keys, m);
	if (m->nfract == 2)
		mlx_hook(m->win, 6, (1L << 6), mouse, m);
	mlx_mouse_hook(m->win, mousebutton, m);
	mlx_put_image_to_window(m->mlx, m->win, m->img, m->imgx, m->imgy);
	mlx_loop(m->mlx);
	return (m);
}

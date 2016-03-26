/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 19:56:14 by rluder            #+#    #+#             */
/*   Updated: 2016/03/26 19:58:51 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(int x, int y, t_mlx *m)
{
	double	tmp[4];
	double	newx;
	double	newy;

	tmp[0] = m->x1;
	tmp[1] = m->x2;
	tmp[2] = m->y1;
	tmp[3] = m->y2;
	newx = m->x1 + x * (m->x2 - m->x1) / m->image_x;
	newy = m->y1 + y * (m->y2 - m->y1) / m->image_y;
	m->x1 = newx - (tmp[1] - tmp[0]) / 4;
	m->x2 = newx + (tmp[1] - tmp[0]) / 4;
	m->y1 = newy - (tmp[3] - tmp[2]) / 4;
	m->y2 = newy + (tmp[3] - tmp[2]) / 4;
	m->zoom = m->zoom * 2;
	m->iter_max = m->iter_max * 2;
}

void	zoom_out(int x, int y, t_mlx *m)
{
	double	tmp[4];
	double	newx;
	double	newy;

	tmp[0] = m->x1;
	tmp[1] = m->x2;
	tmp[2] = m->y1;
	tmp[3] = m->y2;
	newx = m->x1 + x * (m->x2 - m->x1) / m->image_x;
	newy = m->y1 + y * (m->y2 - m->y1) / m->image_y;
	m->x1 = newx - (tmp[1] - tmp[0]);
	m->x2 = newx + (tmp[1] - tmp[0]);
	m->y1 = newy - (tmp[3] - tmp[2]);
	m->y2 = newy + (tmp[3] - tmp[2]);
	m->zoom = m->zoom / 2;
	m->iter_max = m->iter_max / 2;
}

int		mousebutton(int button, int x, int y, t_mlx *m)
{
	int	i;

	if ((button == 5 || button == 1) && x <= (int)m->image_x && y <=
			(int)m->image_y)
		zoom_in(x, y, m);
	if ((button == 4 || button == 2) && x <= (int)m->image_x && y <=
			(int)m->image_y)
		zoom_out(x, y, m);
	mlx_clear_window(m->mlx, m->win);
	other_events(89, m);
	mlx_put_image_to_window(m->mlx, m->win, m->img, m->imgx, m->imgy);
	return (0);
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
	m->color = 0xFFF000;
	m->win = mlx_new_window(m->mlx, m->xsize, m->ysize, "Fractol");
	m->img = mlx_new_image(m->mlx, m->xsize, m->ysize);
	m->intab = (int*)mlx_get_data_addr(m->img, &m->bits, &m->size, &m->endian);
	m->btab = ft_create_btab(m);
	do_fract(m);
	do_fract_bonus(m);
	mlx_hook(m->win, 2, 1, keys, m);
	if (m->nfract >= 2)
		mlx_hook(m->win, 6, (1L << 6), mouse, m);
	mlx_mouse_hook(m->win, mousebutton, m);
	mlx_put_image_to_window(m->mlx, m->win, m->img, m->imgx, m->imgy);
	mlx_loop(m->mlx);
	return (m);
}

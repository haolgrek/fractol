/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/26 19:56:48 by rluder            #+#    #+#             */
/*   Updated: 2016/03/26 20:02:14 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	other_events(int keycode, t_mlx *m)
{
	if (keycode == 89 || keycode == 91 || keycode == 69 || keycode == 78 ||
			keycode == 83 || keycode == 84 || (keycode > 122 && keycode < 127))
	{
		if (m->nfract == 1)
			mandelbrot(m);
		else if (m->nfract == 2)
			julia(m);
		else if (m->nfract == 3)
			burningship(m);
		else if (m->nfract == 4)
			douady(m);
		else if (m->nfract == 5)
			doublebrot(m);
		else if (m->nfract == 6)
			galaxy(m);
		else if (m->nfract == 7)
			racinesinh(m);
	}
	mlx_put_image_to_window(m->mlx, m->win, m->img, m->imgx, m->imgy);
}

void	directions(int keycode, t_mlx *m)
{
	if (keycode == 126)
	{
		m->y2 = m->y2 + 0.0002 * m->zoom;
		m->y1 = m->y1 + 0.0002 * m->zoom;
	}
	else if (keycode == 124)
	{
		m->x2 = m->x2 - 0.0002 * m->zoom;
		m->x1 = m->x1 - 0.0002 * m->zoom;
	}
	else if (keycode == 125)
	{
		m->y2 = m->y2 - 0.0002 * m->zoom;
		m->y1 = m->y1 - 0.0002 * m->zoom;
	}
	else if (keycode == 123)
	{
		m->x2 = m->x2 + 0.0002 * m->zoom;
		m->x1 = m->x1 + 0.0002 * m->zoom;
	}
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
		m->color -= 800;
	else if (keycode == 84)
		m->color += 800;
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
		mlx_clear_window(m->mlx, m->win);
		other_events(89, m);
		mlx_put_image_to_window(m->mlx, m->win, m->img, m->imgx, m->imgy);
	}
	return (0);
}

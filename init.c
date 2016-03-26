/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/26 19:39:17 by rluder            #+#    #+#             */
/*   Updated: 2016/03/26 19:53:43 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

void	do_fract_bonus(t_mlx *m)
{
	if (ft_strcmp("douady", m->data) == 0)
	{
		m->nfract = 4;
		init_julia(m);
		douady(m);
	}
	else if (ft_strcmp("doublebrot", m->data) == 0)
	{
		m->nfract = 5;
		init_julia(m);
		doublebrot(m);
	}
	else if (ft_strcmp("galaxy", m->data) == 0)
	{
		m->nfract = 6;
		init_julia(m);
		galaxy(m);
	}
	else if (ft_strcmp("racinesinh", m->data) == 0)
	{
		m->nfract = 7;
		init_julia(m);
		racinesinh(m);
	}
}

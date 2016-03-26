/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 14:29:27 by rluder            #+#    #+#             */
/*   Updated: 2016/03/26 18:27:15 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

void	julia(t_mlx *m)
{
	m->x = 0;
	while (m->x < m->xsize)
	{
		m->y= 0;
		while (m->y < m->ysize)
		{
			m->c_r = -0.8 + m->k;
			m->c_i = 0.156 + m->j;
			m->z_r = m->x / m->zoom + m->x1;
			m->z_i = m->y / m->zoom + m->y1;
			m->i = 0;
			while ((m->z_r * m->z_r + m->z_i * m->z_i) < 4 && m->i < m->iter_max)
			{
				m->tmp = m->z_r;
				m->z_r = m->z_r * m->z_r - m->z_i * m->z_i + m->c_r;
				m->z_i = 2 * m->z_i * m->tmp + m->c_i;
				m->i++;
			}
			m->btab[m->y][m->x] = m->color * m->i;
			m->y++;
		}
		m->x++;
	}
}

void	mandelbrot(t_mlx *m)
{
	m->x = 0;
	while (m->x < m->xsize)
	{
		m->y= 0;
		while (m->y < m->ysize)
		{
			m->c_r = m->x / m->zoom + m->x1;
			m->c_i = m->y / m->zoom + m->y1;
			m->z_r = 0;
			m->z_i = 0;
			m->i = 0;
			while ((m->z_r * m->z_r + m->z_i * m->z_i) < 4 && m->i < m->iter_max)
			{
				m->tmp = m->z_r;
				m->z_r = m->z_r * m->z_r - m->z_i * m->z_i + m->c_r;
				m->z_i = 2 * m->z_i * m->tmp + m->c_i;
				m->i++;
			}
			m->btab[m->y][m->x] = m->color * m->i;
			m->y++;
		}
		m->x++;
	}
}

void	burningship(t_mlx *m)
{
	m->x = 0;
	while (m->x < m->xsize)
	{
		m->y= 0;
		while (m->y < m->ysize)
		{
			m->c_r = m->x / m->zoom + m->x1;
			m->c_i = m->y / m->zoom + m->y1;
			m->z_r = 0;
			m->z_i = 0;
			m->i = 0;
			while ((m->z_r * m->z_r + m->z_i * m->z_i) < 4 && m->i < m->iter_max)
			{
				m->tmp = m->z_r;
				m->z_r = m->z_r * m->z_r - m->z_i * m->z_i + m->c_r;
				m->z_i = 2 * ((m->z_i * m->tmp > 0) ? m->z_i * m->tmp :m->z_i * m->tmp * -1) + m->c_i;
				m->i++;
			}
			m->btab[m->y][m->x] = m->color * m->i;
			m->y++;
		}
		m->x++;
	}
}

void	douady(t_mlx *m)
{
	m->x = 0;
	while (m->x < m->xsize)
	{
		m->y= 0;
		while (m->y < m->ysize)
		{
			m->c_r = -0.123;
			m->c_i = 0.745;
			m->z_r = m->x / m->zoom + m->x1;
			m->z_i = m->y / m->zoom + m->y1;
			m->i = 0;
			while ((m->z_r * m->z_r + m->z_i * m->z_i) < 4 && m->i < m->iter_max)
			{
				m->tmp = m->z_r;
				m->z_r = m->z_r * m->z_r - m->z_i * m->z_i + m->c_r;
				m->z_i = 2 * m->z_i * m->tmp + m->c_i;
				m->i++;
			}
			m->btab[m->y][m->x] = m->color * m->i;
			m->y++;
		}
		m->x++;
	}
}

void	doublebrot(t_mlx *m)
{
	m->x = 0;
	while (m->x < m->xsize)
	{
		m->y= 0;
		while (m->y < m->ysize)
		{
			m->c_r = -0.8 + m->k;
			m->c_i = 0 + m->j;
			m->z_r = m->x / m->zoom + m->x1;
			m->z_i = m->y / m->zoom + m->y1;
			m->i = 0;
			while ((m->z_r * m->z_r + m->z_i * m->z_i) < 4 && m->i < m->iter_max)
			{
				m->tmp = m->z_r;
				m->z_r = m->z_r * m->z_r - m->z_i * m->z_i + m->c_r;
				m->z_i = 2 * m->z_i * m->tmp + m->c_i;
				m->i++;
			}
			m->btab[m->y][m->x] = m->color * m->i;
			m->y++;
		}
		m->x++;
	}
}
void	galaxy(t_mlx *m)
{
	m->x = 0;
	while (m->x < m->xsize)
	{
		m->y= 0;
		while (m->y < m->ysize)
		{
			m->c_r = 0.4 + m->k;
			m->c_i = 0 + m->j;
			m->z_r = m->x / m->zoom + m->x1;
			m->z_i = m->y / m->zoom + m->y1;
			m->i = 0;
			while ((m->z_r * m->z_r + m->z_i * m->z_i) < 4 && m->i < m->iter_max)
			{
				m->tmp = m->z_r;
				m->z_r = m->z_r * m->z_r * m->z_r - m->z_i * m->z_i + m->c_r;
				m->z_i = 3 * m->z_i * m->tmp + m->c_i;
				m->i++;
			}
			m->btab[m->y][m->x] = m->color * m->i;
			m->y++;
		}
		m->x++;
	}
}
void	racinesinh(t_mlx *m)
{
	m->x = 0;
	while (m->x < m->xsize)
	{
		m->y= 0;
		while (m->y < m->ysize)
		{
			m->c_r = -0.4 + m->k;
			m->c_i = 0 + m->j;
			m->z_r = m->x / m->zoom + m->x1;
			m->z_i = m->y / m->zoom + m->y1;
			m->i = 0;
			while ((m->z_r * m->z_r + m->z_i * m->z_i) < 4 && m->i < m->iter_max)
			{
				m->tmp = m->z_r;
				m->z_r = sqrt(sinh(m->z_r * m->z_r)) - m->z_i * m->z_i + m->c_r;
				m->z_i = 2 * m->z_i * m->tmp + m->c_i;
				m->i++;
			}
			m->btab[m->y][m->x] = m->color * m->i;
			m->y++;
		}
		m->x++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 14:29:27 by rluder            #+#    #+#             */
/*   Updated: 2016/03/25 20:06:49 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
			m->btab[m->y][m->x] = 0x00F00F0F * m->i;
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
			m->btab[m->y][m->x] = 0xFFF000 * m->i;
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
			m->btab[m->y][m->x] = 0x0F00FF * m->i;
			m->y++;
		}
		m->x++;
	}
}

void	buddhabrot(t_mlx *m)
{
	int	iter_min;

	iter_min = 25;
	m->x = 0;
	while (m->x < m->xsize)
	{
		m->y = 0;

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
			if (m->i < m->iter_max && m->i > iter_min && (int)((m->z_i - m->y1) * m->zoom) < m->ysize && (int)((m->z_r - m->x1) * m->zoom) < m->ysize)
				m->btab[(int)((m->z_i - m->y1) * m->zoom)][(int)((m->z_r - m->x1) * m->zoom)] = 0xFFF000 * m->i;
			m->y++;
		}
		m->x++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/26 19:45:10 by rluder            #+#    #+#             */
/*   Updated: 2016/03/26 19:47:36 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	douady(t_mlx *m)
{
	m->x = 0;
	while (m->x < m->xsize)
	{
		m->y = 0;
		while (m->y < m->ysize)
		{
			m->c_r = -0.123;
			m->c_i = 0.745;
			m->z_r = m->x / m->zoom + m->x1;
			m->z_i = m->y / m->zoom + m->y1;
			m->i = 0;
			while ((m->z_r * m->z_r + m->z_i * m->z_i) < 4
					&& m->i < m->iter_max)
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
		m->y = 0;
		while (m->y < m->ysize)
		{
			m->c_r = -0.8;
			m->c_i = 0;
			m->z_r = m->x / m->zoom + m->x1;
			m->z_i = m->y / m->zoom + m->y1;
			m->i = 0;
			while ((m->z_r * m->z_r + m->z_i * m->z_i) < 4
					&& m->i < m->iter_max)
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
		m->y = 0;
		while (m->y < m->ysize)
		{
			m->c_r = 0.4 + m->k;
			m->c_i = 0 + m->j;
			m->z_r = m->x / m->zoom + m->x1;
			m->z_i = m->y / m->zoom + m->y1;
			m->i = 0;
			while ((m->z_r * m->z_r + m->z_i * m->z_i) < 4
					&& m->i < m->iter_max)
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
		m->y = 0;
		while (m->y < m->ysize)
		{
			m->c_r = -0.4 + m->k;
			m->c_i = 0 + m->j;
			m->z_r = m->x / m->zoom + m->x1;
			m->z_i = m->y / m->zoom + m->y1;
			m->i = 0;
			while ((m->z_r * m->z_r + m->z_i * m->z_i) < 4
					&& m->i < m->iter_max)
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

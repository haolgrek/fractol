/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 14:29:27 by rluder            #+#    #+#             */
/*   Updated: 2016/03/22 17:49:44 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*void	julia(t_mlx *m)
{

}*/

void	mandelbrot(t_mlx *m)
{
	m->x = 0;
	ft_putchar('\n');
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

/*void	burningship(t_mlx *m)
{

}*/

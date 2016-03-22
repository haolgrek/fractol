/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 14:29:27 by rluder            #+#    #+#             */
/*   Updated: 2016/03/22 14:15:50 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	trace(int tab, t_mlx *m, int i)
{
	ft_putendl("trace in");
	ft_putendl("intab[0] =");
	ft_putnbr(m->intab[0]);
	m->intab[tab] = i * 100;
	ft_putendl("trace out");
}

/*void	julia(t_mlx *m)
{

}*/

void	mandelbrot(t_mlx *m)
{
/*	x1 = -2.1;
	x2 = 0.6;
	y1 = -1.2;
	y2 = 1.2;
	zoom = 400;
	iter_max = 50;
	ft_putendl("bef imxy");
	ft_putnbr(m->xsize);
	image_x = (x2 - x1) * zoom;
	image_y = (y2 - y1) * zoom;*/
	ft_putendl("after imxy");
//	btab = (int**)malloc(sizeof(int*) * ((int)image_y + 1));

//	m->intab = intab;
	m->x = 0;
	ft_putnbr(m->image_x);
	ft_putchar('\n');
	while (m->x < 1000)
	{
		ft_putendl("in while 1");
		m->y= 0;
		while (m->y < 1000)
		{
			ft_putendl("in while 2");
			m->c_r = m->x / m->zoom + m->x1;
//			ft_putendl("in while 2");
			m->c_i = m->y / m->zoom + m->y1;
//			ft_putendl("in while 2");
			m->z_r = 0;
			m->z_i = 0;
			m->i = 0;
//			ft_putendl("in while 2");
			while ((m->z_r * m->z_r + m->z_i * m->z_i) < 4 && m->i < m->iter_max)
			{
//				ft_putendl("in while 3");
				m->tmp = m->z_r;
				m->z_r = m->z_r * m->z_r - m->z_i * m->z_i + m->c_r;
				m->z_i = 2 * m->z_i * m->tmp + m->c_i;
				m->i++;
			}
//			if (m->i == m->iter_max)
//			{
//				ft_putendl("in if 1");
//				m->btab[m->x][m->y] = 0x00FFFFFF;
//				m->i++;
//			}
//			else
//			{
//				ft_putendl("in if 2");
			m->btab[m->x][m->y] = 0xFFF000 * m->i /*m->colors[m->i]*/;
//				m->i++;
//				ft_putendl("in if 2");
//			}
			m->y++;
		}
		m->x++;
	}
	ft_putendl("at end");
}

/*void	burningship(t_mlx *m)
{

}*/

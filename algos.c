/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 14:29:27 by rluder            #+#    #+#             */
/*   Updated: 2016/03/21 18:22:46 by rluder           ###   ########.fr       */
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
/*	double	x1;
	double	x2;
	double	y1;
	double	y2;
	int	zoom;
	int	iter_max;
	int	image_x;
	int	image_y;
	int	x;
	int	y;
	int	c_r;
	int	c_i;
	int z_r;
	int	z_i;
	int	i;
	int	tmp;
//	int **btab;*/

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

	m->x = 0;
	while (m->x < m->image_x)
	{
		ft_putendl("in while 1");
		m->y= 0;
		while (m->y < m->image_y)
		{
			ft_putnbr(m->xsize);
			ft_putendl("in while 2");
			m->c_r = m->x / m->zoom + m->x1;
			ft_putendl("in while 2");
			m->c_i = m->y / m->zoom + m->y1;
			ft_putendl("in while 2");
			m->z_r = 0;
			m->z_i = 0;
			m->i = 0;
			ft_putendl("in while 2");
			while ((m->z_r * m->z_r + m->z_i * m->z_i) < 4 && m->i < m->iter_max)
			{
				ft_putendl("in while 3");
				m->tmp = m->z_r;
				ft_putendl("in while 3");
				m->z_r = m->z_r * m->z_r - m->z_i * m->z_i + m->c_r;
				ft_putendl("in while 3");
				m->z_i = 2 * m->z_i * m->tmp + m->c_i;
				ft_putendl("in while 3");
				m->i++;
				ft_putendl("in while 3");
			}
			if (m->i == m->iter_max)
			{
				ft_putendl("in if 1");
				m->intab[m->x + m->y * m->ysize] = 0x00FFFFFF;
			}
			else
			{
				ft_putendl("in if 2");
				m->intab[m->x + m->y * m->ysize] = m->colors[m->i];
				ft_putendl("in if 2");
			}
			m->y++;
		}
		m->x++;
	}
	ft_putendl("at end");
}

/*void	burningship(t_mlx *m)
{

}*/

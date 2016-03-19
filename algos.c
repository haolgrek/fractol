/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 14:29:27 by rluder            #+#    #+#             */
/*   Updated: 2016/03/19 23:49:37 by rluder           ###   ########.fr       */
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

void	mandelbrot(t_mlx *m, int *intab)
{
	double	x1;
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

	x1 = -2.1;
	x2 = 0.6;
	y1 = -1.2;
	y2 = 1.2;
	zoom = 400;
	iter_max = 50;
	ft_putendl("bef imxy");
	ft_putnbr(m->xsize);
	image_x = (x2 - x1) * zoom;
	image_y = (y2 - y1) * zoom;
	ft_putendl("after imxy");

	x = 0;
	while (x < image_x)
	{
		ft_putendl("in while 1");
		y= 0;
		while (y < image_y)
		{
			ft_putnbr(m->xsize);
			ft_putendl("in while 2");
			c_r = x / zoom + x1;
			c_i = y / zoom + y1;
			z_r = 0;
			z_i = 0;
			i = 0;
			while ((z_r * z_r + z_i * z_i) < 4 && i < iter_max)
			{
				tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + c_r;
				z_i = 2 * z_i * tmp + c_i;
				i++;
			}
			if (i == iter_max)
			{
				intab[x + y * m->xsize] = 0x00FFFFFF;
			}
			else
				intab[x + y * m->xsize] = m->colors[i];
			y++;
		}
		x++;
	}
}

/*void	burningship(t_mlx *m)
{

}*/

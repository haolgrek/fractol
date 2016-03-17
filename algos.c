/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 14:29:27 by rluder            #+#    #+#             */
/*   Updated: 2016/03/17 15:16:37 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_mlx *m)
{

}

void	mandelbrot(t_mlx *m)
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
	zoom = 100;
	iter_max = 50;
	image_x = (x2 - x1) * zoom;
	image_y = (y2 - y1) * zoom;

	x = 0;
	while (x < image_x)
	{
		y= 0;
		while (y < image_y)
		{
			c_r = x / zoom + x1;
			c_i = y / zoom + y1;
			z_r = 0;
			z_i = 0;
			i = 0;
			tmp = z_r;
			z_r = z_r * z_r - z_i * z_i + c_r;
			z_i = 2 * z_i * tmp + c_i;
			i = i + 1;
			while (z_r * z_r + z_i * z_i < 4 && i < iter_max)

			y++;
		}
		x++;
	}

		Faire
		définir tmp = z_r
		z_r = z_r*z_r - z_i*z_i + c_r
		z_i = 2*z_i*tmp + c_i
		i = i+1
		Tant que z_r*z_r + z_i*z_i < 4 et i < iteration_max

		si i = iteration_max
		dessiner en noir le pixel de coordonné (x; x)
		sinon
		dessiner avec couleur rgb(0, 0, i*255/iterations_max) le pixel de coordonné (x; x)
		finSi
		finPour
		finPour
}

void	burningship(t_mlx *m)
{

}

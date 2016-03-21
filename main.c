/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 11:39:41 by rluder            #+#    #+#             */
/*   Updated: 2016/03/21 17:32:04 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"
#include <stdio.h>
#include "libft/libft.h"

int		main(int argc, char **argv)
{
//	t_data	*file;
	t_mlx	*m;
	int		*intab;

	if (argc != 2)
	{
		ft_putendl("Wrong number of arguments");
		return (0);
	}
	if (ft_strcmp(argv[1], "julia") != 0 && ft_strcmp(argv[1], "mandelbrot")
			!= 0 && ft_strcmp(argv[1], "burningship") != 0)
	{
		ft_putendl("Incorrect argument");
		ft_putendl("Valid arguments are: julia, mandelbrot, burningship");
		return (0);
	}
	ft_putendl("args ok");
	m = init_mlx(argv[1]);
	ft_putendl("init ok");
/*	if (ft_strcmp(argv[1], "julia") == 0)
		trace(m, "j");*/
//	if (ft_strcmp(argv[1], "mendelbrot") == 0)
//		mandelbrot(m, intab);
/*	else if (ft_strcmp(argv[1], "burningship") == 0)
		trace(m, "b");*/
	mlx_put_image_to_window(m->mlx, m->win, m->img, m->imgx, m->imgy);
//	mlx_hook(m->win, 2, 1, keys, m);
	mlx_loop(m->mlx);
	return (0);
}

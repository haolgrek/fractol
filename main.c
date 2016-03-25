/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 11:39:41 by rluder            #+#    #+#             */
/*   Updated: 2016/03/25 18:33:27 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"
#include <stdio.h>
#include "libft/libft.h"

int		main(int argc, char **argv)
{
	t_mlx	*m;
	int		*intab;

	if (argc != 2)
	{
		ft_putendl("Wrong number of arguments");
		return (0);
	}
	if (ft_strcmp(argv[1], "julia") != 0 && ft_strcmp(argv[1], "mandelbrot")
			!= 0 && ft_strcmp(argv[1], "burningship") != 0 && ft_strcmp(argv[1], "buddhabrot") != 0)
	{
		ft_putendl("Incorrect argument");
		ft_putendl("Valid arguments are: julia, mandelbrot, burningship");
		return (0);
	}
	ft_putendl("args ok");
	m = init_mlx(argv[1]);
	ft_putendl("init ok");
	return (0);
}

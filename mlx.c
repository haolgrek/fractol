/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 19:56:14 by rluder            #+#    #+#             */
/*   Updated: 2016/03/17 14:27:02 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*void	directions(int keycode, t_mlx *m)
{
	if (keycode == 126)
		m->imgy -= 10;
	else if (keycode == 124)
		m->imgx += 10;
	else if (keycode == 125)
		m->imgy += 10;
	else if (keycode == 123)
		m->imgx -= 10;
}

int		keys(int keycode, t_mlx *m)
{
	if (keycode == 53)
		exit(0);
	directions(keycode, m);
	if (keycode == 69 && m->maxx * (m->gap + 2) < m->xsize)
		m->gap++;
	else if (keycode == 78 && m->gap > 0)
		m->gap--;
	else if (keycode == 83)
		m->color -= 512;
	else if (keycode == 84)
		m->color += 512;
	else if (keycode == 89 && m->height > -3)
		m->height--;
	else if (keycode == 91 && m->height < 3)
		m->height++;
	else if (keycode == 15)
		reset(m);
	mlx_clear_window(m->mlx, m->win);
	other_events(keycode, m);
	mlx_put_image_to_window(m->mlx, m->win, m->img, m->imgx, m->imgy);
	return (0);
}*/

int		*fillintab(char *file, t_mlx *m, int *intab)
{
	if (ft_strcmp(file, "julia") == 0)
		julia(m);
	else if (ft_strcmp(file, "mendelbrot") == 0)
		mendelbrot(m);
	else if (ft_strcmp(file, "burningship") == 0)
		burningship(m);
	return (intab)
}

/*	int	i;
	int	x;
	int	y;

	while (file)
	{
		i = 0;
		while (i < (file->len - 1))
		{
			x = i * m->gap - file->tab[i] * m->height;
			y = file->y * m->gap * m->xsize - file->tab[i] * m->height *
				m->xsize;
			if ((x + y + 135300) >= 0)
			{
				intab[x + y + 135300] = 0xFFFFFF
					- (file->tab[i] * 256);
			}
			i++;
		}
		file = file->next;
	}
	return (intab);
}*/

t_mlx	*init_mlx(char *file)
{
	t_mlx	*m;
//	int		*max;

//	max = max_sizes(file);
	m = malloc(sizeof(t_mlx));
//	m->height = 1;
	m->color = 16707215;
	m->data = file;
	m->mlx = mlx_init();
	m->xsize = 2048;
	m->ysize = 1024;
//	m->maxx = max[0];
//	m->maxy = max[1];
	m->imgx = 75;
	m->imgy = 75;
//	m->gap = 1;
	m->win = mlx_new_window(m->mlx, m->xsize, m->ysize, "Fractol");
	m->img = mlx_new_image(m->mlx, m->xsize, m->ysize);
	m->intab = fillintab(file, m, (int*)mlx_get_data_addr(m->img, &m->bits,
				&m->size, &m->endian));
	return (m);
}

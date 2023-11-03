/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_hooks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 01:12:39 by naadam            #+#    #+#             */
/*   Updated: 2023/11/03 20:36:23 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	zoom(int button, int x, int y, t_fractal *img)
{
	(void)x;
	(void)y;
	mlx_clear_window(img->mlx, img->window);
	if (button == 4)
		img->scale *= 1.5;
	if (button == 5)
		img->scale /= 1.5;
	redraw(img);
	mlx_put_image_to_window(img->mlx, img->window, img->img, 0, 0);
	return (0);
}

void	reset(t_fractal *img)
{
	mlx_clear_window(img->mlx, img->window);
	img->x = 0.0;
	img->y = 0.0;
	img->height = 720;
	img->width = 720;
	img->max_itr = 150;
	img->color = 0xFFFFFF;
	redraw(img);
	mlx_put_image_to_window(img->mlx, img->window, img->img, 0, 0);
}


int	close_button(int keycode, t_fractal *img)
{
	(void)keycode;
	mlx_clear_window(img->mlx, img->window);
	mlx_destroy_window(img->mlx, img->window);
	ft_putstr_fd("Window exited\n", 1);
	return (0);
}
